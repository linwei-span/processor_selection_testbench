/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    GPIO/GPIO_IOToggle/Src/main.c
  * @author  MCD Application Team
  * @brief   This example describes how to configure and use GPIOs through
  *          the STM32G4xx HAL API.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
//#define RUN_TEST_1
//#define RUN_TEST_2
//#define RUN_TEST_3
//#define RUN_TEST_4
//#define RUN_TEST_5
//#define RUN_TEST_6
#define RUN_TEST_7
//#define RUN_TEST_8

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static GPIO_InitTypeDef  GPIO_InitStruct;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#include "math.h"
#ifdef RUN_TEST_1
#define BUFFER_SIZE       64
#define TABLE_SIZE        64
#define TABLE_SIZE_M_1    TABLE_SIZE-1
#define PIBYTWO           1.570796327
#define PI                3.141592653589
#define INV2PI            0.159154943
float fVal;
float fResult;
float y[BUFFER_SIZE];
float CLAasinTable[]={
    0.0, 1.0, 0.0,
    0.000000636202, 0.999877862610, 0.007815361896,
    0.000005099694, 0.999510644409, 0.015647916155,
    0.000017268312, 0.998895919094, 0.023514960332,
    0.000041121765, 0.998029615282, 0.031434003631,
    0.000080794520, 0.996905974725, 0.039422875916,
    0.000140631089, 0.995517492804, 0.047499840611,
    0.000225244584, 0.993854840311, 0.055683712914,
    0.000339579512, 0.991906765146, 0.063993984848,
    0.000488979852, 0.989659972212, 0.072450958820,
    0.000679263611, 0.987098979366, 0.081075891529,
    0.000916805182, 0.984205946802, 0.089891150305,
    0.001208627040, 0.980960476685, 0.098920384204,
    0.001562502549, 0.977339379243, 0.108188712551,
    0.001987071928, 0.973316400729, 0.117722933997,
    0.002491973784, 0.968861907789, 0.127551759665,
    0.003087995053, 0.963942521723, 0.137706074532,
    0.003787242692, 0.958520694794, 0.148219231941,
    0.004603341138, 0.952554219267, 0.159127386977,
    0.005551660294, 0.945995657913, 0.170469875522,
    0.006649579796, 0.938791682505, 0.182289647088,
    0.007916796475, 0.930882303984, 0.194633761132,
    0.009375683410, 0.922199974574, 0.207553958472,
    0.011051710808, 0.912668537890, 0.221107321885,
    0.012973941175, 0.902201997769, 0.235357042896,
    0.015175614174, 0.890703070035, 0.250373315541,
    0.017694840102, 0.878061473098, 0.266234382514,
    0.020575425537, 0.864151902887, 0.283027765009,
    0.023867860513, 0.848831624374, 0.300851714968,
    0.027630504055, 0.831937595031, 0.319816937941,
    0.031931014547, 0.813283013821, 0.340048646894,
    0.036848083955, 0.792653161200, 0.361689022958,
    0.042473551274, 0.769800358920, 0.384900179460,
    0.048914992206, 0.744437830278, 0.409867752228,
    0.056298910750, 0.716232177740, 0.436805274317,
    0.064774696786, 0.684794109766, 0.465959540059,
    0.074519565699, 0.649666934178, 0.497617226179,
    0.085744766889, 0.610312179660, 0.532113122767,
    0.098703445606, 0.566091493186, 0.569840443472,
    0.113700678529, 0.516243664372, 0.611263845480,
    0.131106395009, 0.459855210927, 0.656936015611,
    0.151372169232, 0.395822366759, 0.707518998893,
    0.175053263659, 0.322801460177, 0.763811905770,
    0.202837883870, 0.239143420888, 0.826787304376,
    0.235586468765, 0.142806299514, 0.897639596948,
    0.274385149825, 0.031236880585, 0.977850174820,
    0.320619535938, -0.098791845166, 1.069276441800,
    0.376078169620, -0.251407364538, 1.174275392129,
    0.443100143614, -0.431959397725, 1.295878193174,
    0.524789871827, -0.647485610469, 1.438041695773,
    0.625336471263, -0.907400624736, 1.606018804842,
    0.750500589935, -1.224540947101, 1.806917563896,
    0.908377657341, -1.616794995066, 2.050569262035,
    1.110633894185, -2.109729648039, 2.350920816737,
    1.374584721437, -2.740985157716, 2.728353889708,
    1.726848242753, -3.567962877198, 3.213722960014,
    2.210117561056, -4.682006534082, 3.855770086891,
    2.896554011854, -6.236312386687, 4.735651038017,
    3.916505715382, -8.505488022524, 5.997790945975,
    5.526855868703, -12.026617159136, 7.922628470498,
    8.298197116322, -17.983705080358, 11.123941286820,
    13.741706072449, -29.488929624542, 17.203344479111,
    27.202707817485, -57.466598393615, 31.741016484669,
    83.158101335898, -171.803399517566, 90.149831709374
};

