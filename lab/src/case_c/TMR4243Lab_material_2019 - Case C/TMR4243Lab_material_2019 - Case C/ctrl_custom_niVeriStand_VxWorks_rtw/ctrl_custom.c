/*
 * ctrl_custom.c
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

/* Block signals (auto storage) */
B_ctrl_custom_T ctrl_custom_B;

/* Continuous states */
X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
DW_ctrl_custom_T ctrl_custom_DW;

/* Real-time model */
RT_MODEL_ctrl_custom_T ctrl_custom_M_;
RT_MODEL_ctrl_custom_T *const ctrl_custom_M = &ctrl_custom_M_;

/* Forward declaration for local functions */
static real_T ctrl_custom_xnrm2(int32_T n, const real_T x[9], int32_T ix0);
static real_T ctrl_custom_xnrm2_l(int32_T n, const real_T x[3], int32_T ix0);
static void ctrl_custom_xaxpy_gz(int32_T n, real_T a, const real_T x[3], int32_T
  ix0, real_T y[9], int32_T iy0);
static void ctrl_custom_xaxpy_g(int32_T n, real_T a, const real_T x[9], int32_T
  ix0, real_T y[3], int32_T iy0);
static void ctrl_custom_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_custom_xswap(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_custom_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ctrl_custom_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static real_T ctrl_custom_xdotc(int32_T n, const real_T x[9], int32_T ix0, const
  real_T y[9], int32_T iy0);
static void ctrl_custom_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0);
static void ctrl_custom_svd(const real_T A[9], real_T U[9], real_T S[9], real_T
  V[9]);

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
  int_T nXc = 9;
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

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static real_T ctrl_custom_xnrm2(int32_T n, const real_T x[9], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 2.2250738585072014E-308;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static real_T ctrl_custom_xnrm2_l(int32_T n, const real_T x[3], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 2.2250738585072014E-308;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_xaxpy_gz(int32_T n, real_T a, const real_T x[3], int32_T
  ix0, real_T y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_xaxpy_g(int32_T n, real_T a, const real_T x[9], int32_T
  ix0, real_T y[3], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_xswap(real_T x[9], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale;
  real_T ads;
  real_T bds;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    scale = 0.0;
    absa = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      absa = *s;
    } else if (*c != 0.0) {
      absa = 1.0 / *c;
    } else {
      absa = 1.0;
    }
  }

  *a = scale;
  *b = absa;
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static real_T ctrl_custom_xdotc(int32_T n, const real_T x[9], int32_T ix0, const
  real_T y[9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (!(n < 1)) {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S7>/BK inverse ' */
static void ctrl_custom_svd(const real_T A[9], real_T U[9], real_T S[9], real_T
  V[9])
{
  real_T b_A[9];
  real_T s[3];
  real_T e[3];
  real_T work[3];
  real_T Vf[9];
  int32_T q;
  boolean_T apply_transform;
  int32_T m;
  int32_T iter;
  real_T snorm;
  real_T ztest0;
  int32_T kase;
  int32_T qs;
  real_T ztest;
  real_T smm1;
  real_T emm1;
  real_T sqds;
  real_T shift;
  int32_T k_ii;
  real_T varargin_1[5];
  boolean_T exitg1;
  boolean_T exitg2;
  int32_T exitg3;
  e[0] = 0.0;
  work[0] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (iter = 0; iter < 9; iter++) {
    b_A[iter] = A[iter];
    U[iter] = 0.0;
    Vf[iter] = 0.0;
  }

  iter = 0;
  apply_transform = false;
  snorm = ctrl_custom_xnrm2(3, b_A, 1);
  if (snorm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      s[0] = -snorm;
    } else {
      s[0] = snorm;
    }

    if (fabs(s[0]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / s[0];
      for (qs = 0; qs + 1 < 4; qs++) {
        b_A[qs] *= snorm;
      }
    } else {
      for (qs = 0; qs + 1 < 4; qs++) {
        b_A[qs] /= s[0];
      }
    }

    b_A[0]++;
    s[0] = -s[0];
  } else {
    s[0] = 0.0;
  }

  for (q = 1; q + 1 < 4; q++) {
    qs = 3 * q;
    if (apply_transform) {
      ctrl_custom_xaxpy(3, -(ctrl_custom_xdotc(3, b_A, 1, b_A, qs + 1) / b_A[0]),
                        1, b_A, qs + 1);
    }

    e[q] = b_A[qs];
  }

  while (iter + 1 < 4) {
    U[iter] = b_A[iter];
    iter++;
  }

  snorm = ctrl_custom_xnrm2_l(2, e, 2);
  if (snorm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      snorm = -snorm;
    }

    e[0] = snorm;
    if (fabs(snorm) >= 1.0020841800044864E-292) {
      snorm = 1.0 / snorm;
      for (iter = 1; iter + 1 < 4; iter++) {
        e[iter] *= snorm;
      }
    } else {
      for (iter = 1; iter + 1 < 4; iter++) {
        e[iter] /= snorm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (iter = 2; iter < 4; iter++) {
      work[iter - 1] = 0.0;
    }

    for (iter = 1; iter + 1 < 4; iter++) {
      ctrl_custom_xaxpy_g(2, e[iter], b_A, 3 * iter + 2, work, 2);
    }

    for (iter = 1; iter + 1 < 4; iter++) {
      ctrl_custom_xaxpy_gz(2, -e[iter] / e[1], work, 2, b_A, 3 * iter + 2);
    }
  }

  for (iter = 1; iter + 1 < 4; iter++) {
    Vf[iter] = e[iter];
  }

  apply_transform = false;
  snorm = ctrl_custom_xnrm2(2, b_A, 5);
  if (snorm > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      s[1] = -snorm;
    } else {
      s[1] = snorm;
    }

    if (fabs(s[1]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / s[1];
      for (qs = 4; qs + 1 < 7; qs++) {
        b_A[qs] *= snorm;
      }
    } else {
      for (qs = 4; qs + 1 < 7; qs++) {
        b_A[qs] /= s[1];
      }
    }

    b_A[4]++;
    s[1] = -s[1];
  } else {
    s[1] = 0.0;
  }

  for (q = 2; q + 1 < 4; q++) {
    qs = 3 * q + 1;
    if (apply_transform) {
      ctrl_custom_xaxpy(2, -(ctrl_custom_xdotc(2, b_A, 5, b_A, qs + 1) / b_A[4]),
                        5, b_A, qs + 1);
    }

    e[q] = b_A[qs];
  }

  for (iter = 1; iter + 1 < 4; iter++) {
    U[iter + 3] = b_A[iter + 3];
  }

  m = 1;
  s[2] = b_A[8];
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (q = 1; q >= 0; q += -1) {
    iter = 3 * q + q;
    if (s[q] != 0.0) {
      for (kase = q + 1; kase + 1 < 4; kase++) {
        qs = (3 * kase + q) + 1;
        ctrl_custom_xaxpy(3 - q, -(ctrl_custom_xdotc(3 - q, U, iter + 1, U, qs) /
          U[iter]), iter + 1, U, qs);
      }

      for (qs = q; qs + 1 < 4; qs++) {
        U[qs + 3 * q] = -U[3 * q + qs];
      }

      U[iter]++;
      iter = 1;
      while (iter <= q) {
        U[3] = 0.0;
        iter = 2;
      }
    } else {
      U[3 * q] = 0.0;
      U[1 + 3 * q] = 0.0;
      U[2 + 3 * q] = 0.0;
      U[iter] = 1.0;
    }
  }

  for (iter = 2; iter >= 0; iter += -1) {
    if ((iter + 1 <= 1) && (e[0] != 0.0)) {
      for (q = 2; q < 4; q++) {
        qs = (q - 1) * 3 + 2;
        ctrl_custom_xaxpy(2, -(ctrl_custom_xdotc(2, Vf, 2, Vf, qs) / Vf[1]), 2,
                          Vf, qs);
      }
    }

    Vf[3 * iter] = 0.0;
    Vf[1 + 3 * iter] = 0.0;
    Vf[2 + 3 * iter] = 0.0;
    Vf[iter + 3 * iter] = 1.0;
  }

  ztest = e[0];
  if (s[0] != 0.0) {
    ztest0 = fabs(s[0]);
    snorm = s[0] / ztest0;
    s[0] = ztest0;
    ztest = e[0] / snorm;
    ctrl_custom_xscal(snorm, U, 1);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[1] *= snorm;
    ctrl_custom_xscal(snorm, Vf, 4);
  }

  e[0] = ztest;
  ztest = b_A[7];
  if (s[1] != 0.0) {
    ztest0 = fabs(s[1]);
    snorm = s[1] / ztest0;
    s[1] = ztest0;
    ztest = b_A[7] / snorm;
    ctrl_custom_xscal(snorm, U, 4);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[2] = b_A[8] * snorm;
    ctrl_custom_xscal(snorm, Vf, 7);
  }

  e[1] = ztest;
  if (s[2] != 0.0) {
    ztest0 = fabs(s[2]);
    snorm = s[2] / ztest0;
    s[2] = ztest0;
    ctrl_custom_xscal(snorm, U, 7);
  }

  e[2] = 0.0;
  iter = 0;
  snorm = 0.0;
  if ((s[0] >= e[0]) || rtIsNaN(e[0])) {
    ztest0 = s[0];
  } else {
    ztest0 = e[0];
  }

  if (!((0.0 >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  if ((s[1] >= ztest) || rtIsNaN(ztest)) {
    ztest = s[1];
  }

  if (!((snorm >= ztest) || rtIsNaN(ztest))) {
    snorm = ztest;
  }

  if (s[2] >= 0.0) {
    ztest0 = s[2];
  } else {
    ztest0 = 0.0;
  }

  if (!((snorm >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  while ((m + 2 > 0) && (!(iter >= 75))) {
    kase = m + 1;
    do {
      exitg3 = 0;
      q = kase;
      if (kase == 0) {
        exitg3 = 1;
      } else {
        ztest0 = fabs(e[kase - 1]);
        if ((ztest0 <= (fabs(s[kase - 1]) + fabs(s[kase])) *
             2.2204460492503131E-16) || ((ztest0 <= 1.0020841800044864E-292) ||
             ((iter > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm)))) {
          e[kase - 1] = 0.0;
          exitg3 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg3 == 0);

    if (m + 1 == kase) {
      kase = 4;
    } else {
      qs = m + 2;
      k_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= kase)) {
        qs = k_ii;
        if (k_ii == kase) {
          exitg2 = true;
        } else {
          ztest0 = 0.0;
          if (k_ii < m + 2) {
            ztest0 = fabs(e[k_ii - 1]);
          }

          if (k_ii > kase + 1) {
            ztest0 += fabs(e[k_ii - 2]);
          }

          ztest = fabs(s[k_ii - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
               1.0020841800044864E-292)) {
            s[k_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            k_ii--;
          }
        }
      }

      if (qs == kase) {
        kase = 3;
      } else if (m + 2 == qs) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      ztest0 = e[m];
      e[m] = 0.0;
      for (qs = m; qs + 1 >= q + 1; qs--) {
        ztest = s[qs];
        ctrl_custom_xrotg(&ztest, &ztest0, &sqds, &smm1);
        s[qs] = ztest;
        if (qs + 1 > q + 1) {
          ztest0 = -smm1 * e[0];
          e[0] *= sqds;
        }

        ctrl_custom_xrot(Vf, 1 + 3 * qs, 1 + 3 * (m + 1), sqds, smm1);
      }
      break;

     case 2:
      ztest0 = e[q - 1];
      e[q - 1] = 0.0;
      for (qs = q; qs + 1 <= m + 2; qs++) {
        ztest = s[qs];
        ctrl_custom_xrotg(&ztest, &ztest0, &sqds, &smm1);
        s[qs] = ztest;
        ztest0 = -smm1 * e[qs];
        e[qs] *= sqds;
        ctrl_custom_xrot(U, 1 + 3 * qs, 1 + 3 * (q - 1), sqds, smm1);
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m + 1]);
      varargin_1[1] = fabs(s[m]);
      varargin_1[2] = fabs(e[m]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      qs = 1;
      ztest = varargin_1[0];
      if (rtIsNaN(varargin_1[0])) {
        kase = 2;
        exitg1 = false;
        while ((!exitg1) && (kase < 6)) {
          qs = kase;
          if (!rtIsNaN(varargin_1[kase - 1])) {
            ztest = varargin_1[kase - 1];
            exitg1 = true;
          } else {
            kase++;
          }
        }
      }

      if (qs < 5) {
        while (qs + 1 < 6) {
          if (varargin_1[qs] > ztest) {
            ztest = varargin_1[qs];
          }

          qs++;
        }
      }

      ztest0 = s[m + 1] / ztest;
      smm1 = s[m] / ztest;
      emm1 = e[m] / ztest;
      sqds = s[q] / ztest;
      smm1 = ((smm1 + ztest0) * (smm1 - ztest0) + emm1 * emm1) / 2.0;
      emm1 *= ztest0;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      ztest0 = (sqds + ztest0) * (sqds - ztest0) + shift;
      ztest = e[q] / ztest * sqds;
      for (qs = q + 1; qs <= m + 1; qs++) {
        ctrl_custom_xrotg(&ztest0, &ztest, &sqds, &smm1);
        if (qs > q + 1) {
          e[0] = ztest0;
        }

        ztest0 = s[qs - 1] * sqds + e[qs - 1] * smm1;
        e[qs - 1] = e[qs - 1] * sqds - s[qs - 1] * smm1;
        ztest = smm1 * s[qs];
        s[qs] *= sqds;
        ctrl_custom_xrot(Vf, 1 + 3 * (qs - 1), 1 + 3 * qs, sqds, smm1);
        ctrl_custom_xrotg(&ztest0, &ztest, &sqds, &smm1);
        s[qs - 1] = ztest0;
        ztest0 = e[qs - 1] * sqds + smm1 * s[qs];
        s[qs] = e[qs - 1] * -smm1 + sqds * s[qs];
        ztest = smm1 * e[qs];
        e[qs] *= sqds;
        ctrl_custom_xrot(U, 1 + 3 * (qs - 1), 1 + 3 * qs, sqds, smm1);
      }

      e[m] = ztest0;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_custom_xscal(-1.0, Vf, 1 + 3 * q);
      }

      iter = q + 1;
      while ((q + 1 < 3) && (s[q] < s[iter])) {
        ztest0 = s[q];
        s[q] = s[iter];
        s[iter] = ztest0;
        ctrl_custom_xswap(Vf, 1 + 3 * q, 1 + 3 * (q + 1));
        ctrl_custom_xswap(U, 1 + 3 * q, 1 + 3 * (q + 1));
        q = iter;
        iter++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  for (m = 0; m < 3; m++) {
    e[m] = s[m];
    V[3 * m] = Vf[3 * m];
    V[1 + 3 * m] = Vf[3 * m + 1];
    V[2 + 3 * m] = Vf[3 * m + 2];
  }

  memset(&S[0], 0, 9U * sizeof(real_T));
  S[0] = e[0];
  S[4] = e[1];
  S[8] = e[2];
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

/* Model output function */
void ctrl_custom_output(void)
{
  real_T BK[9];
  real_T V[9];
  int32_T vcol;
  real_T tol;
  real_T U[9];
  real_T S[9];
  boolean_T b_p;
  int32_T ia;
  int32_T b_ic;
  static const real_T b_b[9] = { 2.629, 0.0, 0.0, 0.0, 1.03, 0.0, 0.0, 0.0, 1.03
  };

  real_T f[5];
  static const real_T a[15] = { 0.49999999999999989, 0.0, 0.49999999999999989,
    0.0, 0.0, 0.020058276376884107, 0.23062280175254893, -0.020058276376884114,
    0.23062280175254893, 0.53875439649490209, 0.11411877324227657,
    -0.58435728189333025, -0.11411877324227657, -0.58435728189333025,
    1.1687145637866609 };

  int32_T p3;
  real_T absx31;
  int32_T itmp;
  real_T rtb_Output;
  real_T rtb_alpha_valid[3];
  real_T rtb_y[9];
  int32_T r;
  real_T tmp[3];
  real_T tmp_0[3];
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

  /* Integrator: '<S6>/Integrator' */
  ctrl_custom_B.Integrator[0] = ctrl_custom_X.Integrator_CSTATE[0];
  ctrl_custom_B.Integrator[1] = ctrl_custom_X.Integrator_CSTATE[1];
  ctrl_custom_B.Integrator[2] = ctrl_custom_X.Integrator_CSTATE[2];

  /* Integrator: '<S6>/Integrator1' */
  ctrl_custom_B.Integrator1[0] = ctrl_custom_X.Integrator1_CSTATE[0];
  ctrl_custom_B.Integrator1[1] = ctrl_custom_X.Integrator1_CSTATE[1];
  ctrl_custom_B.Integrator1[2] = ctrl_custom_X.Integrator1_CSTATE[2];

  /* Integrator: '<S6>/Integrator2' */
  ctrl_custom_B.Integrator2[0] = ctrl_custom_X.Integrator2_CSTATE[0];
  ctrl_custom_B.Integrator2[1] = ctrl_custom_X.Integrator2_CSTATE[1];
  ctrl_custom_B.Integrator2[2] = ctrl_custom_X.Integrator2_CSTATE[2];

  /* Gain: '<S12>/Gain' */
  ctrl_custom_B.Gain = ctrl_custom_P.Gain_Gain * ctrl_custom_B.posYLeft;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  /* Gain: '<S12>/Gain1' */
  ctrl_custom_B.Gain1 = ctrl_custom_P.Gain1_Gain * ctrl_custom_B.posXLeft;

  /* Gain: '<S13>/Gain' */
  ctrl_custom_B.Gain_c = ctrl_custom_P.Gain_Gain_o * ctrl_custom_B.posYLeft;

  /* Gain: '<S13>/Gain2' */
  ctrl_custom_B.Gain2 = ctrl_custom_P.Gain2_Gain * ctrl_custom_B.posXRight;

  /* Gain: '<S13>/Gain1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Sum: '<Root>/Sum'
   */
  ctrl_custom_B.Gain1_o = (ctrl_custom_P.Gain_Gain_d * ctrl_custom_B.R2 -
    ctrl_custom_P.Gain1_Gain_h * ctrl_custom_B.L2) * ctrl_custom_P.Gain1_Gain_i;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtProductInport2' incorporates:
   *  Constant: '<S12>/sway'
   */
  ctrl_custom_B.TmpSignalConversionAtProductInp[0] = ctrl_custom_B.Gain;
  ctrl_custom_B.TmpSignalConversionAtProductInp[1] = ctrl_custom_P.sway_Value;
  ctrl_custom_B.TmpSignalConversionAtProductInp[2] = ctrl_custom_B.Gain1;

  /* SignalConversion: '<Root>/TmpSignal ConversionAttau fullInport1' */
  ctrl_custom_B.TmpSignalConversionAttaufullInp[0] = ctrl_custom_B.Gain_c;
  ctrl_custom_B.TmpSignalConversionAttaufullInp[1] = ctrl_custom_B.Gain2;
  ctrl_custom_B.TmpSignalConversionAttaufullInp[2] = ctrl_custom_B.Gain1_o;

  /* SignalConversion: '<Root>/TmpSignal ConversionAteta_testingInport1' */
  ctrl_custom_B.TmpSignalConversionAteta_testin[0] = ctrl_custom_B.x_m;
  ctrl_custom_B.TmpSignalConversionAteta_testin[1] = ctrl_custom_B.y_m;
  ctrl_custom_B.TmpSignalConversionAteta_testin[2] = ctrl_custom_B.psi_m;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<Root>/Memory' */
    ctrl_custom_B.Memory = ctrl_custom_DW.Memory_PreviousInput;

    /* Memory: '<Root>/Memory1' */
    ctrl_custom_B.Memory1 = ctrl_custom_DW.Memory1_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  ctrl_custom_B.joy_in_prev = ctrl_custom_B.Memory1;

  /* MATLAB Function 'MATLAB Function': '<S2>:1' */
  /* '<S2>:1:1' */
  if ((ctrl_custom_B.Selector != ctrl_custom_B.joy_in_prev) &&
      (ctrl_custom_B.Selector == 1.0)) {
    /* '<S2>:1:3' */
    if (ctrl_custom_B.Memory == 1.0) {
      /* '<S2>:1:4' */
      /* '<S2>:1:5' */
      ctrl_custom_B.joy_out = 0.0;
    } else {
      /* '<S2>:1:7' */
      ctrl_custom_B.joy_out = 1.0;
    }
  } else {
    /* '<S2>:1:10' */
    ctrl_custom_B.joy_out = ctrl_custom_B.Memory;
  }

  /* '<S2>:1:12' */
  ctrl_custom_B.joy_in_prev = ctrl_custom_B.Selector;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  /* MATLAB Function 'MATLAB Function1': '<S3>:1' */
  if (ctrl_custom_B.joy_out == 1.0) {
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    ctrl_custom_B.simple = 1.0;

    /* '<S3>:1:5' */
    ctrl_custom_B.full = 0.0;
  } else {
    /* '<S3>:1:7' */
    ctrl_custom_B.simple = 0.0;

    /* '<S3>:1:8' */
    ctrl_custom_B.full = 1.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* MATLAB Function: '<S7>/Propeller angle logic' incorporates:
     *  Constant: '<Root>/Thruster angles'
     */
    tol = ctrl_custom_P.Thrusterangles_Value[1];
    absx31 = ctrl_custom_P.Thrusterangles_Value[2];

    /* MATLAB Function 'Polar coordinate thrust allocation/Propeller angle logic': '<S24>:1' */
    /* Propeller 1 */
    if (ctrl_custom_P.Thrusterangles_Value[1] > 3.1415926535897931) {
      /* '<S24>:1:5' */
      /* '<S24>:1:6' */
      tol = 3.1415926535897931;
    } else {
      if (ctrl_custom_P.Thrusterangles_Value[1] < -3.1415926535897931) {
        /* '<S24>:1:7' */
        /* '<S24>:1:8' */
        tol = -3.1415926535897931;
      }
    }

    /* Propeller 2 */
    if (ctrl_custom_P.Thrusterangles_Value[2] > 3.1415926535897931) {
      /* '<S24>:1:13' */
      /* '<S24>:1:14' */
      absx31 = 3.1415926535897931;
    } else {
      if (ctrl_custom_P.Thrusterangles_Value[2] < -3.1415926535897931) {
        /* '<S24>:1:15' */
        /* '<S24>:1:16' */
        absx31 = -3.1415926535897931;
      }
    }

    /* MATLAB Function: '<S7>/BK inverse ' incorporates:
     *  MATLAB Function: '<S7>/Propeller angle logic'
     */
    /* '<S24>:1:19' */
    /* '<S24>:1:21' */
    /* MATLAB Function 'Polar coordinate thrust allocation/BK inverse ': '<S23>:1' */
    /* '<S23>:1:27' */
    /* '<S23>:1:10' */
    /* '<S23>:1:11' */
    /* '<S23>:1:13' */
    /* '<S23>:1:17' */
    /* '<S23>:1:18' */
    /* '<S23>:1:19' */
    /* '<S23>:1:20' */
    /* '<S23>:1:22' */
    /* '<S23>:1:27' */
    U[0] = 0.0;
    U[3] = cos(tol);
    U[6] = cos(absx31);
    U[1] = 1.0;
    U[4] = sin(tol);
    U[7] = sin(absx31);
    U[2] = 0.3875;
    U[5] = 0.055 * cos(tol) + -0.4574 * sin(tol);
    U[8] = -0.055 * cos(absx31) + -0.4574 * sin(absx31);
    for (r = 0; r < 3; r++) {
      for (itmp = 0; itmp < 3; itmp++) {
        BK[itmp + 3 * r] = 0.0;
        BK[itmp + 3 * r] += b_b[3 * r] * U[itmp];
        BK[itmp + 3 * r] += b_b[3 * r + 1] * U[itmp + 3];
        BK[itmp + 3 * r] += b_b[3 * r + 2] * U[itmp + 6];
      }
    }

    /* '<S23>:1:29' */
    b_p = true;
    for (r = 0; r < 9; r++) {
      ctrl_custom_B.BK_inv[r] = 0.0;
      if (b_p && ((!rtIsInf(BK[r])) && (!rtIsNaN(BK[r])))) {
      } else {
        b_p = false;
      }
    }

    if (b_p) {
      ctrl_custom_svd(BK, U, S, V);
    } else {
      for (r = 0; r < 9; r++) {
        U[r] = (rtNaN);
        S[r] = 0.0;
        V[r] = (rtNaN);
      }

      S[0] = (rtNaN);
      S[4] = (rtNaN);
      S[8] = (rtNaN);
    }

    tol = 3.0 * S[0] * 2.2204460492503131E-16;
    r = 0;
    vcol = 0;
    while ((vcol + 1 < 4) && (S[3 * vcol + vcol] > tol)) {
      r++;
      vcol++;
    }

    if (r > 0) {
      vcol = 0;
      for (p3 = 0; p3 + 1 <= r; p3++) {
        tol = 1.0 / S[3 * p3 + p3];
        for (itmp = vcol; itmp + 1 <= vcol + 3; itmp++) {
          V[itmp] *= tol;
        }

        vcol += 3;
      }

      memset(&ctrl_custom_B.BK_inv[0], 0, 9U * sizeof(real_T));
      for (p3 = 0; p3 + 1 < 4; p3++) {
        ctrl_custom_B.BK_inv[p3] = 0.0;
      }

      for (p3 = 3; p3 + 1 < 7; p3++) {
        ctrl_custom_B.BK_inv[p3] = 0.0;
      }

      for (p3 = 6; p3 + 1 < 10; p3++) {
        ctrl_custom_B.BK_inv[p3] = 0.0;
      }

      itmp = -1;
      vcol = (r - 1) * 3 + 1;
      for (p3 = 0; p3 + 1 <= vcol; p3 += 3) {
        if (U[p3] != 0.0) {
          ia = itmp;
          for (b_ic = 0; b_ic + 1 < 4; b_ic++) {
            ia++;
            ctrl_custom_B.BK_inv[b_ic] += U[p3] * V[ia];
          }
        }

        itmp += 3;
      }

      itmp = -1;
      vcol = (r - 1) * 3 + 2;
      for (p3 = 1; p3 + 1 <= vcol; p3 += 3) {
        if (U[p3] != 0.0) {
          ia = itmp;
          for (b_ic = 3; b_ic + 1 < 7; b_ic++) {
            ia++;
            ctrl_custom_B.BK_inv[b_ic] += U[p3] * V[ia];
          }
        }

        itmp += 3;
      }

      itmp = -1;
      vcol = (r - 1) * 3 + 3;
      for (p3 = 2; p3 + 1 <= vcol; p3 += 3) {
        if (U[p3] != 0.0) {
          ia = itmp;
          for (b_ic = 6; b_ic + 1 < 10; b_ic++) {
            ia++;
            ctrl_custom_B.BK_inv[b_ic] += U[p3] * V[ia];
          }
        }

        itmp += 3;
      }
    }

    /* End of MATLAB Function: '<S7>/BK inverse ' */
  }

  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Rectangular coordinate thrust allocation/MATLAB Function': '<S25>:1' */
  /* '<S25>:1:21' */
  /*  */
  /* Initialize extended thrust allocation matrix */
  /* Extended force vector */
  /* '<S25>:1:21' */
  for (r = 0; r < 5; r++) {
    f[r] = a[r + 10] * ctrl_custom_B.Gain1_o + (a[r + 5] * ctrl_custom_B.Gain2 +
      a[r] * ctrl_custom_B.Gain_c);
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Thruster angles'
   *  Constant: '<Root>/Turn rate'
   *  Constant: '<Root>/Turn rate1'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  /*  */
  /* Calculate angles and control input */
  /* '<S25>:1:25' */
  /* '<S25>:1:26' */
  /* '<S25>:1:28' */
  /* '<S25>:1:34' */
  /* '<S25>:1:35' */
  /* '<S25>:1:36' */
  /* '<S25>:1:38' */
  /* '<S25>:1:40' */
  if (ctrl_custom_B.joy_out > ctrl_custom_P.Switch_Threshold) {
    /* Product: '<S7>/Product' */
    for (r = 0; r < 3; r++) {
      ctrl_custom_B.Switch[r] = ctrl_custom_B.BK_inv[r + 6] *
        ctrl_custom_B.TmpSignalConversionAtProductInp[2] +
        (ctrl_custom_B.BK_inv[r + 3] *
         ctrl_custom_B.TmpSignalConversionAtProductInp[1] +
         ctrl_custom_B.BK_inv[r] *
         ctrl_custom_B.TmpSignalConversionAtProductInp[0]);
    }

    /* End of Product: '<S7>/Product' */
    ctrl_custom_B.Switch[3] = ctrl_custom_P.Thrusterangles_Value[1];
    ctrl_custom_B.Switch[5] = ctrl_custom_P.Turnrate_Value[0];
    ctrl_custom_B.Switch[4] = ctrl_custom_P.Thrusterangles_Value[2];
    ctrl_custom_B.Switch[6] = ctrl_custom_P.Turnrate_Value[1];
  } else {
    ctrl_custom_B.Switch[0] = f[4] / 2.629;
    ctrl_custom_B.Switch[1] = sqrt(f[0] * f[0] + f[1] * f[1]) *
      0.970873786407767;
    ctrl_custom_B.Switch[3] = rt_atan2d_snf(f[1], f[0]);
    ctrl_custom_B.Switch[5] = ctrl_custom_P.Turnrate1_Value[0];
    ctrl_custom_B.Switch[2] = sqrt(f[2] * f[2] + f[3] * f[3]) *
      0.970873786407767;
    ctrl_custom_B.Switch[4] = rt_atan2d_snf(f[3], f[2]);
    ctrl_custom_B.Switch[6] = ctrl_custom_P.Turnrate1_Value[1];
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<S15>/Saturation2' */
  if (ctrl_custom_B.Switch[0] > ctrl_custom_P.Saturation2_UpperSat) {
    ctrl_custom_B.Saturation2 = ctrl_custom_P.Saturation2_UpperSat;
  } else if (ctrl_custom_B.Switch[0] < ctrl_custom_P.Saturation2_LowerSat) {
    ctrl_custom_B.Saturation2 = ctrl_custom_P.Saturation2_LowerSat;
  } else {
    ctrl_custom_B.Saturation2 = ctrl_custom_B.Switch[0];
  }

  /* End of Saturate: '<S15>/Saturation2' */

  /* Saturate: '<S15>/Saturation11' */
  if (ctrl_custom_B.Switch[1] > ctrl_custom_P.Saturation11_UpperSat) {
    ctrl_custom_B.Saturation11 = ctrl_custom_P.Saturation11_UpperSat;
  } else if (ctrl_custom_B.Switch[1] < ctrl_custom_P.Saturation11_LowerSat) {
    ctrl_custom_B.Saturation11 = ctrl_custom_P.Saturation11_LowerSat;
  } else {
    ctrl_custom_B.Saturation11 = ctrl_custom_B.Switch[1];
  }

  /* End of Saturate: '<S15>/Saturation11' */

  /* Saturate: '<S15>/Saturation1' */
  if (ctrl_custom_B.Switch[2] > ctrl_custom_P.Saturation1_UpperSat) {
    ctrl_custom_B.Saturation1 = ctrl_custom_P.Saturation1_UpperSat;
  } else if (ctrl_custom_B.Switch[2] < ctrl_custom_P.Saturation1_LowerSat) {
    ctrl_custom_B.Saturation1 = ctrl_custom_P.Saturation1_LowerSat;
  } else {
    ctrl_custom_B.Saturation1 = ctrl_custom_B.Switch[2];
  }

  /* End of Saturate: '<S15>/Saturation1' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Gain: '<S18>/Output' incorporates:
     *  RandomNumber: '<S18>/White Noise'
     */
    rtb_Output = ctrl_custom_P.Output_Gain * ctrl_custom_DW.NextOutput;
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Gain: '<S6>/L4' */
    ctrl_custom_B.L4[0] = ctrl_custom_P.L4_Gain[0] * rtb_Output;
    ctrl_custom_B.L4[1] = ctrl_custom_P.L4_Gain[1] * rtb_Output;
    ctrl_custom_B.L4[2] = ctrl_custom_P.L4_Gain[2] * rtb_Output;
  }

  for (r = 0; r < 3; r++) {
    /* Sum: '<S6>/Sum3' incorporates:
     *  Gain: '<S6>/L5'
     *  Product: '<S6>/Product8'
     */
    rtb_Output = ((ctrl_custom_P.L5_Gain[r + 3] * ctrl_custom_B.Noisegain *
                   ctrl_custom_B.L4[1] + ctrl_custom_P.L5_Gain[r] *
                   ctrl_custom_B.Noisegain * ctrl_custom_B.L4[0]) +
                  ctrl_custom_P.L5_Gain[r + 6] * ctrl_custom_B.Noisegain *
                  ctrl_custom_B.L4[2]) +
      ctrl_custom_B.TmpSignalConversionAteta_testin[r];

    /* Sum: '<S6>/Sum' */
    ctrl_custom_B.Sum[r] = rtb_Output - ctrl_custom_B.Integrator[r];

    /* Sum: '<S6>/Sum3' incorporates:
     *  Gain: '<S6>/L5'
     */
    rtb_alpha_valid[r] = rtb_Output;
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* MATLAB Function: '<S6>/Inverse' incorporates:
     *  Constant: '<S6>/M'
     */
    /* MATLAB Function 'Observer2/Inverse': '<S19>:1' */
    /* '<S19>:1:4' */
    memcpy(&BK[0], &ctrl_custom_P.M_Value[0], 9U * sizeof(real_T));
    r = 0;
    vcol = 3;
    p3 = 6;
    rtb_Output = fabs(ctrl_custom_P.M_Value[0]);
    tol = fabs(ctrl_custom_P.M_Value[1]);
    absx31 = fabs(ctrl_custom_P.M_Value[2]);
    if ((tol > rtb_Output) && (tol > absx31)) {
      r = 3;
      vcol = 0;
      BK[0] = ctrl_custom_P.M_Value[1];
      BK[1] = ctrl_custom_P.M_Value[0];
      BK[3] = ctrl_custom_P.M_Value[4];
      BK[4] = ctrl_custom_P.M_Value[3];
      BK[6] = ctrl_custom_P.M_Value[7];
      BK[7] = ctrl_custom_P.M_Value[6];
    } else {
      if (absx31 > rtb_Output) {
        r = 6;
        p3 = 0;
        BK[0] = ctrl_custom_P.M_Value[2];
        BK[2] = ctrl_custom_P.M_Value[0];
        BK[3] = ctrl_custom_P.M_Value[5];
        BK[5] = ctrl_custom_P.M_Value[3];
        BK[6] = ctrl_custom_P.M_Value[8];
        BK[8] = ctrl_custom_P.M_Value[6];
      }
    }

    tol = BK[1] / BK[0];
    BK[1] /= BK[0];
    rtb_Output = BK[2] / BK[0];
    BK[2] /= BK[0];
    BK[4] -= tol * BK[3];
    BK[5] -= rtb_Output * BK[3];
    BK[7] -= tol * BK[6];
    BK[8] -= rtb_Output * BK[6];
    if (fabs(BK[5]) > fabs(BK[4])) {
      itmp = vcol;
      vcol = p3;
      p3 = itmp;
      BK[1] = rtb_Output;
      BK[2] = tol;
      rtb_Output = BK[4];
      BK[4] = BK[5];
      BK[5] = rtb_Output;
      rtb_Output = BK[7];
      BK[7] = BK[8];
      BK[8] = rtb_Output;
    }

    rtb_Output = BK[5] / BK[4];
    BK[5] /= BK[4];
    BK[8] -= rtb_Output * BK[7];
    rtb_Output = (BK[5] * BK[1] - BK[2]) / BK[8];
    tol = -(BK[7] * rtb_Output + BK[1]) / BK[4];
    ctrl_custom_B.y[r] = ((1.0 - BK[3] * tol) - BK[6] * rtb_Output) / BK[0];
    ctrl_custom_B.y[r + 1] = tol;
    ctrl_custom_B.y[r + 2] = rtb_Output;
    rtb_Output = -BK[5] / BK[8];
    tol = (1.0 - BK[7] * rtb_Output) / BK[4];
    ctrl_custom_B.y[vcol] = -(BK[3] * tol + BK[6] * rtb_Output) / BK[0];
    ctrl_custom_B.y[vcol + 1] = tol;
    ctrl_custom_B.y[vcol + 2] = rtb_Output;
    rtb_Output = 1.0 / BK[8];
    tol = -BK[7] * rtb_Output / BK[4];
    ctrl_custom_B.y[p3] = -(BK[3] * tol + BK[6] * rtb_Output) / BK[0];
    ctrl_custom_B.y[p3 + 1] = tol;
    ctrl_custom_B.y[p3 + 2] = rtb_Output;

    /* End of MATLAB Function: '<S6>/Inverse' */
  }

  /* MATLAB Function: '<S6>/rotation matrix' */
  /* MATLAB Function 'Observer2/rotation matrix': '<S22>:1' */
  /* '<S22>:1:3' */
  rtb_y[0] = cos(rtb_alpha_valid[2]);
  rtb_y[3] = -sin(rtb_alpha_valid[2]);
  rtb_y[6] = 0.0;
  rtb_y[1] = sin(rtb_alpha_valid[2]);
  rtb_y[4] = cos(rtb_alpha_valid[2]);
  rtb_y[7] = 0.0;
  rtb_y[2] = 0.0;
  rtb_y[5] = 0.0;
  rtb_y[8] = 1.0;

  /* MATLAB Function 'Observer2/Transpose': '<S21>:1' */
  /* '<S21>:1:4' */
  for (r = 0; r < 3; r++) {
    /* MATLAB Function: '<S6>/Transpose' */
    BK[3 * r] = rtb_y[r];
    BK[1 + 3 * r] = rtb_y[r + 3];
    BK[2 + 3 * r] = rtb_y[r + 6];

    /* Sum: '<S6>/Sum1' incorporates:
     *  Constant: '<S6>/D'
     *  Product: '<S6>/Product1'
     */
    tmp[r] = ctrl_custom_B.TmpSignalConversionAttaufullInp[r] -
      ((ctrl_custom_P.D_Value[r + 3] * ctrl_custom_B.Integrator1[1] +
        ctrl_custom_P.D_Value[r] * ctrl_custom_B.Integrator1[0]) +
       ctrl_custom_P.D_Value[r + 6] * ctrl_custom_B.Integrator1[2]);

    /* Product: '<S6>/Product6' incorporates:
     *  Gain: '<S6>/L2'
     *  Product: '<S6>/Product3'
     */
    rtb_alpha_valid[r] = ctrl_custom_P.L2_Gain[r + 6] *
      ctrl_custom_B.ObservergainL1L2 * ctrl_custom_B.Sum[2] +
      (ctrl_custom_P.L2_Gain[r + 3] * ctrl_custom_B.ObservergainL1L2 *
       ctrl_custom_B.Sum[1] + ctrl_custom_P.L2_Gain[r] *
       ctrl_custom_B.ObservergainL1L2 * ctrl_custom_B.Sum[0]);
  }

  for (r = 0; r < 3; r++) {
    /* Sum: '<S6>/Sum1' incorporates:
     *  Product: '<S6>/Product'
     *  Product: '<S6>/Product2'
     *  Product: '<S6>/Product3'
     */
    tmp_0[r] = ((BK[r + 3] * ctrl_custom_B.Integrator2[1] + BK[r] *
                 ctrl_custom_B.Integrator2[0]) + BK[r + 6] *
                ctrl_custom_B.Integrator2[2]) + (tmp[r] + (BK[r + 6] *
      rtb_alpha_valid[2] + (BK[r + 3] * rtb_alpha_valid[1] + BK[r] *
      rtb_alpha_valid[0])));
  }

  for (r = 0; r < 3; r++) {
    /* Product: '<S6>/Product' */
    ctrl_custom_B.Product[r] = 0.0;

    /* Product: '<S6>/Product7' incorporates:
     *  Gain: '<S6>/L3'
     */
    ctrl_custom_B.Product7[r] = 0.0;

    /* Product: '<S6>/Product' */
    ctrl_custom_B.Product[r] += ctrl_custom_B.y[r] * tmp_0[0];

    /* Product: '<S6>/Product7' incorporates:
     *  Gain: '<S6>/L3'
     */
    ctrl_custom_B.Product7[r] += ctrl_custom_P.L3_Gain[r] *
      ctrl_custom_B.ObservergainL3 * ctrl_custom_B.Sum[0];

    /* Product: '<S6>/Product' */
    ctrl_custom_B.Product[r] += ctrl_custom_B.y[r + 3] * tmp_0[1];

    /* Product: '<S6>/Product7' incorporates:
     *  Gain: '<S6>/L3'
     */
    ctrl_custom_B.Product7[r] += ctrl_custom_P.L3_Gain[r + 3] *
      ctrl_custom_B.ObservergainL3 * ctrl_custom_B.Sum[1];

    /* Product: '<S6>/Product' */
    ctrl_custom_B.Product[r] += ctrl_custom_B.y[r + 6] * tmp_0[2];

    /* Product: '<S6>/Product7' incorporates:
     *  Gain: '<S6>/L3'
     */
    ctrl_custom_B.Product7[r] += ctrl_custom_P.L3_Gain[r + 6] *
      ctrl_custom_B.ObservergainL3 * ctrl_custom_B.Sum[2];

    /* Sum: '<S6>/Sum2' incorporates:
     *  Gain: '<S6>/L1'
     *  Product: '<S6>/Product4'
     *  Product: '<S6>/Product5'
     */
    ctrl_custom_B.Sum2[r] = (ctrl_custom_P.L1_Gain[r + 6] *
      ctrl_custom_B.ObservergainL1L2 * ctrl_custom_B.Sum[2] +
      (ctrl_custom_P.L1_Gain[r + 3] * ctrl_custom_B.ObservergainL1L2 *
       ctrl_custom_B.Sum[1] + ctrl_custom_P.L1_Gain[r] *
       ctrl_custom_B.ObservergainL1L2 * ctrl_custom_B.Sum[0])) + (rtb_y[r + 6] *
      ctrl_custom_B.Integrator1[2] + (rtb_y[r + 3] * ctrl_custom_B.Integrator1[1]
      + rtb_y[r] * ctrl_custom_B.Integrator1[0]));
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }
}

/* Model update function */
void ctrl_custom_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Update for Memory: '<Root>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput = ctrl_custom_B.joy_out;

    /* Update for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput = ctrl_custom_B.joy_in_prev;

    /* Update for RandomNumber: '<S18>/White Noise' */
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

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_custom_B.Sum2[0];

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_custom_B.Product[0];

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_custom_B.Product7[0];

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = ctrl_custom_B.Sum2[1];

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_custom_B.Product[1];

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_custom_B.Product7[1];

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = ctrl_custom_B.Sum2[2];

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_custom_B.Product[2];

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_custom_B.Product7[2];
}

/* Model initialize function */
void ctrl_custom_initialize(void)
{
  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE[0] = ctrl_custom_P.Integrator_IC[0];

    /* InitializeConditions for Integrator: '<S6>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE[0] = ctrl_custom_P.Integrator1_IC[0];

    /* InitializeConditions for Integrator: '<S6>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[0] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE[1] = ctrl_custom_P.Integrator_IC[1];

    /* InitializeConditions for Integrator: '<S6>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE[1] = ctrl_custom_P.Integrator1_IC[1];

    /* InitializeConditions for Integrator: '<S6>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[1] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE[2] = ctrl_custom_P.Integrator_IC[2];

    /* InitializeConditions for Integrator: '<S6>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE[2] = ctrl_custom_P.Integrator1_IC[2];

    /* InitializeConditions for Integrator: '<S6>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE[2] = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    ctrl_custom_DW.Memory_PreviousInput = ctrl_custom_P.Memory_X0;

    /* InitializeConditions for Memory: '<Root>/Memory1' */
    ctrl_custom_DW.Memory1_PreviousInput = ctrl_custom_P.Memory1_X0;

    /* InitializeConditions for RandomNumber: '<S18>/White Noise' */
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

    /* End of InitializeConditions for RandomNumber: '<S18>/White Noise' */
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
  ctrl_custom_M->Sizes.numContStates = (9);/* Number of continuous states */
  ctrl_custom_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_custom_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_custom_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_custom_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_custom_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_custom_M->Sizes.numBlocks = (109);/* Number of blocks */
  ctrl_custom_M->Sizes.numBlockIO = (46);/* Number of block outputs */
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
 * Model version : 1.116
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Mar 05 17:25:43 2019
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

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
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

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

  // ctrl_custom/posYLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.posYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/posXLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.posXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Selector
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Selector, 0, data[index++], 0, 0);
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

  // ctrl_custom/Observer2/Noise gain
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Noisegain, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Observer2/Observer gain L1//L2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.ObservergainL1L2, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/Observer2/Observer gain L3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.ObservergainL3, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 18;
}

int32_t NumOutputPorts(void)
{
  return 40;
}

double ni_extout[40];

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

  // ctrl_custom/tau simple1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/tau simple2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_P.sway_Value, 0,
      36, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/tau simple3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain1, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/tau full1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain_c, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/tau full2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain2, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/tau full3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain1_o, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/tau simple: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAtProductInp, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAtProductInp, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAtProductInp, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/tau full: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAttaufullInp, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAttaufullInp, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAttaufullInp, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/eta_testing: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAteta_testin, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAteta_testin, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_custom_B.TmpSignalConversionAteta_testin, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/QTM_SCOPEPSI: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.psi_m, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/QTM_SCOPEX: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.x_m, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/QTM_SCOPEY: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.y_m, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/selector full: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.full, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/selector simple: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.simple, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 4, 23, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 5, 23, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 6, 23, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 3, 23, 0);
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

  // ctrl_custom/Observer2/Eta_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 0, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 1, 18, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 2, 18, 0);
  } else {
    index += 3;
  }

  // ctrl_custom/IMU/IMU_SCOPEZ: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Acc_z, 0, 0, 0);
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

  // ctrl_custom/tau simple1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain, 0, 0, 0);

  // ctrl_custom/tau simple2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_P.sway_Value, 0, 36,
    0);

  // ctrl_custom/tau simple3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain1, 0, 0, 0);

  // ctrl_custom/tau full1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain_c, 0, 0, 0);

  // ctrl_custom/tau full2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain2, 0, 0, 0);

  // ctrl_custom/tau full3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Gain1_o, 0, 0, 0);

  // ctrl_custom/tau simple: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAtProductInp, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAtProductInp, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAtProductInp, 2, 18, 0);

  // ctrl_custom/tau full: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAttaufullInp, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAttaufullInp, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAttaufullInp, 2, 18, 0);

  // ctrl_custom/eta_testing: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAteta_testin, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAteta_testin, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_custom_B.TmpSignalConversionAteta_testin, 2, 18, 0);

  // ctrl_custom/QTM_SCOPEPSI: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.psi_m, 0, 0, 0);

  // ctrl_custom/QTM_SCOPEX: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.x_m, 0, 0, 0);

  // ctrl_custom/QTM_SCOPEY: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.y_m, 0, 0, 0);

  // ctrl_custom/selector full: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.full, 0, 0, 0);

  // ctrl_custom/selector simple: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.simple, 0, 0, 0);

  // ctrl_custom/u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 4, 23, 0);

  // ctrl_custom/u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 5, 23, 0);

  // ctrl_custom/u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 6, 23, 0);

  // ctrl_custom/u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Switch, 3, 23, 0);

  // ctrl_custom/u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation2, 0, 0,
    0);

  // ctrl_custom/u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation11, 0, 0,
    0);

  // ctrl_custom/u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Saturation1, 0, 0,
    0);

  // ctrl_custom/Observer2/Eta_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 0, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 1, 18, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Sum, 2, 18, 0);

  // ctrl_custom/IMU/IMU_SCOPEZ: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.Acc_z, 0, 0, 0);
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
  { 0, "ctrl_custom/Observer2/Integrator/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator_IC), 21, 3, 2, 0, 0 },

  { 1, "ctrl_custom/Observer2/Integrator1/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator1_IC), 21, 3, 2, 2, 0 },

  { 2, "ctrl_custom/Observer2/Integrator2/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator2_IC), 36, 1, 2, 4, 0 },

  { 3, "ctrl_custom/simpleConversion/Gain/Gain", offsetof(P_ctrl_custom_T,
    Gain_Gain), 36, 1, 2, 6, 0 },

  { 4, "ctrl_custom/simpleConversion/sway/Value", offsetof(P_ctrl_custom_T,
    sway_Value), 36, 1, 2, 8, 0 },

  { 5, "ctrl_custom/simpleConversion/Gain1/Gain", offsetof(P_ctrl_custom_T,
    Gain1_Gain), 36, 1, 2, 10, 0 },

  { 6, "ctrl_custom/simpleConversion1/Gain/Gain", offsetof(P_ctrl_custom_T,
    Gain_Gain_o), 36, 1, 2, 12, 0 },

  { 7, "ctrl_custom/simpleConversion1/Gain2/Gain", offsetof(P_ctrl_custom_T,
    Gain2_Gain), 36, 1, 2, 14, 0 },

  { 8, "ctrl_custom/Gain/Gain", offsetof(P_ctrl_custom_T, Gain_Gain_d), 36, 1, 2,
    16, 0 },

  { 9, "ctrl_custom/Gain1/Gain", offsetof(P_ctrl_custom_T, Gain1_Gain_h), 36, 1,
    2, 18, 0 },

  { 10, "ctrl_custom/simpleConversion1/Gain1/Gain", offsetof(P_ctrl_custom_T,
    Gain1_Gain_i), 36, 1, 2, 20, 0 },

  { 11, "ctrl_custom/Memory/X0", offsetof(P_ctrl_custom_T, Memory_X0), 36, 1, 2,
    22, 0 },

  { 12, "ctrl_custom/Memory1/X0", offsetof(P_ctrl_custom_T, Memory1_X0), 36, 1,
    2, 24, 0 },

  { 13, "ctrl_custom/Thruster angles/Value", offsetof(P_ctrl_custom_T,
    Thrusterangles_Value[0]), 21, 3, 2, 26, 0 },

  { 14, "ctrl_custom/Turn rate/Value", offsetof(P_ctrl_custom_T, Turnrate_Value
    [0]), 22, 2, 2, 28, 0 },

  { 15, "ctrl_custom/Turn rate1/Value", offsetof(P_ctrl_custom_T,
    Turnrate1_Value[0]), 22, 2, 2, 30, 0 },

  { 16, "ctrl_custom/Switch/Threshold", offsetof(P_ctrl_custom_T,
    Switch_Threshold), 36, 1, 2, 32, 0 },

  { 17, "ctrl_custom/u1/Saturation2/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation2_UpperSat), 36, 1, 2, 34, 0 },

  { 18, "ctrl_custom/u1/Saturation2/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation2_LowerSat), 36, 1, 2, 36, 0 },

  { 19, "ctrl_custom/u1/Saturation11/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation11_UpperSat), 36, 1, 2, 38, 0 },

  { 20, "ctrl_custom/u1/Saturation11/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation11_LowerSat), 36, 1, 2, 40, 0 },

  { 21, "ctrl_custom/u1/Saturation1/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation1_UpperSat), 36, 1, 2, 42, 0 },

  { 22, "ctrl_custom/u1/Saturation1/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation1_LowerSat), 36, 1, 2, 44, 0 },

  { 23, "ctrl_custom/Observer2/Band-Limited White Noise/White Noise/Mean",
    offsetof(P_ctrl_custom_T, WhiteNoise_Mean), 36, 1, 2, 46, 0 },

  { 24, "ctrl_custom/Observer2/Band-Limited White Noise/White Noise/StdDev",
    offsetof(P_ctrl_custom_T, WhiteNoise_StdDev), 36, 1, 2, 48, 0 },

  { 25, "ctrl_custom/Observer2/Band-Limited White Noise/White Noise/Seed",
    offsetof(P_ctrl_custom_T, WhiteNoise_Seed), 36, 1, 2, 50, 0 },

  { 26, "ctrl_custom/Observer2/Band-Limited White Noise/Output/Gain", offsetof
    (P_ctrl_custom_T, Output_Gain), 36, 1, 2, 52, 0 },

  { 27, "ctrl_custom/Observer2/L5/Gain", offsetof(P_ctrl_custom_T, L5_Gain), 20,
    9, 2, 54, 0 },

  { 28, "ctrl_custom/Observer2/L4/Gain", offsetof(P_ctrl_custom_T, L4_Gain), 21,
    3, 2, 56, 0 },

  { 29, "ctrl_custom/Observer2/D/Value", offsetof(P_ctrl_custom_T, D_Value[0]),
    20, 9, 2, 58, 0 },

  { 30, "ctrl_custom/Observer2/M/Value", offsetof(P_ctrl_custom_T, M_Value[0]),
    20, 9, 2, 60, 0 },

  { 31, "ctrl_custom/Observer2/L1/Gain", offsetof(P_ctrl_custom_T, L1_Gain), 20,
    9, 2, 62, 0 },

  { 32, "ctrl_custom/Observer2/L2/Gain", offsetof(P_ctrl_custom_T, L2_Gain), 20,
    9, 2, 64, 0 },

  { 33, "ctrl_custom/Observer2/L3/Gain", offsetof(P_ctrl_custom_T, L3_Gain), 20,
    9, 2, 66, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 34;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  3, 1,                                /* Parameter at index 0 */
  3, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  3, 1,                                /* Parameter at index 13 */
  2, 1,                                /* Parameter at index 14 */
  2, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  3, 3,                                /* Parameter at index 27 */
  3, 1,                                /* Parameter at index 28 */
  3, 3,                                /* Parameter at index 29 */
  3, 3,                                /* Parameter at index 30 */
  3, 3,                                /* Parameter at index 31 */
  3, 3,                                /* Parameter at index 32 */
  3, 3,                                /* Parameter at index 33 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_custom/posYLeft", 0, "", offsetof(B_ctrl_custom_T, posYLeft) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_custom/posXLeft", 0, "", offsetof(B_ctrl_custom_T, posXLeft) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_custom/Selector", 0, "", offsetof(B_ctrl_custom_T, Selector) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_custom/posXRight", 0, "", offsetof(B_ctrl_custom_T, posXRight) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_custom/R2", 0, "", offsetof(B_ctrl_custom_T, R2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_custom/L2", 0, "", offsetof(B_ctrl_custom_T, L2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_custom/Observer2/Integrator/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 7, "ctrl_custom/Observer2/Integrator/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 8, "ctrl_custom/Observer2/Integrator/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 9, "ctrl_custom/Observer2/Integrator1/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 10, "ctrl_custom/Observer2/Integrator1/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 11, "ctrl_custom/Observer2/Integrator1/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 12, "ctrl_custom/Observer2/Integrator2/(1, 1)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 13, "ctrl_custom/Observer2/Integrator2/(1, 2)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 14, "ctrl_custom/Observer2/Integrator2/(1, 3)", 0, "", offsetof
    (B_ctrl_custom_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 15, "ctrl_custom/simpleConversion/Gain", 0, "", offsetof(B_ctrl_custom_T,
    Gain) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_custom/simpleConversion/Gain1", 0, "", offsetof(B_ctrl_custom_T,
    Gain1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_custom/simpleConversion1/Gain", 0, "", offsetof(B_ctrl_custom_T,
    Gain_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_custom/simpleConversion1/Gain2", 0, "", offsetof(B_ctrl_custom_T,
    Gain2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_custom/simpleConversion1/Gain1", 0, "", offsetof(B_ctrl_custom_T,
    Gain1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_custom/Pose/x_m", 0, "", offsetof(B_ctrl_custom_T, x_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_custom/Pose/y_m", 0, "", offsetof(B_ctrl_custom_T, y_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_custom/Pose/psi_m", 0, "", offsetof(B_ctrl_custom_T, psi_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "ctrl_custom/Memory", 0, "", offsetof(B_ctrl_custom_T, Memory) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "ctrl_custom/Memory1", 0, "", offsetof(B_ctrl_custom_T, Memory1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "ctrl_custom/Switch/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, Switch) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 26, "ctrl_custom/Switch/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, Switch) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 27, "ctrl_custom/Switch/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, Switch) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 28, "ctrl_custom/Switch/(1, 4)", 0, "", offsetof(B_ctrl_custom_T, Switch) +
    (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 29, "ctrl_custom/Switch/(1, 5)", 0, "", offsetof(B_ctrl_custom_T, Switch) +
    (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 30, "ctrl_custom/Switch/(1, 6)", 0, "", offsetof(B_ctrl_custom_T, Switch) +
    (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 31, "ctrl_custom/Switch/(1, 7)", 0, "", offsetof(B_ctrl_custom_T, Switch) +
    (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 32, "ctrl_custom/u1/Saturation2", 0, "", offsetof(B_ctrl_custom_T,
    Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 33, "ctrl_custom/u1/Saturation11", 0, "", offsetof(B_ctrl_custom_T,
    Saturation11) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 34, "ctrl_custom/u1/Saturation1", 0, "", offsetof(B_ctrl_custom_T,
    Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 35, "ctrl_custom/Observer2/Noise gain", 0, "", offsetof(B_ctrl_custom_T,
    Noisegain) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 36, "ctrl_custom/Observer2/L4/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, L4)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 37, "ctrl_custom/Observer2/L4/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, L4)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 38, "ctrl_custom/Observer2/L4/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, L4)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 39, "ctrl_custom/Observer2/Sum/(1, 1)", 0, "", offsetof(B_ctrl_custom_T, Sum)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 40, "ctrl_custom/Observer2/Sum/(1, 2)", 0, "", offsetof(B_ctrl_custom_T, Sum)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 41, "ctrl_custom/Observer2/Sum/(1, 3)", 0, "", offsetof(B_ctrl_custom_T, Sum)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 42, "ctrl_custom/Observer2/Observer gain L1//L2", 0, "", offsetof
    (B_ctrl_custom_T, ObservergainL1L2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 43, "ctrl_custom/Observer2/Observer gain L3", 0, "", offsetof
    (B_ctrl_custom_T, ObservergainL3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 44, "ctrl_custom/Observer2/Product/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Product) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 45, "ctrl_custom/Observer2/Product/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Product) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 46, "ctrl_custom/Observer2/Product/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Product) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 47, "ctrl_custom/Observer2/Product7/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Product7) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 48, "ctrl_custom/Observer2/Product7/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Product7) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 49, "ctrl_custom/Observer2/Product7/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Product7) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 50, "ctrl_custom/Observer2/Sum2/(1, 1)", 0, "", offsetof(B_ctrl_custom_T,
    Sum2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 51, "ctrl_custom/Observer2/Sum2/(1, 2)", 0, "", offsetof(B_ctrl_custom_T,
    Sum2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 52, "ctrl_custom/Observer2/Sum2/(1, 3)", 0, "", offsetof(B_ctrl_custom_T,
    Sum2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 53, "ctrl_custom/IMU/Acc_z", 0, "", offsetof(B_ctrl_custom_T, Acc_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 54, "ctrl_custom/IMU/Acc_x", 0, "", offsetof(B_ctrl_custom_T, Acc_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 55, "ctrl_custom/IMU/Acc_y", 0, "", offsetof(B_ctrl_custom_T, Acc_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 56, "ctrl_custom/IMU/Gyro_x", 0, "", offsetof(B_ctrl_custom_T, Gyro_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 57, "ctrl_custom/IMU/Gyro_y", 0, "", offsetof(B_ctrl_custom_T, Gyro_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 58, "ctrl_custom/IMU/Gyro_z", 0, "", offsetof(B_ctrl_custom_T, Gyro_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 59, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(1, 1)",
    offsetof(B_ctrl_custom_T, BK_inv) + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 60, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(2, 1)",
    offsetof(B_ctrl_custom_T, BK_inv) + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 61, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(3, 1)",
    offsetof(B_ctrl_custom_T, BK_inv) + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 62, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(1, 2)",
    offsetof(B_ctrl_custom_T, BK_inv) + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 63, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(2, 2)",
    offsetof(B_ctrl_custom_T, BK_inv) + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 64, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(3, 2)",
    offsetof(B_ctrl_custom_T, BK_inv) + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 65, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(1, 3)",
    offsetof(B_ctrl_custom_T, BK_inv) + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 66, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(2, 3)",
    offsetof(B_ctrl_custom_T, BK_inv) + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 67, "ctrl_custom/Polar coordinate thrust allocation/BK inverse", 0, "(3, 3)",
    offsetof(B_ctrl_custom_T, BK_inv) + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1,
    2, 0, 0 },

  { 68, "ctrl_custom/Observer2/Inverse", 0, "(1, 1)", offsetof(B_ctrl_custom_T,
    y) + (0*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 69, "ctrl_custom/Observer2/Inverse", 0, "(2, 1)", offsetof(B_ctrl_custom_T,
    y) + (1*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 70, "ctrl_custom/Observer2/Inverse", 0, "(3, 1)", offsetof(B_ctrl_custom_T,
    y) + (2*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 71, "ctrl_custom/Observer2/Inverse", 0, "(1, 2)", offsetof(B_ctrl_custom_T,
    y) + (3*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 72, "ctrl_custom/Observer2/Inverse", 0, "(2, 2)", offsetof(B_ctrl_custom_T,
    y) + (4*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 73, "ctrl_custom/Observer2/Inverse", 0, "(3, 2)", offsetof(B_ctrl_custom_T,
    y) + (5*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 74, "ctrl_custom/Observer2/Inverse", 0, "(1, 3)", offsetof(B_ctrl_custom_T,
    y) + (6*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 75, "ctrl_custom/Observer2/Inverse", 0, "(2, 3)", offsetof(B_ctrl_custom_T,
    y) + (7*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 76, "ctrl_custom/Observer2/Inverse", 0, "(3, 3)", offsetof(B_ctrl_custom_T,
    y) + (8*sizeof(real_T)), BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 77, "ctrl_custom/MATLAB Function1", 0, "", offsetof(B_ctrl_custom_T, simple)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 78, "ctrl_custom/MATLAB Function1", 1, "", offsetof(B_ctrl_custom_T, full) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 79, "ctrl_custom/MATLAB Function", 0, "", offsetof(B_ctrl_custom_T, joy_out)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 80, "ctrl_custom/MATLAB Function", 1, "", offsetof(B_ctrl_custom_T,
    joy_in_prev) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 81;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 44;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "posYLeft", 0, EXT_IN, 1, 1, 1 },

  { 2, "posXLeft", 0, EXT_IN, 1, 1, 1 },

  { 3, "Selector", 0, EXT_IN, 1, 1, 1 },

  { 4, "posXRight", 0, EXT_IN, 1, 1, 1 },

  { 5, "R2", 0, EXT_IN, 1, 1, 1 },

  { 6, "L2", 0, EXT_IN, 1, 1, 1 },

  { 7, "Pose/x_m", 0, EXT_IN, 1, 1, 1 },

  { 8, "Pose/y_m", 0, EXT_IN, 1, 1, 1 },

  { 9, "Pose/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 10, "Observer2/Noise gain", 0, EXT_IN, 1, 1, 1 },

  { 11, "Observer2/Observer gain L1//L2", 0, EXT_IN, 1, 1, 1 },

  { 12, "Observer2/Observer gain L3", 0, EXT_IN, 1, 1, 1 },

  { 13, "IMU/Acc_z", 1, EXT_IN, 1, 1, 1 },

  { 14, "IMU/Acc_x", 1, EXT_IN, 1, 1, 1 },

  { 15, "IMU/Acc_y", 1, EXT_IN, 1, 1, 1 },

  { 16, "IMU/Gyro_x", 1, EXT_IN, 1, 1, 1 },

  { 17, "IMU/Gyro_y", 1, EXT_IN, 1, 1, 1 },

  { 18, "IMU/Gyro_z", 1, EXT_IN, 1, 1, 1 },

  { 1, "eta_hat", 0, EXT_OUT, 3, 3, 1 },

  { 2, "nu_hat", 0, EXT_OUT, 3, 3, 1 },

  { 3, "b_hat", 0, EXT_OUT, 3, 3, 1 },

  { 4, "tau simple1", 0, EXT_OUT, 1, 1, 1 },

  { 5, "tau simple2", 1, EXT_OUT, 1, 1, 1 },

  { 6, "tau simple3", 0, EXT_OUT, 1, 1, 1 },

  { 7, "tau full1", 0, EXT_OUT, 1, 1, 1 },

  { 8, "tau full2", 0, EXT_OUT, 1, 1, 1 },

  { 9, "tau full3", 0, EXT_OUT, 1, 1, 1 },

  { 10, "tau simple", 0, EXT_OUT, 3, 3, 1 },

  { 11, "tau full", 0, EXT_OUT, 3, 3, 1 },

  { 12, "eta_testing", 0, EXT_OUT, 3, 3, 1 },

  { 13, "QTM_SCOPEPSI", 0, EXT_OUT, 1, 1, 1 },

  { 14, "QTM_SCOPEX", 0, EXT_OUT, 1, 1, 1 },

  { 15, "QTM_SCOPEY", 0, EXT_OUT, 1, 1, 1 },

  { 16, "selector full", 0, EXT_OUT, 1, 1, 1 },

  { 17, "selector simple", 0, EXT_OUT, 1, 1, 1 },

  { 18, "u/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 19, "u/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 20, "u/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 21, "u/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 22, "u/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 23, "u/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 24, "u/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Observer2/Eta_bar", 0, EXT_OUT, 3, 3, 1 },

  { 26, "IMU/IMU_SCOPEZ", 1, EXT_OUT, 1, 1, 1 },

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
static const char* NI_CompiledModelVersion = "1.116";
static const char* NI_CompiledModelDateTime = "Tue Mar 05 17:25:43 2019";
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
      *numContStates = 9;
      *numDiscStates = 590;
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posXLeft_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Selector_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Selector_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posXRight_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.R2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.R2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.L2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.L2_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tausimple1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tausimple1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tausimple2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tausimple2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tausimple3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tausimple3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tausimple_DWORK1,
      0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tausimple_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tausimple_DWORK1,
      1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tausimple_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tausimple_DWORK1,
      2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tausimple_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull_DWORK1, 0,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull_DWORK1, 1,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull_DWORK1, 2,
      18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_testing_DWORK1,
      0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_testing_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_testing_DWORK1,
      1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_testing_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_testing_DWORK1,
      2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_testing_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.QTM_SCOPEPSI_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.QTM_SCOPEPSI_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.QTM_SCOPEX_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.QTM_SCOPEX_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.QTM_SCOPEY_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.QTM_SCOPEY_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Memory1_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.selectorfull_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.selectorfull_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.selectorsimple_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.selectorsimple_DWORK1");
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
      (&ctrl_custom_DW.ObservergainL1L2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ObservergainL1L2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ObservergainL3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ObservergainL3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.IMU_SCOPEZ_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.IMU_SCOPEZ_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.RandSeed");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posYLeft_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posXLeft_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posXLeft_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Selector_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Selector_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.posXRight_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.posXRight_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.R2_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.R2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.L2_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.L2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.eta_hat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_hat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.b_hat_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.b_hat_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.tausimple1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.tausimple1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.tausimple2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.tausimple2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.tausimple3_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.tausimple3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull3_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.tausimple_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.tausimple_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.taufull_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.taufull_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.eta_testing_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.eta_testing_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.QTM_SCOPEPSI_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.QTM_SCOPEPSI_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.QTM_SCOPEX_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.QTM_SCOPEX_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.QTM_SCOPEY_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.QTM_SCOPEY_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.selectorfull_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.selectorfull_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.selectorsimple_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.selectorsimple_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.alpha_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.omega_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.omega_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.alpha_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_BT_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Noisegain_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Noisegain_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Eta_bar_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.ObservergainL1L2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.ObservergainL1L2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.ObservergainL3_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.ObservergainL3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.IMU_SCOPEZ_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.IMU_SCOPEZ_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK2");
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
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 2,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.posXLeft_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Selector_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.posXRight_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.R2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.L2_DWORK1, 0, discStates[idx++], 0,
      0);
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
    NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple3_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.taufull1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.taufull2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.taufull3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple_DWORK1, 0, discStates[idx
      ++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple_DWORK1, 1, discStates[idx
      ++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple_DWORK1, 2, discStates[idx
      ++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.taufull_DWORK1, 0, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.taufull_DWORK1, 1, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.taufull_DWORK1, 2, discStates[idx++],
      18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_testing_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_testing_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.eta_testing_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEPSI_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEX_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEY_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.selectorfull_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.selectorsimple_DWORK1, 0,
      discStates[idx++], 0, 0);
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
    NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL1L2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.IMU_SCOPEZ_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.RandSeed, 0, discStates[idx++], 7, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.posYLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.posXLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Selector_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.posXRight_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.R2_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.L2_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.eta_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.nu_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.b_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.taufull1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.taufull2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.taufull3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.tausimple_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.taufull_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.eta_testing_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEPSI_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEX_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.QTM_SCOPEY_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.selectorfull_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.selectorsimple_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_BT_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Noisegain_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Eta_bar_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL1L2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.ObservergainL3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.IMU_SCOPEZ_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_custom
