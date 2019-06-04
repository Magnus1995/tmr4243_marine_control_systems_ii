/*
 * ctrl_custom.c
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

/* Block signals (auto storage) */
B_ctrl_custom_T ctrl_custom_B;

/* Continuous states */
X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
DW_ctrl_custom_T ctrl_custom_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_custom_T ctrl_custom_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_custom_T ctrl_custom_M_;
RT_MODEL_ctrl_custom_T *const ctrl_custom_M = &ctrl_custom_M_;

/* Forward declaration for local functions */
static real_T ctrl_custom_norm(const real_T x[3]);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_custom_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/Control law' */
static real_T ctrl_custom_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void ctrl_custom_output(void)
{
  ZCEventType zcEvent;
  static const real_T a[9] = { 0.001, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0,
    0.017453292519943295 };

  real_T c_13;
  real_T c_23;
  real_T j_path;
  real_T b_rem;
  real_T j_pos_0;
  real_T Rot_mat[9];
  real_T S_mat[9];
  real_T pd_s[3];
  real_T pd_ss[3];
  real_T z1[3];
  static const real_T b_a[9] = { 16.11, 0.0, 0.0, 0.0, 24.11, 0.53, 0.0, 0.53,
    2.76 };

  real_T f[5];
  static const real_T a_0[15] = { 0.49999999999999989, 0.0, 0.49999999999999989,
    0.0, 0.0, 0.020058276376884107, 0.23062280175254893, -0.020058276376884114,
    0.23062280175254893, 0.53875439649490209, 0.11411877324227657,
    -0.58435728189333025, -0.11411877324227657, -0.58435728189333025,
    1.1687145637866609 };

  static const real_T b[9] = { 2.629, 0.0, 0.0, 0.0, 1.03, 0.0, 0.0, 0.0, 1.03 };

  int32_T p2;
  int32_T p3;
  int32_T itmp;
  real_T rtb_tau_cmd[3];
  real_T rtb_Output;
  real_T rtb_TmpSignalConversionAtSFunct[7];
  real_T rtb_Gain_a[9];
  int32_T i;
  real_T tmp[9];
  real_T tmp_0[9];
  real_T z1_0[3];
  real_T S_mat_0[3];
  real_T S_mat_1[9];
  real_T S_mat_2[3];
  real_T Rot_mat_0[3];
  real_T rtb_Gain_e[9];
  real_T pd_ss_0[3];
  real_T rtb_Gain_e_0[3];
  real_T tmp_1[9];
  boolean_T rtb_Output_0;
  real_T p_1_idx_0;
  real_T p_1_idx_1;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* set solver stop time */
    if (!(ctrl_custom_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTickH0 + 1) *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTick0 + 1) *
        ctrl_custom_M->Timing.stepSize0 + ctrl_custom_M->Timing.clockTickH0 *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_custom_M)) {
    ctrl_custom_M->Timing.t[0] = rtsiGetT(&ctrl_custom_M->solverInfo);
  }

  /* Gain: '<S1>/Gain' */
  for (i = 0; i < 9; i++) {
    rtb_Gain_a[i] = ctrl_custom_P.Gain_Gain_i[i] * ctrl_custom_B.Kp;
  }

  /* End of Gain: '<S1>/Gain' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S7>/Memory1' */
    ctrl_custom_B.Memory1[0] = ctrl_custom_DW.Memory1_PreviousInput[0];
    ctrl_custom_B.Memory1[1] = ctrl_custom_DW.Memory1_PreviousInput[1];
    ctrl_custom_B.Memory1[2] = ctrl_custom_DW.Memory1_PreviousInput[2];

    /* Memory: '<S7>/Memory' */
    ctrl_custom_B.Memory = ctrl_custom_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  SignalConversion: '<S22>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S22>:1' */
  /* '<S22>:1:3' */
  for (i = 0; i < 3; i++) {
    ctrl_custom_B.eta_new[i] = 0.0;
    ctrl_custom_B.eta_new[i] += a[i] * ctrl_custom_B.x_m;
    ctrl_custom_B.eta_new[i] += a[i + 3] * ctrl_custom_B.y_m;
    ctrl_custom_B.eta_new[i] += a[i + 6] * ctrl_custom_B.psi_m;
  }

  if (ctrl_custom_B.eta_new[2] - (ctrl_custom_B.Memory1[2] - 6.2831853071795862 *
       ctrl_custom_B.Memory) < -3.1415926535897931) {
    /* '<S22>:1:5' */
    /* '<S22>:1:6' */
    c_13 = ctrl_custom_B.Memory + 1.0;
  } else if (ctrl_custom_B.eta_new[2] - (ctrl_custom_B.Memory1[2] -
              6.2831853071795862 * ctrl_custom_B.Memory) > 3.1415926535897931) {
    /* '<S22>:1:7' */
    /* '<S22>:1:8' */
    c_13 = ctrl_custom_B.Memory - 1.0;
  } else {
    /* '<S22>:1:10' */
    c_13 = ctrl_custom_B.Memory;
  }

  /* '<S22>:1:13' */
  /* '<S22>:1:15' */
  ctrl_custom_B.eta_new[2] += 6.2831853071795862 * c_13;
  ctrl_custom_B.j_new = c_13;

  /* End of MATLAB Function: '<S7>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S1>/Memory' */
    ctrl_custom_B.Memory_p[0] = ctrl_custom_DW.Memory_PreviousInput_f[0];
    ctrl_custom_B.Memory_p[1] = ctrl_custom_DW.Memory_PreviousInput_f[1];
    ctrl_custom_B.Memory_p[2] = ctrl_custom_DW.Memory_PreviousInput_f[2];

    /* Memory: '<S1>/Memory1' */
    ctrl_custom_B.Memory1_g = ctrl_custom_DW.Memory1_PreviousInput_h;
  }

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* MATLAB Function 'Control law/MATLAB Function': '<S15>:1' */
  if ((ctrl_custom_B.controlswitch != 0.0) && (ctrl_custom_B.Memory1_g == 0.0))
  {
    /* '<S15>:1:3' */
    /* '<S15>:1:4' */
    ctrl_custom_B.eta_0_new[0] = ctrl_custom_B.eta_new[0];
    ctrl_custom_B.eta_0_new[1] = ctrl_custom_B.eta_new[1];
    ctrl_custom_B.eta_0_new[2] = ctrl_custom_B.eta_new[2];

    /* '<S15>:1:5' */
    ctrl_custom_B.s_reset = 1.0;
  } else {
    /* '<S15>:1:7' */
    ctrl_custom_B.s_reset = 0.0;

    /* '<S15>:1:8' */
    ctrl_custom_B.eta_0_new[0] = ctrl_custom_B.Memory_p[0];
    ctrl_custom_B.eta_0_new[1] = ctrl_custom_B.Memory_p[1];
    ctrl_custom_B.eta_0_new[2] = ctrl_custom_B.Memory_p[2];
  }

  /* '<S15>:1:11' */
  ctrl_custom_B.switch_signal_new = ctrl_custom_B.controlswitch;

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Integrator: '<S3>/Integrator' */
  ctrl_custom_B.Integrator[0] = ctrl_custom_X.Integrator_CSTATE[0];

  /* Integrator: '<S3>/Integrator1' */
  ctrl_custom_B.Integrator1[0] = ctrl_custom_X.Integrator1_CSTATE[0];

  /* Integrator: '<S3>/Integrator' */
  ctrl_custom_B.Integrator[1] = ctrl_custom_X.Integrator_CSTATE[1];

  /* Integrator: '<S3>/Integrator1' */
  ctrl_custom_B.Integrator1[1] = ctrl_custom_X.Integrator1_CSTATE[1];

  /* Integrator: '<S3>/Integrator' */
  ctrl_custom_B.Integrator[2] = ctrl_custom_X.Integrator_CSTATE[2];

  /* Integrator: '<S3>/Integrator1' */
  ctrl_custom_B.Integrator1[2] = ctrl_custom_X.Integrator1_CSTATE[2];

  /* MATLAB Function: '<S1>/Damping and coriolis' */
  /* MATLAB Function 'Control law/Damping and coriolis': '<S14>:1' */
  /*  MATRICES */
  /* '<S14>:1:3' */
  /*  x_g  =  0.0460; % Table B.1 */
  /*  Added mass */
  /* '<S14>:1:6' */
  /*  Table B.1 */
  /* '<S14>:1:7' */
  /*  Table B.1 */
  /* '<S14>:1:8' */
  /*  Table B.1 */
  /*  Total mass matrix */
  /*  Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S14>:1:23' */
  /* '<S14>:1:24' */
  /* '<S14>:1:25' */
  /* '<S14>:1:27' */
  /*  Y_r */
  /* '<S14>:1:28' */
  /*  Y_rr */
  /* '<S14>:1:29' */
  /* '<S14>:1:31' */
  /*  Y_rv, Y_vr */
  /* '<S14>:1:33' */
  /*  N_r */
  /* '<S14>:1:34' */
  /*  N_rr */
  /* '<S14>:1:35' */
  /* '<S14>:1:37' */
  /*  N_rv, N_vr */
  /*  Correolis matrix */
  /* '<S14>:1:40' */
  c_13 = -24.11 * ctrl_custom_B.Integrator1[1] - 0.529125 *
    ctrl_custom_B.Integrator1[2];

  /* '<S14>:1:41' */
  c_23 = 16.11 * ctrl_custom_B.Integrator1[0];

  /* Integrator: '<S1>/Integrator1' */
  /* '<S14>:1:42' */
  /*  Assembly of the damping matrix */
  /* '<S14>:1:47' */
  /* '<S14>:1:48' */
  /* '<S14>:1:49' */
  /* '<S14>:1:51' */
  /* '<S14>:1:52' */
  /* '<S14>:1:54' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator1_Reset_ZCE,
                       (ctrl_custom_B.s_reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator1_CSTATE_c = ctrl_custom_P.Integrator1_IC_p;
    }
  }

  ctrl_custom_B.Integrator1_m = ctrl_custom_X.Integrator1_CSTATE_c;

  /* End of Integrator: '<S1>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S1>/Memory3' */
    ctrl_custom_B.Memory3 = ctrl_custom_DW.Memory3_PreviousInput;

    /* Memory: '<S1>/Memory2' */
    ctrl_custom_B.Memory2[0] = ctrl_custom_DW.Memory2_PreviousInput[0];
    ctrl_custom_B.Memory2[1] = ctrl_custom_DW.Memory2_PreviousInput[1];
    ctrl_custom_B.Memory2[2] = ctrl_custom_DW.Memory2_PreviousInput[2];
  }

  /* MATLAB Function: '<S1>/Control law' incorporates:
   *  Gain: '<S1>/Gain1'
   */
  j_path = ctrl_custom_B.Memory3;
  z1[2] = ctrl_custom_B.Memory2[2];

  /* MATLAB Function 'Control law/Control law': '<S13>:1' */
  /* '<S13>:1:149' */
  /* '<S13>:1:50' */
  /* '<S13>:1:46' */
  /*  Path parameters */
  /* path = 'ellipsoidal'; % "linear" or "ellipsoidal" */
  /*  rx  = 1.5;    % Ellipsoidal x-radius */
  /*  ry  = 1;    % Ellipsoidal y-radius */
  /*  Control law parameters */
  /*  mu = 0.01; */
  /*  U_ref = 0.2; */
  /*  Starting position conditions */
  /* '<S13>:1:19' */
  /* '<S13>:1:22' */
  p_1_idx_0 = ctrl_custom_B.eta_0_new[0] + cos(ctrl_custom_B.eta_0_new[2]);
  p_1_idx_1 = ctrl_custom_B.eta_0_new[1] + sin(ctrl_custom_B.eta_0_new[2]);

  /* '<S13>:1:25' */
  /*  Starting point round counter */
  /* '<S13>:1:29' */
  b_rem = ctrl_custom_B.eta_0_new[2] / 6.2831853071795862;
  if (fabs(b_rem - rt_roundd_snf(b_rem)) <= 2.2204460492503131E-16 * fabs(b_rem))
  {
    b_rem = 0.0;
  } else {
    b_rem = (b_rem - floor(b_rem)) * 6.2831853071795862;
  }

  /* '<S13>:1:30' */
  j_pos_0 = (ctrl_custom_B.eta_0_new[2] - b_rem) / 6.2831853071795862;
  if (b_rem >= 3.1415926535897931) {
    /* '<S13>:1:32' */
    /* '<S13>:1:33' */
    j_pos_0++;
  }

  /*  Setting pd_prev within the  */
  if (ctrl_custom_B.s_reset == 1.0) {
    /* '<S13>:1:37' */
    /* '<S13>:1:38' */
    z1[2] = 6.2831853071795862 * j_pos_0;

    /* '<S13>:1:39' */
    j_path = 0.0;
  }

  /*  Rotation and rotation speed matrices */
  /* '<S13>:1:44' */
  Rot_mat[0] = cos(ctrl_custom_B.Integrator[2]);
  Rot_mat[3] = -sin(ctrl_custom_B.Integrator[2]);
  Rot_mat[6] = 0.0;
  Rot_mat[1] = sin(ctrl_custom_B.Integrator[2]);
  Rot_mat[4] = cos(ctrl_custom_B.Integrator[2]);
  Rot_mat[7] = 0.0;

  /* '<S13>:1:48' */
  S_mat[0] = 0.0;
  S_mat[3] = -ctrl_custom_B.Integrator1[2];
  S_mat[6] = 0.0;
  S_mat[1] = ctrl_custom_B.Integrator1[2];
  S_mat[4] = 0.0;
  S_mat[7] = 0.0;
  Rot_mat[2] = 0.0;
  S_mat[2] = 0.0;
  Rot_mat[5] = 0.0;
  S_mat[5] = 0.0;
  Rot_mat[8] = 1.0;
  S_mat[8] = 0.0;

  /*  Path parameterization */
  if (ctrl_custom_B.path == 0.0) {
    /* '<S13>:1:54' */
    /* '<S13>:1:55' */
    ctrl_custom_B.pd[0] = (p_1_idx_0 - ctrl_custom_B.eta_0_new[0]) *
      ctrl_custom_B.Integrator1_m + ctrl_custom_B.eta_0_new[0];
    ctrl_custom_B.pd[1] = (p_1_idx_1 - ctrl_custom_B.eta_0_new[1]) *
      ctrl_custom_B.Integrator1_m + ctrl_custom_B.eta_0_new[1];
    ctrl_custom_B.pd[2] = rt_atan2d_snf(p_1_idx_1 - ctrl_custom_B.eta_0_new[1],
      p_1_idx_0 - ctrl_custom_B.eta_0_new[0]);

    /* '<S13>:1:58' */
    pd_s[0] = p_1_idx_0 - ctrl_custom_B.eta_0_new[0];
    pd_s[1] = p_1_idx_1 - ctrl_custom_B.eta_0_new[1];
    pd_s[2] = 0.0;

    /* '<S13>:1:61' */
    pd_ss[0] = 0.0;
    pd_ss[1] = 0.0;
    pd_ss[2] = 0.0;
  } else if (ctrl_custom_B.path == 1.0) {
    /* '<S13>:1:64' */
    /* '<S13>:1:65' */
    ctrl_custom_B.pd[0] = cos(6.2831853071795862 * ctrl_custom_B.Integrator1_m) *
      ctrl_custom_B.rx + (ctrl_custom_B.eta_0_new[0] - ctrl_custom_B.rx);
    ctrl_custom_B.pd[1] = sin(6.2831853071795862 * ctrl_custom_B.Integrator1_m) *
      ctrl_custom_B.ry + ctrl_custom_B.eta_0_new[1];
    ctrl_custom_B.pd[2] = rt_atan2d_snf(6.2831853071795862 * ctrl_custom_B.ry *
      cos(6.2831853071795862 * ctrl_custom_B.Integrator1_m), -6.2831853071795862
      * ctrl_custom_B.rx * sin(6.2831853071795862 * ctrl_custom_B.Integrator1_m));

    /* '<S13>:1:68' */
    b_rem = sin(6.2831853071795862 * ctrl_custom_B.Integrator1_m);
    p_1_idx_0 = cos(6.2831853071795862 * ctrl_custom_B.Integrator1_m);
    pd_s[0] = -6.2831853071795862 * ctrl_custom_B.rx * sin(6.2831853071795862 *
      ctrl_custom_B.Integrator1_m);
    pd_s[1] = 6.2831853071795862 * ctrl_custom_B.ry * cos(6.2831853071795862 *
      ctrl_custom_B.Integrator1_m);
    pd_s[2] = 6.2831853071795862 * ctrl_custom_B.rx * ctrl_custom_B.ry /
      (ctrl_custom_B.rx * ctrl_custom_B.rx * (b_rem * b_rem) + ctrl_custom_B.ry *
       ctrl_custom_B.ry * (p_1_idx_0 * p_1_idx_0));

    /* '<S13>:1:72' */
    b_rem = sin(6.2831853071795862 * ctrl_custom_B.Integrator1_m);
    p_1_idx_0 = cos(6.2831853071795862 * ctrl_custom_B.Integrator1_m);
    p_1_idx_0 = ctrl_custom_B.ry * ctrl_custom_B.ry * (p_1_idx_0 * p_1_idx_0);
    pd_ss[0] = -39.478417604357432 * ctrl_custom_B.rx * cos(6.2831853071795862 *
      ctrl_custom_B.Integrator1_m);
    pd_ss[1] = -39.478417604357432 * ctrl_custom_B.ry * sin(6.2831853071795862 *
      ctrl_custom_B.Integrator1_m);
    pd_ss[2] = -(78.956835208714864 * ctrl_custom_B.rx * ctrl_custom_B.ry * sin
                 (6.2831853071795862 * ctrl_custom_B.Integrator1_m) * cos
                 (6.2831853071795862 * ctrl_custom_B.Integrator1_m) *
                 (ctrl_custom_B.rx * ctrl_custom_B.rx - ctrl_custom_B.ry *
                  ctrl_custom_B.ry)) / (ctrl_custom_B.rx * ctrl_custom_B.rx *
      (b_rem * b_rem) + p_1_idx_0 * p_1_idx_0);
  } else {
    /* '<S13>:1:77' */
    /* '<S13>:1:78' */
    /* '<S13>:1:79' */
    ctrl_custom_B.pd[0] = 0.0;
    pd_s[0] = 0.0;
    pd_ss[0] = 0.0;
    ctrl_custom_B.pd[1] = 0.0;
    pd_s[1] = 0.0;
    pd_ss[1] = 0.0;
    ctrl_custom_B.pd[2] = 0.0;
    pd_s[2] = 0.0;
    pd_ss[2] = 0.0;
  }

  /*  Calculate path vectors */
  /*  pd      = [ p_x; */
  /*              p_y; */
  /*              atan2(p_y_s, p_x_s)]; */
  /*  pd_s    = [ p_x_s; */
  /*              p_y_s; */
  /*              (p_x_s*p_y_ss - p_y_s*p_x_ss) / (p_x_ss + p_y_ss)]; */
  /*  pd_ss   = [ p_x_ss; */
  /*              p_y_ss; */
  /*              (p_x_s*p_y_sss - p_y_s*p_x_sss) / ((p_x_s)^2 + (p_y_s)^2) ... */
  /*              - 2 * (p_x_s*p_y_ss - p_y_s*p_x_ss) ... */
  /*              * (p_x_s*p_x_ss + p_y_s*p_y_ss) / ((p_x_s)^2 + (p_y_s)^2)^2]; */
  /*  Trajectory round counting */
  /*  Round counter for the trajectory */
  /* '<S13>:1:99' */
  b_rem = ctrl_custom_B.pd[2] - (z1[2] - (j_pos_0 + j_path) * 6.2831853071795862);
  if (b_rem < -3.1415926535897931) {
    /* '<S13>:1:101' */
    /* '<S13>:1:102' */
    j_path++;
  } else {
    if (b_rem > 3.1415926535897931) {
      /* '<S13>:1:103' */
      /* '<S13>:1:104' */
      j_path--;
    }
  }

  /*  Calculate trajectory heading */
  /* '<S13>:1:109' */
  ctrl_custom_B.pd[2] += (j_pos_0 + j_path) * 6.2831853071795862;

  /*  Update laws */
  /* '<S13>:1:113' */
  j_pos_0 = ctrl_custom_B.U_ref / ctrl_custom_norm(pd_s);

  /* '<S13>:1:115' */
  b_rem = ctrl_custom_B.Integrator[0] - ctrl_custom_B.pd[0];
  p_1_idx_0 = ctrl_custom_B.Integrator[1] - ctrl_custom_B.pd[1];
  p_1_idx_1 = ctrl_custom_B.Integrator[2] - ctrl_custom_B.pd[2];
  for (i = 0; i < 3; i++) {
    z1[i] = Rot_mat[3 * i + 2] * p_1_idx_1 + (Rot_mat[3 * i + 1] * p_1_idx_0 +
      Rot_mat[3 * i] * b_rem);
  }

  /* '<S13>:1:116' */
  /* '<S13>:1:117' */
  if (ctrl_custom_B.switch_signal_new != 0.0) {
    /* '<S13>:1:120' */
    /* '<S13>:1:121' */
    b_rem = j_pos_0 - ((-(ctrl_custom_B.Integrator[0] - ctrl_custom_B.pd[0]) *
                        pd_s[0] + -(ctrl_custom_B.Integrator[1] -
      ctrl_custom_B.pd[1]) * pd_s[1]) + -(ctrl_custom_B.Integrator[2] -
      ctrl_custom_B.pd[2]) * pd_s[2]) * ctrl_custom_B.mu / ctrl_custom_norm(pd_s);
  } else {
    /* '<S13>:1:123' */
    b_rem = 0.0;
  }

  /* '<S13>:1:126' */
  p_1_idx_0 = (pd_s[0] * pd_ss[0] + pd_s[1] * pd_ss[1]) * -ctrl_custom_B.U_ref /
    rt_powd_snf(pd_s[0] * pd_s[0] + pd_s[1] * pd_s[1], 1.5);

  /* '<S13>:1:128' */
  p_1_idx_1 = p_1_idx_0 * b_rem;

  /* '<S13>:1:131' */
  /*  Control law */
  /*  Include bias and coriolis matrix? */
  /* '<S13>:1:138' */
  /* '<S13>:1:144' */
  /*  Switch logics */
  if (ctrl_custom_B.switch_signal_new != 0.0) {
    /* MATLAB Function: '<S1>/Damping and coriolis' */
    /* '<S13>:1:148' */
    /* '<S13>:1:149' */
    tmp[0] = (0.6555 - 0.3545 * fabs(ctrl_custom_B.Integrator1[0])) -
      ctrl_custom_B.Integrator1[0] * ctrl_custom_B.Integrator1[0] * -3.787;
    tmp[3] = 0.0;
    tmp[6] = 0.0;
    tmp[1] = 0.0;
    tmp[4] = ((1.33 - -2.776 * fabs(ctrl_custom_B.Integrator1[1])) -
              ctrl_custom_B.Integrator1[1] * ctrl_custom_B.Integrator1[1] *
              -64.91) - -0.805 * fabs(ctrl_custom_B.Integrator1[2]);
    tmp[7] = ((7.25 - -3.45 * fabs(ctrl_custom_B.Integrator1[2])) -
              ctrl_custom_B.Integrator1[2] * ctrl_custom_B.Integrator1[2] * 0.0)
      - -0.845 * fabs(ctrl_custom_B.Integrator1[1]);
    tmp[2] = 0.0;
    tmp[5] = ((-0.0 - -0.2088 * fabs(ctrl_custom_B.Integrator1[1])) -
              ctrl_custom_B.Integrator1[1] * ctrl_custom_B.Integrator1[1] * 0.0)
      - 0.13 * fabs(ctrl_custom_B.Integrator1[2]);
    tmp[8] = ((1.9 - -0.75 * fabs(ctrl_custom_B.Integrator1[2])) -
              ctrl_custom_B.Integrator1[2] * ctrl_custom_B.Integrator1[2] * 0.0)
      - 0.08 * fabs(ctrl_custom_B.Integrator1[1]);
    tmp_0[0] = 0.0;
    tmp_0[3] = 0.0;
    tmp_0[6] = c_13;
    tmp_0[1] = 0.0;
    tmp_0[4] = 0.0;
    tmp_0[7] = c_23;
    tmp_0[2] = -c_13;
    tmp_0[5] = -c_23;
    tmp_0[8] = 0.0;
    for (i = 0; i < 3; i++) {
      z1_0[i] = ((tmp[i + 3] * ctrl_custom_B.Integrator1[1] + tmp[i] *
                  ctrl_custom_B.Integrator1[0]) + tmp[i + 6] *
                 ctrl_custom_B.Integrator1[2]) + -z1[i];
      rtb_tau_cmd[i] = 0.0;
      c_13 = 0.0;
      for (p2 = 0; p2 < 3; p2++) {
        c_13 += S_mat[3 * p2 + i] * z1[p2];
        S_mat_1[i + 3 * p2] = 0.0;
        S_mat_1[i + 3 * p2] += S_mat[i] * Rot_mat[p2];
        S_mat_1[i + 3 * p2] += S_mat[i + 3] * Rot_mat[p2 + 3];
        rtb_tau_cmd[i] += tmp_0[3 * p2 + i] * ctrl_custom_B.Integrator1[p2];
      }

      S_mat_0[i] = c_13 - ctrl_custom_B.Integrator1[i];
      S_mat_2[i] = 0.0;
      Rot_mat_0[i] = 0.0;
      pd_ss_0[i] = pd_ss[i] * j_pos_0 + pd_s[i] * p_1_idx_0;
      rtb_Gain_e_0[i] = 0.0;
      for (p2 = 0; p2 < 3; p2++) {
        rtb_Gain_e[i + 3 * p2] = 0.0;
        rtb_Gain_e[i + 3 * p2] += rtb_Gain_a[i] * Rot_mat[p2];
        rtb_Gain_e[i + 3 * p2] += rtb_Gain_a[i + 3] * Rot_mat[p2 + 3];
        rtb_Gain_e[i + 3 * p2] += rtb_Gain_a[i + 6] * Rot_mat[p2 + 6];
        S_mat_2[i] += S_mat_1[3 * p2 + i] * pd_s[p2];
        Rot_mat_0[i] += Rot_mat[3 * i + p2] * pd_s[p2];
        rtb_Gain_e_0[i] += rtb_Gain_e[3 * p2 + i] * pd_s[p2];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_Gain_e[3 * i] = -rtb_Gain_a[3 * i];
      rtb_Gain_e[1 + 3 * i] = -rtb_Gain_a[3 * i + 1];
      rtb_Gain_e[2 + 3 * i] = -rtb_Gain_a[3 * i + 2];
      pd_ss[i] = ((((rtb_Gain_a[i + 3] * S_mat_0[1] + rtb_Gain_a[i] * S_mat_0[0])
                    + rtb_Gain_a[i + 6] * S_mat_0[2]) - S_mat_2[i] * j_pos_0) +
                  Rot_mat_0[i] * p_1_idx_1) + (rtb_Gain_e_0[i] + (Rot_mat[3 * i
        + 2] * pd_ss_0[2] + (Rot_mat[3 * i + 1] * pd_ss_0[1] + Rot_mat[3 * i] *
        pd_ss_0[0]))) * b_rem;
    }

    for (i = 0; i < 3; i++) {
      S_mat_0[i] = ctrl_custom_B.Integrator1[i] - (((rtb_Gain_e[i + 3] * z1[1] +
        rtb_Gain_e[i] * z1[0]) + rtb_Gain_e[i + 6] * z1[2]) + pd_s[i] * j_pos_0);
      S_mat_2[i] = ((b_a[i + 3] * pd_ss[1] + b_a[i] * pd_ss[0]) + b_a[i + 6] *
                    pd_ss[2]) + (z1_0[i] + rtb_tau_cmd[i]);
    }

    for (i = 0; i < 3; i++) {
      rtb_tau_cmd[i] = S_mat_2[i] - (ctrl_custom_P.Gain1_Gain_f[i + 6] *
        ctrl_custom_B.Kd * S_mat_0[2] + (ctrl_custom_P.Gain1_Gain_f[i + 3] *
        ctrl_custom_B.Kd * S_mat_0[1] + ctrl_custom_P.Gain1_Gain_f[i] *
        ctrl_custom_B.Kd * S_mat_0[0]));
    }
  } else {
    /* '<S13>:1:151' */
    rtb_tau_cmd[0] = 0.0;
    rtb_tau_cmd[1] = 0.0;
    rtb_tau_cmd[2] = 0.0;
  }

  /*  Assign variables for memory blocks */
  /* '<S13>:1:156' */
  /* '<S13>:1:157' */
  ctrl_custom_B.s_dot = b_rem;
  ctrl_custom_B.j_path_curr = j_path;
  ctrl_custom_B.pd_curr[0] = ctrl_custom_B.pd[0];
  ctrl_custom_B.pd_curr[1] = ctrl_custom_B.pd[1];
  ctrl_custom_B.pd_curr[2] = ctrl_custom_B.pd[2];

  /* End of MATLAB Function: '<S1>/Control law' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain2'
   *  Sum: '<Root>/Sum'
   */
  ctrl_custom_B.Sum1[0] = ctrl_custom_P.Gain_Gain * ctrl_custom_B.posYLeft +
    rtb_tau_cmd[0];
  ctrl_custom_B.Sum1[1] = ctrl_custom_P.Gain2_Gain * ctrl_custom_B.posXRight +
    rtb_tau_cmd[1];
  ctrl_custom_B.Sum1[2] = (ctrl_custom_P.Gain_Gain_a * ctrl_custom_B.R2 -
    ctrl_custom_P.Gain1_Gain * ctrl_custom_B.L2) * ctrl_custom_P.Gain1_Gain_h +
    rtb_tau_cmd[2];

  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'Rectangular coordinate thrust allocation/MATLAB Function': '<S21>:1' */
  /* '<S21>:1:21' */
  /*  */
  /* Initialize extended thrust allocation matrix */
  /* Extended force vector */
  /* '<S21>:1:21' */
  for (i = 0; i < 5; i++) {
    f[i] = a_0[i + 10] * ctrl_custom_B.Sum1[2] + (a_0[i + 5] *
      ctrl_custom_B.Sum1[1] + a_0[i] * ctrl_custom_B.Sum1[0]);
  }

  /*  */
  /* Calculate angles and control input */
  /* '<S21>:1:25' */
  /* '<S21>:1:26' */
  /* '<S21>:1:28' */
  /* '<S21>:1:34' */
  /* '<S21>:1:35' */
  /* '<S21>:1:36' */
  /* '<S21>:1:38' */
  /* '<S21>:1:40' */
  ctrl_custom_B.u_ext[0] = sqrt(f[0] * f[0] + f[1] * f[1]) * 0.970873786407767;
  ctrl_custom_B.u_ext[1] = sqrt(f[2] * f[2] + f[3] * f[3]) * 0.970873786407767;
  ctrl_custom_B.u_ext[2] = f[4] / 2.629;
  ctrl_custom_B.u_ext[3] = rt_atan2d_snf(f[1], f[0]);
  ctrl_custom_B.u_ext[4] = rt_atan2d_snf(f[3], f[2]);

  /* End of MATLAB Function: '<S6>/MATLAB Function' */

  /* Saturate: '<S11>/Saturation2' */
  if (ctrl_custom_B.u_ext[2] > ctrl_custom_P.Saturation2_UpperSat) {
    ctrl_custom_B.Saturation2 = ctrl_custom_P.Saturation2_UpperSat;
  } else if (ctrl_custom_B.u_ext[2] < ctrl_custom_P.Saturation2_LowerSat) {
    ctrl_custom_B.Saturation2 = ctrl_custom_P.Saturation2_LowerSat;
  } else {
    ctrl_custom_B.Saturation2 = ctrl_custom_B.u_ext[2];
  }

  /* End of Saturate: '<S11>/Saturation2' */

  /* Saturate: '<S11>/Saturation11' */
  if (ctrl_custom_B.u_ext[0] > ctrl_custom_P.Saturation11_UpperSat) {
    ctrl_custom_B.Saturation11 = ctrl_custom_P.Saturation11_UpperSat;
  } else if (ctrl_custom_B.u_ext[0] < ctrl_custom_P.Saturation11_LowerSat) {
    ctrl_custom_B.Saturation11 = ctrl_custom_P.Saturation11_LowerSat;
  } else {
    ctrl_custom_B.Saturation11 = ctrl_custom_B.u_ext[0];
  }

  /* End of Saturate: '<S11>/Saturation11' */

  /* Saturate: '<S11>/Saturation1' */
  if (ctrl_custom_B.u_ext[1] > ctrl_custom_P.Saturation1_UpperSat) {
    ctrl_custom_B.Saturation1 = ctrl_custom_P.Saturation1_UpperSat;
  } else if (ctrl_custom_B.u_ext[1] < ctrl_custom_P.Saturation1_LowerSat) {
    ctrl_custom_B.Saturation1 = ctrl_custom_P.Saturation1_LowerSat;
  } else {
    ctrl_custom_B.Saturation1 = ctrl_custom_B.u_ext[1];
  }

  /* End of Saturate: '<S11>/Saturation1' */

  /* SignalConversion: '<S23>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<Root>/Turn rate1'
   *  MATLAB Function: '<S12>/u_to_tau_mapping'
   */
  rtb_TmpSignalConversionAtSFunct[0] = ctrl_custom_B.Saturation2;
  rtb_TmpSignalConversionAtSFunct[1] = ctrl_custom_B.Saturation11;
  rtb_TmpSignalConversionAtSFunct[2] = ctrl_custom_B.Saturation1;
  rtb_TmpSignalConversionAtSFunct[3] = ctrl_custom_B.u_ext[3];
  rtb_TmpSignalConversionAtSFunct[5] = ctrl_custom_P.Turnrate1_Value[0];
  rtb_TmpSignalConversionAtSFunct[4] = ctrl_custom_B.u_ext[4];
  rtb_TmpSignalConversionAtSFunct[6] = ctrl_custom_P.Turnrate1_Value[1];

  /* MATLAB Function: '<S12>/u_to_tau_mapping' incorporates:
   *  SignalConversion: '<S23>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'u_to_tau_mapping/u_to_tau_mapping': '<S23>:1' */
  /* '<S23>:1:29' */
  /*  Thruster configuration */
  /* '<S23>:1:5' */
  /* '<S23>:1:8' */
  /* '<S23>:1:9' */
  /* '<S23>:1:10' */
  /* '<S23>:1:19' */
  /*  Mapping */
  /* '<S23>:1:22' */
  /* '<S23>:1:23' */
  /* '<S23>:1:25' */
  /* '<S23>:1:29' */
  tmp_1[0] = 0.0;
  tmp_1[3] = cos(ctrl_custom_B.u_ext[3]);
  tmp_1[6] = cos(ctrl_custom_B.u_ext[4]);
  tmp_1[1] = 1.0;
  tmp_1[4] = sin(ctrl_custom_B.u_ext[3]);
  tmp_1[7] = sin(ctrl_custom_B.u_ext[4]);
  tmp_1[2] = 0.3875;
  tmp_1[5] = -0.4574 * sin(ctrl_custom_B.u_ext[3]) - -0.055 * cos
    (ctrl_custom_B.u_ext[3]);
  tmp_1[8] = -0.4574 * sin(ctrl_custom_B.u_ext[4]) - 0.055 * cos
    (ctrl_custom_B.u_ext[4]);
  for (i = 0; i < 3; i++) {
    ctrl_custom_B.tau[i] = 0.0;
    for (p2 = 0; p2 < 3; p2++) {
      tmp[i + 3 * p2] = 0.0;
      tmp[i + 3 * p2] += b[3 * p2] * tmp_1[i];
      tmp[i + 3 * p2] += b[3 * p2 + 1] * tmp_1[i + 3];
      tmp[i + 3 * p2] += b[3 * p2 + 2] * tmp_1[i + 6];
      ctrl_custom_B.tau[i] += tmp[3 * p2 + i] *
        rtb_TmpSignalConversionAtSFunct[p2];
    }
  }

  /* Integrator: '<S3>/Integrator2' */
  ctrl_custom_B.Integrator2[0] = ctrl_custom_X.Integrator2_CSTATE[0];
  ctrl_custom_B.Integrator2[1] = ctrl_custom_X.Integrator2_CSTATE[1];
  ctrl_custom_B.Integrator2[2] = ctrl_custom_X.Integrator2_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<Root>/Memory1' */
    ctrl_custom_B.Memory1_p[0] = ctrl_custom_DW.Memory1_PreviousInput_e[0];

    /* Memory: '<Root>/Memory2' */
    ctrl_custom_B.Memory2_b[0] = ctrl_custom_DW.Memory2_PreviousInput_i[0];

    /* Memory: '<Root>/Memory3' */
    ctrl_custom_B.Memory3_k[0] = ctrl_custom_DW.Memory3_PreviousInput_b[0];

    /* Memory: '<Root>/Memory1' */
    ctrl_custom_B.Memory1_p[1] = ctrl_custom_DW.Memory1_PreviousInput_e[1];

    /* Memory: '<Root>/Memory2' */
    ctrl_custom_B.Memory2_b[1] = ctrl_custom_DW.Memory2_PreviousInput_i[1];

    /* Memory: '<Root>/Memory3' */
    ctrl_custom_B.Memory3_k[1] = ctrl_custom_DW.Memory3_PreviousInput_b[1];

    /* Memory: '<Root>/Memory1' */
    ctrl_custom_B.Memory1_p[2] = ctrl_custom_DW.Memory1_PreviousInput_e[2];

    /* Memory: '<Root>/Memory2' */
    ctrl_custom_B.Memory2_b[2] = ctrl_custom_DW.Memory2_PreviousInput_i[2];

    /* Memory: '<Root>/Memory3' */
    ctrl_custom_B.Memory3_k[2] = ctrl_custom_DW.Memory3_PreviousInput_b[2];

    /* Gain: '<S16>/Output' incorporates:
     *  RandomNumber: '<S16>/White Noise'
     */
    rtb_Output = ctrl_custom_P.Output_Gain * ctrl_custom_DW.NextOutput;
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Gain: '<S3>/L4' */
    ctrl_custom_B.L4[0] = ctrl_custom_P.L4_Gain[0] * rtb_Output;
    ctrl_custom_B.L4[1] = ctrl_custom_P.L4_Gain[1] * rtb_Output;
    ctrl_custom_B.L4[2] = ctrl_custom_P.L4_Gain[2] * rtb_Output;
  }

  /* MATLAB Function: '<Root>/dead_reckoning' */
  ctrl_custom_B.last[0] = ctrl_custom_B.Memory3_k[0];
  ctrl_custom_B.last2[0] = ctrl_custom_B.Memory2_b[0];
  ctrl_custom_B.last3[0] = ctrl_custom_B.Memory1_p[0];
  ctrl_custom_B.last2[0] = ctrl_custom_B.last[0];
  ctrl_custom_B.last[0] = ctrl_custom_B.eta_new[0];
  ctrl_custom_B.last[1] = ctrl_custom_B.Memory3_k[1];
  ctrl_custom_B.last2[1] = ctrl_custom_B.Memory2_b[1];
  ctrl_custom_B.last3[1] = ctrl_custom_B.Memory1_p[1];
  ctrl_custom_B.last2[1] = ctrl_custom_B.last[1];
  ctrl_custom_B.last[1] = ctrl_custom_B.eta_new[1];
  ctrl_custom_B.last[2] = ctrl_custom_B.Memory3_k[2];
  ctrl_custom_B.last2[2] = ctrl_custom_B.Memory2_b[2];
  ctrl_custom_B.last3[2] = ctrl_custom_B.Memory1_p[2];
  ctrl_custom_B.last2[2] = ctrl_custom_B.last[2];
  ctrl_custom_B.last[2] = ctrl_custom_B.eta_new[2];

  /* MATLAB Function 'dead_reckoning': '<S8>:1' */
  /* '<S8>:1:1' */
  if ((ctrl_custom_B.last[0] == ctrl_custom_B.last2[0]) && (ctrl_custom_B.last[1]
       == ctrl_custom_B.last2[1]) && (ctrl_custom_B.last[2] ==
       ctrl_custom_B.last2[2]) && (ctrl_custom_B.last[0] == ctrl_custom_B.last2
       [0]) && (ctrl_custom_B.last[1] == ctrl_custom_B.last2[1]) &&
      (ctrl_custom_B.last[2] == ctrl_custom_B.last2[2]) && (ctrl_custom_B.last[0]
       == ctrl_custom_B.last3[0]) && (ctrl_custom_B.last[1] ==
       ctrl_custom_B.last3[1]) && (ctrl_custom_B.last[2] == ctrl_custom_B.last3
       [2])) {
    /* '<S8>:1:3' */
    /* '<S8>:1:4' */
    /* '<S8>:1:5' */
    /* '<S8>:1:6' */
    rtb_Output = 0.0;
  } else {
    /* '<S8>:1:8' */
    rtb_Output = 1.0;
  }

  if (ctrl_custom_B.NIVeriStandIn2 == 1.0) {
    /* '<S8>:1:11' */
    /* '<S8>:1:12' */
    rtb_Output = 0.0;
  }

  /* Switch: '<Root>/Switch1' */
  /* '<S8>:1:15' */
  /* '<S8>:1:16' */
  /* '<S8>:1:17' */
  rtb_Output_0 = (rtb_Output > ctrl_custom_P.Switch1_Threshold);
  for (i = 0; i < 3; i++) {
    /* MATLAB Function: '<Root>/dead_reckoning' */
    ctrl_custom_B.last3[i] = ctrl_custom_B.last2[i];

    /* Sum: '<S3>/Sum3' incorporates:
     *  Gain: '<S3>/L5'
     *  Product: '<S3>/Product8'
     *  Switch: '<Root>/Switch1'
     */
    if (rtb_Output_0) {
      rtb_Output = ctrl_custom_B.eta_new[i];
    } else {
      rtb_Output = ctrl_custom_B.Integrator[i];
    }

    j_path = ((ctrl_custom_P.L5_Gain[i + 3] * ctrl_custom_B.Noisegain *
               ctrl_custom_B.L4[1] + ctrl_custom_P.L5_Gain[i] *
               ctrl_custom_B.Noisegain * ctrl_custom_B.L4[0]) +
              ctrl_custom_P.L5_Gain[i + 6] * ctrl_custom_B.Noisegain *
              ctrl_custom_B.L4[2]) + rtb_Output;

    /* Sum: '<S3>/Sum' */
    ctrl_custom_B.Sum[i] = j_path - ctrl_custom_B.Integrator[i];

    /* Sum: '<S3>/Sum3' incorporates:
     *  Gain: '<S3>/L5'
     */
    z1[i] = j_path;
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* MATLAB Function: '<S3>/Inverse' incorporates:
     *  Constant: '<S3>/M'
     */
    /* MATLAB Function 'Observer/Inverse': '<S17>:1' */
    /* '<S17>:1:4' */
    memcpy(&Rot_mat[0], &ctrl_custom_P.M_Value[0], 9U * sizeof(real_T));
    i = 0;
    p2 = 3;
    p3 = 6;
    rtb_Output = fabs(ctrl_custom_P.M_Value[0]);
    c_13 = fabs(ctrl_custom_P.M_Value[1]);
    c_23 = fabs(ctrl_custom_P.M_Value[2]);
    if ((c_13 > rtb_Output) && (c_13 > c_23)) {
      i = 3;
      p2 = 0;
      Rot_mat[0] = ctrl_custom_P.M_Value[1];
      Rot_mat[1] = ctrl_custom_P.M_Value[0];
      Rot_mat[3] = ctrl_custom_P.M_Value[4];
      Rot_mat[4] = ctrl_custom_P.M_Value[3];
      Rot_mat[6] = ctrl_custom_P.M_Value[7];
      Rot_mat[7] = ctrl_custom_P.M_Value[6];
    } else {
      if (c_23 > rtb_Output) {
        i = 6;
        p3 = 0;
        Rot_mat[0] = ctrl_custom_P.M_Value[2];
        Rot_mat[2] = ctrl_custom_P.M_Value[0];
        Rot_mat[3] = ctrl_custom_P.M_Value[5];
        Rot_mat[5] = ctrl_custom_P.M_Value[3];
        Rot_mat[6] = ctrl_custom_P.M_Value[8];
        Rot_mat[8] = ctrl_custom_P.M_Value[6];
      }
    }

    rtb_Output = Rot_mat[1] / Rot_mat[0];
    Rot_mat[1] /= Rot_mat[0];
    c_13 = Rot_mat[2] / Rot_mat[0];
    Rot_mat[2] /= Rot_mat[0];
    Rot_mat[4] -= rtb_Output * Rot_mat[3];
    Rot_mat[5] -= c_13 * Rot_mat[3];
    Rot_mat[7] -= rtb_Output * Rot_mat[6];
    Rot_mat[8] -= c_13 * Rot_mat[6];
    if (fabs(Rot_mat[5]) > fabs(Rot_mat[4])) {
      itmp = p2;
      p2 = p3;
      p3 = itmp;
      Rot_mat[1] = c_13;
      Rot_mat[2] = rtb_Output;
      rtb_Output = Rot_mat[4];
      Rot_mat[4] = Rot_mat[5];
      Rot_mat[5] = rtb_Output;
      rtb_Output = Rot_mat[7];
      Rot_mat[7] = Rot_mat[8];
      Rot_mat[8] = rtb_Output;
    }

    rtb_Output = Rot_mat[5] / Rot_mat[4];
    Rot_mat[5] /= Rot_mat[4];
    Rot_mat[8] -= rtb_Output * Rot_mat[7];
    rtb_Output = (Rot_mat[5] * Rot_mat[1] - Rot_mat[2]) / Rot_mat[8];
    c_13 = -(Rot_mat[7] * rtb_Output + Rot_mat[1]) / Rot_mat[4];
    ctrl_custom_B.y[i] = ((1.0 - Rot_mat[3] * c_13) - Rot_mat[6] * rtb_Output) /
      Rot_mat[0];
    ctrl_custom_B.y[i + 1] = c_13;
    ctrl_custom_B.y[i + 2] = rtb_Output;
    rtb_Output = -Rot_mat[5] / Rot_mat[8];
    c_13 = (1.0 - Rot_mat[7] * rtb_Output) / Rot_mat[4];
    ctrl_custom_B.y[p2] = -(Rot_mat[3] * c_13 + Rot_mat[6] * rtb_Output) /
      Rot_mat[0];
    ctrl_custom_B.y[p2 + 1] = c_13;
    ctrl_custom_B.y[p2 + 2] = rtb_Output;
    rtb_Output = 1.0 / Rot_mat[8];
    c_13 = -Rot_mat[7] * rtb_Output / Rot_mat[4];
    ctrl_custom_B.y[p3] = -(Rot_mat[3] * c_13 + Rot_mat[6] * rtb_Output) /
      Rot_mat[0];
    ctrl_custom_B.y[p3 + 1] = c_13;
    ctrl_custom_B.y[p3 + 2] = rtb_Output;

    /* End of MATLAB Function: '<S3>/Inverse' */
  }

  /* MATLAB Function: '<S3>/rotation matrix' */
  /* MATLAB Function 'Observer/rotation matrix': '<S20>:1' */
  /* '<S20>:1:3' */
  rtb_Gain_a[0] = cos(z1[2]);
  rtb_Gain_a[3] = -sin(z1[2]);
  rtb_Gain_a[6] = 0.0;
  rtb_Gain_a[1] = sin(z1[2]);
  rtb_Gain_a[4] = cos(z1[2]);
  rtb_Gain_a[7] = 0.0;
  rtb_Gain_a[2] = 0.0;
  rtb_Gain_a[5] = 0.0;
  rtb_Gain_a[8] = 1.0;

  /* MATLAB Function 'Observer/Transpose': '<S19>:1' */
  /* '<S19>:1:4' */
  for (i = 0; i < 3; i++) {
    /* MATLAB Function: '<S3>/Transpose' */
    Rot_mat[3 * i] = rtb_Gain_a[i];
    Rot_mat[1 + 3 * i] = rtb_Gain_a[i + 3];
    Rot_mat[2 + 3 * i] = rtb_Gain_a[i + 6];

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<S3>/D'
     *  Product: '<S3>/Product1'
     */
    S_mat_0[i] = ctrl_custom_B.tau[i] - ((ctrl_custom_P.D_Value[i + 3] *
      ctrl_custom_B.Integrator1[1] + ctrl_custom_P.D_Value[i] *
      ctrl_custom_B.Integrator1[0]) + ctrl_custom_P.D_Value[i + 6] *
      ctrl_custom_B.Integrator1[2]);

    /* Product: '<S3>/Product6' incorporates:
     *  Gain: '<S3>/L2'
     *  Product: '<S3>/Product3'
     */
    rtb_tau_cmd[i] = ctrl_custom_P.L2_Gain[i + 6] * ctrl_custom_B.ObservergainL2
      * ctrl_custom_B.Sum[2] + (ctrl_custom_P.L2_Gain[i + 3] *
      ctrl_custom_B.ObservergainL2 * ctrl_custom_B.Sum[1] +
      ctrl_custom_P.L2_Gain[i] * ctrl_custom_B.ObservergainL2 *
      ctrl_custom_B.Sum[0]);
  }

  for (i = 0; i < 3; i++) {
    /* Sum: '<S3>/Sum1' incorporates:
     *  Product: '<S3>/Product'
     *  Product: '<S3>/Product2'
     *  Product: '<S3>/Product3'
     */
    z1[i] = ((Rot_mat[i + 3] * ctrl_custom_B.Integrator2[1] + Rot_mat[i] *
              ctrl_custom_B.Integrator2[0]) + Rot_mat[i + 6] *
             ctrl_custom_B.Integrator2[2]) + (S_mat_0[i] + (Rot_mat[i + 6] *
      rtb_tau_cmd[2] + (Rot_mat[i + 3] * rtb_tau_cmd[1] + Rot_mat[i] *
                        rtb_tau_cmd[0])));
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S3>/Product' */
    ctrl_custom_B.Product[i] = 0.0;

    /* Product: '<S3>/Product7' incorporates:
     *  Gain: '<S3>/L3'
     */
    ctrl_custom_B.Product7[i] = 0.0;

    /* Product: '<S3>/Product' */
    ctrl_custom_B.Product[i] += ctrl_custom_B.y[i] * z1[0];

    /* Product: '<S3>/Product7' incorporates:
     *  Gain: '<S3>/L3'
     */
    ctrl_custom_B.Product7[i] += ctrl_custom_P.L3_Gain[i] *
      ctrl_custom_B.ObservergainL3 * ctrl_custom_B.Sum[0];

    /* Product: '<S3>/Product' */
    ctrl_custom_B.Product[i] += ctrl_custom_B.y[i + 3] * z1[1];

    /* Product: '<S3>/Product7' incorporates:
     *  Gain: '<S3>/L3'
     */
    ctrl_custom_B.Product7[i] += ctrl_custom_P.L3_Gain[i + 3] *
      ctrl_custom_B.ObservergainL3 * ctrl_custom_B.Sum[1];

    /* Product: '<S3>/Product' */
    ctrl_custom_B.Product[i] += ctrl_custom_B.y[i + 6] * z1[2];

    /* Product: '<S3>/Product7' incorporates:
     *  Gain: '<S3>/L3'
     */
    ctrl_custom_B.Product7[i] += ctrl_custom_P.L3_Gain[i + 6] *
      ctrl_custom_B.ObservergainL3 * ctrl_custom_B.Sum[2];

    /* Sum: '<S3>/Sum2' incorporates:
     *  Gain: '<S3>/L1'
     *  Product: '<S3>/Product4'
     *  Product: '<S3>/Product5'
     */
    ctrl_custom_B.Sum2[i] = (ctrl_custom_P.L1_Gain[i + 6] *
      ctrl_custom_B.ObservergainL1 * ctrl_custom_B.Sum[2] +
      (ctrl_custom_P.L1_Gain[i + 3] * ctrl_custom_B.ObservergainL1 *
       ctrl_custom_B.Sum[1] + ctrl_custom_P.L1_Gain[i] *
       ctrl_custom_B.ObservergainL1 * ctrl_custom_B.Sum[0])) + (rtb_Gain_a[i + 6]
      * ctrl_custom_B.Integrator1[2] + (rtb_Gain_a[i + 3] *
      ctrl_custom_B.Integrator1[1] + rtb_Gain_a[i] * ctrl_custom_B.Integrator1[0]));
  }
}