float asin_expected[BUFFER_SIZE]={
    1.570796, 1.393789, 1.320141, 1.263401, 1.215375,
    1.172892, 1.134327, 1.098718, 1.065436, 1.034046,
    1.004232, 0.9757544, 0.9484279, 0.9221048, 0.8966658,
    0.8720123, 0.8480621, 0.8247454, 0.8020028, 0.7797828,
    0.7580408, 0.7367374, 0.7158381, 0.6953120, 0.6751316,
    0.6552721, 0.6357113, 0.6164289, 0.5974064, 0.5786270,
    0.5600753, 0.5417370, 0.5235988, 0.5056486, 0.4878751,
    0.4702678, 0.4528166, 0.4355124, 0.4183464, 0.4013104,
    0.3843968, 0.3675981, 0.3509074, 0.3343180, 0.3178237,
    0.3014185, 0.2850964, 0.2688521, 0.2526802, 0.2365756,
    0.2205333, 0.2045484, 0.1886164, 0.1727327, 0.1568929,
    0.1410927, 0.1253278, 0.1095943, 0.09388787, 0.07820469,
    0.06254076, 0.04689218, 0.03125509, 0.01562564
};
#endif

#ifdef RUN_TEST_2
#include "arm_math.h"
#include "math.h"
#define BUFFER_SIZE        64
float Val;
float ExpRes;
float y[BUFFER_SIZE];
float CLAexpTable[] = {
    1.0, 2.7182818285e+0, 7.3890560989e+0, 2.0085536923e+1,
    5.4598150033e+1, 1.484131591e+2, 4.0342879349e+2, 1.0966331584e+3,
    2.980957987e+3, 8.1030839276e+3, 2.2026465795e+4, 5.9874141715e+4,
    1.6275479142e+5, 4.4241339201e+5, 1.2026042842e+6, 3.2690173725e+6,
    8.8861105205e+6, 2.4154952754e+7, 6.5659969137e+7, 1.7848230096e+8,
    4.8516519541e+8, 1.3188157345e+9, 3.5849128461e+9, 9.7448034462e+9,
    2.648912213e+10, 7.2004899337e+10, 1.9572960943e+11, 5.320482406e+11,
    1.4462570643e+12, 3.9313342971e+12, 1.0686474582e+13, 2.9048849665e+13,
    7.8962960183e+13, 2.1464357979e+14, 5.8346174253e+14, 1.5860134523e+15,
    4.3112315471e+15, 1.1719142373e+16, 3.1855931757e+16, 8.6593400424e+16,
    2.3538526684e+17, 6.3984349353e+17, 1.7392749415e+18, 4.7278394682e+18,
    1.2851600114e+19, 3.4934271057e+19, 9.4961194206e+19, 2.5813128862e+20,
    7.0167359121e+20, 1.9073465725e+21, 5.1847055286e+21, 1.4093490824e+22,
    3.8310080007e+22, 1.0413759433e+23, 2.8307533033e+23, 7.6947852651e+23,
    2.091659496e+24, 5.6857199993e+24, 1.5455389356e+25, 4.2012104038e+25,
    1.1420073898e+26, 3.1042979357e+26, 8.4383566687e+26, 2.2937831595e+27,
    6.2351490808e+27, 1.6948892444e+28, 4.6071866343e+28, 1.2523631708e+29,
    3.4042760499e+29, 9.2537817256e+29, 2.5154386709e+30, 6.8376712298e+30,
    1.8586717453e+31, 5.0523936303e+31, 1.3733829795e+32, 3.7332419968e+32,
    1.0148003881e+33, 2.7585134545e+33, 7.498416997e+33, 2.0382810665e+34,
    5.5406223844e+34, 1.5060973146e+35, 4.0939969621e+35, 1.1128637548e+36,
    3.0250773222e+36, 8.2230127146e+36, 2.2352466037e+37, 6.0760302251e+37,
    1.651636255e+38
};
float exp10_expected[BUFFER_SIZE]={
10, 9.646616, 9.305720, 8.976871, 8.659643,
8.353625, 8.058422, 7.773650, 7.498942, 7.233942,
6.978306, 6.731704, 6.493816, 6.264335, 6.042964,
5.829415, 5.623413, 5.424691, 5.232991, 5.048066,
4.869675, 4.697589, 4.531584, 4.371445, 4.216965,
4.067945, 3.924190, 3.785515, 3.651741, 3.522695,
3.398208, 3.278121, 3.162278, 3.050528, 2.942727,
2.838736, 2.738420, 2.641648, 2.548297, 2.458244,
2.371374, 2.287573, 2.206734, 2.128752, 2.053525,
1.980957, 1.910953, 1.843423, 1.778279, 1.715438,
1.654817, 1.596339, 1.539927, 1.485508, 1.433013,
1.382372, 1.333521, 1.286397, 1.240938, 1.197085,
1.154782, 1.113974, 1.074608, 1.036633 };
float CLALOG10_E = 2.30258509;
//
//Coefficients in the Taylor series expansion of exp(A/B)
//
float CLAINV1 =   1.0 ;
float CLAINV2 =   0.5 ; //1/2
float CLAINV3 =   0.333333333333333333; //1/3
float CLAINV4 =   0.25; //1/4
float CLAINV5 =   0.20; //1/5
float CLAINV6 =   0.166666666666666666; //1/6
float CLAINV7 =   0.142857142857142857; //1/7
#endif

