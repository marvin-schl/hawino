/*
 * DraftSimpleEstimatorANDControl.cpp
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

#include "DraftSimpleEstimatorANDControl.h"
#include "DraftSimpleEstimatorANDControl_private.h"

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si ,
  RT_MODEL_DraftSimpleEstimator_T *const DraftSimpleEstimatorANDContr_M)
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
  DraftSimpleEstimatorANDControl_derivatives(DraftSimpleEstimatorANDContr_M);
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void DraftSimpleEstimatorANDControl_step(RT_MODEL_DraftSimpleEstimator_T *const
  DraftSimpleEstimatorANDContr_M)
{
  B_DraftSimpleEstimatorANDCont_T *DraftSimpleEstimatorANDContro_B{
    DraftSimpleEstimatorANDContr_M->blockIO };

  DW_DraftSimpleEstimatorANDCon_T *DraftSimpleEstimatorANDContr_DW{
    DraftSimpleEstimatorANDContr_M->dwork };

  X_DraftSimpleEstimatorANDCont_T *DraftSimpleEstimatorANDContro_X{
    DraftSimpleEstimatorANDContr_M->contStates };

  real_T velW_tmp_1[9];
  real_T velW_tmp;
  real_T velW_tmp_0;
  int32_T k;
  if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    /* set solver stop time */
    if (!(DraftSimpleEstimatorANDContr_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(DraftSimpleEstimatorANDContr_M->solverInfo,
                            ((DraftSimpleEstimatorANDContr_M->Timing.clockTickH0
        + 1) * DraftSimpleEstimatorANDContr_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(DraftSimpleEstimatorANDContr_M->solverInfo,
                            ((DraftSimpleEstimatorANDContr_M->Timing.clockTick0
        + 1) * DraftSimpleEstimatorANDContr_M->Timing.stepSize0 +
        DraftSimpleEstimatorANDContr_M->Timing.clockTickH0 *
        DraftSimpleEstimatorANDContr_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    DraftSimpleEstimatorANDContr_M->Timing.t[0] = rtsiGetT
      (DraftSimpleEstimatorANDContr_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    boolean_T exitg1;
    boolean_T y;

    /* S-Function (TcModuleInOut): '<Root>/InNextWaypoint' */
    if (DraftSimpleEstimatorANDContr_DW->InNextWaypoint_PWORK != NULL) {
      memcpy(&DraftSimpleEstimatorANDContro_B->InNextWaypoint[0],
             DraftSimpleEstimatorANDContr_DW->InNextWaypoint_PWORK, 24);
    }

    /* S-Function (TcModuleInOut): '<Root>/InCameraPose' */
    if (DraftSimpleEstimatorANDContr_DW->InCameraPose_PWORK != NULL) {
      memcpy(&DraftSimpleEstimatorANDContro_B->InCameraPose[0],
             DraftSimpleEstimatorANDContr_DW->InCameraPose_PWORK, 24);
    }

    /* Math: '<S1>/Transpose1' */
    DraftSimpleEstimatorANDContro_B->CameraPOse[0] =
      DraftSimpleEstimatorANDContro_B->InCameraPose[0];
    DraftSimpleEstimatorANDContro_B->CameraPOse[1] =
      DraftSimpleEstimatorANDContro_B->InCameraPose[1];
    DraftSimpleEstimatorANDContro_B->CameraPOse[2] =
      DraftSimpleEstimatorANDContro_B->InCameraPose[2];

    /* MATLAB Function: '<S1>/CamFlag' incorporates:
     *  Math: '<S1>/Transpose1'
     */
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(DraftSimpleEstimatorANDContro_B->CameraPOse[k] !=
            DraftSimpleEstimatorANDContr_DW->oldCamData[k])) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (y) {
      DraftSimpleEstimatorANDContro_B->newCamDataArrived = true;
    } else {
      DraftSimpleEstimatorANDContro_B->newCamDataArrived = false;
      DraftSimpleEstimatorANDContr_DW->oldCamData[0] =
        DraftSimpleEstimatorANDContro_B->CameraPOse[0];
      DraftSimpleEstimatorANDContr_DW->oldCamData[1] =
        DraftSimpleEstimatorANDContro_B->CameraPOse[1];
      DraftSimpleEstimatorANDContr_DW->oldCamData[2] =
        DraftSimpleEstimatorANDContro_B->CameraPOse[2];
    }

    /* End of MATLAB Function: '<S1>/CamFlag' */

    /* Delay: '<S1>/Delay One Step1' */
    DraftSimpleEstimatorANDContro_B->DelayOneStep1[0] =
      DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[0];
    DraftSimpleEstimatorANDContro_B->DelayOneStep1[1] =
      DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[1];
    DraftSimpleEstimatorANDContro_B->DelayOneStep1[2] =
      DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[2];
  }

  /* Integrator: '<S1>/Integrator' */
  DraftSimpleEstimatorANDContro_B->Odometry[0] =
    DraftSimpleEstimatorANDContro_X->Integrator_CSTATE[0];
  DraftSimpleEstimatorANDContro_B->Odometry[1] =
    DraftSimpleEstimatorANDContro_X->Integrator_CSTATE[1];
  DraftSimpleEstimatorANDContro_B->Odometry[2] =
    DraftSimpleEstimatorANDContro_X->Integrator_CSTATE[2];

  /* Sum: '<S1>/Subtract2' incorporates:
   *  Delay: '<S1>/Delay One Step1'
   *  Integrator: '<S1>/Integrator'
   */
  DraftSimpleEstimatorANDContro_B->Subtract2[0] =
    DraftSimpleEstimatorANDContro_B->Odometry[0] -
    DraftSimpleEstimatorANDContro_B->DelayOneStep1[0];
  DraftSimpleEstimatorANDContro_B->Subtract2[1] =
    DraftSimpleEstimatorANDContro_B->Odometry[1] -
    DraftSimpleEstimatorANDContro_B->DelayOneStep1[1];
  DraftSimpleEstimatorANDContro_B->Subtract2[2] =
    DraftSimpleEstimatorANDContro_B->Odometry[2] -
    DraftSimpleEstimatorANDContro_B->DelayOneStep1[2];
  if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    /* Delay: '<S1>/CameraDelay' */
    DraftSimpleEstimatorANDContro_B->CameraDelay[0] =
      DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[0];
    DraftSimpleEstimatorANDContro_B->CameraDelay[1] =
      DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[1];
    DraftSimpleEstimatorANDContro_B->CameraDelay[2] =
      DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[2];
  }

  /* Sum: '<S1>/Subtract1' incorporates:
   *  Delay: '<S1>/CameraDelay'
   *  Integrator: '<S1>/Integrator'
   */
  DraftSimpleEstimatorANDContro_B->Subtract1[0] =
    DraftSimpleEstimatorANDContro_B->Odometry[0] -
    DraftSimpleEstimatorANDContro_B->CameraDelay[0];
  DraftSimpleEstimatorANDContro_B->Subtract1[1] =
    DraftSimpleEstimatorANDContro_B->Odometry[1] -
    DraftSimpleEstimatorANDContro_B->CameraDelay[1];
  DraftSimpleEstimatorANDContro_B->Subtract1[2] =
    DraftSimpleEstimatorANDContro_B->Odometry[2] -
    DraftSimpleEstimatorANDContro_B->CameraDelay[2];
  if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    /* MATLAB Function: '<S1>/PoseCalculation' incorporates:
     *  Math: '<S1>/Transpose1'
     *  Sum: '<S1>/Subtract1'
     *  Sum: '<S1>/Subtract2'
     */
    if (DraftSimpleEstimatorANDContro_B->newCamDataArrived) {
      DraftSimpleEstimatorANDContr_DW->estPoseOld[0] =
        DraftSimpleEstimatorANDContro_B->CameraPOse[0] +
        DraftSimpleEstimatorANDContro_B->Subtract1[0];
      DraftSimpleEstimatorANDContr_DW->estPoseOld[1] =
        DraftSimpleEstimatorANDContro_B->CameraPOse[1] +
        DraftSimpleEstimatorANDContro_B->Subtract1[1];
      DraftSimpleEstimatorANDContr_DW->estPoseOld[2] =
        DraftSimpleEstimatorANDContro_B->CameraPOse[2] +
        DraftSimpleEstimatorANDContro_B->Subtract1[2];
      DraftSimpleEstimatorANDContro_B->debug = 1.0;
    } else {
      DraftSimpleEstimatorANDContr_DW->estPoseOld[0] +=
        DraftSimpleEstimatorANDContro_B->Subtract2[0];
      DraftSimpleEstimatorANDContr_DW->estPoseOld[1] +=
        DraftSimpleEstimatorANDContro_B->Subtract2[1];
      DraftSimpleEstimatorANDContr_DW->estPoseOld[2] +=
        DraftSimpleEstimatorANDContro_B->Subtract2[2];
      DraftSimpleEstimatorANDContro_B->debug = 2.0;
    }

    DraftSimpleEstimatorANDContro_B->estimatedX =
      DraftSimpleEstimatorANDContr_DW->estPoseOld[0];
    DraftSimpleEstimatorANDContro_B->estimatedY =
      DraftSimpleEstimatorANDContr_DW->estPoseOld[1];
    DraftSimpleEstimatorANDContro_B->estimatedTheta =
      DraftSimpleEstimatorANDContr_DW->estPoseOld[2];

    /* Math: '<Root>/Transpose' incorporates:
     *  SignalConversion generated from: '<Root>/Transpose'
     */
    DraftSimpleEstimatorANDContro_B->Transpose_p[0] =
      DraftSimpleEstimatorANDContro_B->estimatedX;
    DraftSimpleEstimatorANDContro_B->Transpose_p[1] =
      DraftSimpleEstimatorANDContro_B->estimatedY;
    DraftSimpleEstimatorANDContro_B->Transpose_p[2] =
      DraftSimpleEstimatorANDContro_B->estimatedTheta;

    /* MATLAB Function: '<S1>/PoseCalculation' */
    DraftSimpleEstimatorANDContro_B->estimatedPose[0] =
      DraftSimpleEstimatorANDContr_DW->estPoseOld[0];

    /* Sum: '<Root>/Add' incorporates:
     *  Math: '<Root>/Transpose'
     */
    DraftSimpleEstimatorANDContro_B->ErrorPose[0] =
      DraftSimpleEstimatorANDContro_B->InNextWaypoint[0] -
      DraftSimpleEstimatorANDContro_B->Transpose_p[0];

    /* MATLAB Function: '<S1>/PoseCalculation' */
    DraftSimpleEstimatorANDContro_B->estimatedPose[1] =
      DraftSimpleEstimatorANDContr_DW->estPoseOld[1];

    /* Sum: '<Root>/Add' incorporates:
     *  Math: '<Root>/Transpose'
     */
    DraftSimpleEstimatorANDContro_B->ErrorPose[1] =
      DraftSimpleEstimatorANDContro_B->InNextWaypoint[1] -
      DraftSimpleEstimatorANDContro_B->Transpose_p[1];

    /* MATLAB Function: '<S1>/PoseCalculation' */
    DraftSimpleEstimatorANDContro_B->estimatedPose[2] =
      DraftSimpleEstimatorANDContr_DW->estPoseOld[2];

    /* Sum: '<Root>/Add' incorporates:
     *  Math: '<Root>/Transpose'
     */
    DraftSimpleEstimatorANDContro_B->ErrorPose[2] =
      DraftSimpleEstimatorANDContro_B->InNextWaypoint[2] -
      DraftSimpleEstimatorANDContro_B->Transpose_p[2];
  }

  /* S-Function (TcModuleInOut): '<Root>/InVXfromMotors' */
  if (DraftSimpleEstimatorANDContr_DW->InVXfromMotors_PWORK != NULL) {
    DraftSimpleEstimatorANDContro_B->InVXfromMotors = *((real_T*)
      DraftSimpleEstimatorANDContr_DW->InVXfromMotors_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVYfromMotors' */
  if (DraftSimpleEstimatorANDContr_DW->InVYfromMotors_PWORK != NULL) {
    DraftSimpleEstimatorANDContro_B->InVYfromMotors = *((real_T*)
      DraftSimpleEstimatorANDContr_DW->InVYfromMotors_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVThetafromMotors' */
  if (DraftSimpleEstimatorANDContr_DW->InVThetafromMotors_PWORK != NULL) {
    DraftSimpleEstimatorANDContro_B->InVThetafromMotors = *((real_T*)
      DraftSimpleEstimatorANDContr_DW->InVThetafromMotors_PWORK);
  }

  /* SignalConversion generated from: '<S1>/Transpose' */
  DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtTransposeI[0] =
    DraftSimpleEstimatorANDContro_B->InVXfromMotors;
  DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtTransposeI[1] =
    DraftSimpleEstimatorANDContro_B->InVYfromMotors;
  DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtTransposeI[2] =
    DraftSimpleEstimatorANDContro_B->InVThetafromMotors;

  /* MATLAB Function: '<S1>/Transformation Robot to World' incorporates:
   *  MATLAB Function: '<Root>/Transformation World to Robot'
   */
  velW_tmp = std::sin(DraftSimpleEstimatorANDContro_B->estimatedTheta);
  velW_tmp_0 = std::cos(DraftSimpleEstimatorANDContro_B->estimatedTheta);
  velW_tmp_1[0] = velW_tmp_0;
  velW_tmp_1[1] = -velW_tmp;
  velW_tmp_1[2] = 0.0;
  velW_tmp_1[3] = velW_tmp;
  velW_tmp_1[4] = velW_tmp_0;
  velW_tmp_1[5] = 0.0;

  /* Math: '<S1>/Transpose' */
  DraftSimpleEstimatorANDContro_B->Transpose[0] =
    DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtTransposeI[0];

  /* MATLAB Function: '<S1>/Transformation Robot to World' */
  velW_tmp_1[6] = 0.0;

  /* Math: '<S1>/Transpose' */
  DraftSimpleEstimatorANDContro_B->Transpose[1] =
    DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtTransposeI[1];

  /* MATLAB Function: '<S1>/Transformation Robot to World' */
  velW_tmp_1[7] = 0.0;

  /* Math: '<S1>/Transpose' */
  DraftSimpleEstimatorANDContro_B->Transpose[2] =
    DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtTransposeI[2];

  /* MATLAB Function: '<S1>/Transformation Robot to World' incorporates:
   *  Math: '<S1>/Transpose'
   */
  velW_tmp_1[8] = 1.0;
  for (k = 0; k < 3; k++) {
    DraftSimpleEstimatorANDContro_B->velW[k] = 0.0;
    DraftSimpleEstimatorANDContro_B->velW[k] += velW_tmp_1[3 * k] *
      DraftSimpleEstimatorANDContro_B->Transpose[0];
    DraftSimpleEstimatorANDContro_B->velW[k] += velW_tmp_1[3 * k + 1] *
      DraftSimpleEstimatorANDContro_B->Transpose[1];
    DraftSimpleEstimatorANDContro_B->velW[k] += velW_tmp_1[3 * k + 2] *
      DraftSimpleEstimatorANDContro_B->Transpose[2];
  }

  if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    /* S-Function (TcModuleInOut): '<Root>/InContrID' */
    if (DraftSimpleEstimatorANDContr_DW->InContrID_PWORK != NULL) {
      DraftSimpleEstimatorANDContro_B->InContrID = *((real_T*)
        DraftSimpleEstimatorANDContr_DW->InContrID_PWORK);
    }

    /* S-Function (TcModuleInOut): '<Root>/InContrIN' */
    if (DraftSimpleEstimatorANDContr_DW->InContrIN_PWORK != NULL) {
      DraftSimpleEstimatorANDContro_B->InContrIN = *((real_T*)
        DraftSimpleEstimatorANDContr_DW->InContrIN_PWORK);
    }

    /* S-Function (TcModuleInOut): '<Root>/InContrP' */
    if (DraftSimpleEstimatorANDContr_DW->InContrP_PWORK != NULL) {
      DraftSimpleEstimatorANDContro_B->InContrP = *((real_T*)
        DraftSimpleEstimatorANDContr_DW->InContrP_PWORK);
    }

    /* S-Function (TcModuleInOut): '<Root>/InContrlI' */
    if (DraftSimpleEstimatorANDContr_DW->InContrlI_PWORK != NULL) {
      DraftSimpleEstimatorANDContro_B->InContrlI = *((real_T*)
        DraftSimpleEstimatorANDContr_DW->InContrlI_PWORK);
    }

    /* MATLAB Function: '<Root>/Transformation World to Robot' */
    velW_tmp_1[0] = velW_tmp_0;
    velW_tmp_1[3] = velW_tmp;
    velW_tmp_1[6] = 0.0;
    velW_tmp_1[1] = -std::sin(DraftSimpleEstimatorANDContro_B->estimatedTheta);
    velW_tmp_1[4] = velW_tmp_0;
    velW_tmp_1[7] = 0.0;
    velW_tmp_1[2] = 0.0;
    velW_tmp_1[5] = 0.0;
    velW_tmp_1[8] = 1.0;
    for (k = 0; k < 3; k++) {
      DraftSimpleEstimatorANDContro_B->velR[k] = 0.0;
      DraftSimpleEstimatorANDContro_B->velR[k] += velW_tmp_1[k] *
        DraftSimpleEstimatorANDContro_B->ErrorPose[0];
      DraftSimpleEstimatorANDContro_B->velR[k] += velW_tmp_1[k + 3] *
        DraftSimpleEstimatorANDContro_B->ErrorPose[1];
      DraftSimpleEstimatorANDContro_B->velR[k] += velW_tmp_1[k + 6] *
        DraftSimpleEstimatorANDContro_B->ErrorPose[2];
    }

    /* Saturate: '<Root>/Saturation' */
    if (DraftSimpleEstimatorANDContro_B->velR[0] > 500.0) {
      /* Saturate: '<Root>/Saturation' */
      DraftSimpleEstimatorANDContro_B->Saturation = 500.0;
    } else if (DraftSimpleEstimatorANDContro_B->velR[0] < -500.0) {
      /* Saturate: '<Root>/Saturation' */
      DraftSimpleEstimatorANDContro_B->Saturation = -500.0;
    } else {
      /* Saturate: '<Root>/Saturation' */
      DraftSimpleEstimatorANDContro_B->Saturation =
        DraftSimpleEstimatorANDContro_B->velR[0];
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Saturate: '<Root>/Saturation1' */
    if (DraftSimpleEstimatorANDContro_B->velR[1] > 500.0) {
      /* Saturate: '<Root>/Saturation1' */
      DraftSimpleEstimatorANDContro_B->Saturation1 = 500.0;
    } else if (DraftSimpleEstimatorANDContro_B->velR[1] < -500.0) {
      /* Saturate: '<Root>/Saturation1' */
      DraftSimpleEstimatorANDContro_B->Saturation1 = -500.0;
    } else {
      /* Saturate: '<Root>/Saturation1' */
      DraftSimpleEstimatorANDContro_B->Saturation1 =
        DraftSimpleEstimatorANDContro_B->velR[1];
    }

    /* End of Saturate: '<Root>/Saturation1' */

    /* Saturate: '<Root>/Saturation2' */
    if (DraftSimpleEstimatorANDContro_B->velR[2] > 1.0) {
      /* Saturate: '<Root>/Saturation2' */
      DraftSimpleEstimatorANDContro_B->Saturation2 = 1.0;
    } else if (DraftSimpleEstimatorANDContro_B->velR[2] < -1.0) {
      /* Saturate: '<Root>/Saturation2' */
      DraftSimpleEstimatorANDContro_B->Saturation2 = -1.0;
    } else {
      /* Saturate: '<Root>/Saturation2' */
      DraftSimpleEstimatorANDContro_B->Saturation2 =
        DraftSimpleEstimatorANDContro_B->velR[2];
    }

    /* End of Saturate: '<Root>/Saturation2' */

    /* SignalConversion generated from: '<Root>/OutVtoMotors' */
    DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtOutVtoMoto[0] =
      DraftSimpleEstimatorANDContro_B->Saturation;
    DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtOutVtoMoto[1] =
      DraftSimpleEstimatorANDContro_B->Saturation1;
    DraftSimpleEstimatorANDContro_B->TmpSignalConversionAtOutVtoMoto[2] =
      DraftSimpleEstimatorANDContro_B->Saturation2;
  }

  if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
      /* Update for S-Function (TcModuleInOut): '<Root>/OutDebugCase' */
      if (DraftSimpleEstimatorANDContr_DW->OutDebugCase_PWORK != NULL) {
        *((real_T*)DraftSimpleEstimatorANDContr_DW->OutDebugCase_PWORK) =
          DraftSimpleEstimatorANDContro_B->debug;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/OutErrorPose' */
      if (DraftSimpleEstimatorANDContr_DW->OutErrorPose_PWORK != NULL) {
        memcpy(DraftSimpleEstimatorANDContr_DW->OutErrorPose_PWORK,
               &DraftSimpleEstimatorANDContro_B->ErrorPose[0], 24);
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/OutEstTheta' */
      if (DraftSimpleEstimatorANDContr_DW->OutEstTheta_PWORK != NULL) {
        *((real_T*)DraftSimpleEstimatorANDContr_DW->OutEstTheta_PWORK) =
          DraftSimpleEstimatorANDContro_B->estimatedTheta;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/OutEstX' */
      if (DraftSimpleEstimatorANDContr_DW->OutEstX_PWORK != NULL) {
        *((real_T*)DraftSimpleEstimatorANDContr_DW->OutEstX_PWORK) =
          DraftSimpleEstimatorANDContro_B->estimatedX;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/OutEstY' */
      if (DraftSimpleEstimatorANDContr_DW->OutEstY_PWORK != NULL) {
        *((real_T*)DraftSimpleEstimatorANDContr_DW->OutEstY_PWORK) =
          DraftSimpleEstimatorANDContro_B->estimatedY;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/OutVtoMotors' */
      if (DraftSimpleEstimatorANDContr_DW->OutVtoMotors_PWORK != NULL) {
        memcpy(DraftSimpleEstimatorANDContr_DW->OutVtoMotors_PWORK,
               &DraftSimpleEstimatorANDContro_B->
               TmpSignalConversionAtOutVtoMoto[0], 24);
      }

      /* Update for Delay: '<S1>/Delay One Step1' incorporates:
       *  Integrator: '<S1>/Integrator'
       */
      DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[0] =
        DraftSimpleEstimatorANDContro_B->Odometry[0];
      DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[1] =
        DraftSimpleEstimatorANDContro_B->Odometry[1];
      DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[2] =
        DraftSimpleEstimatorANDContro_B->Odometry[2];

      /* Update for Delay: '<S1>/CameraDelay' incorporates:
       *  Integrator: '<S1>/Integrator'
       */
      for (int_T idxDelay{0}; idxDelay < 13; idxDelay++) {
        int32_T CameraDelay_DSTATE_tmp;
        CameraDelay_DSTATE_tmp = (idxDelay + 1) * 3;
        DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[idxDelay * 3] =
          DraftSimpleEstimatorANDContr_DW->
          CameraDelay_DSTATE[CameraDelay_DSTATE_tmp];
        DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[idxDelay * 3 + 1] =
          DraftSimpleEstimatorANDContr_DW->
          CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 1];
        DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[idxDelay * 3 + 2] =
          DraftSimpleEstimatorANDContr_DW->
          CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 2];
      }

      DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[39] =
        DraftSimpleEstimatorANDContro_B->Odometry[0];
      DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[40] =
        DraftSimpleEstimatorANDContro_B->Odometry[1];
      DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[41] =
        DraftSimpleEstimatorANDContro_B->Odometry[2];

      /* End of Update for Delay: '<S1>/CameraDelay' */
    }

    /* Update for S-Function (TcModuleInOut): '<S1>/vMotors' */
    if (DraftSimpleEstimatorANDContr_DW->vMotors_PWORK != NULL) {
      memcpy(DraftSimpleEstimatorANDContr_DW->vMotors_PWORK,
             &DraftSimpleEstimatorANDContro_B->Transpose[0], 24);
    }

    /* Update for S-Function (TcModuleInOut): '<S1>/vWorld' */
    if (DraftSimpleEstimatorANDContr_DW->vWorld_PWORK != NULL) {
      memcpy(DraftSimpleEstimatorANDContr_DW->vWorld_PWORK,
             &DraftSimpleEstimatorANDContro_B->velW[0], 24);
    }

    if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DraftSimpleEstimatorANDContr_M)) {
    rt_ertODEUpdateContinuousStates(DraftSimpleEstimatorANDContr_M->solverInfo,
      DraftSimpleEstimatorANDContr_M);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DraftSimpleEstimatorANDContr_M->Timing.clockTick0)) {
      ++DraftSimpleEstimatorANDContr_M->Timing.clockTickH0;
    }

    DraftSimpleEstimatorANDContr_M->Timing.t[0] = rtsiGetSolverStopTime
      (DraftSimpleEstimatorANDContr_M->solverInfo);

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
      DraftSimpleEstimatorANDContr_M->Timing.clockTick1++;
      if (!DraftSimpleEstimatorANDContr_M->Timing.clockTick1) {
        DraftSimpleEstimatorANDContr_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void DraftSimpleEstimatorANDControl_derivatives(RT_MODEL_DraftSimpleEstimator_T *
  const DraftSimpleEstimatorANDContr_M)
{
  B_DraftSimpleEstimatorANDCont_T *DraftSimpleEstimatorANDContro_B{
    DraftSimpleEstimatorANDContr_M->blockIO };

  XDot_DraftSimpleEstimatorANDC_T *_rtXdot;
  _rtXdot = ((XDot_DraftSimpleEstimatorANDC_T *)
             DraftSimpleEstimatorANDContr_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = DraftSimpleEstimatorANDContro_B->velW[0];
  _rtXdot->Integrator_CSTATE[1] = DraftSimpleEstimatorANDContro_B->velW[1];
  _rtXdot->Integrator_CSTATE[2] = DraftSimpleEstimatorANDContro_B->velW[2];
}

/* Model initialize function */
void DraftSimpleEstimatorANDControl_initialize(RT_MODEL_DraftSimpleEstimator_T *
  const DraftSimpleEstimatorANDContr_M)
{
  DW_DraftSimpleEstimatorANDCon_T *DraftSimpleEstimatorANDContr_DW{
    DraftSimpleEstimatorANDContr_M->dwork };

  X_DraftSimpleEstimatorANDCont_T *DraftSimpleEstimatorANDContro_X{
    DraftSimpleEstimatorANDContr_M->contStates };

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  DraftSimpleEstimatorANDContro_X->Integrator_CSTATE[0] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  DraftSimpleEstimatorANDContro_X->Integrator_CSTATE[1] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  DraftSimpleEstimatorANDContro_X->Integrator_CSTATE[2] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  DraftSimpleEstimatorANDContr_DW->DelayOneStep1_DSTATE[2] = 0.0;

  /* InitializeConditions for Delay: '<S1>/CameraDelay' */
  std::memset(&DraftSimpleEstimatorANDContr_DW->CameraDelay_DSTATE[0], 0, 42U *
              sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  DraftSimpleEstimatorANDContr_DW->oldCamData[0] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/PoseCalculation' */
  DraftSimpleEstimatorANDContr_DW->estPoseOld[0] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  DraftSimpleEstimatorANDContr_DW->oldCamData[1] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/PoseCalculation' */
  DraftSimpleEstimatorANDContr_DW->estPoseOld[1] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  DraftSimpleEstimatorANDContr_DW->oldCamData[2] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/PoseCalculation' */
  DraftSimpleEstimatorANDContr_DW->estPoseOld[2] = 0.0;
}

/* Model terminate function */
void DraftSimpleEstimatorANDControl_terminate(RT_MODEL_DraftSimpleEstimator_T
  * DraftSimpleEstimatorANDContr_M)
{
  rt_FREE(DraftSimpleEstimatorANDContr_M->solverInfo);

  /* model code */
  rt_FREE(DraftSimpleEstimatorANDContr_M->blockIO);
  rt_FREE(DraftSimpleEstimatorANDContr_M->contStates);
  rt_FREE(DraftSimpleEstimatorANDContr_M->dwork);
  delete DraftSimpleEstimatorANDContr_M;
}

/* Model data allocation function */
RT_MODEL_DraftSimpleEstimator_T *DraftSimpleEstimatorANDControl(void)
{
  RT_MODEL_DraftSimpleEstimator_T *DraftSimpleEstimatorANDContr_M;
  DraftSimpleEstimatorANDContr_M = new RT_MODEL_DraftSimpleEstimator_T();
  if (DraftSimpleEstimatorANDContr_M == (nullptr)) {
    return (nullptr);
  }

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo{ (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo))
    };

    rt_VALIDATE_MEMORY(DraftSimpleEstimatorANDContr_M,rt_SolverInfo);
    DraftSimpleEstimatorANDContr_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(DraftSimpleEstimatorANDContr_M->solverInfo,
                          &DraftSimpleEstimatorANDContr_M->Timing.simTimeStep);
    rtsiSetTPtr(DraftSimpleEstimatorANDContr_M->solverInfo, &rtmGetTPtr
                (DraftSimpleEstimatorANDContr_M));
    rtsiSetStepSizePtr(DraftSimpleEstimatorANDContr_M->solverInfo,
                       &DraftSimpleEstimatorANDContr_M->Timing.stepSize0);
    rtsiSetdXPtr(DraftSimpleEstimatorANDContr_M->solverInfo,
                 &DraftSimpleEstimatorANDContr_M->derivs);
    rtsiSetContStatesPtr(DraftSimpleEstimatorANDContr_M->solverInfo, (real_T **)
                         &DraftSimpleEstimatorANDContr_M->contStates);
    rtsiSetNumContStatesPtr(DraftSimpleEstimatorANDContr_M->solverInfo,
      &DraftSimpleEstimatorANDContr_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(DraftSimpleEstimatorANDContr_M->solverInfo,
      &DraftSimpleEstimatorANDContr_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (DraftSimpleEstimatorANDContr_M->solverInfo,
       &DraftSimpleEstimatorANDContr_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(DraftSimpleEstimatorANDContr_M->solverInfo,
      &DraftSimpleEstimatorANDContr_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(DraftSimpleEstimatorANDContr_M->solverInfo,
                          (&rtmGetErrorStatus(DraftSimpleEstimatorANDContr_M)));
    rtsiSetRTModelPtr(DraftSimpleEstimatorANDContr_M->solverInfo,
                      DraftSimpleEstimatorANDContr_M);
  }

  rtsiSetSolverName(DraftSimpleEstimatorANDContr_M->solverInfo,"ode1");

  /* block I/O */
  {
    B_DraftSimpleEstimatorANDCont_T *b{ (B_DraftSimpleEstimatorANDCont_T *)
      malloc(sizeof(B_DraftSimpleEstimatorANDCont_T)) };

    rt_VALIDATE_MEMORY(DraftSimpleEstimatorANDContr_M,b);
    DraftSimpleEstimatorANDContr_M->blockIO = (b);
  }

  /* states (continuous) */
  {
    X_DraftSimpleEstimatorANDCont_T *x{ (X_DraftSimpleEstimatorANDCont_T *)
      malloc(sizeof(X_DraftSimpleEstimatorANDCont_T)) };

    rt_VALIDATE_MEMORY(DraftSimpleEstimatorANDContr_M,x);
    DraftSimpleEstimatorANDContr_M->contStates = (x);
  }

  /* states (dwork) */
  {
    DW_DraftSimpleEstimatorANDCon_T *dwork{
      static_cast<DW_DraftSimpleEstimatorANDCon_T *>(malloc(sizeof
      (DW_DraftSimpleEstimatorANDCon_T))) };

    rt_VALIDATE_MEMORY(DraftSimpleEstimatorANDContr_M,dwork);
    DraftSimpleEstimatorANDContr_M->dwork = (dwork);
  }

  {
    B_DraftSimpleEstimatorANDCont_T *DraftSimpleEstimatorANDContro_B{
      DraftSimpleEstimatorANDContr_M->blockIO };

    DW_DraftSimpleEstimatorANDCon_T *DraftSimpleEstimatorANDContr_DW{
      DraftSimpleEstimatorANDContr_M->dwork };

    X_DraftSimpleEstimatorANDCont_T *DraftSimpleEstimatorANDContro_X{
      DraftSimpleEstimatorANDContr_M->contStates };

    rtsiSetSimTimeStep(DraftSimpleEstimatorANDContr_M->solverInfo,
                       MAJOR_TIME_STEP);
    DraftSimpleEstimatorANDContr_M->intgData.f[0] =
      DraftSimpleEstimatorANDContr_M->odeF[0];
    DraftSimpleEstimatorANDContr_M->contStates =
      ((X_DraftSimpleEstimatorANDCont_T *) DraftSimpleEstimatorANDContro_X);
    rtsiSetSolverData(DraftSimpleEstimatorANDContr_M->solverInfo, static_cast<
                      void *>(&DraftSimpleEstimatorANDContr_M->intgData));
    rtmSetTPtr(DraftSimpleEstimatorANDContr_M,
               &DraftSimpleEstimatorANDContr_M->Timing.tArray[0]);
    DraftSimpleEstimatorANDContr_M->Timing.stepSize0 = 0.01;

    /* block I/O */
    (void) std::memset((static_cast<void *>(DraftSimpleEstimatorANDContro_B)), 0,
                       sizeof(B_DraftSimpleEstimatorANDCont_T));

    /* states (continuous) */
    {
      (void) std::memset(static_cast<void *>(DraftSimpleEstimatorANDContro_X), 0,
                         sizeof(X_DraftSimpleEstimatorANDCont_T));
    }

    /* states (dwork) */
    (void) std::memset(static_cast<void *>(DraftSimpleEstimatorANDContr_DW), 0,
                       sizeof(DW_DraftSimpleEstimatorANDCon_T));
  }

  return DraftSimpleEstimatorANDContr_M;
}
