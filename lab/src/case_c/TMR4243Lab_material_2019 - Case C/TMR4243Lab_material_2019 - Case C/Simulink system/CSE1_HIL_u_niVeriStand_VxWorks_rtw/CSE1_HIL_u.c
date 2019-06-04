/*
 * CSE1_HIL_u.c
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

/* Block signals (auto storage) */
B_CSE1_HIL_u_T CSE1_HIL_u_B;

/* Continuous states */
X_CSE1_HIL_u_T CSE1_HIL_u_X;

/* Block states (auto storage) */
DW_CSE1_HIL_u_T CSE1_HIL_u_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_CSE1_HIL_u_T CSE1_HIL_u_PrevZCX;

/* Real-time model */
RT_MODEL_CSE1_HIL_u_T CSE1_HIL_u_M_;
RT_MODEL_CSE1_HIL_u_T *const CSE1_HIL_u_M = &CSE1_HIL_u_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  CSE1_HIL_u_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  CSE1_HIL_u_output();
  CSE1_HIL_u_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  CSE1_HIL_u_output();
  CSE1_HIL_u_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  CSE1_HIL_u_output();
  CSE1_HIL_u_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S8>/VSP'
 *    '<S8>/VSP1'
 */
void CSE1_HIL_u_VSP(real_T rtu_alpha, real_T rtu_u_VSP, B_VSP_CSE1_HIL_u_T
                    *localB)
{
  /* MATLAB Function 'Simulator_CSE1/Command2force/VSP': '<S11>:1' */
  /*  Calculating the force in x-direction */
  /* '<S11>:1:4' */
  /* '<S11>:1:5' */
  /* '<S11>:1:6' */
  /* '<S11>:1:7' */
  /* '<S11>:1:8' */
  /* '<S11>:1:9' */
  /* '<S11>:1:10' */
  /* '<S11>:1:11' */
  /* '<S11>:1:12' */
  /* '<S11>:1:13' */
  /* '<S11>:1:14' */
  /* '<S11>:1:15' */
  /* '<S11>:1:16' */
  /* '<S11>:1:17' */
  /* '<S11>:1:18' */
  /* '<S11>:1:19' */
  /* '<S11>:1:20' */
  /* '<S11>:1:21' */
  /* '<S11>:1:22' */
  localB->F_x = (((((sin(1.001 * rtu_alpha + 1.564) * 1.107 + sin(0.1397 *
    rtu_alpha + -1.599) * 0.3471) + sin(1.993 * rtu_alpha + 1.886) * 0.1558) +
                   sin(0.218 * rtu_alpha + 1.513) * 0.1599) + sin(2.986 *
    rtu_alpha + -1.601) * 0.08237) + sin(3.964 * rtu_alpha + 1.738) * 0.04641) *
    rtu_u_VSP;

  /*  Calculating the force in y-direction */
  /* '<S11>:1:29' */
  /* '<S11>:1:30' */
  /* '<S11>:1:31' */
  /* '<S11>:1:32' */
  /* '<S11>:1:33' */
  /* '<S11>:1:34' */
  /* '<S11>:1:35' */
  /* '<S11>:1:36' */
  /* '<S11>:1:37' */
  /* '<S11>:1:38' */
  /* '<S11>:1:39' */
  /* '<S11>:1:40' */
  /* '<S11>:1:41' */
  /* '<S11>:1:42' */
  /* '<S11>:1:43' */
  /* '<S11>:1:44' */
  /* '<S11>:1:45' */
  /* '<S11>:1:46' */
  /* '<S11>:1:47' */
  localB->F_y = (((((sin(1.001 * rtu_alpha + 0.01605) * 0.7936 + sin(1.997 *
    rtu_alpha + 0.03229) * 0.2112) + sin(2.991 * rtu_alpha + 2.986) * 0.07608) +
                   sin(3.999 * rtu_alpha + -0.8668) * 0.04817) + sin(4.904 *
    rtu_alpha + -2.622) * 0.01757) + sin(5.068 * rtu_alpha + 0.2548) * -0.02089)
    * rtu_u_VSP;
}