#ifdef RUN_TEST_4
#include "math.h"
#define BUFFER_SIZE     64
float div_expected[BUFFER_SIZE]={
    1, 0.9692308, 0.9393939, 0.9104478, 0.8823529,
    0.8550724, 0.8285714, 0.8028169, 0.7777778, 0.7534246,
    0.7297297, 0.7066666, 0.6842105, 0.6623377, 0.6410257,
    0.6202531, 0.6000000, 0.5802469, 0.5609756, 0.5421687,
    0.5238096, 0.5058824, 0.4883721, 0.4712644, 0.4545455,
    0.4382023, 0.4222222, 0.4065934, 0.3913043, 0.3763441,
    0.3617021, 0.3473684, 0.3333333, 0.3195876, 0.3061225,
    0.2929293, 0.2800000, 0.2673267, 0.2549020, 0.2427184,
    0.2307692, 0.2190476, 0.2075472, 0.1962617, 0.1851852,
    0.1743119, 0.1636364, 0.1531532, 0.1428571, 0.1327434,
    0.1228070, 0.1130435, 0.1034483, 0.09401710, 0.08474576,
    0.07563026, 0.06666667, 0.05785124, 0.04918033, 0.04065040,
    0.03225806, 0.02400000, 0.01587302, 0.007874016
};
float Num;
float Den;
float Res;
float y[BUFFER_SIZE];
#endif

#ifdef RUN_TEST_5
#include "math.h"
#define M	3
#define N	3
int32_t x[M][N];
int32_t y[M][N];
int32_t z[M][N];
int32_t z_expected[][N]={{20,31,40},{7,11,17},{14,22,44}};
#endif

#ifdef RUN_TEST_6
#include "math.h"
#define M	3
#define N	3
float x[M][N];
float z[M][N];
float z_expected[][N]={{1,4,7},{2,5,8},{3,6,9}};
#endif

