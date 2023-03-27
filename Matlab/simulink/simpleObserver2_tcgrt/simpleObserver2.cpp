/*
 * simpleObserver2.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simpleObserver2".
 *
 * Model version              : 1.46
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Mon Mar 27 19:08:06 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simpleObserver2.h"
#include "simpleObserver2_private.h"

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si ,
  RT_MODEL_simpleObserver2_T *const simpleObserver2_M)
{
  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE1_IntgData *id { static_cast<ODE1_IntgData *>(rtsiGetSolverData(si)) };

  real_T *f0 { id->f[0] };

  int_T i;
  int_T nXc { 3 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  simpleObserver2_derivatives(simpleObserver2_M);
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void simpleObserver2_step(RT_MODEL_simpleObserver2_T *const simpleObserver2_M)
{
  B_simpleObserver2_T *simpleObserver2_B{ simpleObserver2_M->blockIO };

  DW_simpleObserver2_T *simpleObserver2_DW{ simpleObserver2_M->dwork };

  X_simpleObserver2_T *simpleObserver2_X{ simpleObserver2_M->contStates };

  PrevZCX_simpleObserver2_T *simpleObserver2_PrevZCX{
    simpleObserver2_M->prevZCSigState };

  int32_T k;
  boolean_T y;
  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
    /* set solver stop time */
    if (!(simpleObserver2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(simpleObserver2_M->solverInfo,
                            ((simpleObserver2_M->Timing.clockTickH0 + 1) *
        simpleObserver2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(simpleObserver2_M->solverInfo,
                            ((simpleObserver2_M->Timing.clockTick0 + 1) *
        simpleObserver2_M->Timing.stepSize0 +
        simpleObserver2_M->Timing.clockTickH0 *
        simpleObserver2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(simpleObserver2_M)) {
    simpleObserver2_M->Timing.t[0] = rtsiGetT(simpleObserver2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
  }

  /* S-Function (TcModuleInOut): '<Root>/InCameraPose' */
  if (simpleObserver2_DW->InCameraPose_PWORK != NULL) {
    memcpy(&simpleObserver2_B->InCameraPose[0],
           simpleObserver2_DW->InCameraPose_PWORK, 24);
  }

  /* S-Function (TcModuleInOut): '<S1>/Reset' */
  if (simpleObserver2_DW->Reset_PWORK != NULL) {
    simpleObserver2_B->Reset = *((boolean_T*)simpleObserver2_DW->Reset_PWORK);
  }

  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
    boolean_T exitg1;
    boolean_T guard1{ false };

    /* MATLAB Function: '<S1>/denormalizeCamData' */
    simpleObserver2_B->angleDenormalizedCamData[0] =
      simpleObserver2_B->InCameraPose[0];
    simpleObserver2_B->angleDenormalizedCamData[1] =
      simpleObserver2_B->InCameraPose[1];
    simpleObserver2_B->angleDenormalizedCamData[2] =
      simpleObserver2_B->InCameraPose[2];
    if ((!simpleObserver2_B->Reset) && (std::abs(simpleObserver2_DW->oldTheta -
          simpleObserver2_B->InCameraPose[2]) > 3.1415926535897931)) {
      if ((simpleObserver2_DW->oldTheta > 0.0) &&
          (simpleObserver2_B->InCameraPose[2] < 0.0)) {
        simpleObserver2_B->angleDenormalizedCamData[2] =
          simpleObserver2_B->InCameraPose[2] + 6.2831853071795862;
      } else if ((simpleObserver2_DW->oldTheta < 0.0) &&
                 (simpleObserver2_B->InCameraPose[2] > 0.0)) {
        simpleObserver2_B->angleDenormalizedCamData[2] =
          simpleObserver2_B->InCameraPose[2] - 6.2831853071795862;
      }
    }

    simpleObserver2_DW->oldTheta = simpleObserver2_B->angleDenormalizedCamData[2];

    /* End of MATLAB Function: '<S1>/denormalizeCamData' */

    /* MATLAB Function: '<S1>/CamFlag' */
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (simpleObserver2_B->angleDenormalizedCamData[k] == 0.0) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    guard1 = false;
    if (y) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!(simpleObserver2_B->angleDenormalizedCamData[k] !=
              simpleObserver2_DW->oldCamData[k])) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (y) {
        simpleObserver2_B->newCamDataArrived = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      simpleObserver2_B->newCamDataArrived = false;
      simpleObserver2_DW->oldCamData[0] =
        simpleObserver2_B->angleDenormalizedCamData[0];
      simpleObserver2_DW->oldCamData[1] =
        simpleObserver2_B->angleDenormalizedCamData[1];
      simpleObserver2_DW->oldCamData[2] =
        simpleObserver2_B->angleDenormalizedCamData[2];
    }

    /* End of MATLAB Function: '<S1>/CamFlag' */
  }

  /* Integrator: '<S1>/Integrator' */
  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
    y = (simpleObserver2_B->Reset &&
         (simpleObserver2_PrevZCX->Integrator_Reset_ZCE != POS_ZCSIG));
    simpleObserver2_PrevZCX->Integrator_Reset_ZCE = simpleObserver2_B->Reset;

    /* evaluate zero-crossings */
    if (y || (simpleObserver2_DW->Integrator_IWORK != 0)) {
      simpleObserver2_X->Integrator_CSTATE[0] = simpleObserver2_B->InCameraPose
        [0];
      simpleObserver2_X->Integrator_CSTATE[1] = simpleObserver2_B->InCameraPose
        [1];
      simpleObserver2_X->Integrator_CSTATE[2] = simpleObserver2_B->InCameraPose
        [2];
    }
  }

  /* Integrator: '<S1>/Integrator' */
  simpleObserver2_B->Odometry[0] = simpleObserver2_X->Integrator_CSTATE[0];
  simpleObserver2_B->Odometry[1] = simpleObserver2_X->Integrator_CSTATE[1];
  simpleObserver2_B->Odometry[2] = simpleObserver2_X->Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
    /* S-Function (TcModuleInOut): '<S1>/cameraDelayCylces' */
    if (simpleObserver2_DW->cameraDelayCylces_PWORK != NULL) {
      simpleObserver2_B->cameraDelayCylces = *((int8_T*)
        simpleObserver2_DW->cameraDelayCylces_PWORK);
    }

    /* Delay: '<S1>/CameraDelay' */
    if (simpleObserver2_B->cameraDelayCylces <= 0) {
      /* Delay: '<S1>/CameraDelay' incorporates:
       *  Integrator: '<S1>/Integrator'
       */
      simpleObserver2_B->CameraDelay[0] = simpleObserver2_B->Odometry[0];
      simpleObserver2_B->CameraDelay[1] = simpleObserver2_B->Odometry[1];
      simpleObserver2_B->CameraDelay[2] = simpleObserver2_B->Odometry[2];
    } else {
      int8_T tmp;
      if (simpleObserver2_B->cameraDelayCylces > 100) {
        tmp = 100;
      } else {
        tmp = simpleObserver2_B->cameraDelayCylces;
      }

      k = static_cast<int8_T>(100 - tmp) * 3;

      /* Delay: '<S1>/CameraDelay' */
      simpleObserver2_B->CameraDelay[0] = simpleObserver2_DW->
        CameraDelay_DSTATE[k];
      simpleObserver2_B->CameraDelay[1] = simpleObserver2_DW->
        CameraDelay_DSTATE[k + 1];
      simpleObserver2_B->CameraDelay[2] = simpleObserver2_DW->
        CameraDelay_DSTATE[k + 2];
    }

    /* End of Delay: '<S1>/CameraDelay' */
  }

  /* S-Function (TcModuleInOut): '<S1>/K' */
  if (simpleObserver2_DW->K_PWORK != NULL) {
    memcpy(&simpleObserver2_B->K[0], simpleObserver2_DW->K_PWORK, 72);
  }

  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
    /* Switch: '<S1>/Switch' */
    if (simpleObserver2_B->newCamDataArrived) {
      /* Sum: '<S1>/Sum1' incorporates:
       *  Delay: '<S1>/CameraDelay'
       */
      simpleObserver2_B->Sum1[0] = simpleObserver2_B->angleDenormalizedCamData[0]
        - simpleObserver2_B->CameraDelay[0];

      /* Switch: '<S1>/Switch' incorporates:
       *  Sum: '<S1>/Sum1'
       */
      simpleObserver2_B->Switch[0] = simpleObserver2_B->Sum1[0];

      /* Sum: '<S1>/Sum1' incorporates:
       *  Delay: '<S1>/CameraDelay'
       */
      simpleObserver2_B->Sum1[1] = simpleObserver2_B->angleDenormalizedCamData[1]
        - simpleObserver2_B->CameraDelay[1];

      /* Switch: '<S1>/Switch' incorporates:
       *  Sum: '<S1>/Sum1'
       */
      simpleObserver2_B->Switch[1] = simpleObserver2_B->Sum1[1];

      /* Sum: '<S1>/Sum1' incorporates:
       *  Delay: '<S1>/CameraDelay'
       */
      simpleObserver2_B->Sum1[2] = simpleObserver2_B->angleDenormalizedCamData[2]
        - simpleObserver2_B->CameraDelay[2];

      /* Switch: '<S1>/Switch' incorporates:
       *  Sum: '<S1>/Sum1'
       */
      simpleObserver2_B->Switch[2] = simpleObserver2_B->Sum1[2];
    } else {
      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/Constant'
       */
      simpleObserver2_B->Switch[0] = 0.0;
      simpleObserver2_B->Switch[1] = 0.0;
      simpleObserver2_B->Switch[2] = 0.0;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  for (k = 0; k < 3; k++) {
    /* Product: '<S1>/Product1' incorporates:
     *  S-Function (TcModuleInOut): '<S1>/K'
     *  Switch: '<S1>/Switch'
     */
    simpleObserver2_B->Product1[k] = 0.0;
    simpleObserver2_B->Product1[k] += simpleObserver2_B->K[k] *
      simpleObserver2_B->Switch[0];
    simpleObserver2_B->Product1[k] += simpleObserver2_B->K[k + 3] *
      simpleObserver2_B->Switch[1];
    simpleObserver2_B->Product1[k] += simpleObserver2_B->K[k + 6] *
      simpleObserver2_B->Switch[2];
  }

  /* S-Function (TcModuleInOut): '<Root>/InVXworld' */
  if (simpleObserver2_DW->InVXworld_PWORK != NULL) {
    simpleObserver2_B->InVXworld = *((real_T*)
      simpleObserver2_DW->InVXworld_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVYworld' */
  if (simpleObserver2_DW->InVYworld_PWORK != NULL) {
    simpleObserver2_B->InVYworld = *((real_T*)
      simpleObserver2_DW->InVYworld_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVThetaworld' */
  if (simpleObserver2_DW->InVThetaworld_PWORK != NULL) {
    simpleObserver2_B->InVThetaworld = *((real_T*)
      simpleObserver2_DW->InVThetaworld_PWORK);
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Product: '<S1>/Product1'
   */
  simpleObserver2_B->Sum[0] = simpleObserver2_B->Product1[0] +
    simpleObserver2_B->InVXworld;
  simpleObserver2_B->Sum[1] = simpleObserver2_B->Product1[1] +
    simpleObserver2_B->InVYworld;
  simpleObserver2_B->Sum[2] = simpleObserver2_B->Product1[2] +
    simpleObserver2_B->InVThetaworld;
  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
    if (rtmIsMajorTimeStep(simpleObserver2_M)) {
      /* Update for S-Function (TcModuleInOut): '<Root>/version' incorporates:
       *  Constant: '<Root>/Constant'
       */
      if (simpleObserver2_DW->version_PWORK != NULL) {
        *((real_T*)simpleObserver2_DW->version_PWORK) = 0.7;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/DEBUG' */
      if (simpleObserver2_DW->DEBUG_PWORK != NULL) {
        memcpy(simpleObserver2_DW->DEBUG_PWORK, &simpleObserver2_B->Switch[0],
               24);
      }
    }

    /* Update for S-Function (TcModuleInOut): '<Root>/OutEstimatedPose' */
    if (simpleObserver2_DW->OutEstimatedPose_PWORK != NULL) {
      memcpy(simpleObserver2_DW->OutEstimatedPose_PWORK,
             &simpleObserver2_B->Odometry[0], 24);
    }

    /* Update for Integrator: '<S1>/Integrator' */
    simpleObserver2_DW->Integrator_IWORK = 0;
    if (rtmIsMajorTimeStep(simpleObserver2_M)) {
      /* Update for Delay: '<S1>/CameraDelay' incorporates:
       *  Integrator: '<S1>/Integrator'
       */
      for (int_T idxDelay{0}; idxDelay < 99; idxDelay++) {
        int32_T CameraDelay_DSTATE_tmp;
        CameraDelay_DSTATE_tmp = (idxDelay + 1) * 3;
        simpleObserver2_DW->CameraDelay_DSTATE[idxDelay * 3] =
          simpleObserver2_DW->CameraDelay_DSTATE[CameraDelay_DSTATE_tmp];
        simpleObserver2_DW->CameraDelay_DSTATE[idxDelay * 3 + 1] =
          simpleObserver2_DW->CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 1];
        simpleObserver2_DW->CameraDelay_DSTATE[idxDelay * 3 + 2] =
          simpleObserver2_DW->CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 2];
      }

      simpleObserver2_DW->CameraDelay_DSTATE[297] = simpleObserver2_B->Odometry
        [0];
      simpleObserver2_DW->CameraDelay_DSTATE[298] = simpleObserver2_B->Odometry
        [1];
      simpleObserver2_DW->CameraDelay_DSTATE[299] = simpleObserver2_B->Odometry
        [2];

      /* End of Update for Delay: '<S1>/CameraDelay' */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(simpleObserver2_M)) {
    rt_ertODEUpdateContinuousStates(simpleObserver2_M->solverInfo,
      simpleObserver2_M);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++simpleObserver2_M->Timing.clockTick0)) {
      ++simpleObserver2_M->Timing.clockTickH0;
    }

    simpleObserver2_M->Timing.t[0] = rtsiGetSolverStopTime
      (simpleObserver2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      simpleObserver2_M->Timing.clockTick1++;
      if (!simpleObserver2_M->Timing.clockTick1) {
        simpleObserver2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void simpleObserver2_derivatives(RT_MODEL_simpleObserver2_T *const
  simpleObserver2_M)
{
  B_simpleObserver2_T *simpleObserver2_B{ simpleObserver2_M->blockIO };

  XDot_simpleObserver2_T *_rtXdot;
  _rtXdot = ((XDot_simpleObserver2_T *) simpleObserver2_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' incorporates:
   *  Sum: '<S1>/Sum'
   */
  _rtXdot->Integrator_CSTATE[0] = simpleObserver2_B->Sum[0];
  _rtXdot->Integrator_CSTATE[1] = simpleObserver2_B->Sum[1];
  _rtXdot->Integrator_CSTATE[2] = simpleObserver2_B->Sum[2];
}

/* Model initialize function */
void simpleObserver2_initialize(RT_MODEL_simpleObserver2_T *const
  simpleObserver2_M)
{
  DW_simpleObserver2_T *simpleObserver2_DW{ simpleObserver2_M->dwork };

  X_simpleObserver2_T *simpleObserver2_X{ simpleObserver2_M->contStates };

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  if (rtmIsFirstInitCond(simpleObserver2_M)) {
    simpleObserver2_X->Integrator_CSTATE[0] = 0.0;
    simpleObserver2_X->Integrator_CSTATE[1] = 0.0;
    simpleObserver2_X->Integrator_CSTATE[2] = 0.0;
  }

  simpleObserver2_DW->Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S1>/Integrator' */

  /* InitializeConditions for Delay: '<S1>/CameraDelay' */
  std::memset(&simpleObserver2_DW->CameraDelay_DSTATE[0], 0, 300U * sizeof
              (real_T));

  /* SystemInitialize for MATLAB Function: '<S1>/denormalizeCamData' */
  simpleObserver2_DW->oldTheta = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  simpleObserver2_DW->oldCamData[0] = 0.0;
  simpleObserver2_DW->oldCamData[1] = 0.0;
  simpleObserver2_DW->oldCamData[2] = 0.0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(simpleObserver2_M)) {
    rtmSetFirstInitCond(simpleObserver2_M, 0);
  }
}

/* Model terminate function */
void simpleObserver2_terminate(RT_MODEL_simpleObserver2_T * simpleObserver2_M)
{
  rt_FREE(simpleObserver2_M->solverInfo);

  /* model code */
  rt_FREE(simpleObserver2_M->blockIO);
  rt_FREE(simpleObserver2_M->contStates);
  rt_FREE(simpleObserver2_M->dwork);
  rt_FREE(simpleObserver2_M->prevZCSigState);
  delete simpleObserver2_M;
}

/* Model data allocation function */
RT_MODEL_simpleObserver2_T *simpleObserver2(void)
{
  RT_MODEL_simpleObserver2_T *simpleObserver2_M;
  simpleObserver2_M = new RT_MODEL_simpleObserver2_T();
  if (simpleObserver2_M == (nullptr)) {
    return (nullptr);
  }

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo{ (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo))
    };

    rt_VALIDATE_MEMORY(simpleObserver2_M,rt_SolverInfo);
    simpleObserver2_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(simpleObserver2_M->solverInfo,
                          &simpleObserver2_M->Timing.simTimeStep);
    rtsiSetTPtr(simpleObserver2_M->solverInfo, &rtmGetTPtr(simpleObserver2_M));
    rtsiSetStepSizePtr(simpleObserver2_M->solverInfo,
                       &simpleObserver2_M->Timing.stepSize0);
    rtsiSetdXPtr(simpleObserver2_M->solverInfo, &simpleObserver2_M->derivs);
    rtsiSetContStatesPtr(simpleObserver2_M->solverInfo, (real_T **)
                         &simpleObserver2_M->contStates);
    rtsiSetNumContStatesPtr(simpleObserver2_M->solverInfo,
      &simpleObserver2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(simpleObserver2_M->solverInfo,
      &simpleObserver2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(simpleObserver2_M->solverInfo,
      &simpleObserver2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(simpleObserver2_M->solverInfo,
      &simpleObserver2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(simpleObserver2_M->solverInfo, (&rtmGetErrorStatus
      (simpleObserver2_M)));
    rtsiSetRTModelPtr(simpleObserver2_M->solverInfo, simpleObserver2_M);
  }

  rtsiSetSolverName(simpleObserver2_M->solverInfo,"ode1");

  /* block I/O */
  {
    B_simpleObserver2_T *b{ (B_simpleObserver2_T *) malloc(sizeof
      (B_simpleObserver2_T)) };

    rt_VALIDATE_MEMORY(simpleObserver2_M,b);
    simpleObserver2_M->blockIO = (b);
  }

  /* states (continuous) */
  {
    X_simpleObserver2_T *x{ (X_simpleObserver2_T *) malloc(sizeof
      (X_simpleObserver2_T)) };

    rt_VALIDATE_MEMORY(simpleObserver2_M,x);
    simpleObserver2_M->contStates = (x);
  }

  /* states (dwork) */
  {
    DW_simpleObserver2_T *dwork{ static_cast<DW_simpleObserver2_T *>(malloc
      (sizeof(DW_simpleObserver2_T))) };

    rt_VALIDATE_MEMORY(simpleObserver2_M,dwork);
    simpleObserver2_M->dwork = (dwork);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_simpleObserver2_T *zc{ (PrevZCX_simpleObserver2_T *) malloc(sizeof
      (PrevZCX_simpleObserver2_T)) };

    rt_VALIDATE_MEMORY(simpleObserver2_M,zc);
    simpleObserver2_M->prevZCSigState = (zc);
  }

  {
    B_simpleObserver2_T *simpleObserver2_B{ simpleObserver2_M->blockIO };

    DW_simpleObserver2_T *simpleObserver2_DW{ simpleObserver2_M->dwork };

    X_simpleObserver2_T *simpleObserver2_X{ simpleObserver2_M->contStates };

    PrevZCX_simpleObserver2_T *simpleObserver2_PrevZCX{
      simpleObserver2_M->prevZCSigState };

    rtsiSetSimTimeStep(simpleObserver2_M->solverInfo, MAJOR_TIME_STEP);
    simpleObserver2_M->intgData.f[0] = simpleObserver2_M->odeF[0];
    simpleObserver2_M->contStates = ((X_simpleObserver2_T *) simpleObserver2_X);
    rtsiSetSolverData(simpleObserver2_M->solverInfo, static_cast<void *>
                      (&simpleObserver2_M->intgData));
    rtmSetTPtr(simpleObserver2_M, &simpleObserver2_M->Timing.tArray[0]);
    simpleObserver2_M->Timing.stepSize0 = 0.01;
    rtmSetFirstInitCond(simpleObserver2_M, 1);

    /* block I/O */
    (void) std::memset((static_cast<void *>(simpleObserver2_B)), 0,
                       sizeof(B_simpleObserver2_T));

    /* states (continuous) */
    {
      (void) std::memset(static_cast<void *>(simpleObserver2_X), 0,
                         sizeof(X_simpleObserver2_T));
    }

    /* states (dwork) */
    (void) std::memset(static_cast<void *>(simpleObserver2_DW), 0,
                       sizeof(DW_simpleObserver2_T));

    /* previous zero-crossing states */
    {
      simpleObserver2_PrevZCX->Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
    }
  }

  return simpleObserver2_M;
}
