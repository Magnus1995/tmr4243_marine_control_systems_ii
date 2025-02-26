/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : CSE1_HIL_u
 * Model version : 1.48
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Feb 07 14:39:49 2019
 *========================================================================*/

/*
 * Note:
 *   This file was generated by the main model, CSE1_HIL_u.
 *   This file redirects parameter references to the NI VeriStand rtParameter buffer.
 *
 *   In a model reference configuration, this file defines the globally shared parameter structure
 *   across all model references. All models must share the same type definition for proper execution.
 *
 */
#if !defined(_DEFINED_TYPEDEF_FOR_niUrtParametersTypeDef_)
#define _DEFINED_TYPEDEF_FOR_niUrtParametersTypeDef_

/* Parameters typedef identifier */
#define NI_PARAM_TYPEDEF               P_CSE1_HIL_u_T
#endif

#if defined(_NI_DEFINE_PARAMS_DBL_BUFFER_)
#undef _NI_DEFINE_PARAMS_DBL_BUFFER_
#ifdef MULTITASKING
#define NI_PARAM_BUFF                  (*param_lookup[tid][READSIDE])
#else
#define NI_PARAM_BUFF                  rtParameter[READSIDE]
#endif

#define CSE1_HIL_u_P                   NI_PARAM_BUFF
#elif defined(_NI_UNDEFINE_PARAMS_DBL_BUFFER_)
#undef _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#undef CSE1_HIL_u_P
#endif
