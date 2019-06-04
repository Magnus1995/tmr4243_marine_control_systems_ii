/*
 * ctrl_custom.h
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

#ifndef RTW_HEADER_ctrl_custom_h_
#define RTW_HEADER_ctrl_custom_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_custom_COMMON_INCLUDES_
# define ctrl_custom_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_custom_COMMON_INCLUDES_ */

#include "ctrl_custom_types.h"

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
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
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
#define ctrl_custom_rtModel            RT_MODEL_ctrl_custom_T

/* Block signals (auto storage) */
typedef struct {
  real_T NIVeriStandIn2;               /* '<Root>/NIVeriStand In2' */
  real_T posXRight;                    /* '<Root>/posXRight' */
  real_T R2;                           /* '<Root>/R2' */
  real_T L2;                           /* '<Root>/L2' */
  real_T posYLeft;                     /* '<Root>/posYLeft' */
  real_T controlswitch;                /* '<S1>/control switch' */
  real_T path;                         /* '<S1>/path' */
  real_T mu;                           /* '<S1>/mu' */
  real_T U_ref;                        /* '<S1>/U_ref' */
  real_T rx;                           /* '<S1>/rx' */
  real_T ry;                           /* '<S1>/ry' */
  real_T Kp;                           /* '<S1>/Kp ' */
  real_T Kd;                           /* '<S1>/Kd' */
  real_T x_m;                          /* '<S4>/x_m' */
  real_T y_m;                          /* '<S4>/y_m' */
  real_T psi_m;                        /* '<S4>/psi_m' */
  real_T Memory1[3];                   /* '<S7>/Memory1' */
  real_T Memory;                       /* '<S7>/Memory' */
  real_T Memory_p[3];                  /* '<S1>/Memory' */
  real_T Memory1_g;                    /* '<S1>/Memory1' */
  real_T Integrator[3];                /* '<S3>/Integrator' */
  real_T Integrator1[3];               /* '<S3>/Integrator1' */
  real_T Integrator1_m;                /* '<S1>/Integrator1' */
  real_T Memory3;                      /* '<S1>/Memory3' */
  real_T Memory2[3];                   /* '<S1>/Memory2' */
  real_T Sum1[3];                      /* '<Root>/Sum1' */
  real_T Saturation2;                  /* '<S11>/Saturation2' */
  real_T Saturation11;                 /* '<S11>/Saturation11' */
  real_T Saturation1;                  /* '<S11>/Saturation1' */
  real_T Integrator2[3];               /* '<S3>/Integrator2' */
  real_T Memory1_p[3];                 /* '<Root>/Memory1' */
  real_T Memory2_b[3];                 /* '<Root>/Memory2' */
  real_T Memory3_k[3];                 /* '<Root>/Memory3' */
  real_T Noisegain;                    /* '<S3>/Noise gain' */
  real_T L4[3];                        /* '<S3>/L4' */
  real_T Sum[3];                       /* '<S3>/Sum' */
  real_T ObservergainL1;               /* '<S3>/Observer gain L1' */
  real_T ObservergainL3;               /* '<S3>/Observer gain L3' */
  real_T ObservergainL2;               /* '<S3>/Observer gain L2' */
  real_T Product[3];                   /* '<S3>/Product' */
  real_T Product7[3];                  /* '<S3>/Product7' */
  real_T Sum2[3];                      /* '<S3>/Sum2' */
  real_T tau[3];                       /* '<S12>/u_to_tau_mapping' */
  real_T last[3];                      /* '<Root>/dead_reckoning' */
  real_T last2[3];                     /* '<Root>/dead_reckoning' */
  real_T last3[3];                     /* '<Root>/dead_reckoning' */
  real_T eta_new[3];                   /* '<S7>/MATLAB Function' */
  real_T j_new;                        /* '<S7>/MATLAB Function' */
  real_T u_ext[5];                     /* '<S6>/MATLAB Function' */
  real_T y[9];                         /* '<S3>/Inverse' */
  real_T s_reset;                      /* '<S1>/MATLAB Function' */
  real_T eta_0_new[3];                 /* '<S1>/MATLAB Function' */
  real_T switch_signal_new;            /* '<S1>/MATLAB Function' */
  real_T pd[3];                        /* '<S1>/Control law' */
  real_T s_dot;                        /* '<S1>/Control law' */
  real_T j_path_curr;                  /* '<S1>/Control law' */
  real_T pd_curr[3];                   /* '<S1>/Control law' */
} B_ctrl_custom_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T NIVeriStandIn2_DWORK1;        /* '<Root>/NIVeriStand In2' */
  real_T posXRight_DWORK1;             /* '<Root>/posXRight' */
  real_T R2_DWORK1;                    /* '<Root>/R2' */
  real_T L2_DWORK1;                    /* '<Root>/L2' */
  real_T posYLeft_DWORK1;              /* '<Root>/posYLeft' */
  real_T controlswitch_DWORK1;         /* '<S1>/control switch' */
  real_T path_DWORK1;                  /* '<S1>/path' */
  real_T mu_DWORK1;                    /* '<S1>/mu' */
  real_T U_ref_DWORK1;                 /* '<S1>/U_ref' */
  real_T rx_DWORK1;                    /* '<S1>/rx' */
  real_T ry_DWORK1;                    /* '<S1>/ry' */
  real_T Kp_DWORK1;                    /* '<S1>/Kp ' */
  real_T Kd_DWORK1;                    /* '<S1>/Kd' */
  real_T x_m_DWORK1;                   /* '<S4>/x_m' */
  real_T y_m_DWORK1;                   /* '<S4>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S4>/psi_m' */
  real_T Memory1_PreviousInput[3];     /* '<S7>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S7>/Memory' */
  real_T Memory_PreviousInput_f[3];    /* '<S1>/Memory' */
  real_T Memory1_PreviousInput_h;      /* '<S1>/Memory1' */
  real_T Memory3_PreviousInput;        /* '<S1>/Memory3' */
  real_T Memory2_PreviousInput[3];     /* '<S1>/Memory2' */
  real_T pd_DWORK1[3];                 /* '<S1>/pd' */
  real_T eta_0_out_DWORK1[3];          /* '<S1>/eta_0_out' */
  real_T s_out_DWORK1;                 /* '<S1>/s_out' */
  real_T j_control_DWORK1;             /* '<S1>/j_control ' */
  real_T tau_sat_DWORK1[3];            /* '<Root>/tau_sat' */
  real_T eta_hat_DWORK1[3];            /* '<Root>/eta_hat' */
  real_T nu_hat_DWORK1[3];             /* '<Root>/nu_hat' */
  real_T b_hat_DWORK1[3];              /* '<Root>/b_hat' */
  real_T tau_cmd_DWORK1[3];            /* '<Root>/tau_cmd' */
  real_T eta_measured_DWORK1[3];       /* '<Root>/eta_measured' */
  real_T alpha_VSP2_DWORK1;            /* '<S10>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<S10>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S10>/omega_VSP2' */
  real_T alpha_VSP1_DWORK1;            /* '<S10>/alpha_VSP1' */
  real_T u_BT_DWORK1;                  /* '<S10>/u_BT' */
  real_T u_VSP1_DWORK1;                /* '<S10>/u_VSP1' */
  real_T u_VSP2_DWORK1;                /* '<S10>/u_VSP2' */
  real_T Memory1_PreviousInput_e[3];   /* '<Root>/Memory1' */
  real_T Memory2_PreviousInput_i[3];   /* '<Root>/Memory2' */
  real_T Memory3_PreviousInput_b[3];   /* '<Root>/Memory3' */
  real_T NextOutput;                   /* '<S16>/White Noise' */
  real_T Noisegain_DWORK1;             /* '<S3>/Noise gain' */
  real_T Eta_bar_DWORK1[3];            /* '<S3>/Eta_bar' */
  real_T ObservergainL1_DWORK1;        /* '<S3>/Observer gain L1' */
  real_T ObservergainL3_DWORK1;        /* '<S3>/Observer gain L3' */
  real_T ObservergainL2_DWORK1;        /* '<S3>/Observer gain L2' */
  real_T j_measurement_DWORK1;         /* '<S7>/j_measurement ' */
  uint32_T RandSeed;                   /* '<S16>/White Noise' */
  uint8_T NIVeriStandIn2_DWORK2[12];   /* '<Root>/NIVeriStand In2' */
  uint8_T posXRight_DWORK2[12];        /* '<Root>/posXRight' */
  uint8_T R2_DWORK2[12];               /* '<Root>/R2' */
  uint8_T L2_DWORK2[12];               /* '<Root>/L2' */
  uint8_T posYLeft_DWORK2[12];         /* '<Root>/posYLeft' */
  uint8_T controlswitch_DWORK2[12];    /* '<S1>/control switch' */
  uint8_T path_DWORK2[12];             /* '<S1>/path' */
  uint8_T mu_DWORK2[12];               /* '<S1>/mu' */
  uint8_T U_ref_DWORK2[12];            /* '<S1>/U_ref' */
  uint8_T rx_DWORK2[12];               /* '<S1>/rx' */
  uint8_T ry_DWORK2[12];               /* '<S1>/ry' */
  uint8_T Kp_DWORK2[12];               /* '<S1>/Kp ' */
  uint8_T Kd_DWORK2[12];               /* '<S1>/Kd' */
  uint8_T x_m_DWORK2[12];              /* '<S4>/x_m' */
  uint8_T y_m_DWORK2[12];              /* '<S4>/y_m' */
  uint8_T psi_m_DWORK2[12];            /* '<S4>/psi_m' */
  uint8_T pd_DWORK2[12];               /* '<S1>/pd' */
  uint8_T eta_0_out_DWORK2[12];        /* '<S1>/eta_0_out' */
  uint8_T s_out_DWORK2[12];            /* '<S1>/s_out' */
  uint8_T j_control_DWORK2[12];        /* '<S1>/j_control ' */
  uint8_T tau_sat_DWORK2[12];          /* '<Root>/tau_sat' */
  uint8_T eta_hat_DWORK2[12];          /* '<Root>/eta_hat' */
  uint8_T nu_hat_DWORK2[12];           /* '<Root>/nu_hat' */
  uint8_T b_hat_DWORK2[12];            /* '<Root>/b_hat' */
  uint8_T tau_cmd_DWORK2[12];          /* '<Root>/tau_cmd' */
  uint8_T eta_measured_DWORK2[12];     /* '<Root>/eta_measured' */
  uint8_T alpha_VSP2_DWORK2[12];       /* '<S10>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2[12];       /* '<S10>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[12];       /* '<S10>/omega_VSP2' */
  uint8_T alpha_VSP1_DWORK2[12];       /* '<S10>/alpha_VSP1' */
  uint8_T u_BT_DWORK2[12];             /* '<S10>/u_BT' */
  uint8_T u_VSP1_DWORK2[12];           /* '<S10>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[12];           /* '<S10>/u_VSP2' */
  uint8_T Noisegain_DWORK2[12];        /* '<S3>/Noise gain' */
  uint8_T Eta_bar_DWORK2[12];          /* '<S3>/Eta_bar' */
  uint8_T ObservergainL1_DWORK2[12];   /* '<S3>/Observer gain L1' */
  uint8_T ObservergainL3_DWORK2[12];   /* '<S3>/Observer gain L3' */
  uint8_T ObservergainL2_DWORK2[12];   /* '<S3>/Observer gain L2' */
  uint8_T j_measurement_DWORK2[12];    /* '<S7>/j_measurement ' */
} DW_ctrl_custom_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_c;         /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S3>/Integrator2' */
} X_ctrl_custom_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_c;         /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S3>/Integrator2' */
} XDot_ctrl_custom_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S3>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S3>/Integrator1' */
  boolean_T Integrator1_CSTATE_c;      /* '<S1>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S3>/Integrator2' */
} XDis_ctrl_custom_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S1>/Integrator1' */
} PrevZCX_ctrl_custom_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_custom_B
#define BlockIO                        B_ctrl_custom_T
#define rtX                            ctrl_custom_X
#define ContinuousStates               X_ctrl_custom_T
#define rtXdot                         ctrl_custom_XDot
#define StateDerivatives               XDot_ctrl_custom_T
#define tXdis                          ctrl_custom_XDis
#define StateDisabled                  XDis_ctrl_custom_T
#define rtP                            ctrl_custom_P
#define Parameters                     P_ctrl_custom_T
#define rtDWork                        ctrl_custom_DW
#define D_Work                         DW_ctrl_custom_T
#define rtPrevZCSigState               ctrl_custom_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_custom_T