/* Model update function */
void ctrl_custom_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Update for Memory: '<S7>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput = ctrl_custom_B.j_new;

    /* Update for Memory: '<S1>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_h = ctrl_custom_B.switch_signal_new;

    /* Update for Memory: '<S1>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput = ctrl_custom_B.j_path_curr;

    /* Update for Memory: '<S7>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[0] = ctrl_custom_B.eta_new[0];

    /* Update for Memory: '<S1>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput_f[0] = ctrl_custom_B.eta_0_new[0];

    /* Update for Memory: '<S1>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[0] = ctrl_custom_B.pd_curr[0];

    /* Update for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_e[0] = ctrl_custom_B.last3[0];

    /* Update for Memory: '<Root>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_i[0] = ctrl_custom_B.last2[0];

    /* Update for Memory: '<Root>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput_b[0] = ctrl_custom_B.last[0];

    /* Update for Memory: '<S7>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[1] = ctrl_custom_B.eta_new[1];

    /* Update for Memory: '<S1>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput_f[1] = ctrl_custom_B.eta_0_new[1];

    /* Update for Memory: '<S1>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[1] = ctrl_custom_B.pd_curr[1];

    /* Update for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_e[1] = ctrl_custom_B.last3[1];

    /* Update for Memory: '<Root>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_i[1] = ctrl_custom_B.last2[1];

    /* Update for Memory: '<Root>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput_b[1] = ctrl_custom_B.last[1];

    /* Update for Memory: '<S7>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[2] = ctrl_custom_B.eta_new[2];

    /* Update for Memory: '<S1>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput_f[2] = ctrl_custom_B.eta_0_new[2];

    /* Update for Memory: '<S1>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[2] = ctrl_custom_B.pd_curr[2];

    /* Update for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_e[2] = ctrl_custom_B.last3[2];

    /* Update for Memory: '<Root>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_i[2] = ctrl_custom_B.last2[2];

    /* Update for Memory: '<Root>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput_b[2] = ctrl_custom_B.last[2];

    /* Update for RandomNumber: '<S16>/White Noise' */
    ctrl_custom_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_custom_DW.RandSeed) * ctrl_custom_P.WhiteNoise_StdDev +
      ctrl_custom_P.WhiteNoise_Mean;
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_custom_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_custom_M->Timing.clockTick0)) {
    ++ctrl_custom_M->Timing.clockTickH0;
  }

  ctrl_custom_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_custom_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_custom_M->Timing.clockTick1)) {
      ++ctrl_custom_M->Timing.clockTickH1;
    }

    ctrl_custom_M->Timing.t[1] = ctrl_custom_M->Timing.clockTick1 *
      ctrl_custom_M->Timing.stepSize1 + ctrl_custom_M->Timing.clockTickH1 *
      ctrl_custom_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_custom_derivatives(void)
{
  XDot_ctrl_custom_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_custom_T *) ctrl_custom_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_c = ctrl_custom_B.s_dot;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_custom_B.Sum2[0];

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_custom_B.Product[0];

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_custom_B.Product7[0];

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = ctrl_custom_B.Sum2[1];

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_custom_B.Product[1];

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_custom_B.Product7[1];

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = ctrl_custom_B.Sum2[2];

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_custom_B.Product[2];

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_custom_B.Product7[2];
}

