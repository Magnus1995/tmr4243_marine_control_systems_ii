/*
 * CSE1_HIL_u_private.h
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

#ifndef RTW_HEADER_CSE1_HIL_u_private_h_
#define RTW_HEADER_CSE1_HIL_u_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "CSE1_HIL_u.h"

extern void CSE1_HIL_u_VSP(real_T rtu_alpha, real_T rtu_u_VSP,
  B_VSP_CSE1_HIL_u_T *localB);

/* private model entry point functions */
extern void CSE1_HIL_u_derivatives(void);

#endif                                 /* RTW_HEADER_CSE1_HIL_u_private_h_ */
