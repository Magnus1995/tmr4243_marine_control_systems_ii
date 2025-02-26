/*
 * CSE1_HIL_u.h
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

#ifndef RTW_HEADER_CSE1_HIL_u_h_
#define RTW_HEADER_CSE1_HIL_u_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef CSE1_HIL_u_COMMON_INCLUDES_
# define CSE1_HIL_u_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* CSE1_HIL_u_COMMON_INCLUDES_ */

#include "CSE1_HIL_u_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define CSE1_HIL_u_rtModel             RT_MODEL_CSE1_HIL_u_T

/* Block signals for system '<S8>/VSP' */
typedef struct {
  real_T F_x;                          /* '<S8>/VSP' */
  real_T F_y;                          /* '<S8>/VSP' */
} B_VSP_CSE1_HIL_u_T;

/* Block signals (auto storage) */
typedef struct {
  real_T integrator_reset;             /* '<Root>/integrator_reset' */
  real_T Memory3;                      /* '<S3>/Memory3' */
  real_T Memory4;                      /* '<S3>/Memory4' */
  real_T Memory5;                      /* '<S3>/Memory5' */
  real_T Position[3];                  /* '<S9>/Position' */
  real_T Velocity[3];                  /* '<S9>/Velocity' */
  real_T u_BT;                         /* '<S7>/u_BT' */
  real_T u_VSP1;                       /* '<S7>/u_VSP1' */
  real_T u_VSP2;                       /* '<S7>/u_VSP2' */
  real_T alpha_VSP1;                   /* '<S7>/alpha_VSP1' */
  real_T alpha_VSP2;                   /* '<S7>/alpha_VSP2' */
  real_T omega_VSP1;                   /* '<S7>/omega_VSP1' */
  real_T omega_VSP2;                   /* '<S7>/omega_VSP2' */
  real_T Sum;                          /* '<S8>/Sum' */
  real_T Add1;                         /* '<S8>/Add1' */
  real_T Gain1;                        /* '<S8>/Gain1' */
  real_T Add;                          /* '<S8>/Add' */
  real_T psi_0;                        /* '<S3>/psi_0' */
  real_T x_0;                          /* '<S3>/x_0' */
  real_T y_0;                          /* '<S3>/y_0' */
  real_T nu_dot[3];                    /* '<S9>/kinetics' */
  real_T eta_dot[3];                   /* '<S9>/kinematics' */
  B_VSP_CSE1_HIL_u_T sf_VSP1;          /* '<S8>/VSP1' */
  B_VSP_CSE1_HIL_u_T sf_VSP;           /* '<S8>/VSP' */
} B_CSE1_HIL_u_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T integrator_reset_DWORK1;      /* '<Root>/integrator_reset' */
  real_T Memory3_PreviousInput;        /* '<S3>/Memory3' */
  real_T Memory4_PreviousInput;        /* '<S3>/Memory4' */
  real_T Memory5_PreviousInput;        /* '<S3>/Memory5' */
  real_T x_DWORK1;                     /* '<S2>/x' */
  real_T y_DWORK1;                     /* '<S2>/y' */
  real_T psi_DWORK1;                   /* '<S2>/psi' */
  real_T r_DWORK1;                     /* '<S4>/r' */
  real_T u_DWORK1;                     /* '<S4>/u' */
  real_T v_DWORK1;                     /* '<S4>/v' */
  real_T u_BT_DWORK1;                  /* '<S7>/u_BT' */
  real_T u_VSP1_DWORK1;                /* '<S7>/u_VSP1' */
  real_T u_VSP2_DWORK1;                /* '<S7>/u_VSP2' */
  real_T alpha_VSP1_DWORK1;            /* '<S7>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1;            /* '<S7>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<S7>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S7>/omega_VSP2' */
  real_T r_dot_DWORK1;                 /* '<S5>/r_dot' */
  real_T u_dot_DWORK1;                 /* '<S5>/u_dot' */
  real_T v_dot_DWORK1;                 /* '<S5>/v_dot' */
  real_T zeroout_DWORK1;               /* '<S5>/zeroout' */
  real_T r_dot1_DWORK1;                /* '<S5>/r_dot1' */
  real_T u_dot1_DWORK1;                /* '<S5>/u_dot1' */
  real_T v_dot1_DWORK1;                /* '<S5>/v_dot1' */
  real_T X_DWORK1;                     /* '<S6>/X' */
  real_T Y_DWORK1;                     /* '<S6>/Y' */
  real_T N_DWORK1;                     /* '<S6>/N' */
  real_T psi_0_DWORK1;                 /* '<S3>/psi_0' */
  real_T x_0_DWORK1;                   /* '<S3>/x_0' */
  real_T y_0_DWORK1;                   /* '<S3>/y_0' */
  int_T Position_IWORK;                /* '<S9>/Position' */
  uint8_T integrator_reset_DWORK2[11]; /* '<Root>/integrator_reset' */
  uint8_T x_DWORK2[11];                /* '<S2>/x' */
  uint8_T y_DWORK2[11];                /* '<S2>/y' */
  uint8_T psi_DWORK2[11];              /* '<S2>/psi' */
  uint8_T r_DWORK2[11];                /* '<S4>/r' */
  uint8_T u_DWORK2[11];                /* '<S4>/u' */
  uint8_T v_DWORK2[11];                /* '<S4>/v' */
  uint8_T u_BT_DWORK2[11];             /* '<S7>/u_BT' */
  uint8_T u_VSP1_DWORK2[11];           /* '<S7>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[11];           /* '<S7>/u_VSP2' */
  uint8_T alpha_VSP1_DWORK2[11];       /* '<S7>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2[11];       /* '<S7>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2[11];       /* '<S7>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[11];       /* '<S7>/omega_VSP2' */
  uint8_T r_dot_DWORK2[11];            /* '<S5>/r_dot' */
  uint8_T u_dot_DWORK2[11];            /* '<S5>/u_dot' */
  uint8_T v_dot_DWORK2[11];            /* '<S5>/v_dot' */
  uint8_T zeroout_DWORK2[11];          /* '<S5>/zeroout' */
  uint8_T r_dot1_DWORK2[11];           /* '<S5>/r_dot1' */
  uint8_T u_dot1_DWORK2[11];           /* '<S5>/u_dot1' */
  uint8_T v_dot1_DWORK2[11];           /* '<S5>/v_dot1' */
  uint8_T X_DWORK2[11];                /* '<S6>/X' */
  uint8_T Y_DWORK2[11];                /* '<S6>/Y' */
  uint8_T N_DWORK2[11];                /* '<S6>/N' */
  uint8_T psi_0_DWORK2[11];            /* '<S3>/psi_0' */
  uint8_T x_0_DWORK2[11];              /* '<S3>/x_0' */
  uint8_T y_0_DWORK2[11];              /* '<S3>/y_0' */
} DW_CSE1_HIL_u_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Position_CSTATE[3];           /* '<S9>/Position' */
  real_T Velocity_CSTATE[3];           /* '<S9>/Velocity' */
} X_CSE1_HIL_u_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Position_CSTATE[3];           /* '<S9>/Position' */
  real_T Velocity_CSTATE[3];           /* '<S9>/Velocity' */
} XDot_CSE1_HIL_u_T;