/* Model initialize function */
void ctrl_custom_initialize(void)
{
  ctrl_custom_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Memory: '<S7>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput = ctrl_custom_P.Memory_X0;

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_h = ctrl_custom_P.Memory1_X0_p;

    /* InitializeConditions for Integrator: '<S1>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE_c = ctrl_custom_P.Integrator1_IC_p;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput = ctrl_custom_P.Memory3_X0;

    /* InitializeConditions for Memory: '<S7>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[0] = ctrl_custom_P.Memory1_X0[0];

    /* InitializeConditions for Memory: '<S1>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput_f[0] = ctrl_custom_P.Memory_X0_n[0];

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE[0] = ctrl_custom_P.Integrator_IC[0];

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE[0] = ctrl_custom_P.Integrator1_IC[0];

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[0] = ctrl_custom_P.Memory2_X0[0];

    /* InitializeConditions for Integrator: '<S3>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[0] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_e[0] = ctrl_custom_P.Memory1_X0_ps[0];

    /* InitializeConditions for Memory: '<Root>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_i[0] = ctrl_custom_P.Memory2_X0_d[0];

    /* InitializeConditions for Memory: '<Root>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput_b[0] = ctrl_custom_P.Memory3_X0_f[0];

    /* InitializeConditions for Memory: '<S7>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[1] = ctrl_custom_P.Memory1_X0[1];

    /* InitializeConditions for Memory: '<S1>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput_f[1] = ctrl_custom_P.Memory_X0_n[1];

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE[1] = ctrl_custom_P.Integrator_IC[1];

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE[1] = ctrl_custom_P.Integrator1_IC[1];

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[1] = ctrl_custom_P.Memory2_X0[1];

    /* InitializeConditions for Integrator: '<S3>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[1] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_e[1] = ctrl_custom_P.Memory1_X0_ps[1];

    /* InitializeConditions for Memory: '<Root>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_i[1] = ctrl_custom_P.Memory2_X0_d[1];

    /* InitializeConditions for Memory: '<Root>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput_b[1] = ctrl_custom_P.Memory3_X0_f[1];

    /* InitializeConditions for Memory: '<S7>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput[2] = ctrl_custom_P.Memory1_X0[2];

    /* InitializeConditions for Memory: '<S1>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput_f[2] = ctrl_custom_P.Memory_X0_n[2];

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE[2] = ctrl_custom_P.Integrator_IC[2];

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE[2] = ctrl_custom_P.Integrator1_IC[2];

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput[2] = ctrl_custom_P.Memory2_X0[2];

    /* InitializeConditions for Integrator: '<S3>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[2] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput_e[2] = ctrl_custom_P.Memory1_X0_ps[2];

    /* InitializeConditions for Memory: '<Root>/Memory2' */
    ctrl_custom_DW.Memory2_PreviousInput_i[2] = ctrl_custom_P.Memory2_X0_d[2];

    /* InitializeConditions for Memory: '<Root>/Memory3' */
    ctrl_custom_DW.Memory3_PreviousInput_b[2] = ctrl_custom_P.Memory3_X0_f[2];

    /* InitializeConditions for RandomNumber: '<S16>/White Noise' */
    tmp = floor(ctrl_custom_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_custom_DW.RandSeed = tseed;
    ctrl_custom_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_custom_DW.RandSeed) * ctrl_custom_P.WhiteNoise_StdDev +
      ctrl_custom_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S16>/White Noise' */
  }
}

