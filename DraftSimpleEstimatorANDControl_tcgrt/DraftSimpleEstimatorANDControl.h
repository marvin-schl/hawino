/*
 * DraftSimpleEstimatorANDControl.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DraftSimpleEstimatorANDControl".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Fri Feb 17 16:08:28 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DraftSimpleEstimatorANDControl_h_
#define RTW_HEADER_DraftSimpleEstimatorANDControl_h_
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "DraftSimpleEstimatorANDControl_types.h"

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

#define DraftSimpleEstimatorANDControl_M_TYPE RT_MODEL_DraftSimpleEstimator_T

/* Block signals (default storage) */
struct B_DraftSimpleEstimatorANDCont_T {
  real_T InNextWaypoint[3];            /* '<Root>/InNextWaypoint' */
  real_T InCameraPose[3];              /* '<Root>/InCameraPose' */
  real_T CameraPOse[3];                /* '<S1>/Transpose1' */
  real_T Odometry[3];                  /* '<S1>/Integrator' */
  real_T DelayOneStep1[3];             /* '<S1>/Delay One Step1' */
  real_T Subtract2[3];                 /* '<S1>/Subtract2' */
  real_T CameraDelay[3];               /* '<S1>/CameraDelay' */
  real_T Subtract1[3];                 /* '<S1>/Subtract1' */
  real_T ErrorPose[3];                 /* '<Root>/Add' */
  real_T InVXfromMotors;               /* '<Root>/InVXfromMotors' */
  real_T InVYfromMotors;               /* '<Root>/InVYfromMotors' */
  real_T InVThetafromMotors;           /* '<Root>/InVThetafromMotors' */
  real_T Transpose[3];                 /* '<S1>/Transpose' */
  real_T InContrID;                    /* '<Root>/InContrID' */
  real_T InContrIN;                    /* '<Root>/InContrIN' */
  real_T InContrP;                     /* '<Root>/InContrP' */
  real_T InContrlI;                    /* '<Root>/InContrlI' */
  real_T TmpSignalConversionAtOutVtoMoto[3];
  real_T velR[3];                   /* '<Root>/Transformation World to Robot' */
  real_T velW[3];                     /* '<S1>/Transformation Robot to World' */
  real_T estimatedPose[3];             /* '<S1>/PoseCalculation' */
  real_T debug;                        /* '<S1>/PoseCalculation' */
  real_T estimatedX;                   /* '<S1>/PoseCalculation' */
  real_T estimatedY;                   /* '<S1>/PoseCalculation' */
  real_T estimatedTheta;               /* '<S1>/PoseCalculation' */
  real_T TmpSignalConversionAtTransposeI[3];
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Saturation2;                  /* '<Root>/Saturation2' */
  real_T Transpose_p[3];               /* '<Root>/Transpose' */
  boolean_T newCamDataArrived;         /* '<S1>/CamFlag' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_DraftSimpleEstimatorANDCon_T {
  real_T DelayOneStep1_DSTATE[3];      /* '<S1>/Delay One Step1' */
  real_T CameraDelay_DSTATE[42];       /* '<S1>/CameraDelay' */
  real_T estPoseOld[3];                /* '<S1>/PoseCalculation' */
  real_T oldCamData[3];                /* '<S1>/CamFlag' */
  void *OutDebugCase_PWORK;            /* '<Root>/OutDebugCase' */
  void *OutErrorPose_PWORK;            /* '<Root>/OutErrorPose' */
  void *OutEstTheta_PWORK;             /* '<Root>/OutEstTheta' */
  void *OutEstX_PWORK;                 /* '<Root>/OutEstX' */
  void *OutEstY_PWORK;                 /* '<Root>/OutEstY' */
  void *OutVtoMotors_PWORK;            /* '<Root>/OutVtoMotors' */
  void *InNextWaypoint_PWORK;          /* '<Root>/InNextWaypoint' */
  void *InCameraPose_PWORK;            /* '<Root>/InCameraPose' */
  void *vMotors_PWORK;                 /* '<S1>/vMotors' */
  void *vWorld_PWORK;                  /* '<S1>/vWorld' */
  void *InVXfromMotors_PWORK;          /* '<Root>/InVXfromMotors' */
  void *InVYfromMotors_PWORK;          /* '<Root>/InVYfromMotors' */
  void *InVThetafromMotors_PWORK;      /* '<Root>/InVThetafromMotors' */
  void *InContrID_PWORK;               /* '<Root>/InContrID' */
  void *InContrIN_PWORK;               /* '<Root>/InContrIN' */
  void *InContrP_PWORK;                /* '<Root>/InContrP' */
  void *InContrlI_PWORK;               /* '<Root>/InContrlI' */
};