/* Model output function */
void CSE1_HIL_u_output(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation3;
  real_T rtb_Saturation;
  real_T rtb_Saturation4;
  real_T rtb_Saturation1;
  ZCEventType zcEvent;
  real_T B[3];
  real_T rtb_Saturation2;
  real_T rtb_Sum1;
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  int32_T i;
  real_T rtb_TmpSignalConversionAtSFun_0[3];
  real_T tmp_2[9];
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
    /* set solver stop time */
    if (!(CSE1_HIL_u_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&CSE1_HIL_u_M->solverInfo,
                            ((CSE1_HIL_u_M->Timing.clockTickH0 + 1) *
        CSE1_HIL_u_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&CSE1_HIL_u_M->solverInfo,
                            ((CSE1_HIL_u_M->Timing.clockTick0 + 1) *
        CSE1_HIL_u_M->Timing.stepSize0 + CSE1_HIL_u_M->Timing.clockTickH0 *
        CSE1_HIL_u_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CSE1_HIL_u_M)) {
    CSE1_HIL_u_M->Timing.t[0] = rtsiGetT(&CSE1_HIL_u_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
    /* Memory: '<S3>/Memory3' */
    CSE1_HIL_u_B.Memory3 = CSE1_HIL_u_DW.Memory3_PreviousInput;

    /* Memory: '<S3>/Memory4' */
    CSE1_HIL_u_B.Memory4 = CSE1_HIL_u_DW.Memory4_PreviousInput;

    /* Memory: '<S3>/Memory5' */
    CSE1_HIL_u_B.Memory5 = CSE1_HIL_u_DW.Memory5_PreviousInput;
  }

  /* Integrator: '<S9>/Position' */
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&CSE1_HIL_u_PrevZCX.Position_Reset_ZCE,
                       (CSE1_HIL_u_B.integrator_reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (CSE1_HIL_u_DW.Position_IWORK != 0)) {
      CSE1_HIL_u_X.Position_CSTATE[0] = CSE1_HIL_u_B.Memory3;
      CSE1_HIL_u_X.Position_CSTATE[1] = CSE1_HIL_u_B.Memory4;
      CSE1_HIL_u_X.Position_CSTATE[2] = CSE1_HIL_u_B.Memory5;
    }
  }

  CSE1_HIL_u_B.Position[0] = CSE1_HIL_u_X.Position_CSTATE[0];
  CSE1_HIL_u_B.Position[1] = CSE1_HIL_u_X.Position_CSTATE[1];
  CSE1_HIL_u_B.Position[2] = CSE1_HIL_u_X.Position_CSTATE[2];

  /* End of Integrator: '<S9>/Position' */

  /* Integrator: '<S9>/Velocity' */
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&CSE1_HIL_u_PrevZCX.Velocity_Reset_ZCE,
                       (CSE1_HIL_u_B.integrator_reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      CSE1_HIL_u_X.Velocity_CSTATE[0] = CSE1_HIL_u_P.Velocity_IC[0];
      CSE1_HIL_u_X.Velocity_CSTATE[1] = CSE1_HIL_u_P.Velocity_IC[1];
      CSE1_HIL_u_X.Velocity_CSTATE[2] = CSE1_HIL_u_P.Velocity_IC[2];
    }
  }

  CSE1_HIL_u_B.Velocity[0] = CSE1_HIL_u_X.Velocity_CSTATE[0];
  CSE1_HIL_u_B.Velocity[1] = CSE1_HIL_u_X.Velocity_CSTATE[1];
  CSE1_HIL_u_B.Velocity[2] = CSE1_HIL_u_X.Velocity_CSTATE[2];

  /* End of Integrator: '<S9>/Velocity' */
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
  }

  /* Saturate: '<S8>/Saturation3' */
  if (CSE1_HIL_u_B.alpha_VSP1 > CSE1_HIL_u_P.Saturation3_UpperSat) {
    rtb_Saturation3 = CSE1_HIL_u_P.Saturation3_UpperSat;
  } else if (CSE1_HIL_u_B.alpha_VSP1 < CSE1_HIL_u_P.Saturation3_LowerSat) {
    rtb_Saturation3 = CSE1_HIL_u_P.Saturation3_LowerSat;
  } else {
    rtb_Saturation3 = CSE1_HIL_u_B.alpha_VSP1;
  }

  /* End of Saturate: '<S8>/Saturation3' */

  /* Saturate: '<S8>/Saturation' */
  if (CSE1_HIL_u_B.u_VSP1 > CSE1_HIL_u_P.Saturation_UpperSat) {
    rtb_Saturation = CSE1_HIL_u_P.Saturation_UpperSat;
  } else if (CSE1_HIL_u_B.u_VSP1 < CSE1_HIL_u_P.Saturation_LowerSat) {
    rtb_Saturation = CSE1_HIL_u_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = CSE1_HIL_u_B.u_VSP1;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* MATLAB Function: '<S8>/VSP' */
  CSE1_HIL_u_VSP(rtb_Saturation3, rtb_Saturation, &CSE1_HIL_u_B.sf_VSP);

  /* Saturate: '<S8>/Saturation4' */
  if (CSE1_HIL_u_B.alpha_VSP2 > CSE1_HIL_u_P.Saturation4_UpperSat) {
    rtb_Saturation4 = CSE1_HIL_u_P.Saturation4_UpperSat;
  } else if (CSE1_HIL_u_B.alpha_VSP2 < CSE1_HIL_u_P.Saturation4_LowerSat) {
    rtb_Saturation4 = CSE1_HIL_u_P.Saturation4_LowerSat;
  } else {
    rtb_Saturation4 = CSE1_HIL_u_B.alpha_VSP2;
  }

  /* End of Saturate: '<S8>/Saturation4' */

  /* Saturate: '<S8>/Saturation1' */
  if (CSE1_HIL_u_B.u_VSP2 > CSE1_HIL_u_P.Saturation1_UpperSat) {
    rtb_Saturation1 = CSE1_HIL_u_P.Saturation1_UpperSat;
  } else if (CSE1_HIL_u_B.u_VSP2 < CSE1_HIL_u_P.Saturation1_LowerSat) {
    rtb_Saturation1 = CSE1_HIL_u_P.Saturation1_LowerSat;
  } else {
    rtb_Saturation1 = CSE1_HIL_u_B.u_VSP2;
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* MATLAB Function: '<S8>/VSP1' */
  CSE1_HIL_u_VSP(rtb_Saturation4, rtb_Saturation1, &CSE1_HIL_u_B.sf_VSP1);

  /* Sum: '<S8>/Sum' */
  CSE1_HIL_u_B.Sum = CSE1_HIL_u_B.sf_VSP.F_x + CSE1_HIL_u_B.sf_VSP1.F_x;

  /* Saturate: '<S8>/Saturation2' */
  if (CSE1_HIL_u_B.u_BT > CSE1_HIL_u_P.Saturation2_UpperSat) {
    rtb_Saturation2 = CSE1_HIL_u_P.Saturation2_UpperSat;
  } else if (CSE1_HIL_u_B.u_BT < CSE1_HIL_u_P.Saturation2_LowerSat) {
    rtb_Saturation2 = CSE1_HIL_u_P.Saturation2_LowerSat;
  } else {
    rtb_Saturation2 = CSE1_HIL_u_B.u_BT;
  }

  /* End of Saturate: '<S8>/Saturation2' */

  /* MATLAB Function: '<S8>/Bow thruster' */
  /* MATLAB Function 'Simulator_CSE1/Command2force/Bow thruster': '<S10>:1' */
  /* '<S10>:1:3' */
  /*  Thruster characteristics */
  if (rtb_Saturation2 > 0.0) {
    /* '<S10>:1:5' */
    /* '<S10>:1:6' */
    /* '<S10>:1:7' */
    /* '<S10>:1:8' */
    /* '<S10>:1:9' */
    /* '<S10>:1:10' */
    /* '<S10>:1:11' */
    rtb_Saturation2 = -(exp(-(rtb_Saturation2 + 0.059) * 0.193) * -548.0 + exp
                        (-(rtb_Saturation2 + 0.059) * 0.1992) * 548.2);
  } else if (rtb_Saturation2 < 0.0) {
    /* '<S10>:1:12' */
    /* '<S10>:1:13' */
    /* '<S10>:1:14' */
    /* '<S10>:1:15' */
    /* '<S10>:1:16' */
    /* '<S10>:1:17' */
    /* '<S10>:1:18' */
    rtb_Saturation2 = exp((rtb_Saturation2 - 0.059) * 0.193) * -548.0 + exp
      ((rtb_Saturation2 - 0.059) * 0.1992) * 548.2;
  } else {
    /* '<S10>:1:20' */
    rtb_Saturation2 = 0.0;
  }

  /*  Thruster losses due to forward speed */
  /* '<S10>:1:23' */
  /* '<S10>:1:24' */
  /* '<S10>:1:25' */
  /* '<S10>:1:26' */
  /* '<S10>:1:27' */
  /* '<S10>:1:28' */
  rtb_Saturation2 = (atan(-10.22 * CSE1_HIL_u_B.Velocity[0] + 2.947) * 0.3075 +
                     0.7561) * rtb_Saturation2 / 1.1385 * 2.62 / 2.7629;

  /* End of MATLAB Function: '<S8>/Bow thruster' */

  /* Sum: '<S8>/Sum1' */
  /* 2019 changes- Some add-hock changes, because it did not make sense previously.  */
  rtb_Sum1 = CSE1_HIL_u_B.sf_VSP.F_y + CSE1_HIL_u_B.sf_VSP1.F_y;

  /* Sum: '<S8>/Add1' */
  CSE1_HIL_u_B.Add1 = rtb_Saturation2 + rtb_Sum1;
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
    /* Gain: '<S8>/Gain1' incorporates:
     *  Constant: '<S8>/L_VSP'
     */
    CSE1_HIL_u_B.Gain1 = CSE1_HIL_u_P.Gain1_Gain * CSE1_HIL_u_P.L_VSP_Value;
  }

  /* Sum: '<S8>/Add' incorporates:
   *  Constant: '<S8>/L_BTX'
   *  Constant: '<S8>/L_VSPy'
   *  Gain: '<S8>/Gain'
   *  Product: '<S8>/Multiply'
   *  Product: '<S8>/Multiply1'
   *  Product: '<S8>/Multiply2'
   *  Product: '<S8>/Multiply3'
   */
  CSE1_HIL_u_B.Add = ((CSE1_HIL_u_P.L_VSPy_Value * CSE1_HIL_u_B.sf_VSP.F_x *
                       CSE1_HIL_u_P.Gain_Gain + rtb_Saturation2 *
                       CSE1_HIL_u_P.L_BTX_Value) + rtb_Sum1 * CSE1_HIL_u_B.Gain1)
    + CSE1_HIL_u_P.L_VSPy_Value * CSE1_HIL_u_B.sf_VSP1.F_x;

  /* MATLAB Function: '<S9>/kinetics' incorporates:
   *  SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Simulator_CSE1/EquationsOfMotion_FossenModel/kinetics': '<S14>:1' */
  /* '<S14>:1:75' */
  /* '<S14>:1:3' */
  /* '<S14>:1:4' */
  /* '<S14>:1:5' */
  /* '<S14>:1:7' */
  /*  MATRICES  */
  /* changed m from 14.79 to 14.11 */
  /* '<S14>:1:11' */
  /*  x_g  =  0.0460; % Table B.1 */
  /*  Added mass */
  /* changed Y_vd from -1.0 to -10.0 */
  /* '<S14>:1:15' */
  /*  Table B.1 */
  /* '<S14>:1:16' */
  /*  Table B.1 */
  /* '<S14>:1:17' */
  /*  Table B.1 */
  /*  Total mass matrix */
  /*  noted as Y_rd in handbook, but same value */
  /*  Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S14>:1:32' */
  /* '<S14>:1:33' */
  /* '<S14>:1:34' */
  /* '<S14>:1:36' */
  /*  Y_r */
  /* '<S14>:1:37' */
  /*  Y_rr */
  /* '<S14>:1:38' */
  /* '<S14>:1:40' */
  /*  Y_rv, Y_vr */
  /* '<S14>:1:42' */
  /*  N_r */
  /* '<S14>:1:43' */
  /*  N_rr */
  /* '<S14>:1:44' */
  /* '<S14>:1:46' */
  /*  N_rv, N_vr */
  /*  Correolis matrix */
  /* '<S14>:1:49' */
  rtb_Saturation2 = -24.11 * CSE1_HIL_u_B.Velocity[1] - 0.529125 *
    CSE1_HIL_u_B.Velocity[2];

  /* '<S14>:1:50' */
  rtb_Sum1 = 16.11 * CSE1_HIL_u_B.Velocity[0];

  /* '<S14>:1:51' */
  /*  Assembly of the damping matrix */
  /* should be abs(u), abs(v) some places, only positive values?  */
  /* '<S14>:1:58' */
  /* '<S14>:1:59' */
  /* '<S14>:1:60' */
  /*  using abs(r) */
  /* '<S14>:1:63' */
  /* '<S14>:1:64' */
  /* D    = [d_11 d_12 0      vet ikke hvorfor d_12 er her */
  /*         0    d_22 d_23 */
  /*         0    d_32 d_33]; */
  /* '<S14>:1:69' */
  /*  CALCULATION */
  /* '<S14>:1:75' */
  tmp[0] = 0.0;
  tmp[3] = 0.0;
  tmp[6] = rtb_Saturation2;
  tmp[1] = 0.0;
  tmp[4] = 0.0;
  tmp[7] = rtb_Sum1;
  tmp[2] = -rtb_Saturation2;
  tmp[5] = -rtb_Sum1;
  tmp[8] = 0.0;
  tmp_0[0] = (0.6555 - 0.3545 * CSE1_HIL_u_B.Velocity[0]) -
    CSE1_HIL_u_B.Velocity[0] * CSE1_HIL_u_B.Velocity[0] * -3.787;
  tmp_0[3] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[4] = ((1.33 - -2.776 * CSE1_HIL_u_B.Velocity[1]) -
              CSE1_HIL_u_B.Velocity[1] * CSE1_HIL_u_B.Velocity[1] * -64.91) -
    -0.805 * fabs(CSE1_HIL_u_B.Velocity[2]);
  tmp_0[7] = ((7.25 - -3.45 * fabs(CSE1_HIL_u_B.Velocity[2])) -
              CSE1_HIL_u_B.Velocity[2] * CSE1_HIL_u_B.Velocity[2] * 0.0) -
    -0.845 * fabs(CSE1_HIL_u_B.Velocity[1]);
  tmp_0[2] = 0.0;
  tmp_0[5] = ((-0.0 - -0.2088 * CSE1_HIL_u_B.Velocity[1]) -
              CSE1_HIL_u_B.Velocity[1] * CSE1_HIL_u_B.Velocity[1] * 0.0) - 0.13 *
    fabs(CSE1_HIL_u_B.Velocity[2]);
  tmp_0[8] = ((1.9 - -0.75 * fabs(CSE1_HIL_u_B.Velocity[2])) -
              CSE1_HIL_u_B.Velocity[2] * CSE1_HIL_u_B.Velocity[2] * 0.0) - 0.08 *
    fabs(CSE1_HIL_u_B.Velocity[1]);
  for (i = 0; i < 3; i++) {
    tmp_1[3 * i] = tmp[3 * i] + tmp_0[3 * i];
    tmp_1[1 + 3 * i] = tmp[3 * i + 1] + tmp_0[3 * i + 1];
    tmp_1[2 + 3 * i] = tmp[3 * i + 2] + tmp_0[3 * i + 2];
  }

  rtb_TmpSignalConversionAtSFun_0[0] = CSE1_HIL_u_B.Sum;
  rtb_TmpSignalConversionAtSFun_0[1] = CSE1_HIL_u_B.Add1;
  rtb_TmpSignalConversionAtSFun_0[2] = CSE1_HIL_u_B.Add;
  for (i = 0; i < 3; i++) {
    B[i] = rtb_TmpSignalConversionAtSFun_0[i] - (tmp_1[i + 6] *
      CSE1_HIL_u_B.Velocity[2] + (tmp_1[i + 3] * CSE1_HIL_u_B.Velocity[1] +
      tmp_1[i] * CSE1_HIL_u_B.Velocity[0]));
  }

  CSE1_HIL_u_B.nu_dot[0] = B[0];
  CSE1_HIL_u_B.nu_dot[1] = B[1] - CSE1_HIL_u_B.nu_dot[0] * 0.0;
  CSE1_HIL_u_B.nu_dot[2] = (B[2] - CSE1_HIL_u_B.nu_dot[0] * 0.0) -
    CSE1_HIL_u_B.nu_dot[1] * 0.021946287847366238;
  CSE1_HIL_u_B.nu_dot[2] /= 2.7483876704427623;
  CSE1_HIL_u_B.nu_dot[0] -= CSE1_HIL_u_B.nu_dot[2] * 0.0;
  CSE1_HIL_u_B.nu_dot[1] -= CSE1_HIL_u_B.nu_dot[2] * 0.529125;
  CSE1_HIL_u_B.nu_dot[1] /= 24.11;
  CSE1_HIL_u_B.nu_dot[0] -= CSE1_HIL_u_B.nu_dot[1] * 0.0;
  CSE1_HIL_u_B.nu_dot[0] /= 16.11;

  /* End of MATLAB Function: '<S9>/kinetics' */
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
  }

  /* MATLAB Function: '<S9>/kinematics' */
  /* MATLAB Function 'Simulator_CSE1/EquationsOfMotion_FossenModel/kinematics': '<S13>:1' */
  /* '<S13>:1:7' */
  /* '<S13>:1:3' */
  /* '<S13>:1:5' */
  /* '<S13>:1:9' */
  tmp_2[0] = cos(CSE1_HIL_u_B.Position[2]);
  tmp_2[3] = -sin(CSE1_HIL_u_B.Position[2]);
  tmp_2[6] = 0.0;
  tmp_2[1] = sin(CSE1_HIL_u_B.Position[2]);
  tmp_2[4] = cos(CSE1_HIL_u_B.Position[2]);
  tmp_2[7] = 0.0;
  tmp_2[2] = 0.0;
  tmp_2[5] = 0.0;
  tmp_2[8] = 1.0;
  for (i = 0; i < 3; i++) {
    CSE1_HIL_u_B.eta_dot[i] = 0.0;
    CSE1_HIL_u_B.eta_dot[i] += tmp_2[i] * CSE1_HIL_u_B.Velocity[0];
    CSE1_HIL_u_B.eta_dot[i] += tmp_2[i + 3] * CSE1_HIL_u_B.Velocity[1];
    CSE1_HIL_u_B.eta_dot[i] += tmp_2[i + 6] * CSE1_HIL_u_B.Velocity[2];
  }

  /* End of MATLAB Function: '<S9>/kinematics' */
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
  }
}

