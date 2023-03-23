/*
 * simpleObserver.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simpleObserver".
 *
 * Model version              : 1.14
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Mar  9 17:18:43 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simpleObserver_h_
#define RTW_HEADER_simpleObserver_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "simpleObserver_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
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

/* Block signals (default storage) */
struct B_simpleObserver_T {
  real_T InCameraPose[3];              /* '<Root>/InCameraPose' */
  real_T CameraDelay[3];               /* '<S1>/CameraDelay' */
  real_T DelayOneStep1[3];             /* '<S1>/Delay One Step1' */
  real_T Odometry[3];                  /* '<S1>/Integrator' */
  real_T Sum1[3];                      /* '<S1>/Sum1' */
  real_T Sum2[3];                      /* '<S1>/Sum2' */
  real_T InVXworld;                    /* '<Root>/InVXworld' */
  real_T InVYworld;                    /* '<Root>/InVYworld' */
  real_T InVThetaworld;                /* '<Root>/InVThetaworld' */
  real_T TmpSignalConversionAtIntegrator[3];
  real_T Integrator[3];                /* '<Root>/Integrator' */
  real_T vxToRobot;                    /* '<Root>/vxToRobot' */
  real_T vyToRobot;                    /* '<Root>/vyToRobot' */
  real_T omegaToRobot;                 /* '<Root>/omegaToRobot' */
  real_T Sum[3];                       /* '<Root>/Sum' */
  real_T estimatedPose[3];             /* '<S1>/PoseCalculation' */
  real_T debug;                        /* '<S1>/PoseCalculation' */
  real_T estimatedX;                   /* '<S1>/PoseCalculation' */
  real_T estimatedY;                   /* '<S1>/PoseCalculation' */
  real_T estimatedTheta;               /* '<S1>/PoseCalculation' */
  real_T Sum1_p[3];                    /* '<Root>/Sum1' */
  real_T Gain[3];                      /* '<Root>/Gain' */
  boolean_T newCamDataArrived;         /* '<S1>/CamFlag' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_simpleObserver_T {
  real_T CameraDelay_DSTATE[42];       /* '<S1>/CameraDelay' */
  real_T DelayOneStep1_DSTATE[3];      /* '<S1>/Delay One Step1' */
  real_T estPoseOld[3];                /* '<S1>/PoseCalculation' */
  real_T oldCamData[3];                /* '<S1>/CamFlag' */
  void *version_PWORK;                 /* '<Root>/version' */
  void *DEBUG_PWORK;                   /* '<Root>/DEBUG' */
  void *OutEstimatedPose_PWORK;        /* '<Root>/OutEstimatedPose' */
  void *InCameraPose_PWORK;            /* '<Root>/InCameraPose' */
  void *InVXworld_PWORK;               /* '<Root>/InVXworld' */
  void *InVYworld_PWORK;               /* '<Root>/InVYworld' */
  void *InVThetaworld_PWORK;           /* '<Root>/InVThetaworld' */
  void *vxToRobot_PWORK;               /* '<Root>/vxToRobot' */
  void *vyToRobot_PWORK;               /* '<Root>/vyToRobot' */
  void *omegaToRobot_PWORK;            /* '<Root>/omegaToRobot' */
};

/* Continuous states (default storage) */
struct X_simpleObserver_T {
  real_T Integrator_CSTATE[3];         /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_p[3];       /* '<Root>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_simpleObserver_T {
  real_T Integrator_CSTATE[3];         /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_p[3];       /* '<Root>/Integrator' */
};

/* State disabled  */
struct XDis_simpleObserver_T {
  boolean_T Integrator_CSTATE[3];      /* '<S1>/Integrator' */
  boolean_T Integrator_CSTATE_p[3];    /* '<Root>/Integrator' */
};

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
struct ODE1_IntgData {
  real_T *f[1];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_simpleObserver_T_ {
  real_T Constant_Value;               /* Expression: 0.6
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T CameraDelay_InitialCondition; /* Expression: 0.0
                                        * Referenced by: '<S1>/CameraDelay'
                                        */
  real_T DelayOneStep1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S1>/Delay One Step1'
                                         */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator_IC_i;              /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Gain_Gain[9];                 /* Expression: [9 0 0; 0 9 0; 0 0 9]
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_simpleObserver_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_simpleObserver_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][6];
  ODE1_IntgData intgData;

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
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_simpleObserver_T simpleObserver_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_simpleObserver_T simpleObserver_B;

#ifdef __cplusplus

}
#endif

/* Continuous states (default storage) */
extern X_simpleObserver_T simpleObserver_X;

/* Block states (default storage) */
extern struct DW_simpleObserver_T simpleObserver_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void simpleObserver_initialize(void);
  extern void simpleObserver_step(void);
  extern void simpleObserver_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_simpleObserver_T *const simpleObserver_M;

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
 * '<Root>' : 'simpleObserver'
 * '<S1>'   : 'simpleObserver/Estimator1'
 * '<S2>'   : 'simpleObserver/Estimator1/CamFlag'
 * '<S3>'   : 'simpleObserver/Estimator1/PoseCalculation'
 */
#endif                                 /* RTW_HEADER_simpleObserver_h_ */