#ifdef RUN_TEST_7
#include "math.h"
#define LENGTH3 7
#define LENGTH4 10
#define int32 int32_t
#define float32 float_t
float  vector1[] = {1.0,-11.3,6.2,10.8,2.5,7.3,13.2,3.1};
int32  length1 = 8; // Length 3 and 4 are #defined in vmaxfloat_shared.h
float32 max1;
int32   index1;
float  vector2[] = {-3.6,-11.3,-16.2,-10.8,-2.5,-12.5,-33.3};
int32  length2 = 7;
float32 max2;
int32   index2;
float  vector3[] = {12.2,2.3,9.6,9.2,6.2,10.8,2.5,-13.3};
int32   index3;
float32 max3;
float  vector4[] = {1.1,9.9,7.7,-5.5,-2.2,4.4,-8.8,0.0,6.6,-4.4};
float32 max4, min4;
int32   i;
#endif

#ifdef RUN_TEST_8
#include "math.h"
//#include "arm_math.h"
float fVal; //input
float fResult;  //Estimated result
#endif

uint16_t pass=0;
uint16_t fail=0;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* STM32G4xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user
         can eventually implement his proper time base source (a general purpose
         timer for example or other time source), keeping in mind that Time base
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

   /* -1- Enable GPIO Clock (to be able to program the configuration registers) */
  LED2_GPIO_CLK_ENABLE();

  /* -2- Configure IO in output push-pull mode to drive external LEDs */
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  GPIO_InitStruct.Pin = LED2_PIN;
  HAL_GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);

  /* USER CODE END 2 */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

#ifdef RUN_TEST_1
	  int16_t i, error;

	  for(i=0; i < BUFFER_SIZE; i++)
	  {
		  fVal= (float)(BUFFER_SIZE - i)/(float)BUFFER_SIZE;
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);

		  //
		  //Local Variables
		  //
		  int xTblIdx; //integer valued Table index
		  float A0,A1,A2; //Table coefficients
		  float *entry;
		  float result;

		  //
		  //Preprocessing
		  //
		  xTblIdx = fVal * TABLE_SIZE_M_1; //convert table index to u16-bits
		  xTblIdx = xTblIdx * 3; //Table is ordered as 3 32-bit coefficients, the
								 //index points to these triplets, hence the *3*sizeof(float)
		  entry = &CLAasinTable[xTblIdx];
		  A0 = *entry++;
		  A1 = *entry++;
		  A2 = *entry;


		  result = A0 + fVal*(A1 + A2*fVal);

		  //
		  //Post processing
		  //
		  if(fVal < 0)
		  {
			  result = - result;
		  }

		  fResult = result;
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

		  y[i] = fResult;
		  error = fabs(asin_expected[i]-y[i]);

		  if(error < 0.1)
		  {
			  pass++;
		  }
		  else
		  {
			  fail++;
		  }
	  }
#endif

#ifdef RUN_TEST_2
	int i, error;

	for(i=0; i < BUFFER_SIZE; i++)
	{
		Val = (float)(BUFFER_SIZE - i)/(float)BUFFER_SIZE;
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);

		//Local Variables
		float X;        //Exponent
		float Xm;       //Residue
		int Idx;        //index into EXP table

		float Ei,Em;    //Exponent(Integer), Exponent(Mantissa)
		float result;
		float temp;

		//
		//Step(1):    Calculate absolute of x/LOG10(e) (or x*LN(10))
		//
		X = fabs(Val*CLALOG10_E);

		//
		//Step(2):   Identify the integer and mantissa of the input
		//
		Idx = (int)X;
		Xm = frexpf(X, &Idx);

		//
		//Step(3):   Obtain the e^integer(x) from the table
		//
		Ei = CLAexpTable[Idx];
		Em = CLAINV1 + Xm*(CLAINV1 + Xm*CLAINV2 *(CLAINV1+(Xm*CLAINV3) \
					 *(CLAINV1+(Xm*CLAINV4)*(CLAINV1+(Xm*CLAINV5) \
					 *(CLAINV1+(Xm*CLAINV6)*(CLAINV1+Xm*CLAINV7))))));
		result = Ei*Em;

		temp = 1/result;
		if(Val < 0.0)
		{
			result = temp;
		}

		ExpRes  = result;
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
		y[i] = ExpRes;
		error = fabs(exp10_expected[i]-y[i]);

		if(error < 0.01)
		{
			pass++;
		}
		else
		{
			fail++;
		}
	}
#endif