/* Model terminate function */
void ctrl_custom_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_custom_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_custom_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_custom_initialize();
}

void MdlTerminate(void)
{
  ctrl_custom_terminate();
}

/* Registration function */
RT_MODEL_ctrl_custom_T *ctrl_custom(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_custom_M, 0,
                sizeof(RT_MODEL_ctrl_custom_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_custom_M->solverInfo,
                          &ctrl_custom_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_custom_M->solverInfo, &rtmGetTPtr(ctrl_custom_M));
    rtsiSetStepSizePtr(&ctrl_custom_M->solverInfo,
                       &ctrl_custom_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_custom_M->solverInfo, &ctrl_custom_M->derivs);
    rtsiSetContStatesPtr(&ctrl_custom_M->solverInfo, (real_T **)
                         &ctrl_custom_M->contStates);
    rtsiSetNumContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_custom_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_custom_M)));
    rtsiSetRTModelPtr(&ctrl_custom_M->solverInfo, ctrl_custom_M);
  }

  rtsiSetSimTimeStep(&ctrl_custom_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_custom_M->intgData.y = ctrl_custom_M->odeY;
  ctrl_custom_M->intgData.f[0] = ctrl_custom_M->odeF[0];
  ctrl_custom_M->intgData.f[1] = ctrl_custom_M->odeF[1];
  ctrl_custom_M->intgData.f[2] = ctrl_custom_M->odeF[2];
  ctrl_custom_M->intgData.f[3] = ctrl_custom_M->odeF[3];
  ctrl_custom_M->contStates = ((real_T *) &ctrl_custom_X);
  rtsiSetSolverData(&ctrl_custom_M->solverInfo, (void *)&ctrl_custom_M->intgData);
  rtsiSetSolverName(&ctrl_custom_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_custom_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_custom_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_custom_M->Timing.sampleTimes = (&ctrl_custom_M->
      Timing.sampleTimesArray[0]);
    ctrl_custom_M->Timing.offsetTimes = (&ctrl_custom_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_custom_M->Timing.sampleTimes[0] = (0.0);
    ctrl_custom_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_custom_M->Timing.offsetTimes[0] = (0.0);
    ctrl_custom_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_custom_M, &ctrl_custom_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_custom_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_custom_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_custom_M, 500.0);
  ctrl_custom_M->Timing.stepSize0 = 0.01;
  ctrl_custom_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_custom_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_custom_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_custom_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_custom_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_custom_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_custom_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
  }

  ctrl_custom_M->solverInfoPtr = (&ctrl_custom_M->solverInfo);
  ctrl_custom_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_custom_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_custom_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_custom_M->blockIO = ((void *) &ctrl_custom_B);
  (void) memset(((void *) &ctrl_custom_B), 0,
                sizeof(B_ctrl_custom_T));

  /* parameters */
  ctrl_custom_M->defaultParam = ((real_T *)&ctrl_custom_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_custom_X;
    ctrl_custom_M->contStates = (x);
    (void) memset((void *)&ctrl_custom_X, 0,
                  sizeof(X_ctrl_custom_T));
  }

  /* states (dwork) */
  ctrl_custom_M->dwork = ((void *) &ctrl_custom_DW);
  (void) memset((void *)&ctrl_custom_DW, 0,
                sizeof(DW_ctrl_custom_T));

  /* Initialize Sizes */
  ctrl_custom_M->Sizes.numContStates = (10);/* Number of continuous states */
  ctrl_custom_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_custom_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_custom_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_custom_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_custom_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_custom_M->Sizes.numBlocks = (110);/* Number of blocks */
  ctrl_custom_M->Sizes.numBlockIO = (57);/* Number of block outputs */
  ctrl_custom_M->Sizes.numBlockPrms = (356);/* Sum of parameter "widths" */
  return ctrl_custom_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.212
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Mon Mar 25 10:47:05 2019
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_custom
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 29:
    return (( double *)ptr)[subindex];

   case 30:
    return (( double *)ptr)[subindex];

   case 31:
    return (( double *)ptr)[subindex];

   case 32:
    return (( double *)ptr)[subindex];

   case 33:
    return (( double *)ptr)[subindex];

   case 34:
    return (( double *)ptr)[subindex];

   case 35:
    return (( double *)ptr)[subindex];

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 17:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 29:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 31:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 32:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 35:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_custom_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_custom/NIVeriStand In2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.NIVeriStandIn2, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/posXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.posXRight, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/R2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.R2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/L2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.L2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/posYLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.posYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/control switch
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.controlswitch, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/path
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.path, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/mu
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.mu, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/U_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.U_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/rx
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.rx, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/ry
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.ry, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/Kp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Kp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/Kd
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Kd, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Pose/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Pose/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Pose/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.psi_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Observer/Noise gain
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Noisegain, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Observer/Observer gain L1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.ObservergainL1, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/Observer/Observer gain L3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.ObservergainL3, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/Observer/Observer gain L2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.ObservergainL2, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 20;
}

