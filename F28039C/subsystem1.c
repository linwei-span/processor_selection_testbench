/*
************************************************************
* NOTE: Automatically generated file. DO NOT MODIFY!
************************************************************
*
* File: subsystem1.c
*
* Code generated from model             : 'dab_dc_dc_converter_solver'.
* Subsystem selected for code generation: 'subsystem1'.
*
* Schematic Editor version              : 2023.1 SP1
* C source code generated on            : 24-Feb-2023 @ 12:08:19 PM
*
*/

#include "subsystem1.h"

//@cmp.def.start
// custom defines
//@cmp.def.end

// Model entry point functions
void subsystem1_step(subsystem1_ModelData *p_m_Data) {
    subsystem1_ExtIn *ext_In = (subsystem1_ExtIn *) p_m_Data->p_extIn;
    subsystem1_ExtOut *ext_Out = (subsystem1_ExtOut *) p_m_Data->p_extOut;
    subsystem1_ModelSinks *m_Sinks = (subsystem1_ModelSinks *) p_m_Data->p_Sinks;
    subsystem1_ModelStates *m_States = (subsystem1_ModelStates *) p_m_Data->p_States;
    //////////////////////////////////////////////////////////////////////////
    // Local variables
    //////////////////////////////////////////////////////////////////////////
    //@cmp.var.start
    real_t _subsystem1_modulation2__out = 180.0;
    real_t _subsystem1_sum__out;
    real_t _subsystem1_pi__out;
    real_t _subsystem1_pi__pi_reg_out_int;
    real_t _subsystem1_gain__out;
    real_t _subsystem1_c_function1__in;
    real_t _subsystem1_c_function1__out;
    real_t _subsystem1_sum2__out;
//@cmp.var.end
    //////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Subsystem1.Sum
    _subsystem1_sum__out = ext_In->In1 - ext_In->In2;
    // Generated from the component: Subsystem1.PI
    _subsystem1_pi__pi_reg_out_int = m_States->_subsystem1_pi__integrator_state + 0.0014193050559820114 * _subsystem1_sum__out;
    if (_subsystem1_pi__pi_reg_out_int < -90.0)
        m_States->_subsystem1_pi__av_active = -1;
    else if (_subsystem1_pi__pi_reg_out_int > 90.0)
        m_States->_subsystem1_pi__av_active = 1;
    else
        m_States->_subsystem1_pi__av_active = 0;
    _subsystem1_pi__out = MIN(MAX(_subsystem1_pi__pi_reg_out_int, -90.0), 90.0);
    // Generated from the component: Subsystem1.Gain
    _subsystem1_gain__out = -1.0 * _subsystem1_pi__out;
    // Generated from the component: Subsystem1.C function1
    _subsystem1_c_function1__in = _subsystem1_gain__out;
    if (_subsystem1_c_function1__in <= 2 && _subsystem1_c_function1__in >= -2) {
        _subsystem1_c_function1__out = 1;
    }
    else {
        _subsystem1_c_function1__out = _subsystem1_c_function1__in;
    }
    // Generated from the component: Subsystem1.Sum2
    _subsystem1_sum2__out = _subsystem1_c_function1__out + _subsystem1_modulation2__out;
///////////////
    // Update sinks
    ///////////////
    ////////////////
    // Update output
    ////////////////
    ext_Out->Out3 = _subsystem1_c_function1__out;
    ext_Out->Out4 = _subsystem1_sum2__out;
    //@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Subsystem1.PI
    if (!m_States->_subsystem1_pi__av_active || ((m_States->_subsystem1_pi__av_active < 0 && _subsystem1_sum__out > 0 ) || (m_States->_subsystem1_pi__av_active > 0 && _subsystem1_sum__out < 0 ))) {
        m_States->_subsystem1_pi__integrator_state += 225.48273896843085 * _subsystem1_sum__out * 1e-05;
    }
    // Generated from the component: Subsystem1.C function1
//@cmp.update.block.end
}

void subsystem1_init(subsystem1_ModelData *p_m_Data) {
    //@cmp.init.block.start
    subsystem1_ModelStates *m_States = (subsystem1_ModelStates *) p_m_Data->p_States;
    m_States->_subsystem1_pi__integrator_state =  0.0;
    m_States->_subsystem1_pi__filter_state =  0.0;
    //@cmp.init.block.end
}