#ifdef RUN_TEST_3
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
	  long a,b,mask,r;

	  //
	  //implement same set of operations as the CLA
	  //as a point of comparison
	  //1. Compute sign of an integer
	  //
	  a = -12;
	  (-(a<0) == -1) ? pass++ : fail++;

	  //
	  //2.Detect if two integers have opposite signs
	  //
	  a = -12;
	  b =12;
	  ((a^b) < 0)?pass++:fail++;

	  //
	  //3.compute absolute value of 'a'
	  //
	  a = -13;
	  b = 4;
	  mask = a >> 31;
	  r = (a + mask)^mask;

	  (r == 13)? pass++ : fail++;

	  mask = b >> 31;
	  r = (b + mask)^mask;

	  (r == 4)? pass++ : fail++;

	  //
	  //4.Compute min of two integers
	  //
	  a = 5;
	  b = 2;
	  r = b^((a ^ b) & -( a < b ));

	  (r == 2)? pass++ : fail++;

	  r = b^((a^b) & -(a>b));
	  (r == 5)? pass++ : fail++;

	  //
	  //5. determine if a number is a power of 2
	  //
	  a = 64;
	  b = 37;

	  r = ((a & (a -1)) == 0); //do a boolean operation
	  (r == 1)? pass++ : fail++;

	  r = ((b & (b -1)) == 0); //do a boolean operation
	  (r == 0)? pass++ : fail++;
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
#endif

#ifdef RUN_TEST_4
	int i, error;

	for(i=0; i<BUFFER_SIZE; i++)
	{
		 Num = (float)(BUFFER_SIZE - i);
		 Den = (float)(BUFFER_SIZE + i);

		 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		 Res = Num/Den;
		 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

		 y[i] = Res;
		 error = fabs(div_expected[i]-y[i]);
		 if (error < 0.01)
		 {
			pass++;
		 }
		 else
		 {
			fail++;
		 }
	}
#endif

#ifdef RUN_TEST_5
	//
	//    x[][] = {{10,3,4}, {3,1,2}, {4,2,6}};
	//
	x[0][0] = 10;
	x[0][1] = 3;
	x[0][2] = 4;
	x[1][0] = 3;
	x[1][1] = 1;
	x[1][2] = 2;
	x[2][0] = 4;
	x[2][1] = 2;
	x[2][2] = 6;

	//
	//    y[][] = {{1,2,1}, {2,1,2}, {1,2,6}};
	//
	y[0][0] = 1;
	y[0][1] = 2;
	y[0][2] = 1;
	y[1][0] = 2;
	y[1][1] = 1;
	y[1][2] = 2;
	y[2][0] = 1;
	y[2][1] = 2;
	y[2][2] = 6;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
	//Local Variables
	int32_t tmp;
	int ii,jj,kk;

	for(ii=0;ii<M;ii++)
	{
		for(jj=0;jj<N;jj++)
		{
			tmp = 0;
			for(kk=0;kk<N;kk++)
			{
			  tmp += x[ii][kk]*y[kk][jj];
			}
			z[ii][jj] = tmp;
		}
	}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

	unsigned int i,j;

	int32_t fError[M][N];
	for(i=0; i < M; i++)
	{
		for(j=0; j < N; j++)
		{
			fError[i][j] = fabs(z_expected[i][j]-z[i][j]);

			if(fError[i][j] == 0)
			{
				pass++;
			}
			else
			{
				fail++;
			}
		}
	}
#endif

#ifdef RUN_TEST_6
	//
	//  x[][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
	//
	x[0][0] = 1;
	x[0][1] = 2;
	x[0][2] = 3;
	x[1][0] = 4;
	x[1][1] = 5;
	x[1][2] = 6;
	x[2][0] = 7;
	x[2][1] = 8;
	x[2][2] = 9;


	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
	//Local Variables
	int ii,jj;

	for(ii=0;ii<M;ii++)
	{
		for(jj=0;jj<N;jj++)
		{
			z[jj][ii] = x[ii][jj];
		}
	}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

	unsigned int i,j;
	float fError[M][N];

	for(i=0; i < M; i++)
	{
		for(j=0; j < N; j++)
		{
			fError[i][j] = fabs(z_expected[i][j]-z[i][j]);

			if(fError[i][j] == 0)
			{
				pass++;
			}
			else
			{
				fail++;
			}
		}
	}