/* Model update function */
void CSE1_HIL_u_update(void)
{
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
    /* Update for Memory: '<S3>/Memory3' */
    CSE1_HIL_u_DW.Memory3_PreviousInput = CSE1_HIL_u_B.x_0;

    /* Update for Memory: '<S3>/Memory4' */
    CSE1_HIL_u_DW.Memory4_PreviousInput = CSE1_HIL_u_B.y_0;

    /* Update for Memory: '<S3>/Memory5' */
    CSE1_HIL_u_DW.Memory5_PreviousInput = CSE1_HIL_u_B.psi_0;
  }

  /* Update for Integrator: '<S9>/Position' */
  CSE1_HIL_u_DW.Position_IWORK = 0;
  if (rtmIsMajorTimeStep(CSE1_HIL_u_M)) {
    rt_ertODEUpdateContinuousStates(&CSE1_HIL_u_M->solverInfo);
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
  if (!(++CSE1_HIL_u_M->Timing.clockTick0)) {
    ++CSE1_HIL_u_M->Timing.clockTickH0;
  }

  CSE1_HIL_u_M->Timing.t[0] = rtsiGetSolverStopTime(&CSE1_HIL_u_M->solverInfo);

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
    if (!(++CSE1_HIL_u_M->Timing.clockTick1)) {
      ++CSE1_HIL_u_M->Timing.clockTickH1;
    }

    CSE1_HIL_u_M->Timing.t[1] = CSE1_HIL_u_M->Timing.clockTick1 *
      CSE1_HIL_u_M->Timing.stepSize1 + CSE1_HIL_u_M->Timing.clockTickH1 *
      CSE1_HIL_u_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void CSE1_HIL_u_derivatives(void)
{
  XDot_CSE1_HIL_u_T *_rtXdot;
  _rtXdot = ((XDot_CSE1_HIL_u_T *) CSE1_HIL_u_M->derivs);

  /* Derivatives for Integrator: '<S9>/Position' */
  _rtXdot->Position_CSTATE[0] = CSE1_HIL_u_B.eta_dot[0];

  /* Derivatives for Integrator: '<S9>/Velocity' */
  _rtXdot->Velocity_CSTATE[0] = CSE1_HIL_u_B.nu_dot[0];

  /* Derivatives for Integrator: '<S9>/Position' */
  _rtXdot->Position_CSTATE[1] = CSE1_HIL_u_B.eta_dot[1];

  /* Derivatives for Integrator: '<S9>/Velocity' */
  _rtXdot->Velocity_CSTATE[1] = CSE1_HIL_u_B.nu_dot[1];

  /* Derivatives for Integrator: '<S9>/Position' */
  _rtXdot->Position_CSTATE[2] = CSE1_HIL_u_B.eta_dot[2];

  /* Derivatives for Integrator: '<S9>/Velocity' */
  _rtXdot->Velocity_CSTATE[2] = CSE1_HIL_u_B.nu_dot[2];
}

/* Model initialize function */
void CSE1_HIL_u_initialize(void)
{
  CSE1_HIL_u_PrevZCX.Position_Reset_ZCE = UNINITIALIZED_ZCSIG;
  CSE1_HIL_u_PrevZCX.Velocity_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S3>/Memory3' */
  CSE1_HIL_u_DW.Memory3_PreviousInput = CSE1_HIL_u_P.Memory3_X0;

  /* InitializeConditions for Memory: '<S3>/Memory4' */
  CSE1_HIL_u_DW.Memory4_PreviousInput = CSE1_HIL_u_P.Memory4_X0;

  /* InitializeConditions for Memory: '<S3>/Memory5' */
  CSE1_HIL_u_DW.Memory5_PreviousInput = CSE1_HIL_u_P.Memory5_X0;

  /* InitializeConditions for Integrator: '<S9>/Position' */
  if (rtmIsFirstInitCond(CSE1_HIL_u_M)) {
    CSE1_HIL_u_X.Position_CSTATE[0] = 0.0;
    CSE1_HIL_u_X.Position_CSTATE[1] = 0.0;
    CSE1_HIL_u_X.Position_CSTATE[2] = 0.0;
  }

  CSE1_HIL_u_DW.Position_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S9>/Position' */

  /* InitializeConditions for Integrator: '<S9>/Velocity' */
  CSE1_HIL_u_X.Velocity_CSTATE[0] = CSE1_HIL_u_P.Velocity_IC[0];
  CSE1_HIL_u_X.Velocity_CSTATE[1] = CSE1_HIL_u_P.Velocity_IC[1];
  CSE1_HIL_u_X.Velocity_CSTATE[2] = CSE1_HIL_u_P.Velocity_IC[2];

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(CSE1_HIL_u_M)) {
    rtmSetFirstInitCond(CSE1_HIL_u_M, 0);
  }
}

