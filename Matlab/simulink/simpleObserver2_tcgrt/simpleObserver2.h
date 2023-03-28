/*
 * simpleObserver2.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simpleObserver2".
 *
 * Model version              : 1.47
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Tue Mar 28 18:15:14 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simpleObserver2_h_
#define RTW_HEADER_simpleObserver2_h_
#include <cstring>
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "simpleObserver2_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define simpleObserver2_M_TYPE         RT_MODEL_simpleObserver2_T

/* Block signals (default storage) */
struct B_simpleObserver2_T {
  real_T InCameraPose[3];              /* '<Root>/InCameraPose' */
  real_T Odometry[3];                  /* '<S1>/Integrator' */
  real_T CameraDelay[3];               /* '<S1>/CameraDelay' */
  real_T K[9];                         /* '<S1>/K' */
  real_T InVXworld;                    /* '<Root>/InVXworld' */
  real_T InVYworld;                    /* '<Root>/InVYworld' */
  real_T InVThetaworld;                /* '<Root>/InVThetaworld' */
  real_T Sum[3];                       /* '<S1>/Sum' */
  real_T Sum1[3];                      /* '<S1>/Sum1' */
  real_T Switch[3];                    /* '<S1>/Switch' */
  real_T Product1[3];                  /* '<S1>/Product1' */
  int8_T cameraDelayCylces;            /* '<S1>/cameraDelayCylces' */
  boolean_T Reset;                     /* '<S1>/Reset' */
  boolean_T newCamDataArrived;         /* '<S1>/CamFlag' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_simpleObserver2_T {
  real_T CameraDelay_DSTATE[300];      /* '<S1>/CameraDelay' */
  real_T oldCamData[3];                /* '<S1>/CamFlag' */
  void *version_PWORK;                 /* '<Root>/version' */
  void *OutEstimatedPose_PWORK;        /* '<Root>/OutEstimatedPose' */
  void *ThetaDenormalized_PWORK;       /* '<Root>/ThetaDenormalized' */
  void *InCameraPose_PWORK;            /* '<Root>/InCameraPose' */
  void *Reset_PWORK;                   /* '<S1>/Reset' */
  void *cameraDelayCylces_PWORK;       /* '<S1>/cameraDelayCylces' */
  void *K_PWORK;                       /* '<S1>/K' */
  void *InVXworld_PWORK;               /* '<Root>/InVXworld' */
  void *InVYworld_PWORK;               /* '<Root>/InVYworld' */
  void *InVThetaworld_PWORK;           /* '<Root>/InVThetaworld' */
  int_T Integrator_IWORK;              /* '<S1>/Integrator' */
};

/* Continuous states (default storage) */
struct X_simpleObserver2_T {
  real_T Integrator_CSTATE[3];         /* '<S1>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_simpleObserver2_T {
  real_T Integrator_CSTATE[3];         /* '<S1>/Integrator' */
};

/* State disabled  */
struct XDis_simpleObserver2_T {
  boolean_T Integrator_CSTATE[3];      /* '<S1>/Integrator' */
};

/* Zero-crossing (trigger) state */
struct PrevZCX_simpleObserver2_T {
  ZCSigState Integrator_Reset_ZCE;     /* '<S1>/Integrator' */
};

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
struct ODE1_IntgData {
  real_T *f[1];                        /* derivatives */
};

#endif

/* Real-time Model Data Structure */
struct tag_RTM_simpleObserver2_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_simpleObserver2_T *blockIO;
  PrevZCX_simpleObserver2_T *prevZCSigState;
  X_simpleObserver2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][3];
  ODE1_IntgData intgData;
  DW_simpleObserver2_T *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* External data declarations for dependent source files */
#ifdef __cplusplus

extern "C" {

#endif

  extern const char *RT_MEMORY_ALLOCATION_ERROR;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern RT_MODEL_simpleObserver2_T *simpleObserver2(void);
  extern void simpleObserver2_initialize(RT_MODEL_simpleObserver2_T *const
    simpleObserver2_M);
  extern void simpleObserver2_step(RT_MODEL_simpleObserver2_T *const
    simpleObserver2_M);
  extern void simpleObserver2_terminate(RT_MODEL_simpleObserver2_T
    * simpleObserver2_M);

#ifdef __cplusplus

}
#endif

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
 * '<Root>' : 'simpleObserver2'
 * '<S1>'   : 'simpleObserver2/Estimator1'
 * '<S2>'   : 'simpleObserver2/Estimator1/CamFlag'
 */
#endif                                 /* RTW_HEADER_simpleObserver2_h_ */
