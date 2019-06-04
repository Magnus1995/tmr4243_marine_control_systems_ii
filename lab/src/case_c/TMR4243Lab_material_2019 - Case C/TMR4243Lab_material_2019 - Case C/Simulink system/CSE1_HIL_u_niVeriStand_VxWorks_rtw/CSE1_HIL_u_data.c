#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define CSE1_HIL_u_P                   CSE1_HIL_u_P DataSection(".NIVS.defaultparams")
#endif

/*
 * CSE1_HIL_u_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CSE1_HIL_u".
 *
 * Model version              : 1.48
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Feb 07 14:39:49 2019
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "CSE1_HIL_u.h"
#include "CSE1_HIL_u_private.h"

/* Block parameters (auto storage) */
P_CSE1_HIL_u_T CSE1_HIL_u_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/psi'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S9>/Velocity'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/r'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/r'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/r'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/r'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/r'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/r'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/v'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/v'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/v'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/v'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/v'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/v'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  0.3875,                              /* Expression: 0.3875
                                        * Referenced by: '<S8>/L_BTX'
                                        */
  0.055,                               /* Expression: 0.055
                                        * Referenced by: '<S8>/L_VSPy'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S8>/Gain'
                                        */
  -0.4575,                             /* Expression: -0.4575;
                                        * Referenced by: '<S8>/L_VSP'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/r_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/r_dot'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/r_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/r_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/r_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/r_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_dot'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/v_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/v_dot'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/v_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/v_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/v_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/v_dot'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/zeroout'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/zeroout'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/zeroout'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/zeroout'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/zeroout'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/zeroout'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/X'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/N'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/N'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/N'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/N'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/N'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi_0'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_0'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_0'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y_0'
                                        */
  1.0                                  /* Expression: btype
                                        * Referenced by: '<S3>/y_0'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : CSE1_HIL_u
 * Model version : 1.48
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Feb 07 14:39:49 2019
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_CSE1_HIL_u_T_sizes[] DataSection(".NIVS.defaultparamsizes") =
{
  { sizeof(P_CSE1_HIL_u_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