/* Model terminate function */
void CSE1_HIL_u_terminate(void)
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
  CSE1_HIL_u_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  CSE1_HIL_u_update();
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
  CSE1_HIL_u_initialize();
}

void MdlTerminate(void)
{
  CSE1_HIL_u_terminate();
}

/* Registration function */
RT_MODEL_CSE1_HIL_u_T *CSE1_HIL_u(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CSE1_HIL_u_M, 0,
                sizeof(RT_MODEL_CSE1_HIL_u_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CSE1_HIL_u_M->solverInfo,
                          &CSE1_HIL_u_M->Timing.simTimeStep);
    rtsiSetTPtr(&CSE1_HIL_u_M->solverInfo, &rtmGetTPtr(CSE1_HIL_u_M));
    rtsiSetStepSizePtr(&CSE1_HIL_u_M->solverInfo,
                       &CSE1_HIL_u_M->Timing.stepSize0);
    rtsiSetdXPtr(&CSE1_HIL_u_M->solverInfo, &CSE1_HIL_u_M->derivs);
    rtsiSetContStatesPtr(&CSE1_HIL_u_M->solverInfo, (real_T **)
                         &CSE1_HIL_u_M->contStates);
    rtsiSetNumContStatesPtr(&CSE1_HIL_u_M->solverInfo,
      &CSE1_HIL_u_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CSE1_HIL_u_M->solverInfo,
      &CSE1_HIL_u_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CSE1_HIL_u_M->solverInfo,
      &CSE1_HIL_u_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CSE1_HIL_u_M->solverInfo,
      &CSE1_HIL_u_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&CSE1_HIL_u_M->solverInfo, (&rtmGetErrorStatus
      (CSE1_HIL_u_M)));
    rtsiSetRTModelPtr(&CSE1_HIL_u_M->solverInfo, CSE1_HIL_u_M);
  }

  rtsiSetSimTimeStep(&CSE1_HIL_u_M->solverInfo, MAJOR_TIME_STEP);
  CSE1_HIL_u_M->intgData.y = CSE1_HIL_u_M->odeY;
  CSE1_HIL_u_M->intgData.f[0] = CSE1_HIL_u_M->odeF[0];
  CSE1_HIL_u_M->intgData.f[1] = CSE1_HIL_u_M->odeF[1];
  CSE1_HIL_u_M->intgData.f[2] = CSE1_HIL_u_M->odeF[2];
  CSE1_HIL_u_M->intgData.f[3] = CSE1_HIL_u_M->odeF[3];
  CSE1_HIL_u_M->contStates = ((real_T *) &CSE1_HIL_u_X);
  rtsiSetSolverData(&CSE1_HIL_u_M->solverInfo, (void *)&CSE1_HIL_u_M->intgData);
  rtsiSetSolverName(&CSE1_HIL_u_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CSE1_HIL_u_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    CSE1_HIL_u_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CSE1_HIL_u_M->Timing.sampleTimes = (&CSE1_HIL_u_M->Timing.sampleTimesArray[0]);
    CSE1_HIL_u_M->Timing.offsetTimes = (&CSE1_HIL_u_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CSE1_HIL_u_M->Timing.sampleTimes[0] = (0.0);
    CSE1_HIL_u_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    CSE1_HIL_u_M->Timing.offsetTimes[0] = (0.0);
    CSE1_HIL_u_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(CSE1_HIL_u_M, &CSE1_HIL_u_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CSE1_HIL_u_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    CSE1_HIL_u_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CSE1_HIL_u_M, -1);
  CSE1_HIL_u_M->Timing.stepSize0 = 0.01;
  CSE1_HIL_u_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(CSE1_HIL_u_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    CSE1_HIL_u_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(CSE1_HIL_u_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(CSE1_HIL_u_M->rtwLogInfo, (NULL));
    rtliSetLogT(CSE1_HIL_u_M->rtwLogInfo, "tout");
    rtliSetLogX(CSE1_HIL_u_M->rtwLogInfo, "");
    rtliSetLogXFinal(CSE1_HIL_u_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(CSE1_HIL_u_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(CSE1_HIL_u_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(CSE1_HIL_u_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(CSE1_HIL_u_M->rtwLogInfo, 1);
    rtliSetLogY(CSE1_HIL_u_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(CSE1_HIL_u_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(CSE1_HIL_u_M->rtwLogInfo, (NULL));
  }

  CSE1_HIL_u_M->solverInfoPtr = (&CSE1_HIL_u_M->solverInfo);
  CSE1_HIL_u_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&CSE1_HIL_u_M->solverInfo, 0.01);
  rtsiSetSolverMode(&CSE1_HIL_u_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  CSE1_HIL_u_M->blockIO = ((void *) &CSE1_HIL_u_B);
  (void) memset(((void *) &CSE1_HIL_u_B), 0,
                sizeof(B_CSE1_HIL_u_T));

  /* parameters */
  CSE1_HIL_u_M->defaultParam = ((real_T *)&CSE1_HIL_u_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &CSE1_HIL_u_X;
    CSE1_HIL_u_M->contStates = (x);
    (void) memset((void *)&CSE1_HIL_u_X, 0,
                  sizeof(X_CSE1_HIL_u_T));
  }

  /* states (dwork) */
  CSE1_HIL_u_M->dwork = ((void *) &CSE1_HIL_u_DW);
  (void) memset((void *)&CSE1_HIL_u_DW, 0,
                sizeof(DW_CSE1_HIL_u_T));

  /* Initialize Sizes */
  CSE1_HIL_u_M->Sizes.numContStates = (6);/* Number of continuous states */
  CSE1_HIL_u_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  CSE1_HIL_u_M->Sizes.numY = (0);      /* Number of model outputs */
  CSE1_HIL_u_M->Sizes.numU = (0);      /* Number of model inputs */
  CSE1_HIL_u_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CSE1_HIL_u_M->Sizes.numSampTimes = (2);/* Number of sample times */
  CSE1_HIL_u_M->Sizes.numBlocks = (61);/* Number of blocks */
  CSE1_HIL_u_M->Sizes.numBlockIO = (26);/* Number of block outputs */
  CSE1_HIL_u_M->Sizes.numBlockPrms = (184);/* Sum of parameter "widths" */
  return CSE1_HIL_u_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : CSE1_HIL_u
 * Model version : 1.48
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Feb 07 14:39:49 2019
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_CSE1_HIL_u
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 24:
    return (( double *)ptr)[subindex];

   case 25:
    return (( double *)ptr)[subindex];

   case 26:
    return (( double *)ptr)[subindex];

   case 27:
    return (( double *)ptr)[subindex];

   case 28:
    return (( double *)ptr)[subindex];

   case 29:
    return (( double *)ptr)[subindex];

   case 30:
    return (( double *)ptr)[subindex];

   case 31:
    return (( double *)ptr)[subindex];

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
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
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 24:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 25:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

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
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern CSE1_HIL_u_rtModel *S;
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

  // CSE1_HIL_u/integrator_reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.integrator_reset, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/u/u_BT
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.u_BT, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/u/u_VSP1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.u_VSP1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/u/u_VSP2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.u_VSP2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/u/alpha_VSP1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.alpha_VSP1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/u/alpha_VSP2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.alpha_VSP2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/u/omega_VSP1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.omega_VSP1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/u/omega_VSP2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.omega_VSP2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/eta_0/psi_0
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.psi_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/eta_0/x_0
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.x_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/eta_0/y_0
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSE1_HIL_u_B.y_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 11;
}

int32_t NumOutputPorts(void)
{
  return 16;
}

double ni_extout[16];

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

  // CSE1_HIL_u/eta/x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Position, 0, 18,
      0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/eta/y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Position, 1, 18,
      0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/eta/psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Position, 2, 18,
      0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu/r: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Velocity, 2, 18,
      0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu/u: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Velocity, 0, 18,
      0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu/v: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Velocity, 1, 18,
      0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu_dot/r_dot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 2, 18, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu_dot/u_dot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 0, 18, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu_dot/v_dot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 1, 18, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu_dot/zeroout: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_P.Constant_Value, 0,
      0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu_dot/r_dot1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 2, 18, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu_dot/u_dot1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 0, 18, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/nu_dot/v_dot1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 1, 18, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/tau/X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Sum, 0, 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/tau/Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Add1, 0, 0, 0);
  } else {
    index += 1;
  }

  // CSE1_HIL_u/tau/N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Add, 0, 0, 0);
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

  // CSE1_HIL_u/eta/x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Position, 0, 18, 0);

  // CSE1_HIL_u/eta/y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Position, 1, 18, 0);

  // CSE1_HIL_u/eta/psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Position, 2, 18, 0);

  // CSE1_HIL_u/nu/r: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Velocity, 2, 18, 0);

  // CSE1_HIL_u/nu/u: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Velocity, 0, 18, 0);

  // CSE1_HIL_u/nu/v: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Velocity, 1, 18, 0);

  // CSE1_HIL_u/nu_dot/r_dot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 2, 18, 0);

  // CSE1_HIL_u/nu_dot/u_dot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 0, 18, 0);

  // CSE1_HIL_u/nu_dot/v_dot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 1, 18, 0);

  // CSE1_HIL_u/nu_dot/zeroout: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_P.Constant_Value, 0,
    0, 0);

  // CSE1_HIL_u/nu_dot/r_dot1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 2, 18, 0);

  // CSE1_HIL_u/nu_dot/u_dot1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 0, 18, 0);

  // CSE1_HIL_u/nu_dot/v_dot1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.nu_dot, 1, 18, 0);

  // CSE1_HIL_u/tau/X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Sum, 0, 0, 0);

  // CSE1_HIL_u/tau/Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Add1, 0, 0, 0);

  // CSE1_HIL_u/tau/N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSE1_HIL_u_B.Add, 0, 0, 0);
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
  { 0, "cse1_hil_u/eta_0/Memory3/X0", offsetof(P_CSE1_HIL_u_T, Memory3_X0), 32,
    1, 2, 0, 0 },

  { 1, "cse1_hil_u/eta_0/Memory4/X0", offsetof(P_CSE1_HIL_u_T, Memory4_X0), 32,
    1, 2, 2, 0 },

  { 2, "cse1_hil_u/eta_0/Memory5/X0", offsetof(P_CSE1_HIL_u_T, Memory5_X0), 32,
    1, 2, 4, 0 },

  { 3,
    "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/Velocity/InitialCondition",
    offsetof(P_CSE1_HIL_u_T, Velocity_IC), 22, 3, 2, 6, 0 },

  { 4, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation3/UpperLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation3_UpperSat), 32, 1, 2, 8, 0 },

  { 5, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation3/LowerLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation3_LowerSat), 32, 1, 2, 10, 0 },

  { 6, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation/UpperLimit", offsetof
    (P_CSE1_HIL_u_T, Saturation_UpperSat), 32, 1, 2, 12, 0 },

  { 7, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation/LowerLimit", offsetof
    (P_CSE1_HIL_u_T, Saturation_LowerSat), 32, 1, 2, 14, 0 },

  { 8, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation4/UpperLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation4_UpperSat), 32, 1, 2, 16, 0 },

  { 9, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation4/LowerLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation4_LowerSat), 32, 1, 2, 18, 0 },

  { 10, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation1/UpperLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation1_UpperSat), 32, 1, 2, 20, 0 },

  { 11, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation1/LowerLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation1_LowerSat), 32, 1, 2, 22, 0 },

  { 12, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation2/UpperLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation2_UpperSat), 32, 1, 2, 24, 0 },

  { 13, "cse1_hil_u/Simulator_CSE1/Command2force/Saturation2/LowerLimit",
    offsetof(P_CSE1_HIL_u_T, Saturation2_LowerSat), 32, 1, 2, 26, 0 },

  { 14, "cse1_hil_u/Simulator_CSE1/Command2force/L_BTX/Value", offsetof
    (P_CSE1_HIL_u_T, L_BTX_Value), 32, 1, 2, 28, 0 },

  { 15, "cse1_hil_u/Simulator_CSE1/Command2force/L_VSPy/Value", offsetof
    (P_CSE1_HIL_u_T, L_VSPy_Value), 32, 1, 2, 30, 0 },

  { 16, "cse1_hil_u/Simulator_CSE1/Command2force/Gain/Gain", offsetof
    (P_CSE1_HIL_u_T, Gain_Gain), 32, 1, 2, 32, 0 },

  { 17, "cse1_hil_u/Simulator_CSE1/Command2force/L_VSP/Value", offsetof
    (P_CSE1_HIL_u_T, L_VSP_Value), 32, 1, 2, 34, 0 },

  { 18, "cse1_hil_u/Simulator_CSE1/Command2force/Gain1/Gain", offsetof
    (P_CSE1_HIL_u_T, Gain1_Gain), 32, 1, 2, 36, 0 },

  { 19, "cse1_hil_u/nu_dot/Constant/Value", offsetof(P_CSE1_HIL_u_T,
    Constant_Value), 32, 1, 2, 38, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 20;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  3, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "cse1_hil_u/integrator_reset", 0, "", offsetof(B_CSE1_HIL_u_T,
    integrator_reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "cse1_hil_u/eta_0/Memory3", 0, "", offsetof(B_CSE1_HIL_u_T, Memory3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "cse1_hil_u/eta_0/Memory4", 0, "", offsetof(B_CSE1_HIL_u_T, Memory4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "cse1_hil_u/eta_0/Memory5", 0, "", offsetof(B_CSE1_HIL_u_T, Memory5) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/Position/(1, 1)",
    0, "", offsetof(B_CSE1_HIL_u_T, Position) + (0*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 5, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/Position/(1, 2)",
    0, "", offsetof(B_CSE1_HIL_u_T, Position) + (1*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 6, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/Position/(1, 3)",
    0, "", offsetof(B_CSE1_HIL_u_T, Position) + (2*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 7, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/Velocity/(1, 1)",
    0, "", offsetof(B_CSE1_HIL_u_T, Velocity) + (0*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 8, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/Velocity/(1, 2)",
    0, "", offsetof(B_CSE1_HIL_u_T, Velocity) + (1*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 9, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/Velocity/(1, 3)",
    0, "", offsetof(B_CSE1_HIL_u_T, Velocity) + (2*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 10, "cse1_hil_u/u/u_BT", 0, "", offsetof(B_CSE1_HIL_u_T, u_BT) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "cse1_hil_u/u/u_VSP1", 0, "", offsetof(B_CSE1_HIL_u_T, u_VSP1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "cse1_hil_u/u/u_VSP2", 0, "", offsetof(B_CSE1_HIL_u_T, u_VSP2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "cse1_hil_u/u/alpha_VSP1", 0, "", offsetof(B_CSE1_HIL_u_T, alpha_VSP1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "cse1_hil_u/u/alpha_VSP2", 0, "", offsetof(B_CSE1_HIL_u_T, alpha_VSP2) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "cse1_hil_u/u/omega_VSP1", 0, "", offsetof(B_CSE1_HIL_u_T, omega_VSP1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "cse1_hil_u/u/omega_VSP2", 0, "", offsetof(B_CSE1_HIL_u_T, omega_VSP2) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "cse1_hil_u/Simulator_CSE1/Command2force/Sum", 0, "", offsetof
    (B_CSE1_HIL_u_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "cse1_hil_u/Simulator_CSE1/Command2force/Add1", 0, "", offsetof
    (B_CSE1_HIL_u_T, Add1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "cse1_hil_u/Simulator_CSE1/Command2force/Gain1", 0, "", offsetof
    (B_CSE1_HIL_u_T, Gain1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "cse1_hil_u/Simulator_CSE1/Command2force/Add", 0, "", offsetof
    (B_CSE1_HIL_u_T, Add) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "cse1_hil_u/eta_0/psi_0", 0, "", offsetof(B_CSE1_HIL_u_T, psi_0) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "cse1_hil_u/eta_0/x_0", 0, "", offsetof(B_CSE1_HIL_u_T, x_0) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "cse1_hil_u/eta_0/y_0", 0, "", offsetof(B_CSE1_HIL_u_T, y_0) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinetics", 0,
    "(1, 1)", offsetof(B_CSE1_HIL_u_T, nu_dot) + (0*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 25, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinetics", 0,
    "(1, 2)", offsetof(B_CSE1_HIL_u_T, nu_dot) + (1*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 26, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinetics", 0,
    "(1, 3)", offsetof(B_CSE1_HIL_u_T, nu_dot) + (2*sizeof(real_T)), BLOCKIO_SIG,
    18, 1, 2, 0, 0 },

  { 27, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinematics", 0,
    "(1, 1)", offsetof(B_CSE1_HIL_u_T, eta_dot) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 28, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinematics", 0,
    "(1, 2)", offsetof(B_CSE1_HIL_u_T, eta_dot) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 29, "cse1_hil_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinematics", 0,
    "(1, 3)", offsetof(B_CSE1_HIL_u_T, eta_dot) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 30, "cse1_hil_u/Simulator_CSE1/Command2force/VSP1", 0, "", offsetof
    (B_CSE1_HIL_u_T, sf_VSP1.F_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 31, "cse1_hil_u/Simulator_CSE1/Command2force/VSP1", 1, "", offsetof
    (B_CSE1_HIL_u_T, sf_VSP1.F_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 32, "cse1_hil_u/Simulator_CSE1/Command2force/VSP", 0, "", offsetof
    (B_CSE1_HIL_u_T, sf_VSP.F_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 33, "cse1_hil_u/Simulator_CSE1/Command2force/VSP", 1, "", offsetof
    (B_CSE1_HIL_u_T, sf_VSP.F_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 34;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 27;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "integrator_reset", 0, EXT_IN, 1, 1, 1 },

  { 2, "u/u_BT", 0, EXT_IN, 1, 1, 1 },

  { 3, "u/u_VSP1", 0, EXT_IN, 1, 1, 1 },

  { 4, "u/u_VSP2", 0, EXT_IN, 1, 1, 1 },

  { 5, "u/alpha_VSP1", 0, EXT_IN, 1, 1, 1 },

  { 6, "u/alpha_VSP2", 0, EXT_IN, 1, 1, 1 },

  { 7, "u/omega_VSP1", 1, EXT_IN, 1, 1, 1 },

  { 8, "u/omega_VSP2", 1, EXT_IN, 1, 1, 1 },

  { 9, "eta_0/psi_0", 1, EXT_IN, 1, 1, 1 },

  { 10, "eta_0/x_0", 1, EXT_IN, 1, 1, 1 },

  { 11, "eta_0/y_0", 1, EXT_IN, 1, 1, 1 },

  { 1, "eta/x", 0, EXT_OUT, 1, 1, 1 },

  { 2, "eta/y", 0, EXT_OUT, 1, 1, 1 },

  { 3, "eta/psi", 0, EXT_OUT, 1, 1, 1 },

  { 4, "nu/r", 0, EXT_OUT, 1, 1, 1 },

  { 5, "nu/u", 0, EXT_OUT, 1, 1, 1 },

  { 6, "nu/v", 0, EXT_OUT, 1, 1, 1 },

  { 7, "nu_dot/r_dot", 0, EXT_OUT, 1, 1, 1 },

  { 8, "nu_dot/u_dot", 0, EXT_OUT, 1, 1, 1 },

  { 9, "nu_dot/v_dot", 0, EXT_OUT, 1, 1, 1 },

  { 10, "nu_dot/zeroout", 1, EXT_OUT, 1, 1, 1 },

  { 11, "nu_dot/r_dot1", 0, EXT_OUT, 1, 1, 1 },

  { 12, "nu_dot/u_dot1", 0, EXT_OUT, 1, 1, 1 },

  { 13, "nu_dot/v_dot1", 0, EXT_OUT, 1, 1, 1 },

  { 14, "tau/X", 0, EXT_OUT, 1, 1, 1 },

  { 15, "tau/Y", 0, EXT_OUT, 1, 1, 1 },

  { 16, "tau/N", 0, EXT_OUT, 1, 1, 1 },

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
  "CSE1_HIL_u";
static const char* NI_CompiledModelVersion = "1.48";
static const char* NI_CompiledModelDateTime = "Thu Feb 07 14:39:49 2019";
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
  memcpy(&rtParameter[0], &CSE1_HIL_u_P, sizeof(P_CSE1_HIL_u_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka CSE1_HIL_u_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_CSE1_HIL_u_T));
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
             (P_CSE1_HIL_u_T));
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
               (P_CSE1_HIL_u_T));
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
             (P_CSE1_HIL_u_T));
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
           (P_CSE1_HIL_u_T));
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
           (P_CSE1_HIL_u_T));
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
      *numContStates = 6;
      *numDiscStates = 327;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(CSE1_HIL_u_X.Position_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Position_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(CSE1_HIL_u_X.Position_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Position_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(CSE1_HIL_u_X.Position_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Position_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(CSE1_HIL_u_X.Velocity_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Velocity_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(CSE1_HIL_u_X.Velocity_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Velocity_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(CSE1_HIL_u_X.Velocity_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Velocity_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&CSE1_HIL_u_DW.integrator_reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&CSE1_HIL_u_DW.integrator_reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&CSE1_HIL_u_DW.Memory3_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&CSE1_HIL_u_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&CSE1_HIL_u_DW.Memory4_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&CSE1_HIL_u_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&CSE1_HIL_u_DW.Memory5_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&CSE1_HIL_u_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.r_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.r_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.v_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.v_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_BT_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_VSP1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_VSP2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.omega_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.omega_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.r_dot_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.r_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_dot_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.v_dot_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.v_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.zeroout_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.zeroout_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.r_dot1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.r_dot1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_dot1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_dot1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.v_dot1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.v_dot1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.N_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.psi_0_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.x_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.y_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.y_0_DWORK1");
    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&CSE1_HIL_u_DW.integrator_reset_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&CSE1_HIL_u_DW.integrator_reset_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.x_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.x_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.y_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.y_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.psi_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.psi_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.r_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.r_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.v_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.v_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_BT_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_VSP1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_VSP2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.omega_VSP1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.omega_VSP2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.r_dot_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.r_dot_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_dot_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_dot_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.v_dot_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.v_dot_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.zeroout_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.zeroout_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.r_dot1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.r_dot1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.u_dot1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.u_dot1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.v_dot1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.v_dot1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.X_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.X_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.Y_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.Y_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.N_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.N_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.psi_0_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.x_0_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.x_0_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSE1_HIL_u_DW.y_0_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSE1_HIL_u_DW.y_0_DWORK2");
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
    NIRT_SetValueByDataType(&(CSE1_HIL_u_X.Position_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(CSE1_HIL_u_X.Position_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(CSE1_HIL_u_X.Position_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(CSE1_HIL_u_X.Velocity_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(CSE1_HIL_u_X.Velocity_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(CSE1_HIL_u_X.Velocity_CSTATE), 2, contStates[idx++],
      0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.integrator_reset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.Memory4_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.Memory5_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.r_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.v_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_BT_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.omega_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.omega_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.r_dot_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_dot_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.v_dot_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.zeroout_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.r_dot1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_dot1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.v_dot1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.X_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.Y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.N_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.psi_0_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.x_0_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSE1_HIL_u_DW.y_0_DWORK1, 0, discStates[idx++], 0,
      0);
    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.integrator_reset_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.x_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.y_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.psi_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.r_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.v_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_BT_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.r_dot_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_dot_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.v_dot_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.zeroout_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.r_dot1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.u_dot1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.v_dot1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.X_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.Y_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.N_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.psi_0_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.x_0_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&CSE1_HIL_u_DW.y_0_DWORK2, count, discStates[idx++],
        19, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_CSE1_HIL_u
