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
 * Model version              : 1.116
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Mar 05 17:25:43 2019
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
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  1.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/posXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/posXLeft'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/posXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/posXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/posXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/posXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Selector'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Selector'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Selector'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Selector'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Selector'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Selector'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/posXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/posXRight'
                                        */
  4.0,                                 /* Expression: portnum
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
  5.0,                                 /* Expression: portnum
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
  6.0,                                 /* Expression: portnum
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

  /*  Expression: [0 0 0]'
   * Referenced by: '<S6>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  8.0,                                 /* Expression: portnum
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

  /*  Expression: [0 0 0]'
   * Referenced by: '<S6>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  9.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/b_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/b_hat'
                                        */
  10.0,                                /* Expression: portnum
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
  2.06,                                /* Expression: 2.06
                                        * Referenced by: '<S12>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau simple1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau simple1'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau simple1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau simple1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau simple1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau simple1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/sway'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau simple2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau simple2'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau simple2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau simple2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau simple2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau simple2'
                                        */
  1.07535,                             /* Expression: 1.07535
                                        * Referenced by: '<S12>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau simple3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau simple3'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau simple3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau simple3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau simple3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau simple3'
                                        */
  2.06,                                /* Expression: 2.06
                                        * Referenced by: '<S13>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau full1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau full1'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau full1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau full1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau full1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau full1'
                                        */
  4.689,                               /* Expression: 4.689
                                        * Referenced by: '<S13>/Gain2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau full2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau full2'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau full2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau full2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau full2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau full2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.96,                                /* Expression: 1.96
                                        * Referenced by: '<S13>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau full3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau full3'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau full3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau full3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau full3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau full3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau simple'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau simple'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau simple'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau simple'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau simple'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau simple'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau full'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau full'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau full'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau full'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau full'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau full'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_testing'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_testing'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/eta_testing'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_testing'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_testing'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_testing'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  20.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEPSI'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  21.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEX'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  22.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/QTM_SCOPEY'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/selector full'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/selector full'
                                        */
  23.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/selector full'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/selector full'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/selector full'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/selector full'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/selector simple'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/selector simple'
                                        */
  24.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/selector simple'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/selector simple'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/selector simple'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/selector simple'
                                        */

  /*  Expression: [pi/2; 0; 0]
   * Referenced by: '<Root>/Thruster angles'
   */
  { 1.5707963267948966, 0.0, 0.0 },

  /*  Expression: [2*pi/120; 2*pi/120]
   * Referenced by: '<Root>/Turn rate'
   */
  { 0.052359877559829883, 0.052359877559829883 },

  /*  Expression: [2*pi/120; 2*pi/120]
   * Referenced by: '<Root>/Turn rate1'
   */
  { 0.052359877559829883, 0.052359877559829883 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/omega_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S15>/Saturation2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/u_BT'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Saturation11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Saturation11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/u_VSP1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/u_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S18>/White Noise'
                                        */
  23341.0,                             /* Expression: seed
                                        * Referenced by: '<S18>/White Noise'
                                        */
  1.0,                                 /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * Referenced by: '<S18>/Output'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Noise gain'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Noise gain'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Noise gain'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Noise gain'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Noise gain'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Noise gain'
                                        */

  /*  Expression: eye(3)
   * Referenced by: '<S6>/L5'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: [1;1;1]
   * Referenced by: '<S6>/L4'
   */
  { 1.0, 1.0, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Eta_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Eta_bar'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Eta_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Eta_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Eta_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Eta_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Observer gain L1//L2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Observer gain L1//L2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Observer gain L1//L2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Observer gain L1//L2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Observer gain L1//L2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Observer gain L1//L2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Observer gain L3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Observer gain L3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Observer gain L3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Observer gain L3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Observer gain L3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Observer gain L3'
                                        */

  /*  Expression: [0.6555 0 0; 0 1.33 7.25; 0 0 1.9]
   * Referenced by: '<S6>/D'
   */
  { 0.6555, 0.0, 0.0, 0.0, 1.33, 0.0, 0.0, 7.25, 1.9 },

  /*  Expression: [16.11 0 0; 0 24.11 0.53; 0 0.53 2.76]
   * Referenced by: '<S6>/M'
   */
  { 16.11, 0.0, 0.0, 0.0, 24.11, 0.53, 0.0, 0.53, 2.76 },

  /*  Expression: eye(3)
   * Referenced by: '<S6>/L1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: eye(3)
   * Referenced by: '<S6>/L2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: eye(3)
   * Referenced by: '<S6>/L3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/IMU_SCOPEZ'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/IMU_SCOPEZ'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/IMU_SCOPEZ'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/IMU_SCOPEZ'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  1.0                                  /* Expression: btype
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.116
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Mar 05 17:25:43 2019
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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 2, 0 },

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
};

#endif