int32_t NumOutputPorts(void)
{
  return 37;
}

double ni_extout[37];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_custom/Control law/pd: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.pd, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.pd, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.pd, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/Control law/eta_0_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_0_new, 0, 18,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_0_new, 1, 18,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_0_new, 2, 18,
      0);
  } else {
    index += 3;
  }

  // ctrl_custom/Control law/s_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1_m, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Control law/j_control : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.j_path_curr, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/tau_sat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.tau, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.tau, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.tau, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/eta_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator, 0,
      18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator, 1,
      18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator, 2,
      18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/nu_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1, 0,
      18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1, 1,
      18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1, 2,
      18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/b_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator2, 0,
      18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator2, 1,
      18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator2, 2,
      18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/tau_cmd: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum1, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum1, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum1, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/eta_measured: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_new, 0, 18,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_new, 1, 18,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_new, 2, 18,
      0);
  } else {
    index += 3;
  }

  // ctrl_custom/u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u_ext, 4, 23, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_P.Turnrate1_Value,
      0, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_P.Turnrate1_Value,
      1, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u_ext, 3, 23, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation2, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation11, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation1, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Observer/Eta_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/Subsystem/j_measurement : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.j_new, 0, 0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // ctrl_custom/Control law/pd: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.pd, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.pd, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.pd, 2, 18, 0);

  // ctrl_custom/Control law/eta_0_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_0_new, 0, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_0_new, 1, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_0_new, 2, 18,
    0);

  // ctrl_custom/Control law/s_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1_m, 0,
    0, 0);

  // ctrl_custom/Control law/j_control : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.j_path_curr, 0, 0,
    0);

  // ctrl_custom/tau_sat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.tau, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.tau, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.tau, 2, 18, 0);

  // ctrl_custom/eta_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator, 0, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator, 1, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator, 2, 18,
    0);

  // ctrl_custom/nu_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1, 0, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1, 1, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator1, 2, 18,
    0);

  // ctrl_custom/b_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator2, 0, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator2, 1, 18,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Integrator2, 2, 18,
    0);

  // ctrl_custom/tau_cmd: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum1, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum1, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum1, 2, 18, 0);

  // ctrl_custom/eta_measured: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_new, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_new, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.eta_new, 2, 18, 0);

  // ctrl_custom/u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u_ext, 4, 23, 0);

  // ctrl_custom/u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_P.Turnrate1_Value, 0,
    21, 0);

  // ctrl_custom/u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_P.Turnrate1_Value, 1,
    21, 0);

  // ctrl_custom/u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u_ext, 3, 23, 0);

  // ctrl_custom/u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation2, 0, 0,
    0);

  // ctrl_custom/u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation11, 0, 0,
    0);

  // ctrl_custom/u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation1, 0, 0,
    0);

  // ctrl_custom/Observer/Eta_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 2, 18, 0);

  // ctrl_custom/Subsystem/j_measurement : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.j_new, 0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_custom/simpleConversion1/Gain/Gain", offsetof(P_ctrl_custom_T,
    Gain_Gain), 36, 1, 2, 0, 0 },

  { 1, "ctrl_custom/simpleConversion1/Gain2/Gain", offsetof(P_ctrl_custom_T,
    Gain2_Gain), 36, 1, 2, 2, 0 },

  { 2, "ctrl_custom/Gain/Gain", offsetof(P_ctrl_custom_T, Gain_Gain_a), 36, 1, 2,
    4, 0 },

  { 3, "ctrl_custom/Gain1/Gain", offsetof(P_ctrl_custom_T, Gain1_Gain), 36, 1, 2,
    6, 0 },

  { 4, "ctrl_custom/simpleConversion1/Gain1/Gain", offsetof(P_ctrl_custom_T,
    Gain1_Gain_h), 36, 1, 2, 8, 0 },

  { 5, "ctrl_custom/Control law/Gain/Gain", offsetof(P_ctrl_custom_T,
    Gain_Gain_i), 19, 9, 2, 10, 0 },

  { 6, "ctrl_custom/Control law/Gain1/Gain", offsetof(P_ctrl_custom_T,
    Gain1_Gain_f), 19, 9, 2, 12, 0 },

  { 7, "ctrl_custom/Subsystem/Memory1/X0", offsetof(P_ctrl_custom_T, Memory1_X0),
    25, 3, 2, 14, 0 },

  { 8, "ctrl_custom/Subsystem/Memory/X0", offsetof(P_ctrl_custom_T, Memory_X0),
    36, 1, 2, 16, 0 },

  { 9, "ctrl_custom/Control law/Memory/X0", offsetof(P_ctrl_custom_T,
    Memory_X0_n), 25, 3, 2, 18, 0 },

  { 10, "ctrl_custom/Control law/Memory1/X0", offsetof(P_ctrl_custom_T,
    Memory1_X0_p), 36, 1, 2, 20, 0 },

  { 11, "ctrl_custom/Observer/Integrator/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator_IC), 25, 3, 2, 22, 0 },

  { 12, "ctrl_custom/Observer/Integrator1/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator1_IC), 25, 3, 2, 24, 0 },

  { 13, "ctrl_custom/Control law/Integrator1/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator1_IC_p), 36, 1, 2, 26, 0 },

  { 14, "ctrl_custom/Control law/Memory3/X0", offsetof(P_ctrl_custom_T,
    Memory3_X0), 36, 1, 2, 28, 0 },

  { 15, "ctrl_custom/Control law/Memory2/X0", offsetof(P_ctrl_custom_T,
    Memory2_X0), 25, 3, 2, 30, 0 },

  { 16, "ctrl_custom/u1/Saturation2/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation2_UpperSat), 36, 1, 2, 32, 0 },

  { 17, "ctrl_custom/u1/Saturation2/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation2_LowerSat), 36, 1, 2, 34, 0 },

  { 18, "ctrl_custom/u1/Saturation11/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation11_UpperSat), 36, 1, 2, 36, 0 },

  { 19, "ctrl_custom/u1/Saturation11/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation11_LowerSat), 36, 1, 2, 38, 0 },

  { 20, "ctrl_custom/u1/Saturation1/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation1_UpperSat), 36, 1, 2, 40, 0 },

  { 21, "ctrl_custom/u1/Saturation1/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation1_LowerSat), 36, 1, 2, 42, 0 },

  { 22, "ctrl_custom/Turn rate1/Value", offsetof(P_ctrl_custom_T,
    Turnrate1_Value[0]), 21, 2, 2, 44, 0 },

  { 23, "ctrl_custom/Observer/Integrator2/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator2_IC), 36, 1, 2, 46, 0 },

  { 24, "ctrl_custom/Memory1/X0", offsetof(P_ctrl_custom_T, Memory1_X0_ps), 25,
    3, 2, 48, 0 },

  { 25, "ctrl_custom/Memory2/X0", offsetof(P_ctrl_custom_T, Memory2_X0_d), 25, 3,
    2, 50, 0 },

  { 26, "ctrl_custom/Memory3/X0", offsetof(P_ctrl_custom_T, Memory3_X0_f), 25, 3,
    2, 52, 0 },

  { 27, "ctrl_custom/Observer/Band-Limited White Noise/White Noise/Mean",
    offsetof(P_ctrl_custom_T, WhiteNoise_Mean), 36, 1, 2, 54, 0 },

  { 28, "ctrl_custom/Observer/Band-Limited White Noise/White Noise/StdDev",
    offsetof(P_ctrl_custom_T, WhiteNoise_StdDev), 36, 1, 2, 56, 0 },

  { 29, "ctrl_custom/Observer/Band-Limited White Noise/White Noise/Seed",
    offsetof(P_ctrl_custom_T, WhiteNoise_Seed), 36, 1, 2, 58, 0 },

  { 30, "ctrl_custom/Observer/Band-Limited White Noise/Output/Gain", offsetof
    (P_ctrl_custom_T, Output_Gain), 36, 1, 2, 60, 0 },

  { 31, "ctrl_custom/Observer/L5/Gain", offsetof(P_ctrl_custom_T, L5_Gain), 19,
    9, 2, 62, 0 },

  { 32, "ctrl_custom/Observer/L4/Gain", offsetof(P_ctrl_custom_T, L4_Gain), 25,
    3, 2, 64, 0 },

  { 33, "ctrl_custom/Switch1/Threshold", offsetof(P_ctrl_custom_T,
    Switch1_Threshold), 36, 1, 2, 66, 0 },

  { 34, "ctrl_custom/Observer/D/Value", offsetof(P_ctrl_custom_T, D_Value[0]),
    19, 9, 2, 68, 0 },

  { 35, "ctrl_custom/Observer/M/Value", offsetof(P_ctrl_custom_T, M_Value[0]),
    19, 9, 2, 70, 0 },

  { 36, "ctrl_custom/Observer/L1/Gain", offsetof(P_ctrl_custom_T, L1_Gain), 19,
    9, 2, 72, 0 },

  { 37, "ctrl_custom/Observer/L2/Gain", offsetof(P_ctrl_custom_T, L2_Gain), 19,
    9, 2, 74, 0 },

  { 38, "ctrl_custom/Observer/L3/Gain", offsetof(P_ctrl_custom_T, L3_Gain), 19,
    9, 2, 76, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 39;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  3, 3,                                /* Parameter at index 5 */
  3, 3,                                /* Parameter at index 6 */
  3, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  3, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  3, 1,                                /* Parameter at index 11 */
  3, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  3, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  2, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  3, 1,                                /* Parameter at index 24 */
  3, 1,                                /* Parameter at index 25 */
  3, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  3, 3,                                /* Parameter at index 31 */
  3, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  3, 3,                                /* Parameter at index 34 */
  3, 3,                                /* Parameter at index 35 */
  3, 3,                                /* Parameter at index 36 */
  3, 3,                                /* Parameter at index 37 */
  3, 3,                                /* Parameter at index 38 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_custom/NIVeriStand In2", 0, "", offsetof(B_ctrl_custom_T,
    NIVeriStandIn2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_custom/posXRight", 0, "", offsetof(B_ctrl_custom_T, posXRight) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_custom/R2", 0, "", offsetof(B_ctrl_custom_T, R2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_custom/L2", 0, "", offsetof(B_ctrl_custom_T, L2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_custom/posYLeft", 0, "", offsetof(B_ctrl_custom_T, posYLeft) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_custom/Control law/control switch", 0, "", offsetof(B_ctrl_custom_T,
    controlswitch) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_custom/Control law/path", 0, "", offsetof(B_ctrl_custom_T, path) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_custom/Control law/mu", 0, "", offsetof(B_ctrl_custom_T, mu) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_custom/Control law/U_ref", 0, "", offsetof(B_ctrl_custom_T, U_ref)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_custom/Control law/rx", 0, "", offsetof(B_ctrl_custom_T, rx) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_custom/Control law/ry", 0, "", offsetof(B_ctrl_custom_T, ry) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_custom/Control law/Kp", 0, "", offsetof(B_ctrl_custom_T, Kp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_custom/Control law/Kd", 0, "", offsetof(B_ctrl_custom_T, Kd) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_custom/Pose/x_m", 0, "", offsetof(B_ctrl_custom_T, x_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_custom/Pose/y_m", 0, "", offsetof(B_ctrl_custom_T, y_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_custom/Pose/psi_m", 0, "", offsetof(B_ctrl_custom_T, psi_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_custom/Subsystem/Memory1/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Memory1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 17, "ctrl_custom/Subsystem/Memory1/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Memory1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 18, "ctrl_custom/Subsystem/Memory1/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Memory1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 19, "ctrl_custom/Subsystem/Memory", 0, "", offsetof(B_ctrl_custom_T, Memory)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_custom/Control law/Memory/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Memory_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 21, "ctrl_custom/Control law/Memory/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Memory_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 22, "ctrl_custom/Control law/Memory/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Memory_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 23, "ctrl_custom/Control law/Memory1", 0, "", offsetof(B_ctrl_custom_T,
    Memory1_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "ctrl_custom/Observer/Integrator/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 25, "ctrl_custom/Observer/Integrator/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 26, "ctrl_custom/Observer/Integrator/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 27, "ctrl_custom/Observer/Integrator1/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 28, "ctrl_custom/Observer/Integrator1/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 29, "ctrl_custom/Observer/Integrator1/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 30, "ctrl_custom/Control law/Integrator1", 0, "", offsetof(B_ctrl_custom_T,
    Integrator1_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 31, "ctrl_custom/Control law/Memory3", 0, "", offsetof(B_ctrl_custom_T,
    Memory3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 32, "ctrl_custom/Control law/Memory2/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Memory2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 33, "ctrl_custom/Control law/Memory2/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Memory2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 34, "ctrl_custom/Control law/Memory2/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Memory2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 35, "ctrl_custom/Sum1/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, Sum1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 36, "ctrl_custom/Sum1/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, Sum1) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 37, "ctrl_custom/Sum1/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, Sum1) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 38, "ctrl_custom/u1/Saturation2", 0, "", offsetof(B_ctrl_custom_T,
    Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 39, "ctrl_custom/u1/Saturation11", 0, "", offsetof(B_ctrl_custom_T,
    Saturation11) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 40, "ctrl_custom/u1/Saturation1", 0, "", offsetof(B_ctrl_custom_T,
    Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 41, "ctrl_custom/Observer/Integrator2/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 42, "ctrl_custom/Observer/Integrator2/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 43, "ctrl_custom/Observer/Integrator2/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 44, "ctrl_custom/Memory1/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, Memory1_p)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 45, "ctrl_custom/Memory1/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, Memory1_p)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 46, "ctrl_custom/Memory1/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, Memory1_p)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 47, "ctrl_custom/Memory2/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, Memory2_b)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 48, "ctrl_custom/Memory2/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, Memory2_b)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 49, "ctrl_custom/Memory2/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, Memory2_b)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 50, "ctrl_custom/Memory3/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, Memory3_k)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 51, "ctrl_custom/Memory3/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, Memory3_k)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 52, "ctrl_custom/Memory3/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, Memory3_k)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 53, "ctrl_custom/Observer/Noise gain", 0, "", offsetof(B_ctrl_custom_T,
    Noisegain) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 54, "ctrl_custom/Observer/L4/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, L4) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 55, "ctrl_custom/Observer/L4/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, L4) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 56, "ctrl_custom/Observer/L4/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, L4) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 57, "ctrl_custom/Observer/Sum/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, Sum)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 58, "ctrl_custom/Observer/Sum/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, Sum)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 59, "ctrl_custom/Observer/Sum/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, Sum)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 60, "ctrl_custom/Observer/Observer gain L1", 0, "", offsetof(B_ctrl_custom_T,
    ObservergainL1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 61, "ctrl_custom/Observer/Observer gain L3", 0, "", offsetof(B_ctrl_custom_T,
    ObservergainL3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 62, "ctrl_custom/Observer/Observer gain L2", 0, "", offsetof(B_ctrl_custom_T,
    ObservergainL2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 63, "ctrl_custom/Observer/Product/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Product) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 64, "ctrl_custom/Observer/Product/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Product) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 65, "ctrl_custom/Observer/Product/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Product) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 66, "ctrl_custom/Observer/Product7/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Product7) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 67, "ctrl_custom/Observer/Product7/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Product7) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 68, "ctrl_custom/Observer/Product7/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Product7) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 69, "ctrl_custom/Observer/Sum2/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Sum2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 70, "ctrl_custom/Observer/Sum2/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Sum2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 71, "ctrl_custom/Observer/Sum2/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Sum2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 72, "ctrl_custom/u_to_tau_mapping/u_to_tau_mapping", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, tau) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 73, "ctrl_custom/u_to_tau_mapping/u_to_tau_mapping", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, tau) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 74, "ctrl_custom/u_to_tau_mapping/u_to_tau_mapping", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, tau) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 75, "ctrl_custom/dead_reckoning", 1, "(1, 1)", offsetof(B_ctrl_custom_T,
    last) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 76, "ctrl_custom/dead_reckoning", 1, "(1, 2)", offsetof(B_ctrl_custom_T,
    last) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 77, "ctrl_custom/dead_reckoning", 1, "(1, 3)", offsetof(B_ctrl_custom_T,
    last) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 78, "ctrl_custom/dead_reckoning", 2, "(1, 1)", offsetof(B_ctrl_custom_T,
    last2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 79, "ctrl_custom/dead_reckoning", 2, "(1, 2)", offsetof(B_ctrl_custom_T,
    last2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 80, "ctrl_custom/dead_reckoning", 2, "(1, 3)", offsetof(B_ctrl_custom_T,
    last2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 81, "ctrl_custom/dead_reckoning", 3, "(1, 1)", offsetof(B_ctrl_custom_T,
    last3) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 82, "ctrl_custom/dead_reckoning", 3, "(1, 2)", offsetof(B_ctrl_custom_T,
    last3) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 83, "ctrl_custom/dead_reckoning", 3, "(1, 3)", offsetof(B_ctrl_custom_T,
    last3) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 84, "ctrl_custom/Subsystem/MATLAB Function", 0, "(1, 1)", offsetof
    (B_ctrl_custom_T, eta_new) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 85, "ctrl_custom/Subsystem/MATLAB Function", 0, "(1, 2)", offsetof
    (B_ctrl_custom_T, eta_new) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 86, "ctrl_custom/Subsystem/MATLAB Function", 0, "(1, 3)", offsetof
    (B_ctrl_custom_T, eta_new) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 87, "ctrl_custom/Subsystem/MATLAB Function", 1, "", offsetof(B_ctrl_custom_T,
    j_new) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 88, "ctrl_custom/Rectangular coordinate thrust allocation/MATLAB Function",
    0, "(1, 1)", offsetof(B_ctrl_custom_T, u_ext) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 89, "ctrl_custom/Rectangular coordinate thrust allocation/MATLAB Function",
    0, "(1, 2)", offsetof(B_ctrl_custom_T, u_ext) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 90, "ctrl_custom/Rectangular coordinate thrust allocation/MATLAB Function",
    0, "(1, 3)", offsetof(B_ctrl_custom_T, u_ext) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 91, "ctrl_custom/Rectangular coordinate thrust allocation/MATLAB Function",
    0, "(1, 4)", offsetof(B_ctrl_custom_T, u_ext) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 92, "ctrl_custom/Rectangular coordinate thrust allocation/MATLAB Function",
    0, "(1, 5)", offsetof(B_ctrl_custom_T, u_ext) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 93, "ctrl_custom/Observer/Inverse", 0, "(1, 1)", offsetof(B_ctrl_custom_T, y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 94, "ctrl_custom/Observer/Inverse", 0, "(2, 1)", offsetof(B_ctrl_custom_T, y)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 95, "ctrl_custom/Observer/Inverse", 0, "(3, 1)", offsetof(B_ctrl_custom_T, y)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 96, "ctrl_custom/Observer/Inverse", 0, "(1, 2)", offsetof(B_ctrl_custom_T, y)
    + (3*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 97, "ctrl_custom/Observer/Inverse", 0, "(2, 2)", offsetof(B_ctrl_custom_T, y)
    + (4*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 98, "ctrl_custom/Observer/Inverse", 0, "(3, 2)", offsetof(B_ctrl_custom_T, y)
    + (5*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 99, "ctrl_custom/Observer/Inverse", 0, "(1, 3)", offsetof(B_ctrl_custom_T, y)
    + (6*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 100, "ctrl_custom/Observer/Inverse", 0, "(2, 3)", offsetof(B_ctrl_custom_T,
    y) + (7*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 101, "ctrl_custom/Observer/Inverse", 0, "(3, 3)", offsetof(B_ctrl_custom_T,
    y) + (8*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 102, "ctrl_custom/Control law/MATLAB Function", 0, "", offsetof
    (B_ctrl_custom_T, s_reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 103, "ctrl_custom/Control law/MATLAB Function", 1, "(1, 1)", offsetof
    (B_ctrl_custom_T, eta_0_new) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 104, "ctrl_custom/Control law/MATLAB Function", 1, "(1, 2)", offsetof
    (B_ctrl_custom_T, eta_0_new) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 105, "ctrl_custom/Control law/MATLAB Function", 1, "(1, 3)", offsetof
    (B_ctrl_custom_T, eta_0_new) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 106, "ctrl_custom/Control law/MATLAB Function", 2, "", offsetof
    (B_ctrl_custom_T, switch_signal_new) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 107, "ctrl_custom/Control law/Control law", 1, "(1, 1)", offsetof
    (B_ctrl_custom_T, pd) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 108, "ctrl_custom/Control law/Control law", 1, "(1, 2)", offsetof
    (B_ctrl_custom_T, pd) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 109, "ctrl_custom/Control law/Control law", 1, "(1, 3)", offsetof
    (B_ctrl_custom_T, pd) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 110, "ctrl_custom/Control law/Control law", 2, "", offsetof(B_ctrl_custom_T,
    s_dot) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 111, "ctrl_custom/Control law/Control law", 3, "", offsetof(B_ctrl_custom_T,
    j_path_curr) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 112, "ctrl_custom/Control law/Control law", 4, "(1, 1)", offsetof
    (B_ctrl_custom_T, pd_curr) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 113, "ctrl_custom/Control law/Control law", 4, "(1, 2)", offsetof
    (B_ctrl_custom_T, pd_curr) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 114, "ctrl_custom/Control law/Control law", 4, "(1, 3)", offsetof
    (B_ctrl_custom_T, pd_curr) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 115;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 39;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "NIVeriStand In2", 0, EXT_IN, 1, 1, 1 },

  { 2, "posXRight", 0, EXT_IN, 1, 1, 1 },

  { 3, "R2", 0, EXT_IN, 1, 1, 1 },

  { 4, "L2", 0, EXT_IN, 1, 1, 1 },

  { 5, "posYLeft", 0, EXT_IN, 1, 1, 1 },

  { 6, "Control law/control switch", 0, EXT_IN, 1, 1, 1 },

  { 7, "Control law/path", 0, EXT_IN, 1, 1, 1 },

  { 8, "Control law/mu", 0, EXT_IN, 1, 1, 1 },

  { 9, "Control law/U_ref", 0, EXT_IN, 1, 1, 1 },

  { 10, "Control law/rx", 0, EXT_IN, 1, 1, 1 },

  { 11, "Control law/ry", 0, EXT_IN, 1, 1, 1 },

  { 12, "Control law/Kp ", 0, EXT_IN, 1, 1, 1 },

  { 13, "Control law/Kd", 0, EXT_IN, 1, 1, 1 },

  { 14, "Pose/x_m", 0, EXT_IN, 1, 1, 1 },

  { 15, "Pose/y_m", 0, EXT_IN, 1, 1, 1 },

  { 16, "Pose/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 17, "Observer/Noise gain", 0, EXT_IN, 1, 1, 1 },

  { 18, "Observer/Observer gain L1", 0, EXT_IN, 1, 1, 1 },

  { 19, "Observer/Observer gain L3", 0, EXT_IN, 1, 1, 1 },

  { 20, "Observer/Observer gain L2", 0, EXT_IN, 1, 1, 1 },

  { 1, "Control law/pd", 0, EXT_OUT, 3, 3, 1 },

  { 2, "Control law/eta_0_out", 0, EXT_OUT, 3, 3, 1 },

  { 3, "Control law/s_out", 0, EXT_OUT, 1, 1, 1 },

  { 4, "Control law/j_control ", 0, EXT_OUT, 1, 1, 1 },

  { 5, "tau_sat", 0, EXT_OUT, 3, 3, 1 },

  { 6, "eta_hat", 0, EXT_OUT, 3, 3, 1 },

  { 7, "nu_hat", 0, EXT_OUT, 3, 3, 1 },

  { 8, "b_hat", 0, EXT_OUT, 3, 3, 1 },

  { 9, "tau_cmd", 0, EXT_OUT, 3, 3, 1 },

  { 10, "eta_measured", 0, EXT_OUT, 3, 3, 1 },

  { 11, "u/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 12, "u/omega_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 13, "u/omega_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 14, "u/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 15, "u/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 16, "u/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 17, "u/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 18, "Observer/Eta_bar", 0, EXT_OUT, 3, 3, 1 },

  { 19, "Subsystem/j_measurement ", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_custom";
static const char* NI_CompiledModelVersion = "1.212";
static const char* NI_CompiledModelDateTime = "Mon Mar 25 10:47:05 2019";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2017.0.0.143 (2017) for Simulink Coder 8.11 (R2016b)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2017.0.0.143";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      // no index or ID specified.
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      // no need for return string to be null terminated!
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    // check if ID has been specified.
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      // lookup the table for matching ID
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      // no index or ID specified.
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_custom_P, sizeof(P_ctrl_custom_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_custom_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_custom_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_custom_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      // fail the transaction.
      // copy old list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_custom_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_custom_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 10;
      *numDiscStates = 548;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator1_CSTATE_c), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.NIVeriStandIn2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.NIVeriStandIn2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posXRight_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.R2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.R2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.L2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.L2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.controlswitch_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.controlswitch_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.path_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.path_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.mu_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.mu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.U_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.U_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.rx_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.rx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ry_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ry_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Kp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Kp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Kd_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Kd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory_PreviousInput_f, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory_PreviousInput_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory_PreviousInput_f, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory_PreviousInput_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory_PreviousInput_f, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory_PreviousInput_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory3_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.pd_DWORK1, 0, 18,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.pd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.pd_DWORK1, 1, 18,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.pd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.pd_DWORK1, 2, 18,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.pd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK1,
      0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_0_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK1,
      1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_0_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK1,
      2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_0_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.s_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.s_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.j_control_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.j_control_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK1, 0,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_sat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK1, 1,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_sat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK1, 2,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_sat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK1, 0,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK1, 1,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK1, 2,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK1, 0,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK1, 1,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK1, 2,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.b_hat_DWORK1, 0,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.b_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.b_hat_DWORK1, 1,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.b_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.b_hat_DWORK1, 2,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.b_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK1, 0,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_cmd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK1, 1,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_cmd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK1, 2,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_cmd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.eta_measured_DWORK1, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.eta_measured_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.eta_measured_DWORK1, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.eta_measured_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.eta_measured_DWORK1, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.eta_measured_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.omega_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.omega_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_BT_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput_e, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput_e, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput_e, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput_i, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput_i, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory2_PreviousInput_i, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory2_PreviousInput_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory3_PreviousInput_b, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory3_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory3_PreviousInput_b, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory3_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory3_PreviousInput_b, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory3_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.NextOutput, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Noisegain_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Noisegain_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK1, 0,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Eta_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK1, 1,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Eta_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK1, 2,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Eta_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ObservergainL1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ObservergainL1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ObservergainL3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ObservergainL3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ObservergainL2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ObservergainL2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.j_measurement_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.j_measurement_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.RandSeed");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.NIVeriStandIn2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.NIVeriStandIn2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posXRight_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posXRight_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.R2_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.R2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.L2_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.L2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posYLeft_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.controlswitch_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.controlswitch_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.path_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.path_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.mu_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.mu_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.U_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.U_ref_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.rx_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.rx_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ry_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ry_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Kp_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Kp_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Kd_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Kd_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.pd_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.pd_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_0_out_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.s_out_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.s_out_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.j_control_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.j_control_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_sat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_hat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_hat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.b_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.b_hat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tau_cmd_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.eta_measured_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.eta_measured_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.alpha_VSP2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.omega_VSP1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.omega_VSP2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.alpha_VSP1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_BT_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Noisegain_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Noisegain_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Eta_bar_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.ObservergainL1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.ObservergainL1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.ObservergainL3_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.ObservergainL3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.ObservergainL2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.ObservergainL2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.j_measurement_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.j_measurement_DWORK2");
    }
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if (contStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE_c), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 2,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_custom_DW.NIVeriStandIn2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.posXRight_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.R2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.L2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.controlswitch_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.path_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.mu_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.U_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.rx_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ry_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Kp_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Kd_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory_PreviousInput_f, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory_PreviousInput_f, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory_PreviousInput_f, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.pd_DWORK1, 0, discStates[idx++], 18,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.pd_DWORK1, 1, discStates[idx++], 18,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.pd_DWORK1, 2, discStates[idx++], 18,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK1, 0, discStates[idx
      ++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK1, 1, discStates[idx
      ++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK1, 2, discStates[idx
      ++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.s_out_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.j_control_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK1, 0, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK1, 1, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK1, 2, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK1, 0, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK1, 1, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK1, 2, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK1, 0, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK1, 1, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK1, 2, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.b_hat_DWORK1, 0, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.b_hat_DWORK1, 1, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.b_hat_DWORK1, 2, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK1, 0, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK1, 1, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK1, 2, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_measured_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_measured_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_measured_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u_BT_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput_e, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput_e, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput_e, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput_i, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput_i, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory2_PreviousInput_i, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory3_PreviousInput_b, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory3_PreviousInput_b, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory3_PreviousInput_b, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.NextOutput, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Noisegain_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK1, 0, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK1, 1, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK1, 2, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.j_measurement_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.RandSeed, 0, discStates[idx++], 7, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.NIVeriStandIn2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.posXRight_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.R2_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.L2_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.controlswitch_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.path_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.mu_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.U_ref_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.rx_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.ry_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Kp_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Kd_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.pd_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.eta_0_out_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.s_out_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.j_control_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.tau_sat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.b_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.tau_cmd_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.eta_measured_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_BT_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Noisegain_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL3_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.j_measurement_DWORK2, count,
        discStates[idx++], 20, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_custom