/* Continuous states (default storage) */
struct X_DraftSimpleEstimatorANDCont_T {
  real_T Integrator_CSTATE[3];         /* '<S1>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_DraftSimpleEstimatorANDC_T {
  real_T Integrator_CSTATE[3];         /* '<S1>/Integrator' */
};

/* State disabled  */
struct XDis_DraftSimpleEstimatorANDC_T {
  boolean_T Integrator_CSTATE[3];      /* '<S1>/Integrator' */
};

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
struct ODE1_IntgData {
  real_T *f[1];                        /* derivatives */
};

#endif

/* Real-time Model Data Structure */
struct tag_RTM_DraftSimpleEstimatorA_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_DraftSimpleEstimatorANDCont_T *blockIO;
  X_DraftSimpleEstimatorANDCont_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][3];
  ODE1_IntgData intgData;
  DW_DraftSimpleEstimatorANDCon_T *dwork;

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
  extern RT_MODEL_DraftSimpleEstimator_T *DraftSimpleEstimatorANDControl(void);
  extern void DraftSimpleEstimatorANDControl_initialize
    (RT_MODEL_DraftSimpleEstimator_T *const DraftSimpleEstimatorANDContr_M);
  extern void DraftSimpleEstimatorANDControl_step
    (RT_MODEL_DraftSimpleEstimator_T *const DraftSimpleEstimatorANDContr_M);
  extern void DraftSimpleEstimatorANDControl_terminate
    (RT_MODEL_DraftSimpleEstimator_T * DraftSimpleEstimatorANDContr_M);

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
 * '<Root>' : 'DraftSimpleEstimatorANDControl'
 * '<S1>'   : 'DraftSimpleEstimatorANDControl/Estimator1'
 * '<S2>'   : 'DraftSimpleEstimatorANDControl/PID Controller'
 * '<S3>'   : 'DraftSimpleEstimatorANDControl/Transformation World to Robot'
 * '<S4>'   : 'DraftSimpleEstimatorANDControl/Estimator1/CamFlag'
 * '<S5>'   : 'DraftSimpleEstimatorANDControl/Estimator1/PoseCalculation'
 * '<S6>'   : 'DraftSimpleEstimatorANDControl/Estimator1/Transformation Robot to World'
 * '<S7>'   : 'DraftSimpleEstimatorANDControl/PID Controller/Anti-windup'
 * '<S8>'   : 'DraftSimpleEstimatorANDControl/PID Controller/D Gain'
 * '<S9>'   : 'DraftSimpleEstimatorANDControl/PID Controller/Filter'
 * '<S10>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Filter ICs'
 * '<S11>'  : 'DraftSimpleEstimatorANDControl/PID Controller/I Gain'
 * '<S12>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Ideal P Gain'
 * '<S13>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Ideal P Gain Fdbk'
 * '<S14>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Integrator'
 * '<S15>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Integrator ICs'
 * '<S16>'  : 'DraftSimpleEstimatorANDControl/PID Controller/N Copy'
 * '<S17>'  : 'DraftSimpleEstimatorANDControl/PID Controller/N Gain'
 * '<S18>'  : 'DraftSimpleEstimatorANDControl/PID Controller/P Copy'
 * '<S19>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Parallel P Gain'
 * '<S20>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Reset Signal'
 * '<S21>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Saturation'
 * '<S22>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Saturation Fdbk'
 * '<S23>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Sum'
 * '<S24>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Sum Fdbk'
 * '<S25>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tracking Mode'
 * '<S26>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tracking Mode Sum'
 * '<S27>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tsamp - Integral'
 * '<S28>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tsamp - Ngain'
 * '<S29>'  : 'DraftSimpleEstimatorANDControl/PID Controller/postSat Signal'
 * '<S30>'  : 'DraftSimpleEstimatorANDControl/PID Controller/preSat Signal'
 * '<S31>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Anti-windup/Passthrough'
 * '<S32>'  : 'DraftSimpleEstimatorANDControl/PID Controller/D Gain/External Parameters'
 * '<S33>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S34>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'DraftSimpleEstimatorANDControl/PID Controller/I Gain/External Parameters'
 * '<S36>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Integrator/Discrete'
 * '<S39>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'DraftSimpleEstimatorANDControl/PID Controller/N Copy/Disabled'
 * '<S41>'  : 'DraftSimpleEstimatorANDControl/PID Controller/N Gain/External Parameters'
 * '<S42>'  : 'DraftSimpleEstimatorANDControl/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Parallel P Gain/External Parameters'
 * '<S44>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Saturation/Passthrough'
 * '<S46>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Sum/Sum_PID'
 * '<S48>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'DraftSimpleEstimatorANDControl/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'DraftSimpleEstimatorANDControl/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'DraftSimpleEstimatorANDControl/PID Controller/preSat Signal/Forward_Path'
 */
#endif                        /* RTW_HEADER_DraftSimpleEstimatorANDControl_h_ */
