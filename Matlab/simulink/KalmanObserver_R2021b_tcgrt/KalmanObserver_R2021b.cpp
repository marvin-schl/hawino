/*
 * KalmanObserver_R2021b.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "KalmanObserver_R2021b".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Mon Mar 20 12:17:59 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "KalmanObserver_R2021b.h"
#include "KalmanObserver_R2021b_private.h"

/* Block signals (default storage) */
B_KalmanObserver_R2021b_T KalmanObserver_R2021b_B;

/* Continuous states */
X_KalmanObserver_R2021b_T KalmanObserver_R2021b_X;

/* Block states (default storage) */
DW_KalmanObserver_R2021b_T KalmanObserver_R2021b_DW;

/* Real-time model */
RT_MODEL_KalmanObserver_R2021_T KalmanObserver_R2021b_M_{ };

RT_MODEL_KalmanObserver_R2021_T *const KalmanObserver_R2021b_M{ &
  KalmanObserver_R2021b_M_ };

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
  int_T nXc { 3 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  KalmanObserver_R2021b_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void KalmanObserver_R2021b_step(void)
{
  static const real_T b[9]{ 3.8635, 0.4415, -0.0036, 0.4415, 9.3899, -0.0078,
    -0.0036, -0.0078, 0.0001 };

  static const real_T c[9]{ 0.00127820524383046, -0.00144745069148629,
    1.57202639633006E-6, -0.00144745069148629, 0.0142936660651043,
    -2.43008878392535E-5, 1.57202639633006E-6, -2.43008878392535E-5,
    2.50703907504212E-7 };

  static const int8_T a[9]{ 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T PAp[9];
  real_T b_x[9];
  real_T xHatAp_tmp_0[9];
  real_T tmp[3];
  real_T xHatAp[3];
  int32_T p1;
  int8_T xHatAp_tmp[9];
  if (rtmIsMajorTimeStep(KalmanObserver_R2021b_M)) {
    /* set solver stop time */
    if (!(KalmanObserver_R2021b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&KalmanObserver_R2021b_M->solverInfo,
                            ((KalmanObserver_R2021b_M->Timing.clockTickH0 + 1) *
        KalmanObserver_R2021b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&KalmanObserver_R2021b_M->solverInfo,
                            ((KalmanObserver_R2021b_M->Timing.clockTick0 + 1) *
        KalmanObserver_R2021b_M->Timing.stepSize0 +
        KalmanObserver_R2021b_M->Timing.clockTickH0 *
        KalmanObserver_R2021b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(KalmanObserver_R2021b_M)) {
    KalmanObserver_R2021b_M->Timing.t[0] = rtsiGetT
      (&KalmanObserver_R2021b_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(KalmanObserver_R2021b_M)) {
    boolean_T exitg1;
    boolean_T y;

    /* S-Function (TcModuleInOut): '<Root>/InCameraPose' */
    if (KalmanObserver_R2021b_DW.InCameraPose_PWORK != NULL) {
      memcpy(&KalmanObserver_R2021b_B.InCameraPose[0],
             KalmanObserver_R2021b_DW.InCameraPose_PWORK, 24);
    }

    /* MATLAB Function: '<S1>/CamFlag' */
    y = true;
    p1 = 0;
    exitg1 = false;
    while ((!exitg1) && (p1 < 3)) {
      if (!(KalmanObserver_R2021b_B.InCameraPose[p1] !=
            KalmanObserver_R2021b_DW.oldCamData[p1])) {
        y = false;
        exitg1 = true;
      } else {
        p1++;
      }
    }

    if (y) {
      KalmanObserver_R2021b_B.newCamDataArrived = true;
      p1 = 0;
      exitg1 = false;
      while ((!exitg1) && (p1 < 2)) {
        if (KalmanObserver_R2021b_B.InCameraPose[p1] == 0.0) {
          KalmanObserver_R2021b_B.newCamDataArrived = false;
          exitg1 = true;
        } else {
          p1++;
        }
      }
    } else {
      KalmanObserver_R2021b_B.newCamDataArrived = false;
    }

    KalmanObserver_R2021b_DW.oldCamData[0] =
      KalmanObserver_R2021b_B.InCameraPose[0];

    /* Delay: '<S1>/CameraDelay' */
    KalmanObserver_R2021b_B.CameraDelay[0] =
      KalmanObserver_R2021b_DW.CameraDelay_DSTATE[0];

    /* Delay: '<S1>/Delay One Step1' */
    KalmanObserver_R2021b_B.DelayOneStep1[0] =
      KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[0];

    /* MATLAB Function: '<S1>/CamFlag' */
    KalmanObserver_R2021b_DW.oldCamData[1] =
      KalmanObserver_R2021b_B.InCameraPose[1];

    /* Delay: '<S1>/CameraDelay' */
    KalmanObserver_R2021b_B.CameraDelay[1] =
      KalmanObserver_R2021b_DW.CameraDelay_DSTATE[1];

    /* Delay: '<S1>/Delay One Step1' */
    KalmanObserver_R2021b_B.DelayOneStep1[1] =
      KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[1];

    /* MATLAB Function: '<S1>/CamFlag' */
    KalmanObserver_R2021b_DW.oldCamData[2] =
      KalmanObserver_R2021b_B.InCameraPose[2];

    /* Delay: '<S1>/CameraDelay' */
    KalmanObserver_R2021b_B.CameraDelay[2] =
      KalmanObserver_R2021b_DW.CameraDelay_DSTATE[2];

    /* Delay: '<S1>/Delay One Step1' */
    KalmanObserver_R2021b_B.DelayOneStep1[2] =
      KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[2];
  }

  /* Integrator: '<S1>/Integrator' */
  KalmanObserver_R2021b_B.Odometry[0] =
    KalmanObserver_R2021b_X.Integrator_CSTATE[0];
  KalmanObserver_R2021b_B.Odometry[1] =
    KalmanObserver_R2021b_X.Integrator_CSTATE[1];
  KalmanObserver_R2021b_B.Odometry[2] =
    KalmanObserver_R2021b_X.Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(KalmanObserver_R2021b_M)) {
    /* S-Function (TcModuleInOut): '<Root>/vxToRobot' */
    if (KalmanObserver_R2021b_DW.vxToRobot_PWORK != NULL) {
      KalmanObserver_R2021b_B.vxToRobot = *((real_T*)
        KalmanObserver_R2021b_DW.vxToRobot_PWORK);
    }

    /* S-Function (TcModuleInOut): '<Root>/vyToRobot' */
    if (KalmanObserver_R2021b_DW.vyToRobot_PWORK != NULL) {
      KalmanObserver_R2021b_B.vyToRobot = *((real_T*)
        KalmanObserver_R2021b_DW.vyToRobot_PWORK);
    }

    /* S-Function (TcModuleInOut): '<Root>/omegaToRobot' */
    if (KalmanObserver_R2021b_DW.omegaToRobot_PWORK != NULL) {
      KalmanObserver_R2021b_B.omegaToRobot = *((real_T*)
        KalmanObserver_R2021b_DW.omegaToRobot_PWORK);
    }
  }

  /* Sum: '<S1>/Sum2' */
  KalmanObserver_R2021b_B.Sum2[0] = KalmanObserver_R2021b_B.Odometry[0] -
    KalmanObserver_R2021b_B.CameraDelay[0];
  KalmanObserver_R2021b_B.Sum2[1] = KalmanObserver_R2021b_B.Odometry[1] -
    KalmanObserver_R2021b_B.CameraDelay[1];
  KalmanObserver_R2021b_B.Sum2[2] = KalmanObserver_R2021b_B.Odometry[2] -
    KalmanObserver_R2021b_B.CameraDelay[2];

  /* Sum: '<S1>/Sum1' */
  KalmanObserver_R2021b_B.Sum1[0] = KalmanObserver_R2021b_B.Odometry[0] -
    KalmanObserver_R2021b_B.DelayOneStep1[0];
  KalmanObserver_R2021b_B.Sum1[1] = KalmanObserver_R2021b_B.Odometry[1] -
    KalmanObserver_R2021b_B.DelayOneStep1[1];
  KalmanObserver_R2021b_B.Sum1[2] = KalmanObserver_R2021b_B.Odometry[2] -
    KalmanObserver_R2021b_B.DelayOneStep1[2];
  if (rtmIsMajorTimeStep(KalmanObserver_R2021b_M)) {
    real_T absx11;
    real_T absx21;
    real_T absx31;
    int32_T p2;
    int32_T p3;

    /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function'
     */
    KalmanObserver_R2021b_B.TmpSignalConversionAtSFunctionI[0] =
      KalmanObserver_R2021b_B.vxToRobot;
    KalmanObserver_R2021b_B.TmpSignalConversionAtSFunctionI[1] =
      KalmanObserver_R2021b_B.vyToRobot;
    KalmanObserver_R2021b_B.TmpSignalConversionAtSFunctionI[2] =
      KalmanObserver_R2021b_B.omegaToRobot;

    /* MATLAB Function: '<S1>/MATLAB Function' */
    KalmanObserver_R2021b_B.camDataAdj[0] = 0.0;
    KalmanObserver_R2021b_B.camDataAdj[1] = 0.0;
    KalmanObserver_R2021b_B.camDataAdj[2] = 0.0;
    for (p1 = 0; p1 < 9; p1++) {
      xHatAp_tmp[p1] = a[p1];
    }

    for (p3 = 0; p3 < 3; p3++) {
      absx11 = 0.0;
      for (p1 = 0; p1 < 3; p1++) {
        p2 = 3 * p1 + p3;
        absx11 += static_cast<real_T>(xHatAp_tmp[p2]) *
          KalmanObserver_R2021b_DW.xHatOld[p1];
        xHatAp_tmp_0[p2] = 0.0;
        xHatAp_tmp_0[p2] += KalmanObserver_R2021b_DW.P[3 * p1] *
          static_cast<real_T>(xHatAp_tmp[p3]);
        xHatAp_tmp_0[p2] += KalmanObserver_R2021b_DW.P[3 * p1 + 1] *
          static_cast<real_T>(xHatAp_tmp[p3 + 3]);
        xHatAp_tmp_0[p2] += KalmanObserver_R2021b_DW.P[3 * p1 + 2] *
          static_cast<real_T>(xHatAp_tmp[p3 + 6]);
      }

      absx11 += 0.01 *
        KalmanObserver_R2021b_B.TmpSignalConversionAtSFunctionI[p3];
      for (p1 = 0; p1 < 3; p1++) {
        p2 = 3 * p1 + p3;
        PAp[p2] = ((static_cast<real_T>(xHatAp_tmp[3 * p1 + 1]) *
                    xHatAp_tmp_0[p3 + 3] + static_cast<real_T>(xHatAp_tmp[3 * p1])
                    * xHatAp_tmp_0[p3]) + static_cast<real_T>(xHatAp_tmp[3 * p1
                    + 2]) * xHatAp_tmp_0[p3 + 6]) + b[p2];
      }

      KalmanObserver_R2021b_B.xHat[p3] = absx11;
      xHatAp[p3] = absx11;
    }

    for (p1 = 0; p1 < 9; p1++) {
      absx11 = PAp[p1];
      KalmanObserver_R2021b_DW.P[p1] = absx11;
      absx11 += c[p1];
      b_x[p1] = absx11;
      xHatAp_tmp_0[p1] = absx11;
    }

    p1 = 0;
    p2 = 3;
    p3 = 6;
    absx11 = std::abs(xHatAp_tmp_0[0]);
    absx21 = std::abs(xHatAp_tmp_0[1]);
    absx31 = std::abs(xHatAp_tmp_0[2]);
    if ((absx21 > absx11) && (absx21 > absx31)) {
      p1 = 3;
      p2 = 0;
      b_x[0] = xHatAp_tmp_0[1];
      b_x[1] = xHatAp_tmp_0[0];
      b_x[3] = xHatAp_tmp_0[4];
      b_x[4] = xHatAp_tmp_0[3];
      b_x[6] = xHatAp_tmp_0[7];
      b_x[7] = xHatAp_tmp_0[6];
    } else if (absx31 > absx11) {
      p1 = 6;
      p3 = 0;
      b_x[0] = xHatAp_tmp_0[2];
      b_x[2] = xHatAp_tmp_0[0];
      b_x[3] = xHatAp_tmp_0[5];
      b_x[5] = xHatAp_tmp_0[3];
      b_x[6] = xHatAp_tmp_0[8];
      b_x[8] = xHatAp_tmp_0[6];
    }

    b_x[1] /= b_x[0];
    b_x[2] /= b_x[0];
    b_x[4] -= b_x[1] * b_x[3];
    b_x[5] -= b_x[2] * b_x[3];
    b_x[7] -= b_x[1] * b_x[6];
    b_x[8] -= b_x[2] * b_x[6];
    if (std::abs(b_x[5]) > std::abs(b_x[4])) {
      int32_T itmp;
      itmp = p2;
      p2 = p3;
      p3 = itmp;
      absx11 = b_x[1];
      b_x[1] = b_x[2];
      b_x[2] = absx11;
      absx11 = b_x[4];
      b_x[4] = b_x[5];
      b_x[5] = absx11;
      absx11 = b_x[7];
      b_x[7] = b_x[8];
      b_x[8] = absx11;
    }

    b_x[5] /= b_x[4];
    b_x[8] -= b_x[5] * b_x[7];
    absx11 = (b_x[1] * b_x[5] - b_x[2]) / b_x[8];
    absx21 = -(b_x[7] * absx11 + b_x[1]) / b_x[4];
    xHatAp_tmp_0[p1] = ((1.0 - b_x[3] * absx21) - b_x[6] * absx11) / b_x[0];
    xHatAp_tmp_0[p1 + 1] = absx21;
    xHatAp_tmp_0[p1 + 2] = absx11;
    absx11 = -b_x[5] / b_x[8];
    absx21 = (1.0 - b_x[7] * absx11) / b_x[4];
    xHatAp_tmp_0[p2] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
    xHatAp_tmp_0[p2 + 1] = absx21;
    xHatAp_tmp_0[p2 + 2] = absx11;
    absx11 = 1.0 / b_x[8];
    absx21 = -b_x[7] * absx11 / b_x[4];
    xHatAp_tmp_0[p3] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
    xHatAp_tmp_0[p3 + 1] = absx21;
    xHatAp_tmp_0[p3 + 2] = absx11;
    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = 3 * p1 + p2;
        KalmanObserver_R2021b_B.H[p3] = 0.0;
        KalmanObserver_R2021b_B.H[p3] += xHatAp_tmp_0[3 * p1] * PAp[p2];
        KalmanObserver_R2021b_B.H[p3] += xHatAp_tmp_0[3 * p1 + 1] * PAp[p2 + 3];
        KalmanObserver_R2021b_B.H[p3] += xHatAp_tmp_0[3 * p1 + 2] * PAp[p2 + 6];
      }
    }

    if (KalmanObserver_R2021b_B.newCamDataArrived) {
      for (p3 = 0; p3 < 3; p3++) {
        KalmanObserver_R2021b_B.camDataAdj[p3] =
          KalmanObserver_R2021b_B.InCameraPose[p3] +
          KalmanObserver_R2021b_B.Sum2[p3];
        tmp[p3] = KalmanObserver_R2021b_B.camDataAdj[p3] - ((static_cast<real_T>
          (xHatAp_tmp[p3 + 3]) * KalmanObserver_R2021b_DW.xHatOld[1] +
          static_cast<real_T>(xHatAp_tmp[p3]) *
          KalmanObserver_R2021b_DW.xHatOld[0]) + static_cast<real_T>
          (xHatAp_tmp[p3 + 6]) * KalmanObserver_R2021b_DW.xHatOld[2]);
      }

      for (p1 = 0; p1 < 3; p1++) {
        absx11 = 0.0;
        for (p2 = 0; p2 < 3; p2++) {
          p3 = 3 * p2 + p1;
          absx11 += KalmanObserver_R2021b_B.H[p3] * tmp[p2];
          xHatAp_tmp_0[p3] = 0.0;
          xHatAp_tmp_0[p3] += static_cast<real_T>(xHatAp_tmp[3 * p2]) *
            KalmanObserver_R2021b_B.H[p1];
          xHatAp_tmp_0[p3] += static_cast<real_T>(xHatAp_tmp[3 * p2 + 1]) *
            KalmanObserver_R2021b_B.H[p1 + 3];
          xHatAp_tmp_0[p3] += static_cast<real_T>(xHatAp_tmp[3 * p2 + 2]) *
            KalmanObserver_R2021b_B.H[p1 + 6];
        }

        KalmanObserver_R2021b_B.xHat[p1] = xHatAp[p1] + absx11;
        for (p2 = 0; p2 < 3; p2++) {
          p3 = 3 * p2 + p1;
          KalmanObserver_R2021b_DW.P[p3] = PAp[p3] - ((PAp[3 * p2 + 1] *
            xHatAp_tmp_0[p1 + 3] + PAp[3 * p2] * xHatAp_tmp_0[p1]) + PAp[3 * p2
            + 2] * xHatAp_tmp_0[p1 + 6]);
        }
      }
    }

    KalmanObserver_R2021b_DW.xHatOld[0] = KalmanObserver_R2021b_B.xHat[0];
    KalmanObserver_R2021b_DW.xHatOld[1] = KalmanObserver_R2021b_B.xHat[1];
    KalmanObserver_R2021b_DW.xHatOld[2] = KalmanObserver_R2021b_B.xHat[2];
    std::memcpy(&KalmanObserver_R2021b_B.Pout[0], &KalmanObserver_R2021b_DW.P[0],
                9U * sizeof(real_T));

    /* MATLAB Function: '<S1>/PoseCalculation' */
    if (KalmanObserver_R2021b_B.newCamDataArrived) {
      KalmanObserver_R2021b_DW.estPoseOld[0] =
        KalmanObserver_R2021b_B.InCameraPose[0] + KalmanObserver_R2021b_B.Sum2[0];
      KalmanObserver_R2021b_DW.estPoseOld[1] =
        KalmanObserver_R2021b_B.InCameraPose[1] + KalmanObserver_R2021b_B.Sum2[1];
      KalmanObserver_R2021b_DW.estPoseOld[2] =
        KalmanObserver_R2021b_B.InCameraPose[2] + KalmanObserver_R2021b_B.Sum2[2];
      KalmanObserver_R2021b_B.debug = 1.0;
    } else {
      KalmanObserver_R2021b_DW.estPoseOld[0] += KalmanObserver_R2021b_B.Sum1[0];
      KalmanObserver_R2021b_DW.estPoseOld[1] += KalmanObserver_R2021b_B.Sum1[1];
      KalmanObserver_R2021b_DW.estPoseOld[2] += KalmanObserver_R2021b_B.Sum1[2];
      KalmanObserver_R2021b_B.debug = 2.0;
    }

    KalmanObserver_R2021b_B.estimatedX = KalmanObserver_R2021b_DW.estPoseOld[0];
    KalmanObserver_R2021b_B.estimatedY = KalmanObserver_R2021b_DW.estPoseOld[1];
    KalmanObserver_R2021b_B.estimatedTheta =
      KalmanObserver_R2021b_DW.estPoseOld[2];
    KalmanObserver_R2021b_B.estimatedPose[0] =
      KalmanObserver_R2021b_DW.estPoseOld[0];
    KalmanObserver_R2021b_B.estimatedPose[1] =
      KalmanObserver_R2021b_DW.estPoseOld[1];
    KalmanObserver_R2021b_B.estimatedPose[2] =
      KalmanObserver_R2021b_DW.estPoseOld[2];

    /* End of MATLAB Function: '<S1>/PoseCalculation' */
  }

  /* S-Function (TcModuleInOut): '<Root>/InVXworld' */
  if (KalmanObserver_R2021b_DW.InVXworld_PWORK != NULL) {
    KalmanObserver_R2021b_B.InVXworld = *((real_T*)
      KalmanObserver_R2021b_DW.InVXworld_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVYworld' */
  if (KalmanObserver_R2021b_DW.InVYworld_PWORK != NULL) {
    KalmanObserver_R2021b_B.InVYworld = *((real_T*)
      KalmanObserver_R2021b_DW.InVYworld_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/InVThetaworld' */
  if (KalmanObserver_R2021b_DW.InVThetaworld_PWORK != NULL) {
    KalmanObserver_R2021b_B.InVThetaworld = *((real_T*)
      KalmanObserver_R2021b_DW.InVThetaworld_PWORK);
  }

  /* SignalConversion generated from: '<S1>/Integrator' */
  KalmanObserver_R2021b_B.TmpSignalConversionAtIntegrator[0] =
    KalmanObserver_R2021b_B.InVXworld;
  KalmanObserver_R2021b_B.TmpSignalConversionAtIntegrator[1] =
    KalmanObserver_R2021b_B.InVYworld;
  KalmanObserver_R2021b_B.TmpSignalConversionAtIntegrator[2] =
    KalmanObserver_R2021b_B.InVThetaworld;
  if (rtmIsMajorTimeStep(KalmanObserver_R2021b_M)) {
    if (rtmIsMajorTimeStep(KalmanObserver_R2021b_M)) {
      /* Update for S-Function (TcModuleInOut): '<Root>/version' incorporates:
       *  Constant: '<Root>/Constant'
       */
      if (KalmanObserver_R2021b_DW.version_PWORK != NULL) {
        *((real_T*)KalmanObserver_R2021b_DW.version_PWORK) =
          KalmanObserver_R2021b_P.Constant_Value;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/DEBUG' */
      if (KalmanObserver_R2021b_DW.DEBUG_PWORK != NULL) {
        *((real_T*)KalmanObserver_R2021b_DW.DEBUG_PWORK) =
          KalmanObserver_R2021b_B.debug;
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/OutSimpleObsPose' */
      if (KalmanObserver_R2021b_DW.OutSimpleObsPose_PWORK != NULL) {
        memcpy(KalmanObserver_R2021b_DW.OutSimpleObsPose_PWORK,
               &KalmanObserver_R2021b_B.estimatedPose[0], 24);
      }

      /* Update for S-Function (TcModuleInOut): '<Root>/OutSimpleObsPose1' */
      if (KalmanObserver_R2021b_DW.OutSimpleObsPose1_PWORK != NULL) {
        memcpy(KalmanObserver_R2021b_DW.OutSimpleObsPose1_PWORK,
               &KalmanObserver_R2021b_B.xHat[0], 24);
      }

      /* Update for Delay: '<S1>/CameraDelay' */
      for (int_T idxDelay{0}; idxDelay < 13; idxDelay++) {
        int32_T CameraDelay_DSTATE_tmp;
        CameraDelay_DSTATE_tmp = (idxDelay + 1) * 3;
        KalmanObserver_R2021b_DW.CameraDelay_DSTATE[idxDelay * 3] =
          KalmanObserver_R2021b_DW.CameraDelay_DSTATE[CameraDelay_DSTATE_tmp];
        KalmanObserver_R2021b_DW.CameraDelay_DSTATE[idxDelay * 3 + 1] =
          KalmanObserver_R2021b_DW.CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 1];
        KalmanObserver_R2021b_DW.CameraDelay_DSTATE[idxDelay * 3 + 2] =
          KalmanObserver_R2021b_DW.CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 2];
      }

      KalmanObserver_R2021b_DW.CameraDelay_DSTATE[39] =
        KalmanObserver_R2021b_B.Odometry[0];

      /* Update for Delay: '<S1>/Delay One Step1' */
      KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[0] =
        KalmanObserver_R2021b_B.Odometry[0];

      /* Update for Delay: '<S1>/CameraDelay' */
      KalmanObserver_R2021b_DW.CameraDelay_DSTATE[40] =
        KalmanObserver_R2021b_B.Odometry[1];

      /* Update for Delay: '<S1>/Delay One Step1' */
      KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[1] =
        KalmanObserver_R2021b_B.Odometry[1];

      /* Update for Delay: '<S1>/CameraDelay' */
      KalmanObserver_R2021b_DW.CameraDelay_DSTATE[41] =
        KalmanObserver_R2021b_B.Odometry[2];

      /* Update for Delay: '<S1>/Delay One Step1' */
      KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[2] =
        KalmanObserver_R2021b_B.Odometry[2];
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(KalmanObserver_R2021b_M)) {
    rt_ertODEUpdateContinuousStates(&KalmanObserver_R2021b_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++KalmanObserver_R2021b_M->Timing.clockTick0)) {
      ++KalmanObserver_R2021b_M->Timing.clockTickH0;
    }

    KalmanObserver_R2021b_M->Timing.t[0] = rtsiGetSolverStopTime
      (&KalmanObserver_R2021b_M->solverInfo);

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
      KalmanObserver_R2021b_M->Timing.clockTick1++;
      if (!KalmanObserver_R2021b_M->Timing.clockTick1) {
        KalmanObserver_R2021b_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void KalmanObserver_R2021b_derivatives(void)
{
  XDot_KalmanObserver_R2021b_T *_rtXdot;
  _rtXdot = ((XDot_KalmanObserver_R2021b_T *) KalmanObserver_R2021b_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] =
    KalmanObserver_R2021b_B.TmpSignalConversionAtIntegrator[0];
  _rtXdot->Integrator_CSTATE[1] =
    KalmanObserver_R2021b_B.TmpSignalConversionAtIntegrator[1];
  _rtXdot->Integrator_CSTATE[2] =
    KalmanObserver_R2021b_B.TmpSignalConversionAtIntegrator[2];
}

/* Model initialize function */
void KalmanObserver_R2021b_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&KalmanObserver_R2021b_M->solverInfo,
                          &KalmanObserver_R2021b_M->Timing.simTimeStep);
    rtsiSetTPtr(&KalmanObserver_R2021b_M->solverInfo, &rtmGetTPtr
                (KalmanObserver_R2021b_M));
    rtsiSetStepSizePtr(&KalmanObserver_R2021b_M->solverInfo,
                       &KalmanObserver_R2021b_M->Timing.stepSize0);
    rtsiSetdXPtr(&KalmanObserver_R2021b_M->solverInfo,
                 &KalmanObserver_R2021b_M->derivs);
    rtsiSetContStatesPtr(&KalmanObserver_R2021b_M->solverInfo, (real_T **)
                         &KalmanObserver_R2021b_M->contStates);
    rtsiSetNumContStatesPtr(&KalmanObserver_R2021b_M->solverInfo,
      &KalmanObserver_R2021b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&KalmanObserver_R2021b_M->solverInfo,
      &KalmanObserver_R2021b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&KalmanObserver_R2021b_M->solverInfo,
      &KalmanObserver_R2021b_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&KalmanObserver_R2021b_M->solverInfo,
      &KalmanObserver_R2021b_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&KalmanObserver_R2021b_M->solverInfo,
                          (&rtmGetErrorStatus(KalmanObserver_R2021b_M)));
    rtsiSetRTModelPtr(&KalmanObserver_R2021b_M->solverInfo,
                      KalmanObserver_R2021b_M);
  }

  rtsiSetSimTimeStep(&KalmanObserver_R2021b_M->solverInfo, MAJOR_TIME_STEP);
  KalmanObserver_R2021b_M->intgData.f[0] = KalmanObserver_R2021b_M->odeF[0];
  KalmanObserver_R2021b_M->contStates = ((X_KalmanObserver_R2021b_T *)
    &KalmanObserver_R2021b_X);
  rtsiSetSolverData(&KalmanObserver_R2021b_M->solverInfo, static_cast<void *>
                    (&KalmanObserver_R2021b_M->intgData));
  rtsiSetSolverName(&KalmanObserver_R2021b_M->solverInfo,"ode1");
  rtmSetTPtr(KalmanObserver_R2021b_M, &KalmanObserver_R2021b_M->Timing.tArray[0]);
  KalmanObserver_R2021b_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&KalmanObserver_R2021b_B)), 0,
                     sizeof(B_KalmanObserver_R2021b_T));

  /* states (continuous) */
  {
    (void) std::memset(static_cast<void *>(&KalmanObserver_R2021b_X), 0,
                       sizeof(X_KalmanObserver_R2021b_T));
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&KalmanObserver_R2021b_DW), 0,
                     sizeof(DW_KalmanObserver_R2021b_T));

  /* InitializeConditions for Delay: '<S1>/CameraDelay' */
  for (int32_T i{0}; i < 42; i++) {
    KalmanObserver_R2021b_DW.CameraDelay_DSTATE[i] =
      KalmanObserver_R2021b_P.CameraDelay_InitialCondition;
  }

  /* End of InitializeConditions for Delay: '<S1>/CameraDelay' */

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[0] =
    KalmanObserver_R2021b_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  KalmanObserver_R2021b_X.Integrator_CSTATE[0] =
    KalmanObserver_R2021b_P.Integrator_IC;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  KalmanObserver_R2021b_DW.oldCamData[0] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  KalmanObserver_R2021b_DW.xHatOld[0] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[1] =
    KalmanObserver_R2021b_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  KalmanObserver_R2021b_X.Integrator_CSTATE[1] =
    KalmanObserver_R2021b_P.Integrator_IC;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  KalmanObserver_R2021b_DW.oldCamData[1] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  KalmanObserver_R2021b_DW.xHatOld[1] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  KalmanObserver_R2021b_DW.DelayOneStep1_DSTATE[2] =
    KalmanObserver_R2021b_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  KalmanObserver_R2021b_X.Integrator_CSTATE[2] =
    KalmanObserver_R2021b_P.Integrator_IC;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  KalmanObserver_R2021b_DW.oldCamData[2] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  KalmanObserver_R2021b_DW.xHatOld[2] = 0.0;
  std::memset(&KalmanObserver_R2021b_DW.P[0], 0, 9U * sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S1>/PoseCalculation' */
  KalmanObserver_R2021b_DW.estPoseOld[0] = 0.0;
  KalmanObserver_R2021b_DW.estPoseOld[1] = 0.0;
  KalmanObserver_R2021b_DW.estPoseOld[2] = 0.0;
}

/* Model terminate function */
void KalmanObserver_R2021b_terminate(void)
{
  /* (no terminate code required) */
}
