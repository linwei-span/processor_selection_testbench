/*
************************************************************
* NOTE: Automatically generated file. DO NOT MODIFY!
************************************************************
*
* File: subsystem1.h
*
* Code generated from model             : 'dab_dc_dc_converter_solver'.
* Subsystem selected for code generation: 'subsystem1'.
*
* Schematic Editor version              : 2023.1 SP1
* C source code generated on            : 24-Feb-2023 @ 12:08:19 PM
*
*/

#include "types.h"

// External input
typedef struct {
    // Generated from the component: Subsystem1.In1
    real_t In1;
    // Generated from the component: Subsystem1.In2
    real_t In2;
} subsystem1_ExtIn;


// External output
typedef struct {
    // Generated from the component: Subsystem1.Out3
    real_t Out3;
    // Generated from the component: Subsystem1.Out4
    real_t Out4;
} subsystem1_ExtOut;

// Sinks
typedef struct {
} subsystem1_ModelSinks;

// States
typedef struct {
    // Generated from the component: Subsystem1.PI
    real_t _subsystem1_pi__integrator_state;
    int_t _subsystem1_pi__av_active;
    real_t _subsystem1_pi__filter_state;
} subsystem1_ModelStates;

// Model data structure
typedef struct {
    subsystem1_ExtIn *p_extIn;
    subsystem1_ExtOut *p_extOut;
    subsystem1_ModelSinks *p_Sinks;
    subsystem1_ModelStates *p_States;
} subsystem1_ModelData;

// External input
extern subsystem1_ExtIn subsystem1_ext_In;

// External output
extern subsystem1_ExtOut subsystem1_ext_Out;

// Sinks
extern subsystem1_ModelSinks subsystem1_m_Sinks;

// States
extern subsystem1_ModelStates subsystem1_m_States;

// Model data structure
extern subsystem1_ModelData subsystem1_m_Data;

// Model entry point functions
extern void subsystem1_init(subsystem1_ModelData *p_m_Data);
extern void subsystem1_step(subsystem1_ModelData *p_m_Data);