/* State disabled  */
typedef struct {
  boolean_T Position_CSTATE[3];        /* '<S9>/Position' */
  boolean_T Velocity_CSTATE[3];        /* '<S9>/Velocity' */
} XDis_CSE1_HIL_u_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Position_Reset_ZCE;       /* '<S9>/Position' */
  ZCSigState Velocity_Reset_ZCE;       /* '<S9>/Velocity' */
} PrevZCX_CSE1_HIL_u_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            CSE1_HIL_u_B
#define BlockIO                        B_CSE1_HIL_u_T
#define rtX                            CSE1_HIL_u_X
#define ContinuousStates               X_CSE1_HIL_u_T
#define rtXdot                         CSE1_HIL_u_XDot
#define StateDerivatives               XDot_CSE1_HIL_u_T
#define tXdis                          CSE1_HIL_u_XDis
#define StateDisabled                  XDis_CSE1_HIL_u_T
#define rtP                            CSE1_HIL_u_P
#define Parameters                     P_CSE1_HIL_u_T
#define rtDWork                        CSE1_HIL_u_DW
#define D_Work                         DW_CSE1_HIL_u_T
#define rtPrevZCSigState               CSE1_HIL_u_PrevZCX
#define PrevZCSigStates                PrevZCX_CSE1_HIL_u_T

