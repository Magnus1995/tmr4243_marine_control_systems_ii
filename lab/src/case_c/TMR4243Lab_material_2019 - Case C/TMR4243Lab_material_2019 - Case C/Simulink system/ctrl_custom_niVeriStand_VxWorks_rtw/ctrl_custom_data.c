#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define ctrl_custom_P                  ctrl_custom_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_custom_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.212
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Mar 25 10:47:06 2019
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_custom.h"
#include "ctrl_custom_private.h"

/* Block parameters (auto storage) */
P_ctrl_custom_T ctrl_custom_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/posXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/posXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/posXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/posXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/posXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/posXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/R2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/R2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/R2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/R2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/R2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/R2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/L2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/L2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/L2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/L2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/L2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/L2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  2.06,                                /* Expression: 2.06
                                        * Referenced by: '<S9>/Gain'
                                        */
  4.689,                               /* Expression: 4.689
                                        * Referenced by: '<S9>/Gain2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.96,                                /* Expression: 1.96
                                        * Referenced by: '<S9>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/control switch'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/control switch'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/control switch'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/control switch'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/control switch'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/control switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/path'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/path'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/path'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/path'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/path'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/path'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/mu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/mu'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/mu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/mu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/mu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/mu'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/U_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/U_ref'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/U_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/U_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/U_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/U_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/rx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/rx'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/rx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/rx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/rx'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/rx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/ry'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/ry'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/ry'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/ry'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/ry'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/ry'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Kp '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Kp '
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Kp '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Kp '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Kp '
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Kp '
                                        */

  /*  Expression: eye(3)
   * Referenced by: '<S1>/Gain'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Kd'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Kd'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Kd'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Kd'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Kd'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Kd'
                                        */

  /*  Expression: eye(3)
   * Referenced by: '<S1>/Gain1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_m'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S7>/Memory1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S1>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S3>/Integrator'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]'
   * Referenced by: '<S3>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S1>/Memory2'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pd'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pd'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pd'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pd'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pd'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pd'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/s_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/s_out'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/s_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/s_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/s_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/s_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/j_control '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/j_control '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/j_control '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/j_control '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/j_control '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/j_control '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S11>/Saturation2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Saturation11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Saturation11'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Saturation1'
                                        */

  /*  Expression: [0.3;0.3]
   * Referenced by: '<Root>/Turn rate1'
   */
  { 0.3, 0.3 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/b_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/b_hat'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/b_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/b_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/b_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/b_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<Root>/Memory1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]'
   * Referenced by: '<Root>/Memory2'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]'
   * Referenced by: '<Root>/Memory3'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S16>/White Noise'
                                        */
  23341.0,                             /* Expression: seed
                                        * Referenced by: '<S16>/White Noise'
                                        */
  1.0,                                 /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * Referenced by: '<S16>/Output'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Noise gain'
                                        */

  /*  Expression: eye(3)
   * Referenced by: '<S3>/L5'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: [1;1;1]
   * Referenced by: '<S3>/L4'
   */
  { 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */

  /*  Expression: [0.6555 0 0; 0 1.33 7.25; 0 0 1.9]
   * Referenced by: '<S3>/D'
   */
  { 0.6555, 0.0, 0.0, 0.0, 1.33, 0.0, 0.0, 7.25, 1.9 },

  /*  Expression: [16.11 0 0; 0 24.11 0.53; 0 0.53 2.76]
   * Referenced by: '<S3>/M'
   */
  { 16.11, 0.0, 0.0, 0.0, 24.11, 0.53, 0.0, 0.53, 2.76 },

  /*  Expression: eye(3)
   * Referenced by: '<S3>/L1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: eye(3)
   * Referenced by: '<S3>/L2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: eye(3)
   * Referenced by: '<S3>/L3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S7>/j_measurement '
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.212
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Mon Mar 25 10:47:05 2019
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_custom_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_ctrl_custom_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