/* Parameters (auto storage) */
struct P_ctrl_custom_T_ {
  real_T NIVeriStandIn2_P1;            /* Expression: width
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  real_T NIVeriStandIn2_P2;            /* Expression: dtype
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  real_T NIVeriStandIn2_P3;            /* Expression: portnum
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  real_T NIVeriStandIn2_P4;            /* Expression: stime
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  real_T NIVeriStandIn2_P5;            /* Expression: stype
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  real_T NIVeriStandIn2_P6;            /* Expression: btype
                                        * Referenced by: '<Root>/NIVeriStand In2'
                                        */
  real_T posXRight_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/posXRight'
                                        */
  real_T posXRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/posXRight'
                                        */
  real_T posXRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/posXRight'
                                        */
  real_T posXRight_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/posXRight'
                                        */
  real_T posXRight_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/posXRight'
                                        */
  real_T posXRight_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/posXRight'
                                        */
  real_T R2_P1;                        /* Expression: width
                                        * Referenced by: '<Root>/R2'
                                        */
  real_T R2_P2;                        /* Expression: dtype
                                        * Referenced by: '<Root>/R2'
                                        */
  real_T R2_P3;                        /* Expression: portnum
                                        * Referenced by: '<Root>/R2'
                                        */
  real_T R2_P4;                        /* Expression: stime
                                        * Referenced by: '<Root>/R2'
                                        */
  real_T R2_P5;                        /* Expression: stype
                                        * Referenced by: '<Root>/R2'
                                        */
  real_T R2_P6;                        /* Expression: btype
                                        * Referenced by: '<Root>/R2'
                                        */
  real_T L2_P1;                        /* Expression: width
                                        * Referenced by: '<Root>/L2'
                                        */
  real_T L2_P2;                        /* Expression: dtype
                                        * Referenced by: '<Root>/L2'
                                        */
  real_T L2_P3;                        /* Expression: portnum
                                        * Referenced by: '<Root>/L2'
                                        */
  real_T L2_P4;                        /* Expression: stime
                                        * Referenced by: '<Root>/L2'
                                        */
  real_T L2_P5;                        /* Expression: stype
                                        * Referenced by: '<Root>/L2'
                                        */
  real_T L2_P6;                        /* Expression: btype
                                        * Referenced by: '<Root>/L2'
                                        */
  real_T posYLeft_P1;                  /* Expression: width
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  real_T posYLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  real_T posYLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  real_T posYLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  real_T posYLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  real_T posYLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<Root>/posYLeft'
                                        */
  real_T Gain_Gain;                    /* Expression: 2.06
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 4.689
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 1.96
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T controlswitch_P1;             /* Expression: width
                                        * Referenced by: '<S1>/control switch'
                                        */
  real_T controlswitch_P2;             /* Expression: dtype
                                        * Referenced by: '<S1>/control switch'
                                        */
  real_T controlswitch_P3;             /* Expression: portnum
                                        * Referenced by: '<S1>/control switch'
                                        */
  real_T controlswitch_P4;             /* Expression: stime
                                        * Referenced by: '<S1>/control switch'
                                        */
  real_T controlswitch_P5;             /* Expression: stype
                                        * Referenced by: '<S1>/control switch'
                                        */
  real_T controlswitch_P6;             /* Expression: btype
                                        * Referenced by: '<S1>/control switch'
                                        */
  real_T path_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/path'
                                        */
  real_T path_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/path'
                                        */
  real_T path_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/path'
                                        */
  real_T path_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/path'
                                        */
  real_T path_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/path'
                                        */
  real_T path_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/path'
                                        */
  real_T mu_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/mu'
                                        */
  real_T mu_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/mu'
                                        */
  real_T mu_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/mu'
                                        */
  real_T mu_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/mu'
                                        */
  real_T mu_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/mu'
                                        */
  real_T mu_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/mu'
                                        */
  real_T U_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/U_ref'
                                        */
  real_T U_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/U_ref'
                                        */
  real_T U_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/U_ref'
                                        */
  real_T U_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/U_ref'
                                        */
  real_T U_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/U_ref'
                                        */
  real_T U_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/U_ref'
                                        */
  real_T rx_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/rx'
                                        */
  real_T rx_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/rx'
                                        */
  real_T rx_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/rx'
                                        */
  real_T rx_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/rx'
                                        */
  real_T rx_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/rx'
                                        */
  real_T rx_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/rx'
                                        */
  real_T ry_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/ry'
                                        */
  real_T ry_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/ry'
                                        */
  real_T ry_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/ry'
                                        */
  real_T ry_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/ry'
                                        */
  real_T ry_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/ry'
                                        */
  real_T ry_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/ry'
                                        */
  real_T Kp_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/Kp '
                                        */
  real_T Kp_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/Kp '
                                        */
  real_T Kp_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/Kp '
                                        */
  real_T Kp_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/Kp '
                                        */
  real_T Kp_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/Kp '
                                        */
  real_T Kp_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/Kp '
                                        */
  real_T Gain_Gain_i[9];               /* Expression: eye(3)
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Kd_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Kd_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Kd_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Kd_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Kd_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Kd_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Gain1_Gain_f[9];              /* Expression: eye(3)
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T Memory1_X0[3];                /* Expression: [0;0;0]
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Memory_X0_n[3];               /* Expression: [0;0;0]
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Memory1_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T Integrator_IC[3];             /* Expression: [0 0 0]'
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Integrator1_IC_p;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */
  real_T Memory2_X0[3];                /* Expression: [0 0 0]'
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T pd_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/pd'
                                        */
  real_T pd_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/pd'
                                        */
  real_T pd_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/pd'
                                        */
  real_T pd_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/pd'
                                        */
  real_T pd_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/pd'
                                        */
  real_T pd_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/pd'
                                        */
  real_T eta_0_out_P1;                 /* Expression: width
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  real_T eta_0_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  real_T eta_0_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  real_T eta_0_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  real_T eta_0_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  real_T eta_0_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S1>/eta_0_out'
                                        */
  real_T s_out_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/s_out'
                                        */
  real_T s_out_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/s_out'
                                        */
  real_T s_out_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/s_out'
                                        */
  real_T s_out_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/s_out'
                                        */
  real_T s_out_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/s_out'
                                        */
  real_T s_out_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/s_out'
                                        */
  real_T j_control_P1;                 /* Expression: width
                                        * Referenced by: '<S1>/j_control '
                                        */
  real_T j_control_P2;                 /* Expression: dtype
                                        * Referenced by: '<S1>/j_control '
                                        */
  real_T j_control_P3;                 /* Expression: portnum
                                        * Referenced by: '<S1>/j_control '
                                        */
  real_T j_control_P4;                 /* Expression: stime
                                        * Referenced by: '<S1>/j_control '
                                        */
  real_T j_control_P5;                 /* Expression: stype
                                        * Referenced by: '<S1>/j_control '
                                        */
  real_T j_control_P6;                 /* Expression: btype
                                        * Referenced by: '<S1>/j_control '
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S11>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S11>/Saturation2'
                                        */
  real_T Saturation11_UpperSat;        /* Expression: 1
                                        * Referenced by: '<S11>/Saturation11'
                                        */
  real_T Saturation11_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S11>/Saturation11'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real_T Turnrate1_Value[2];           /* Expression: [0.3;0.3]
                                        * Referenced by: '<Root>/Turn rate1'
                                        */
  real_T tau_sat_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  real_T tau_sat_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  real_T tau_sat_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  real_T tau_sat_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  real_T tau_sat_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  real_T tau_sat_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/tau_sat'
                                        */
  real_T eta_hat_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T nu_hat_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  real_T nu_hat_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  real_T nu_hat_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  real_T nu_hat_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  real_T nu_hat_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  real_T nu_hat_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T b_hat_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/b_hat'
                                        */
  real_T b_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/b_hat'
                                        */
  real_T b_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/b_hat'
                                        */
  real_T b_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/b_hat'
                                        */
  real_T b_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/b_hat'
                                        */
  real_T b_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/b_hat'
                                        */
  real_T tau_cmd_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  real_T tau_cmd_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  real_T tau_cmd_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  real_T tau_cmd_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  real_T tau_cmd_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  real_T tau_cmd_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/tau_cmd'
                                        */
  real_T eta_measured_P1;              /* Expression: width
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  real_T eta_measured_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  real_T eta_measured_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  real_T eta_measured_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  real_T eta_measured_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  real_T eta_measured_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/eta_measured'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T Memory1_X0_ps[3];             /* Expression: [0 0 0]'
                                        * Referenced by: '<Root>/Memory1'
                                        */
  real_T Memory2_X0_d[3];              /* Expression: [0 0 0]'
                                        * Referenced by: '<Root>/Memory2'
                                        */
  real_T Memory3_X0_f[3];              /* Expression: [0 0 0]'
                                        * Referenced by: '<Root>/Memory3'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S16>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S16>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: seed
                                        * Referenced by: '<S16>/White Noise'
                                        */
  real_T Output_Gain;                  /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * Referenced by: '<S16>/Output'
                                        */
  real_T Noisegain_P1;                 /* Expression: width
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  real_T Noisegain_P2;                 /* Expression: dtype
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  real_T Noisegain_P3;                 /* Expression: portnum
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  real_T Noisegain_P4;                 /* Expression: stime
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  real_T Noisegain_P5;                 /* Expression: stype
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  real_T Noisegain_P6;                 /* Expression: btype
                                        * Referenced by: '<S3>/Noise gain'
                                        */
  real_T L5_Gain[9];                   /* Expression: eye(3)
                                        * Referenced by: '<S3>/L5'
                                        */
  real_T L4_Gain[3];                   /* Expression: [1;1;1]
                                        * Referenced by: '<S3>/L4'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Eta_bar_P1;                   /* Expression: width
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  real_T Eta_bar_P2;                   /* Expression: dtype
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  real_T Eta_bar_P3;                   /* Expression: portnum
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  real_T Eta_bar_P4;                   /* Expression: stime
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  real_T Eta_bar_P5;                   /* Expression: stype
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  real_T Eta_bar_P6;                   /* Expression: btype
                                        * Referenced by: '<S3>/Eta_bar'
                                        */
  real_T ObservergainL1_P1;            /* Expression: width
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  real_T ObservergainL1_P2;            /* Expression: dtype
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  real_T ObservergainL1_P3;            /* Expression: portnum
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  real_T ObservergainL1_P4;            /* Expression: stime
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  real_T ObservergainL1_P5;            /* Expression: stype
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  real_T ObservergainL1_P6;            /* Expression: btype
                                        * Referenced by: '<S3>/Observer gain L1'
                                        */
  real_T ObservergainL3_P1;            /* Expression: width
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  real_T ObservergainL3_P2;            /* Expression: dtype
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  real_T ObservergainL3_P3;            /* Expression: portnum
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  real_T ObservergainL3_P4;            /* Expression: stime
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  real_T ObservergainL3_P5;            /* Expression: stype
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  real_T ObservergainL3_P6;            /* Expression: btype
                                        * Referenced by: '<S3>/Observer gain L3'
                                        */
  real_T ObservergainL2_P1;            /* Expression: width
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  real_T ObservergainL2_P2;            /* Expression: dtype
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  real_T ObservergainL2_P3;            /* Expression: portnum
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  real_T ObservergainL2_P4;            /* Expression: stime
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  real_T ObservergainL2_P5;            /* Expression: stype
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  real_T ObservergainL2_P6;            /* Expression: btype
                                        * Referenced by: '<S3>/Observer gain L2'
                                        */
  real_T D_Value[9];                   /* Expression: [0.6555 0 0; 0 1.33 7.25; 0 0 1.9]
                                        * Referenced by: '<S3>/D'
                                        */
  real_T M_Value[9];                   /* Expression: [16.11 0 0; 0 24.11 0.53; 0 0.53 2.76]
                                        * Referenced by: '<S3>/M'
                                        */
  real_T L1_Gain[9];                   /* Expression: eye(3)
                                        * Referenced by: '<S3>/L1'
                                        */
  real_T L2_Gain[9];                   /* Expression: eye(3)
                                        * Referenced by: '<S3>/L2'
                                        */
  real_T L3_Gain[9];                   /* Expression: eye(3)
                                        * Referenced by: '<S3>/L3'
                                        */
  real_T j_measurement_P1;             /* Expression: width
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  real_T j_measurement_P2;             /* Expression: dtype
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  real_T j_measurement_P3;             /* Expression: portnum
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  real_T j_measurement_P4;             /* Expression: stime
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  real_T j_measurement_P5;             /* Expression: stype
                                        * Referenced by: '<S7>/j_measurement '
                                        */
  real_T j_measurement_P6;             /* Expression: btype
                                        * Referenced by: '<S7>/j_measurement '
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_custom_T {
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
  real_T odeY[10];
  real_T odeF[4][10];
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
extern P_ctrl_custom_T ctrl_custom_P;

/* Block signals (auto storage) */
extern B_ctrl_custom_T ctrl_custom_B;

/* Continuous states (auto storage) */
extern X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
extern DW_ctrl_custom_T ctrl_custom_DW;

/* Model entry point functions */
extern void ctrl_custom_initialize(void);
extern void ctrl_custom_output(void);
extern void ctrl_custom_update(void);
extern void ctrl_custom_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_custom_rtModel *ctrl_custom(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_custom_T *const ctrl_custom_M;

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
 * '<Root>' : 'ctrl_custom'
 * '<S1>'   : 'ctrl_custom/Control law'
 * '<S2>'   : 'ctrl_custom/Model Info'
 * '<S3>'   : 'ctrl_custom/Observer'
 * '<S4>'   : 'ctrl_custom/Pose'
 * '<S5>'   : 'ctrl_custom/Pose1'
 * '<S6>'   : 'ctrl_custom/Rectangular coordinate thrust allocation'
 * '<S7>'   : 'ctrl_custom/Subsystem'
 * '<S8>'   : 'ctrl_custom/dead_reckoning'
 * '<S9>'   : 'ctrl_custom/simpleConversion1'
 * '<S10>'  : 'ctrl_custom/u'
 * '<S11>'  : 'ctrl_custom/u1'
 * '<S12>'  : 'ctrl_custom/u_to_tau_mapping'
 * '<S13>'  : 'ctrl_custom/Control law/Control law'
 * '<S14>'  : 'ctrl_custom/Control law/Damping and coriolis'
 * '<S15>'  : 'ctrl_custom/Control law/MATLAB Function'
 * '<S16>'  : 'ctrl_custom/Observer/Band-Limited White Noise'
 * '<S17>'  : 'ctrl_custom/Observer/Inverse'
 * '<S18>'  : 'ctrl_custom/Observer/MATLAB Function'
 * '<S19>'  : 'ctrl_custom/Observer/Transpose'
 * '<S20>'  : 'ctrl_custom/Observer/rotation matrix'
 * '<S21>'  : 'ctrl_custom/Rectangular coordinate thrust allocation/MATLAB Function'
 * '<S22>'  : 'ctrl_custom/Subsystem/MATLAB Function'
 * '<S23>'  : 'ctrl_custom/u_to_tau_mapping/u_to_tau_mapping'
 */
#endif                                 /* RTW_HEADER_ctrl_custom_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.212
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Mon Mar 25 10:47:05 2019
 *========================================================================*/
#if !defined(NI_HEADER_ctrl_custom_h_)
#define NI_HEADER_ctrl_custom_h_
#ifdef NI_ROOTMODEL_ctrl_custom

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_custom.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_custom_T rtParameter[NUMST+!TID01EQ];
P_ctrl_custom_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_custom_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_custom_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_custom_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_ctrl_custom_h_ */