/* Parameters (auto storage) */
struct P_CSE1_HIL_u_T_ {
  real_T integrator_reset_P1;          /* Expression: width
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  real_T integrator_reset_P2;          /* Expression: dtype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  real_T integrator_reset_P3;          /* Expression: portnum
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  real_T integrator_reset_P4;          /* Expression: stime
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  real_T integrator_reset_P5;          /* Expression: stype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  real_T integrator_reset_P6;          /* Expression: btype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S3>/Memory3'
                                        */
  real_T Memory4_X0;                   /* Expression: 0
                                        * Referenced by: '<S3>/Memory4'
                                        */
  real_T Memory5_X0;                   /* Expression: 0
                                        * Referenced by: '<S3>/Memory5'
                                        */
  real_T x_P1;                         /* Expression: width
                                        * Referenced by: '<S2>/x'
                                        */
  real_T x_P2;                         /* Expression: dtype
                                        * Referenced by: '<S2>/x'
                                        */
  real_T x_P3;                         /* Expression: portnum
                                        * Referenced by: '<S2>/x'
                                        */
  real_T x_P4;                         /* Expression: stime
                                        * Referenced by: '<S2>/x'
                                        */
  real_T x_P5;                         /* Expression: stype
                                        * Referenced by: '<S2>/x'
                                        */
  real_T x_P6;                         /* Expression: btype
                                        * Referenced by: '<S2>/x'
                                        */
  real_T y_P1;                         /* Expression: width
                                        * Referenced by: '<S2>/y'
                                        */
  real_T y_P2;                         /* Expression: dtype
                                        * Referenced by: '<S2>/y'
                                        */
  real_T y_P3;                         /* Expression: portnum
                                        * Referenced by: '<S2>/y'
                                        */
  real_T y_P4;                         /* Expression: stime
                                        * Referenced by: '<S2>/y'
                                        */
  real_T y_P5;                         /* Expression: stype
                                        * Referenced by: '<S2>/y'
                                        */
  real_T y_P6;                         /* Expression: btype
                                        * Referenced by: '<S2>/y'
                                        */
  real_T psi_P1;                       /* Expression: width
                                        * Referenced by: '<S2>/psi'
                                        */
  real_T psi_P2;                       /* Expression: dtype
                                        * Referenced by: '<S2>/psi'
                                        */
  real_T psi_P3;                       /* Expression: portnum
                                        * Referenced by: '<S2>/psi'
                                        */
  real_T psi_P4;                       /* Expression: stime
                                        * Referenced by: '<S2>/psi'
                                        */
  real_T psi_P5;                       /* Expression: stype
                                        * Referenced by: '<S2>/psi'
                                        */
  real_T psi_P6;                       /* Expression: btype
                                        * Referenced by: '<S2>/psi'
                                        */
  real_T Velocity_IC[3];               /* Expression: [0 0 0]'
                                        * Referenced by: '<S9>/Velocity'
                                        */
  real_T r_P1;                         /* Expression: width
                                        * Referenced by: '<S4>/r'
                                        */
  real_T r_P2;                         /* Expression: dtype
                                        * Referenced by: '<S4>/r'
                                        */
  real_T r_P3;                         /* Expression: portnum
                                        * Referenced by: '<S4>/r'
                                        */
  real_T r_P4;                         /* Expression: stime
                                        * Referenced by: '<S4>/r'
                                        */
  real_T r_P5;                         /* Expression: stype
                                        * Referenced by: '<S4>/r'
                                        */
  real_T r_P6;                         /* Expression: btype
                                        * Referenced by: '<S4>/r'
                                        */
  real_T u_P1;                         /* Expression: width
                                        * Referenced by: '<S4>/u'
                                        */
  real_T u_P2;                         /* Expression: dtype
                                        * Referenced by: '<S4>/u'
                                        */
  real_T u_P3;                         /* Expression: portnum
                                        * Referenced by: '<S4>/u'
                                        */
  real_T u_P4;                         /* Expression: stime
                                        * Referenced by: '<S4>/u'
                                        */
  real_T u_P5;                         /* Expression: stype
                                        * Referenced by: '<S4>/u'
                                        */
  real_T u_P6;                         /* Expression: btype
                                        * Referenced by: '<S4>/u'
                                        */
  real_T v_P1;                         /* Expression: width
                                        * Referenced by: '<S4>/v'
                                        */
  real_T v_P2;                         /* Expression: dtype
                                        * Referenced by: '<S4>/v'
                                        */
  real_T v_P3;                         /* Expression: portnum
                                        * Referenced by: '<S4>/v'
                                        */
  real_T v_P4;                         /* Expression: stime
                                        * Referenced by: '<S4>/v'
                                        */
  real_T v_P5;                         /* Expression: stype
                                        * Referenced by: '<S4>/v'
                                        */
  real_T v_P6;                         /* Expression: btype
                                        * Referenced by: '<S4>/v'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  real_T L_BTX_Value;                  /* Expression: 0.3875
                                        * Referenced by: '<S8>/L_BTX'
                                        */
  real_T L_VSPy_Value;                 /* Expression: 0.055
                                        * Referenced by: '<S8>/L_VSPy'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T L_VSP_Value;                  /* Expression: -0.4575;
                                        * Referenced by: '<S8>/L_VSP'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T r_dot_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/r_dot'
                                        */
  real_T r_dot_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/r_dot'
                                        */
  real_T r_dot_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/r_dot'
                                        */
  real_T r_dot_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/r_dot'
                                        */
  real_T r_dot_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/r_dot'
                                        */
  real_T r_dot_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/r_dot'
                                        */
  real_T u_dot_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/u_dot'
                                        */
  real_T u_dot_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/u_dot'
                                        */
  real_T u_dot_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/u_dot'
                                        */
  real_T u_dot_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/u_dot'
                                        */
  real_T u_dot_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/u_dot'
                                        */
  real_T u_dot_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/u_dot'
                                        */
  real_T v_dot_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/v_dot'
                                        */
  real_T v_dot_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/v_dot'
                                        */
  real_T v_dot_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/v_dot'
                                        */
  real_T v_dot_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/v_dot'
                                        */
  real_T v_dot_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/v_dot'
                                        */
  real_T v_dot_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/v_dot'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T zeroout_P1;                   /* Expression: width
                                        * Referenced by: '<S5>/zeroout'
                                        */
  real_T zeroout_P2;                   /* Expression: dtype
                                        * Referenced by: '<S5>/zeroout'
                                        */
  real_T zeroout_P3;                   /* Expression: portnum
                                        * Referenced by: '<S5>/zeroout'
                                        */
  real_T zeroout_P4;                   /* Expression: stime
                                        * Referenced by: '<S5>/zeroout'
                                        */
  real_T zeroout_P5;                   /* Expression: stype
                                        * Referenced by: '<S5>/zeroout'
                                        */
  real_T zeroout_P6;                   /* Expression: btype
                                        * Referenced by: '<S5>/zeroout'
                                        */
  real_T r_dot1_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  real_T r_dot1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  real_T r_dot1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  real_T r_dot1_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  real_T r_dot1_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  real_T r_dot1_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/r_dot1'
                                        */
  real_T u_dot1_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  real_T u_dot1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  real_T u_dot1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  real_T u_dot1_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  real_T u_dot1_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  real_T u_dot1_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/u_dot1'
                                        */
  real_T v_dot1_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  real_T v_dot1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  real_T v_dot1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  real_T v_dot1_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  real_T v_dot1_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  real_T v_dot1_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/v_dot1'
                                        */
  real_T X_P1;                         /* Expression: width
                                        * Referenced by: '<S6>/X'
                                        */
  real_T X_P2;                         /* Expression: dtype
                                        * Referenced by: '<S6>/X'
                                        */
  real_T X_P3;                         /* Expression: portnum
                                        * Referenced by: '<S6>/X'
                                        */
  real_T X_P4;                         /* Expression: stime
                                        * Referenced by: '<S6>/X'
                                        */
  real_T X_P5;                         /* Expression: stype
                                        * Referenced by: '<S6>/X'
                                        */
  real_T X_P6;                         /* Expression: btype
                                        * Referenced by: '<S6>/X'
                                        */
  real_T Y_P1;                         /* Expression: width
                                        * Referenced by: '<S6>/Y'
                                        */
  real_T Y_P2;                         /* Expression: dtype
                                        * Referenced by: '<S6>/Y'
                                        */
  real_T Y_P3;                         /* Expression: portnum
                                        * Referenced by: '<S6>/Y'
                                        */
  real_T Y_P4;                         /* Expression: stime
                                        * Referenced by: '<S6>/Y'
                                        */
  real_T Y_P5;                         /* Expression: stype
                                        * Referenced by: '<S6>/Y'
                                        */
  real_T Y_P6;                         /* Expression: btype
                                        * Referenced by: '<S6>/Y'
                                        */
  real_T N_P1;                         /* Expression: width
                                        * Referenced by: '<S6>/N'
                                        */
  real_T N_P2;                         /* Expression: dtype
                                        * Referenced by: '<S6>/N'
                                        */
  real_T N_P3;                         /* Expression: portnum
                                        * Referenced by: '<S6>/N'
                                        */
  real_T N_P4;                         /* Expression: stime
                                        * Referenced by: '<S6>/N'
                                        */
  real_T N_P5;                         /* Expression: stype
                                        * Referenced by: '<S6>/N'
                                        */
  real_T N_P6;                         /* Expression: btype
                                        * Referenced by: '<S6>/N'
                                        */
  real_T psi_0_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/psi_0'
                                        */
  real_T psi_0_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/psi_0'
                                        */
  real_T psi_0_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/psi_0'
                                        */
  real_T psi_0_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/psi_0'
                                        */
  real_T psi_0_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/psi_0'
                                        */
  real_T psi_0_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/psi_0'
                                        */
  real_T x_0_P1;                       /* Expression: width
                                        * Referenced by: '<S3>/x_0'
                                        */
  real_T x_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S3>/x_0'
                                        */
  real_T x_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S3>/x_0'
                                        */
  real_T x_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S3>/x_0'
                                        */
  real_T x_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S3>/x_0'
                                        */
  real_T x_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S3>/x_0'
                                        */
  real_T y_0_P1;                       /* Expression: width
                                        * Referenced by: '<S3>/y_0'
                                        */
  real_T y_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S3>/y_0'
                                        */
  real_T y_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S3>/y_0'
                                        */
  real_T y_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S3>/y_0'
                                        */
  real_T y_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S3>/y_0'
                                        */
  real_T y_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S3>/y_0'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_CSE1_HIL_u_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[6];
  real_T odeF[4][6];
  ODE4_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_CSE1_HIL_u_T CSE1_HIL_u_P;

/* Block signals (auto storage) */
extern B_CSE1_HIL_u_T CSE1_HIL_u_B;

/* Continuous states (auto storage) */
extern X_CSE1_HIL_u_T CSE1_HIL_u_X;

/* Block states (auto storage) */
extern DW_CSE1_HIL_u_T CSE1_HIL_u_DW;

/* Model entry point functions */
extern void CSE1_HIL_u_initialize(void);
extern void CSE1_HIL_u_output(void);
extern void CSE1_HIL_u_update(void);
extern void CSE1_HIL_u_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern CSE1_HIL_u_rtModel *CSE1_HIL_u(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_CSE1_HIL_u_T *const CSE1_HIL_u_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CSE1_HIL_u'
 * '<S1>'   : 'CSE1_HIL_u/Simulator_CSE1'
 * '<S2>'   : 'CSE1_HIL_u/eta'
 * '<S3>'   : 'CSE1_HIL_u/eta_0'
 * '<S4>'   : 'CSE1_HIL_u/nu'
 * '<S5>'   : 'CSE1_HIL_u/nu_dot'
 * '<S6>'   : 'CSE1_HIL_u/tau'
 * '<S7>'   : 'CSE1_HIL_u/u'
 * '<S8>'   : 'CSE1_HIL_u/Simulator_CSE1/Command2force'
 * '<S9>'   : 'CSE1_HIL_u/Simulator_CSE1/EquationsOfMotion_FossenModel'
 * '<S10>'  : 'CSE1_HIL_u/Simulator_CSE1/Command2force/Bow thruster'
 * '<S11>'  : 'CSE1_HIL_u/Simulator_CSE1/Command2force/VSP'
 * '<S12>'  : 'CSE1_HIL_u/Simulator_CSE1/Command2force/VSP1'
 * '<S13>'  : 'CSE1_HIL_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinematics'
 * '<S14>'  : 'CSE1_HIL_u/Simulator_CSE1/EquationsOfMotion_FossenModel/kinetics'
 */
#endif                                 /* RTW_HEADER_CSE1_HIL_u_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : CSE1_HIL_u
 * Model version : 1.48
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Thu Feb 07 14:39:49 2019
 *========================================================================*/
#if !defined(NI_HEADER_CSE1_HIL_u_h_)
#define NI_HEADER_CSE1_HIL_u_h_
#ifdef NI_ROOTMODEL_CSE1_HIL_u

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* CSE1_HIL_u.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_CSE1_HIL_u_T rtParameter[NUMST+!TID01EQ];
P_CSE1_HIL_u_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_CSE1_HIL_u_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_CSE1_HIL_u_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_CSE1_HIL_u_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_CSE1_HIL_u_h_ */