#endif

#ifdef RUN_TEST_7
	//
	//    float  vector1[] = {1.0,-11.3,6.2,10.8,2.5,7.3,13.2,3.1};
	//
	length1 = 8;
	vector1[0] = 1.0;
	vector1[1] = -11.3;
	vector1[2] = 6.2;
	vector1[3] = 10.8;
	vector1[4] = 2.5;
	vector1[5] = 7.3;
	vector1[6] = 13.2;
	vector1[7] = 3.1;

	//
	//    float  vector2[] = {-3.6,-11.3,-16.2,-10.8,-2.5,-12.5,-33.3};
	//
	length2 = 7;
	vector2[0] = -3.6;
	vector2[1] = -11.3;
	vector2[2] = -16.2;
	vector2[3] = -10.8;
	vector2[4] = -2.5;
	vector2[5] = -12.5;
	vector2[6] = -33.3;

	//
	//    float  vector3[] = {12.2,2.3,9.6,9.2,6.2,10.8,2.5,-13.3};
	//
	vector3[0] = 12.2;
	vector3[1] = 2.3;
	vector3[2] = 9.6;
	vector3[3] = 9.2;
	vector3[4] = 6.2;
	vector3[5] = 10.8;
	vector3[6] = 2.5;
	vector3[7] = -13.3;

	//
	//    float  vector4[] = {1.1,9.9,7.7,-5.5,-2.2,4.4,-8.8,0.0,6.6,-4.4};
	//
	vector4[0] = 1.1;
	vector4[1] = 9.9;
	vector4[2] = 7.7;
	vector4[3] = -5.5;
	vector4[4] = -2.2;
	vector4[5] = 4.4;
	vector4[6] = -8.8;
	vector4[7] = 0.0;
	vector4[8] = 6.6;
	vector4[9] = -4.4;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
#ifdef RUN_CLA
	Cla1ForceTask1andWait();
#else
	max1 = vector1[length1-1];
	index1 = length1-1;

	for(i = length1-1; i >= 0; i--)
	{
		if(vector1[i] > max1)
		{
		   max1 = vector1[i];
		   index1 = i;
		}
	}
#endif
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
#ifdef RUN_CLA
	Cla1ForceTask2andWait();
#else
	max2 = vector2[0];
	index2 = 0;

	for(i = 1; i < length2; i++)
	{
		if(vector2[i] > max2)
		{
		   max2 = vector2[i];
		   index2 = i;
		}
	}
#endif
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
#ifdef RUN_CLA
	Cla1ForceTask3andWait();
#else
	int32 local_index;
	max3 = vector3[0];
	index3 = 0;

	for(local_index = 1; local_index < LENGTH3; local_index++)
	{
		max3 = (vector3[local_index] > max3) ? vector3[local_index] : max3;
		index3 = (vector3[local_index] > max3) ? local_index : index3 ;
	}
#endif
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
#ifdef RUN_CLA
	Cla1ForceTask4andWait();
#else
	local_index = 0;
	max4 = vector4[0];
	min4 = vector4[0];
	for(local_index = 1; local_index < LENGTH4; local_index++)
	{
	   min4 = fmin(min4, vector4[local_index]);
	   max4 = fmax(max4, vector4[local_index]);
	}
#endif
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);

	if(index1 != 6 || max1 != 13.2)
	{
		fail++;
	}
	else
	{
		pass++;
	}
	if(index2 != 4 || max2 != -2.5)
	{
		fail++;
	}
	else
	{
		pass++;
	}
	if(index3 != 0 || max3 != 12.2)
	{
		fail++;
	}
	else
	{
		pass++;
	}
	if(max4 != 9.9 || min4 != -8.8)
	{
		fail++;
	}
	else
	{
		pass++;
	}
#endif

#ifdef RUN_TEST_8
	fVal = 2;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
//	fResult = arm_sqrt_f32(fVal);
	fResult = sqrt(fVal);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

	if(fResult < 1.4143 && fResult > 1.4141)
	{
	   pass++;
	}
	else
	{
	   fail++;
	}
#endif

//    /* USER CODE BEGIN 3 */
//    HAL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
//    /* Insert delay 100 ms */
//    HAL_Delay(100);

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {
  }

  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

