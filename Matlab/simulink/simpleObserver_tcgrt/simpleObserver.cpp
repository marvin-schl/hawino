/*
 * simpleObserver.cpp
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

#include "simpleObserver.h"
#include "simpleObserver_private.h"

/* Block signals (default storage) */
B_simpleObserver_T simpleObserver_B;

/* Continuous states */
X_simpleObserver_T simpleObserver_X;

/* Block states (default storage) */
DW_simpleObserver_T simpleObserver_DW;

/* Real-time model */
RT_MODEL_simpleObserver_T simpleObserver_M_{ };

RT_MODEL_simpleObserver_T *const simpleObserver_M{ &simpleObserver_M_ };

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE1_IntgData *id { static_cast<ODE1_IntgData *>(rtsiGetSolverData(si)) };

  real_T *f0 { id->f[0] };

  int_T i;
  int_T nXc { 6 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  simpleObserver_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void simpleObserver_step(void)
{
  int32_T k;
  if (rtmIsMajorTimeStep(simpleObserver_M)) {
    /* set solver stop time */
    if (!(simpleObserver_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&simpleObserver_M->solverInfo,
                            ((simpleObserver_M->Timing.clockTickH0 + 1) *
        simpleObserver_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&simpleObserver_M->solverInfo,
                            ((simpleObserver_M->Timing.clockTick0 + 1) *
        simpleObserver_M->Timing.stepSize0 +
        simpleObserver_M->Timing.clockTickH0 *
        simpleObserver_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(simpleObserver_M)) {
    simpleObserver_M->Timing.t[0] = rtsiGetT(&simpleObserver_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(simpleObserver_M)) {
  }

  if (rtmIsMajorTimeStep(simpleObserver_M)) {
    boolean_T exitg1;
    boolean_T y;

    /* S-Function (TcModuleInOut): '<Root>/InCameraPose' */
    if (simpleObserver_DW.InCameraPose_PWORK != NULL) {
      memcpy(&simpleObserver_B.InCameraPose[0],
             simpleObserver_DW.InCameraPose_PWORK, 24);
    }

    /* MATLAB Function: '<S1>/CamFlag' */
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(simpleObserver_B.InCameraPose[k] != simpleObserver_DW.oldCamData[k]))
      {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (y) {
      simpleObserver_B.newCamDataArrived = true;
    } else {
      simpleObserver_B.newCamDataArrived = false;
      simpleObserver_DW.oldCamData[0] = simpleObserver_B.InCameraPose[0];
      simpleObserver_DW.oldCamData[1] = simpleObserver_B.InCameraPose[1];
      simpleObserver_DW.oldCamData[2] = simpleObserver_B.InCameraPose[2];
    }

    /* End of MATLAB Function: '<S1>/CamFlag' */

    /* Delay: '<S1>/CameraDelay' */
    simpleObserver_B.CameraDelay[0] = simpleObserver_DW.CameraDelay_DSTATE[0];

    /* Delay: '<S1>/Delay One Step1' */
    simpleObserver_B.DelayOneStep1[0] = simpleObserver_DW.DelayOneStep1_DSTATE[0];

    /* Delay: '<S1>/CameraDelay' */
    simpleObserver_B.CameraDelay[1] = simpleObserver_DW.CameraDelay_DSTATE[1];

    /* Delay: '<S1>/Delay One Step1' */
    simpleObserver_B.DelayOneStep1[1] = simpleObserver_DW.DelayOneStep1_DSTATE[1];

    /* Delay: '<S1>/CameraDelay' */
    simpleObserver_B.CameraDelay[2] = simpleObserver_DW.CameraDelay_DSTATE[2];

    /* Delay: '<S1>/Delay One Step1' */
    simpleObserver_B.DelayOneStep1[2] = simpleObserver_DW.DelayOneStep1_DSTATE[2];
  }

  /* Integrator: '<S1>/Integrator' */
  simpleObserver_B.Odometry[0] = simpleObserver_X.Integrator_CSTATE[0];

  /* Sum: '<S1>/Sum1' */
  simpleObserver_B.Sum1[0] = simpleObserver_B.Odometry[0] -
    simpleObserver_B.DelayOneStep1[0];

  /* Sum: '<S1>/Sum2' */
  simpleObserver_B.Sum2[0] = simpleObserver_B.Odometry[0] -
    simpleObserver_B.CameraDelay[0];

  /* Integrator: '<S1>/Integrator' */
  simpleObserver_B.Odometry[1] = simpleObserver_X.Integrator_CSTATE[1];

  /* Sum: '<S1>/Sum1' */
  simpleObserver_B.Sum1[1] = simpleObserver_B.Odometry[1] -
    simpleObserver_B.DelayOneStep1[1];

  /* Sum: '<S1>/Sum2' */
  simpleObserver_B.Sum2[1] = simpleObserver_B.Odometry[1] -
    simpleObserver_B.CameraDelay[1];

  /* Integrator: '<S1>/Integrator' */
  simpleObserver_B.Odometry[2] = simpleObserver_X.Integrator_CSTATE[2];

  /* Sum: '<S1>/Sum1' */
  simpleObserver_B.Sum1[2] = simpleObserver_B.Odometry[2] -
    simpleObserver_B.DelayOneStep1[2];

  /* Sum: '<S1>/Sum2' */
  simpleObserver_B.Sum2[2] = simpleObserver_B.Odometry[2] -
    simpleObserver_B.CameraDelay[2];
  if (rtmIsMajorTimeStep(simpleObserver_M)) {
    /* MATLAB Function: '<S1>/PoseCalculation' */
    if (simpleObserver_B.newCamDataArrived) {
      simpleObserver_DW.estPoseOld[0] = simpleObserver_B.InCameraPose[0] +
        simpleObserver_B.Sum2[0];
      simpleObserver_DW.estPoseOld[1] = simpleObserver_B.InCameraPose[1] +
        simpleObserver_B.Sum2[1];
      simpleObserver_DW.estPoseOld[2] = simpleObserver_B.InCameraPose[2] +
        simpleObserver_B.Sum2[2];
      simpleObserver_B.debug = 1.0;
    } else {
      simpleObserver_DW.estPoseOld[0] += simpleObserver_B.Sum1[0];
      simpleObserver_DW.estPoseOld[1] += simpleObserver_B.Sum1[1];
      simpleObserver_DW.estPoseOld[2] += simpleObserver_B.Sum1[2];
      simpleObserver_B.debug = 2.0;
    }

    simpleObserver_B.estimatedX = simpleObserver_DW.estPoseOld[0];
    simpleObserver_B.estimatedY = simpleObserver_DW.estPoseOld[1];
    simpleObserver_B.estimatedTheta = simpleObserver_DW.estPoseOld[2];
    simpleObserver_B.estimatedPose[0] = simpleObserver_DW.estPoseOld[0];
    simpleObserver_B.estimatedPose[1] = simpleObserver_DW.estPoseOld[1];
    simpleObserver_B.estimatedPose[2] = simpleObserver_DW.estPoseOld[2];

    /* End of MATLAB Function: '<S1>/PoseCalculation' */
  }

  /* S-Function (TcModuleInOut): '<Root>/InVXworld' */
  if (simpleObserver_DW.InVXworld_PWORK != NULL) {
    simpleObserver_B.InVXworld = *((real_T*)simpleObserver_DW.InVXworld_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVYworld' */
  if (simpleObserver_DW.InVYworld_PWORK != NULL) {
    simpleObserver_B.InVYworld = *((real_T*)simpleObserver_DW.InVYworld_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVThetaworld' */
  if (simpleObserver_DW.InVThetaworld_PWORK != NULL) {
    simpleObserver_B.InVThetaworld = *((real_T*)
      simpleObserver_DW.InVThetaworld_PWORK);
  }

  /* SignalConversion generated from: '<S1>/Integrator' */
  simpleObserver_B.TmpSignalConversionAtIntegrator[0] =
    simpleObserver_B.InVXworld;
  simpleObserver_B.TmpSignalConversionAtIntegrator[1] =
    simpleObserver_B.InVYworld;
  simpleObserver_B.TmpSignalConversionAtIntegrator[2] =
    simpleObserver_B.InVThetaworld;

  /* Integrator: '<Root>/Integrator' */
  simpleObserver_B.Integrator[0] = simpleObserver_X.Integrator_CSTATE_p[0];
  simpleObserver_B.Integrator[1] = simpleObserver_X.Integrator_CSTATE_p[1];
  simpleObserver_B.Integrator[2] = simpleObserver_X.Integrator_CSTATE_p[2];

  /* Sum: '<Root>/Sum1' */
  simpleObserver_B.Sum1_p[0] = simpleObserver_B.estimatedX -
    simpleObserver_B.Integrator[0];
  simpleObserver_B.Sum1_p[1] = simpleObserver_B.estimatedY -
    simpleObserver_B.Integrator[1];
  simpleObserver_B.Sum1_p[2] = simpleObserver_B.estimatedTheta -
    simpleObserver_B.Integrator[2];
  for (k = 0; k < 3; k++) {
    /* Gain: '<Root>/Gain' */
    simpleObserver_B.Gain[k] = 0.0;
    simpleObserver_B.Gain[k] += simpleObserver_P.Gain_Gain[k] *
      simpleObserver_B.Sum1_p[0];
    simpleObserver_B.Gain[k] += simpleObserver_P.Gain_Gain[k + 3] *
      simpleObserver_B.Sum1_p[1];
    simpleObserver_B.Gain[k] += simpleObserver_P.Gain_Gain[k + 6] *
      simpleObserver_B.Sum1_p[2];
  }

  /* S-Function (TcModuleInOut): '<Root>/vxToRobot' */
  if (simpleObserver_DW.vxToRobot_PWORK != NULL) {
    simpleObserver_B.vxToRobot = *((real_T*)simpleObserver_DW.vxToRobot_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/vyToRobot' */
  if (simpleObserver_DW.vyToRobot_PWORK != NULL) {
    simpleObserver_B.vyToRobot = *((real_T*)simpleObserver_DW.vyToRobot_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/omegaToRobot' */
  if (simpleObserver_DW.omegaToRobot_PWORK != NULL) {
    simpleObserver_B.omegaToRobot = *((real_T*)
      simpleObserver_DW.omegaToRobot_PWORK);
  }

  /* Sum: '<Root>/Sum' */
  simpleObserver_B.Sum[0] = simpleObserver_B.Gain[0] +
    simpleObserver_B.vxToRobot;
  simpleObserver_B.Sum[1] = simpleObserver_B.Gain[1] +
    simpleObserver_B.vyToRobot;
  simpleObserver_B.Sum[2] = simpleObserver_B.Gain[2] +
    simpleObserver_B.omegaToRobot;
  if (rtmIsMajorTimeStep(simpleObserver_M)) {
    if (rtmIsMajorTimeStep(simpleObserver_M)) {
      /* Update for S-Function (TcModuleInOut): '<Root>/version' incorporates:
       *  Constant: '<Root>/Constant'
       */
      if (simpleObserver_DW.version_PWORK != NULL) {
        *((real_T*)simpleObserver_DW.version_PWORK) =
          simpleObserver_P.Constant_Value;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/DEBUG' */
      if (simpleObserver_DW.DEBUG_PWORK != NULL) {
        *((real_T*)simpleObserver_DW.DEBUG_PWORK) = simpleObserver_B.debug;
      }
    }

    /* Update for S-Function (TcModuleInOut): '<Root>/OutEstimatedPose' */
    if (simpleObserver_DW.OutEstimatedPose_PWORK != NULL) {
      memcpy(simpleObserver_DW.OutEstimatedPose_PWORK,
             &simpleObserver_B.Integrator[0], 24);
    }

    if (rtmIsMajorTimeStep(simpleObserver_M)) {
      /* Update for Delay: '<S1>/CameraDelay' */
      for (int_T idxDelay{0}; idxDelay < 13; idxDelay++) {
        int32_T CameraDelay_DSTATE_tmp;
        CameraDelay_DSTATE_tmp = (idxDelay + 1) * 3;
        simpleObserver_DW.CameraDelay_DSTATE[idxDelay * 3] =
          simpleObserver_DW.CameraDelay_DSTATE[CameraDelay_DSTATE_tmp];
        simpleObserver_DW.CameraDelay_DSTATE[idxDelay * 3 + 1] =
          simpleObserver_DW.CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 1];
        simpleObserver_DW.CameraDelay_DSTATE[idxDelay * 3 + 2] =
          simpleObserver_DW.CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 2];
      }

      simpleObserver_DW.CameraDelay_DSTATE[39] = simpleObserver_B.Odometry[0];

      /* Update for Delay: '<S1>/Delay One Step1' */
      simpleObserver_DW.DelayOneStep1_DSTATE[0] = simpleObserver_B.Odometry[0];

      /* Update for Delay: '<S1>/CameraDelay' */
      simpleObserver_DW.CameraDelay_DSTATE[40] = simpleObserver_B.Odometry[1];

      /* Update for Delay: '<S1>/Delay One Step1' */
      simpleObserver_DW.DelayOneStep1_DSTATE[1] = simpleObserver_B.Odometry[1];

      /* Update for Delay: '<S1>/CameraDelay' */
      simpleObserver_DW.CameraDelay_DSTATE[41] = simpleObserver_B.Odometry[2];

      /* Update for Delay: '<S1>/Delay One Step1' */
      simpleObserver_DW.DelayOneStep1_DSTATE[2] = simpleObserver_B.Odometry[2];
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(simpleObserver_M)) {
    rt_ertODEUpdateContinuousStates(&simpleObserver_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++simpleObserver_M->Timing.clockTick0)) {
      ++simpleObserver_M->Timing.clockTickH0;
    }

    simpleObserver_M->Timing.t[0] = rtsiGetSolverStopTime
      (&simpleObserver_M->solverInfo);

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
      simpleObserver_M->Timing.clockTick1++;
      if (!simpleObserver_M->Timing.clockTick1) {
        simpleObserver_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void simpleObserver_derivatives(void)
{
  XDot_simpleObserver_T *_rtXdot;
  _rtXdot = ((XDot_simpleObserver_T *) simpleObserver_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] =
    simpleObserver_B.TmpSignalConversionAtIntegrator[0];

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_p[0] = simpleObserver_B.Sum[0];

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] =
    simpleObserver_B.TmpSignalConversionAtIntegrator[1];

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_p[1] = simpleObserver_B.Sum[1];

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] =
    simpleObserver_B.TmpSignalConversionAtIntegrator[2];

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_p[2] = simpleObserver_B.Sum[2];
}

/* Model initialize function */
void simpleObserver_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&simpleObserver_M->solverInfo,
                          &simpleObserver_M->Timing.simTimeStep);
    rtsiSetTPtr(&simpleObserver_M->solverInfo, &rtmGetTPtr(simpleObserver_M));
    rtsiSetStepSizePtr(&simpleObserver_M->solverInfo,
                       &simpleObserver_M->Timing.stepSize0);
    rtsiSetdXPtr(&simpleObserver_M->solverInfo, &simpleObserver_M->derivs);
    rtsiSetContStatesPtr(&simpleObserver_M->solverInfo, (real_T **)
                         &simpleObserver_M->contStates);
    rtsiSetNumContStatesPtr(&simpleObserver_M->solverInfo,
      &simpleObserver_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&simpleObserver_M->solverInfo,
      &simpleObserver_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&simpleObserver_M->solverInfo,
      &simpleObserver_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&simpleObserver_M->solverInfo,
      &simpleObserver_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&simpleObserver_M->solverInfo, (&rtmGetErrorStatus
      (simpleObserver_M)));
    rtsiSetRTModelPtr(&simpleObserver_M->solverInfo, simpleObserver_M);
  }

  rtsiSetSimTimeStep(&simpleObserver_M->solverInfo, MAJOR_TIME_STEP);
  simpleObserver_M->intgData.f[0] = simpleObserver_M->odeF[0];
  simpleObserver_M->contStates = ((X_simpleObserver_T *) &simpleObserver_X);
  rtsiSetSolverData(&simpleObserver_M->solverInfo, static_cast<void *>
                    (&simpleObserver_M->intgData));
  rtsiSetSolverName(&simpleObserver_M->solverInfo,"ode1");
  rtmSetTPtr(simpleObserver_M, &simpleObserver_M->Timing.tArray[0]);
  simpleObserver_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&simpleObserver_B)), 0,
                     sizeof(B_simpleObserver_T));

  /* states (continuous) */
  {
    (void) std::memset(static_cast<void *>(&simpleObserver_X), 0,
                       sizeof(X_simpleObserver_T));
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&simpleObserver_DW), 0,
                     sizeof(DW_simpleObserver_T));

  /* InitializeConditions for Delay: '<S1>/CameraDelay' */
  for (int32_T i{0}; i < 42; i++) {
    simpleObserver_DW.CameraDelay_DSTATE[i] =
      simpleObserver_P.CameraDelay_InitialCondition;
  }

  /* End of InitializeConditions for Delay: '<S1>/CameraDelay' */

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  simpleObserver_DW.DelayOneStep1_DSTATE[0] =
    simpleObserver_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  simpleObserver_X.Integrator_CSTATE[0] = simpleObserver_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  simpleObserver_X.Integrator_CSTATE_p[0] = simpleObserver_P.Integrator_IC_i;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  simpleObserver_DW.oldCamData[0] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/PoseCalculation' */
  simpleObserver_DW.estPoseOld[0] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  simpleObserver_DW.DelayOneStep1_DSTATE[1] =
    simpleObserver_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  simpleObserver_X.Integrator_CSTATE[1] = simpleObserver_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  simpleObserver_X.Integrator_CSTATE_p[1] = simpleObserver_P.Integrator_IC_i;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  simpleObserver_DW.oldCamData[1] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/PoseCalculation' */
  simpleObserver_DW.estPoseOld[1] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  simpleObserver_DW.DelayOneStep1_DSTATE[2] =
    simpleObserver_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  simpleObserver_X.Integrator_CSTATE[2] = simpleObserver_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  simpleObserver_X.Integrator_CSTATE_p[2] = simpleObserver_P.Integrator_IC_i;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  simpleObserver_DW.oldCamData[2] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/PoseCalculation' */
  simpleObserver_DW.estPoseOld[2] = 0.0;
}

/* Model terminate function */
void simpleObserver_terminate(void)
{
  /* (no terminate code required) */
}
