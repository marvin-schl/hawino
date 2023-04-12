/*
 * simpleObserver2withKalman.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simpleObserver2withKalman".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Mar 30 11:34:38 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simpleObserver2withKalman.h"
#include "simpleObserver2withKalman_private.h"

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si ,
  RT_MODEL_simpleObserver2withK_T *const simpleObserver2withKalman_M)
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
  simpleObserver2withKalman_derivatives(simpleObserver2withKalman_M);
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void simpleObserver2withKalman_step(RT_MODEL_simpleObserver2withK_T *const
  simpleObserver2withKalman_M)
{
  B_simpleObserver2withKalman_T *simpleObserver2withKalman_B{
    simpleObserver2withKalman_M->blockIO };

  DW_simpleObserver2withKalman_T *simpleObserver2withKalman_DW{
    simpleObserver2withKalman_M->dwork };

  X_simpleObserver2withKalman_T *simpleObserver2withKalman_X{
    simpleObserver2withKalman_M->contStates };

  PrevZCX_simpleObserver2withKa_T *simpleObserver2withKalm_PrevZCX{
    simpleObserver2withKalman_M->prevZCSigState };

  if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
    /* set solver stop time */
    if (!(simpleObserver2withKalman_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(simpleObserver2withKalman_M->solverInfo,
                            ((simpleObserver2withKalman_M->Timing.clockTickH0 +
        1) * simpleObserver2withKalman_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(simpleObserver2withKalman_M->solverInfo,
                            ((simpleObserver2withKalman_M->Timing.clockTick0 + 1)
        * simpleObserver2withKalman_M->Timing.stepSize0 +
        simpleObserver2withKalman_M->Timing.clockTickH0 *
        simpleObserver2withKalman_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(simpleObserver2withKalman_M)) {
    simpleObserver2withKalman_M->Timing.t[0] = rtsiGetT
      (simpleObserver2withKalman_M->solverInfo);
  }

  {
    static const real_T b[9]{ 9.3047, 0.4415, -0.0036, 0.4415, 26.0708, -0.0078,
      -0.0036, -0.0078, 0.0007 };

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
    int32_T init;
    int32_T p1;
    int8_T xHatAp_tmp[9];
    boolean_T y;
    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
    }

    /* S-Function (TcModuleInOut): '<Root>/InCameraPose' */
    if (simpleObserver2withKalman_DW->InCameraPose_PWORK != NULL) {
      memcpy(&simpleObserver2withKalman_B->InCameraPose[0],
             simpleObserver2withKalman_DW->InCameraPose_PWORK, 24);
    }

    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
      boolean_T exitg1;
      boolean_T guard1{ false };

      /* MATLAB Function: '<S1>/CamFlag' */
      y = true;
      init = 0;
      exitg1 = false;
      while ((!exitg1) && (init < 2)) {
        if (simpleObserver2withKalman_B->InCameraPose[init] == 0.0) {
          y = false;
          exitg1 = true;
        } else {
          init++;
        }
      }

      guard1 = false;
      if (y) {
        init = 0;
        exitg1 = false;
        while ((!exitg1) && (init < 3)) {
          if (!(simpleObserver2withKalman_B->InCameraPose[init] !=
                simpleObserver2withKalman_DW->oldCamData[init])) {
            y = false;
            exitg1 = true;
          } else {
            init++;
          }
        }

        if (y) {
          simpleObserver2withKalman_B->newCamDataArrived = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        simpleObserver2withKalman_B->newCamDataArrived = false;
        simpleObserver2withKalman_DW->oldCamData[0] =
          simpleObserver2withKalman_B->InCameraPose[0];
        simpleObserver2withKalman_DW->oldCamData[1] =
          simpleObserver2withKalman_B->InCameraPose[1];
        simpleObserver2withKalman_DW->oldCamData[2] =
          simpleObserver2withKalman_B->InCameraPose[2];
      }

      /* End of MATLAB Function: '<S1>/CamFlag' */
    }

    /* S-Function (TcModuleInOut): '<S1>/Reset' */
    if (simpleObserver2withKalman_DW->Reset_PWORK != NULL) {
      simpleObserver2withKalman_B->Reset = *((boolean_T*)
        simpleObserver2withKalman_DW->Reset_PWORK);
    }

    /* Integrator: '<S1>/Integrator' */
    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
      y = (simpleObserver2withKalman_B->Reset &&
           (simpleObserver2withKalm_PrevZCX->Integrator_Reset_ZCE != POS_ZCSIG));
      simpleObserver2withKalm_PrevZCX->Integrator_Reset_ZCE =
        simpleObserver2withKalman_B->Reset;

      /* evaluate zero-crossings */
      if (y || (simpleObserver2withKalman_DW->Integrator_IWORK != 0)) {
        simpleObserver2withKalman_X->Integrator_CSTATE[0] =
          simpleObserver2withKalman_B->InCameraPose[0];
        simpleObserver2withKalman_X->Integrator_CSTATE[1] =
          simpleObserver2withKalman_B->InCameraPose[1];
        simpleObserver2withKalman_X->Integrator_CSTATE[2] =
          simpleObserver2withKalman_B->InCameraPose[2];
      }
    }

    /* Integrator: '<S1>/Integrator' */
    simpleObserver2withKalman_B->Odometry[0] =
      simpleObserver2withKalman_X->Integrator_CSTATE[0];
    simpleObserver2withKalman_B->Odometry[1] =
      simpleObserver2withKalman_X->Integrator_CSTATE[1];
    simpleObserver2withKalman_B->Odometry[2] =
      simpleObserver2withKalman_X->Integrator_CSTATE[2];

    /* S-Function (TcModuleInOut): '<S1>/cameraDelayCylces' */
    if (simpleObserver2withKalman_DW->cameraDelayCylces_PWORK != NULL) {
      simpleObserver2withKalman_B->cameraDelayCylces = *((int8_T*)
        simpleObserver2withKalman_DW->cameraDelayCylces_PWORK);
    }

    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
      /* Delay: '<S1>/CameraDelay' */
      if (simpleObserver2withKalman_B->cameraDelayCylces <= 0) {
        /* Delay: '<S1>/CameraDelay' incorporates:
         *  Integrator: '<S1>/Integrator'
         */
        simpleObserver2withKalman_B->CameraDelay[0] =
          simpleObserver2withKalman_B->Odometry[0];
        simpleObserver2withKalman_B->CameraDelay[1] =
          simpleObserver2withKalman_B->Odometry[1];
        simpleObserver2withKalman_B->CameraDelay[2] =
          simpleObserver2withKalman_B->Odometry[2];
      } else {
        int8_T tmp_1;
        if (simpleObserver2withKalman_B->cameraDelayCylces > 100) {
          tmp_1 = 100;
        } else {
          tmp_1 = simpleObserver2withKalman_B->cameraDelayCylces;
        }

        init = static_cast<int8_T>(100 - tmp_1) * 3;

        /* Delay: '<S1>/CameraDelay' */
        simpleObserver2withKalman_B->CameraDelay[0] =
          simpleObserver2withKalman_DW->CameraDelay_DSTATE[init];
        simpleObserver2withKalman_B->CameraDelay[1] =
          simpleObserver2withKalman_DW->CameraDelay_DSTATE[init + 1];
        simpleObserver2withKalman_B->CameraDelay[2] =
          simpleObserver2withKalman_DW->CameraDelay_DSTATE[init + 2];
      }

      /* End of Delay: '<S1>/CameraDelay' */
    }

    /* S-Function (TcModuleInOut): '<Root>/InVXworld' */
    if (simpleObserver2withKalman_DW->InVXworld_PWORK != NULL) {
      simpleObserver2withKalman_B->InVXworld = *((real_T*)
        simpleObserver2withKalman_DW->InVXworld_PWORK);
    }

    /* S-Function (TcModuleInOut): '<Root>/InVYworld' */
    if (simpleObserver2withKalman_DW->InVYworld_PWORK != NULL) {
      simpleObserver2withKalman_B->InVYworld = *((real_T*)
        simpleObserver2withKalman_DW->InVYworld_PWORK);
    }

    /* S-Function (TcModuleInOut): '<Root>/InVThetaworld' */
    if (simpleObserver2withKalman_DW->InVThetaworld_PWORK != NULL) {
      simpleObserver2withKalman_B->InVThetaworld = *((real_T*)
        simpleObserver2withKalman_DW->InVThetaworld_PWORK);
    }

    /* Sum: '<S1>/Subtract' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    simpleObserver2withKalman_B->Subtract = static_cast<real_T>
      (simpleObserver2withKalman_B->cameraDelayCylces) - 1.0;
    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
      real_T absx11;
      real_T absx21;
      real_T absx31;
      int32_T p2;
      int32_T p3;

      /* Memory: '<S1>/Memory' */
      simpleObserver2withKalman_B->Memory[0] =
        simpleObserver2withKalman_DW->Memory_PreviousInput[0];
      simpleObserver2withKalman_B->Memory[1] =
        simpleObserver2withKalman_DW->Memory_PreviousInput[1];
      simpleObserver2withKalman_B->Memory[2] =
        simpleObserver2withKalman_DW->Memory_PreviousInput[2];

      /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
       *  MATLAB Function: '<S1>/MATLAB Function'
       */
      simpleObserver2withKalman_B->TmpSignalConversionAtSFunctionI[0] =
        simpleObserver2withKalman_B->InVXworld;
      simpleObserver2withKalman_B->TmpSignalConversionAtSFunctionI[1] =
        simpleObserver2withKalman_B->InVYworld;
      simpleObserver2withKalman_B->TmpSignalConversionAtSFunctionI[2] =
        simpleObserver2withKalman_B->InVThetaworld;

      /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
       *  Memory: '<S1>/Memory'
       */
      if (!simpleObserver2withKalman_DW->init_not_empty) {
        init = 1;
        simpleObserver2withKalman_DW->init_not_empty = true;
      } else {
        init = 0;
      }

      for (p1 = 0; p1 < 9; p1++) {
        xHatAp_tmp[p1] = a[p1];
      }

      for (p1 = 0; p1 < 3; p1++) {
        absx11 = 0.0;
        for (p2 = 0; p2 < 3; p2++) {
          p3 = 3 * p2 + p1;
          absx11 += static_cast<real_T>(xHatAp_tmp[p3]) *
            simpleObserver2withKalman_DW->xHatOld[p2];
          xHatAp_tmp_0[p3] = 0.0;
          xHatAp_tmp_0[p3] += simpleObserver2withKalman_DW->P[3 * p2] *
            static_cast<real_T>(xHatAp_tmp[p1]);
          xHatAp_tmp_0[p3] += simpleObserver2withKalman_DW->P[3 * p2 + 1] *
            static_cast<real_T>(xHatAp_tmp[p1 + 3]);
          xHatAp_tmp_0[p3] += simpleObserver2withKalman_DW->P[3 * p2 + 2] *
            static_cast<real_T>(xHatAp_tmp[p1 + 6]);
        }

        xHatAp[p1] = 0.01 *
          simpleObserver2withKalman_B->TmpSignalConversionAtSFunctionI[p1] +
          absx11;
        for (p2 = 0; p2 < 3; p2++) {
          p3 = 3 * p2 + p1;
          PAp[p3] = ((static_cast<real_T>(xHatAp_tmp[3 * p2 + 1]) *
                      xHatAp_tmp_0[p1 + 3] + static_cast<real_T>(xHatAp_tmp[3 *
            p2]) * xHatAp_tmp_0[p1]) + static_cast<real_T>(xHatAp_tmp[3 * p2 + 2])
                     * xHatAp_tmp_0[p1 + 6]) + b[p3];
        }
      }

      simpleObserver2withKalman_DW->xHatOld[0] = xHatAp[0];
      simpleObserver2withKalman_DW->xHatOld[1] = xHatAp[1];
      simpleObserver2withKalman_DW->xHatOld[2] = xHatAp[2];
      for (p1 = 0; p1 < 9; p1++) {
        absx11 = PAp[p1];
        simpleObserver2withKalman_DW->P[p1] = absx11;
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
          simpleObserver2withKalman_B->H[p3] = 0.0;
          simpleObserver2withKalman_B->H[p3] += xHatAp_tmp_0[3 * p1] * PAp[p2];
          simpleObserver2withKalman_B->H[p3] += xHatAp_tmp_0[3 * p1 + 1] *
            PAp[p2 + 3];
          simpleObserver2withKalman_B->H[p3] += xHatAp_tmp_0[3 * p1 + 2] *
            PAp[p2 + 6];
        }
      }

      if (simpleObserver2withKalman_B->newCamDataArrived) {
        for (p1 = 0; p1 < 3; p1++) {
          tmp[p1] = simpleObserver2withKalman_B->InCameraPose[p1] - ((
            static_cast<real_T>(xHatAp_tmp[p1 + 3]) *
            simpleObserver2withKalman_B->Memory[1] + static_cast<real_T>
            (xHatAp_tmp[p1]) * simpleObserver2withKalman_B->Memory[0]) +
            static_cast<real_T>(xHatAp_tmp[p1 + 6]) *
            simpleObserver2withKalman_B->Memory[2]);
        }

        for (p1 = 0; p1 < 3; p1++) {
          absx11 = 0.0;
          for (p2 = 0; p2 < 3; p2++) {
            p3 = 3 * p2 + p1;
            absx11 += simpleObserver2withKalman_B->H[p3] * tmp[p2];
            xHatAp_tmp_0[p3] = 0.0;
            xHatAp_tmp_0[p3] += static_cast<real_T>(xHatAp_tmp[3 * p2]) *
              simpleObserver2withKalman_B->H[p1];
            xHatAp_tmp_0[p3] += static_cast<real_T>(xHatAp_tmp[3 * p2 + 1]) *
              simpleObserver2withKalman_B->H[p1 + 3];
            xHatAp_tmp_0[p3] += static_cast<real_T>(xHatAp_tmp[3 * p2 + 2]) *
              simpleObserver2withKalman_B->H[p1 + 6];
          }

          simpleObserver2withKalman_DW->xHatOld[p1] = xHatAp[p1] + absx11;
          simpleObserver2withKalman_DW->xHatOld[p1] +=
            simpleObserver2withKalman_DW->xHatOld[p1] -
            simpleObserver2withKalman_B->Memory[p1];
          for (p2 = 0; p2 < 3; p2++) {
            p3 = 3 * p2 + p1;
            simpleObserver2withKalman_DW->P[p3] = PAp[p3] - ((PAp[3 * p2 + 1] *
              xHatAp_tmp_0[p1 + 3] + PAp[3 * p2] * xHatAp_tmp_0[p1]) + PAp[3 *
              p2 + 2] * xHatAp_tmp_0[p1 + 6]);
          }
        }
      }

      std::memcpy(&simpleObserver2withKalman_B->Pout[0],
                  &simpleObserver2withKalman_DW->P[0], 9U * sizeof(real_T));
      simpleObserver2withKalman_B->initOut = init;
      simpleObserver2withKalman_B->xHat[0] =
        simpleObserver2withKalman_DW->xHatOld[0];
      simpleObserver2withKalman_B->xHat[1] =
        simpleObserver2withKalman_DW->xHatOld[1];
      simpleObserver2withKalman_B->xHat[2] =
        simpleObserver2withKalman_DW->xHatOld[2];

      /* Delay: '<S1>/CameraDelay1' */
      if ((simpleObserver2withKalman_B->Subtract < 1.0) || std::isnan
          (simpleObserver2withKalman_B->Subtract)) {
        /* Delay: '<S1>/CameraDelay1' */
        simpleObserver2withKalman_B->CameraDelay1[0] =
          simpleObserver2withKalman_B->xHat[0];
        simpleObserver2withKalman_B->CameraDelay1[1] =
          simpleObserver2withKalman_B->xHat[1];
        simpleObserver2withKalman_B->CameraDelay1[2] =
          simpleObserver2withKalman_B->xHat[2];
      } else {
        uint32_T tmp_0;
        if (simpleObserver2withKalman_B->Subtract > 100.0) {
          tmp_0 = 100U;
        } else {
          absx11 = std::trunc(simpleObserver2withKalman_B->Subtract);
          if (std::isnan(absx11) || std::isinf(absx11)) {
            absx11 = 0.0;
          } else {
            absx11 = std::fmod(absx11, 4.294967296E+9);
          }

          tmp_0 = absx11 < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(
            static_cast<uint32_T>(-absx11))) : static_cast<uint32_T>(absx11);
        }

        init = static_cast<int32_T>(100U - tmp_0) * 3;

        /* Delay: '<S1>/CameraDelay1' */
        simpleObserver2withKalman_B->CameraDelay1[0] =
          simpleObserver2withKalman_DW->CameraDelay1_DSTATE[init];
        simpleObserver2withKalman_B->CameraDelay1[1] =
          simpleObserver2withKalman_DW->CameraDelay1_DSTATE[init + 1];
        simpleObserver2withKalman_B->CameraDelay1[2] =
          simpleObserver2withKalman_DW->CameraDelay1_DSTATE[init + 2];
      }

      /* End of Delay: '<S1>/CameraDelay1' */
    }

    /* S-Function (TcModuleInOut): '<S1>/K' */
    if (simpleObserver2withKalman_DW->K_PWORK != NULL) {
      memcpy(&simpleObserver2withKalman_B->K[0],
             simpleObserver2withKalman_DW->K_PWORK, 72);
    }

    /* S-Function (TcModuleInOut): '<S1>/UseSimpleNotKalman' */
    if (simpleObserver2withKalman_DW->UseSimpleNotKalman_PWORK != NULL) {
      simpleObserver2withKalman_B->UseSimpleNotKalman = *((real_T*)
        simpleObserver2withKalman_DW->UseSimpleNotKalman_PWORK);
    }

    /* Switch: '<S1>/Switch' */
    if (simpleObserver2withKalman_B->newCamDataArrived) {
      /* Switch: '<S1>/SwitchObserver' */
      if (simpleObserver2withKalman_B->UseSimpleNotKalman != 0.0) {
        /* Switch: '<S1>/SwitchObserver' incorporates:
         *  Delay: '<S1>/CameraDelay'
         */
        simpleObserver2withKalman_B->SwitchObserver[0] =
          simpleObserver2withKalman_B->CameraDelay[0];
      } else {
        /* Switch: '<S1>/SwitchObserver' incorporates:
         *  Delay: '<S1>/CameraDelay1'
         */
        simpleObserver2withKalman_B->SwitchObserver[0] =
          simpleObserver2withKalman_B->CameraDelay1[0];
      }

      /* Sum: '<S1>/Sum1' incorporates:
       *  Switch: '<S1>/SwitchObserver'
       */
      simpleObserver2withKalman_B->Sum1[0] =
        simpleObserver2withKalman_B->InCameraPose[0] -
        simpleObserver2withKalman_B->SwitchObserver[0];

      /* Switch: '<S1>/Switch' incorporates:
       *  Sum: '<S1>/Sum1'
       */
      simpleObserver2withKalman_B->Switch[0] = simpleObserver2withKalman_B->
        Sum1[0];

      /* Switch: '<S1>/SwitchObserver' */
      if (simpleObserver2withKalman_B->UseSimpleNotKalman != 0.0) {
        /* Switch: '<S1>/SwitchObserver' incorporates:
         *  Delay: '<S1>/CameraDelay'
         */
        simpleObserver2withKalman_B->SwitchObserver[1] =
          simpleObserver2withKalman_B->CameraDelay[1];
      } else {
        /* Switch: '<S1>/SwitchObserver' incorporates:
         *  Delay: '<S1>/CameraDelay1'
         */
        simpleObserver2withKalman_B->SwitchObserver[1] =
          simpleObserver2withKalman_B->CameraDelay1[1];
      }

      /* Sum: '<S1>/Sum1' incorporates:
       *  Switch: '<S1>/SwitchObserver'
       */
      simpleObserver2withKalman_B->Sum1[1] =
        simpleObserver2withKalman_B->InCameraPose[1] -
        simpleObserver2withKalman_B->SwitchObserver[1];

      /* Switch: '<S1>/Switch' incorporates:
       *  Sum: '<S1>/Sum1'
       */
      simpleObserver2withKalman_B->Switch[1] = simpleObserver2withKalman_B->
        Sum1[1];

      /* Switch: '<S1>/SwitchObserver' */
      if (simpleObserver2withKalman_B->UseSimpleNotKalman != 0.0) {
        /* Switch: '<S1>/SwitchObserver' incorporates:
         *  Delay: '<S1>/CameraDelay'
         */
        simpleObserver2withKalman_B->SwitchObserver[2] =
          simpleObserver2withKalman_B->CameraDelay[2];
      } else {
        /* Switch: '<S1>/SwitchObserver' incorporates:
         *  Delay: '<S1>/CameraDelay1'
         */
        simpleObserver2withKalman_B->SwitchObserver[2] =
          simpleObserver2withKalman_B->CameraDelay1[2];
      }

      /* Sum: '<S1>/Sum1' incorporates:
       *  Switch: '<S1>/SwitchObserver'
       */
      simpleObserver2withKalman_B->Sum1[2] =
        simpleObserver2withKalman_B->InCameraPose[2] -
        simpleObserver2withKalman_B->SwitchObserver[2];

      /* Switch: '<S1>/Switch' incorporates:
       *  Sum: '<S1>/Sum1'
       */
      simpleObserver2withKalman_B->Switch[2] = simpleObserver2withKalman_B->
        Sum1[2];
    } else {
      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/Constant'
       */
      simpleObserver2withKalman_B->Switch[0] = 0.0;
      simpleObserver2withKalman_B->Switch[1] = 0.0;
      simpleObserver2withKalman_B->Switch[2] = 0.0;
    }

    /* End of Switch: '<S1>/Switch' */
    for (p1 = 0; p1 < 3; p1++) {
      /* Product: '<S1>/Product1' incorporates:
       *  S-Function (TcModuleInOut): '<S1>/K'
       *  Switch: '<S1>/Switch'
       */
      simpleObserver2withKalman_B->Product1[p1] = 0.0;
      simpleObserver2withKalman_B->Product1[p1] +=
        simpleObserver2withKalman_B->K[p1] * simpleObserver2withKalman_B->
        Switch[0];
      simpleObserver2withKalman_B->Product1[p1] +=
        simpleObserver2withKalman_B->K[p1 + 3] *
        simpleObserver2withKalman_B->Switch[1];
      simpleObserver2withKalman_B->Product1[p1] +=
        simpleObserver2withKalman_B->K[p1 + 6] *
        simpleObserver2withKalman_B->Switch[2];
    }

    /* Sum: '<S1>/Sum' incorporates:
     *  Product: '<S1>/Product1'
     */
    simpleObserver2withKalman_B->Sum[0] = simpleObserver2withKalman_B->Product1
      [0] + simpleObserver2withKalman_B->InVXworld;
    simpleObserver2withKalman_B->Sum[1] = simpleObserver2withKalman_B->Product1
      [1] + simpleObserver2withKalman_B->InVYworld;
    simpleObserver2withKalman_B->Sum[2] = simpleObserver2withKalman_B->Product1
      [2] + simpleObserver2withKalman_B->InVThetaworld;
  }

  if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
    int_T idxDelay;
    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
      /* Update for S-Function (TcModuleInOut): '<Root>/version' incorporates:
       *  Constant: '<Root>/Constant'
       */
      if (simpleObserver2withKalman_DW->version_PWORK != NULL) {
        *((real_T*)simpleObserver2withKalman_DW->version_PWORK) = 0.8;
      }
    }

    /* Update for S-Function (TcModuleInOut): '<Root>/OutEstimatedPose' */
    if (simpleObserver2withKalman_DW->OutEstimatedPose_PWORK != NULL) {
      memcpy(simpleObserver2withKalman_DW->OutEstimatedPose_PWORK,
             &simpleObserver2withKalman_B->Odometry[0], 24);
    }

    /* Update for Integrator: '<S1>/Integrator' */
    simpleObserver2withKalman_DW->Integrator_IWORK = 0;
    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
      /* Update for Delay: '<S1>/CameraDelay' incorporates:
       *  Integrator: '<S1>/Integrator'
       */
      for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        int32_T CameraDelay_DSTATE_tmp;
        CameraDelay_DSTATE_tmp = (idxDelay + 1) * 3;
        simpleObserver2withKalman_DW->CameraDelay_DSTATE[idxDelay * 3] =
          simpleObserver2withKalman_DW->
          CameraDelay_DSTATE[CameraDelay_DSTATE_tmp];
        simpleObserver2withKalman_DW->CameraDelay_DSTATE[idxDelay * 3 + 1] =
          simpleObserver2withKalman_DW->
          CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 1];
        simpleObserver2withKalman_DW->CameraDelay_DSTATE[idxDelay * 3 + 2] =
          simpleObserver2withKalman_DW->
          CameraDelay_DSTATE[CameraDelay_DSTATE_tmp + 2];
      }

      simpleObserver2withKalman_DW->CameraDelay_DSTATE[297] =
        simpleObserver2withKalman_B->Odometry[0];
      simpleObserver2withKalman_DW->CameraDelay_DSTATE[298] =
        simpleObserver2withKalman_B->Odometry[1];
      simpleObserver2withKalman_DW->CameraDelay_DSTATE[299] =
        simpleObserver2withKalman_B->Odometry[2];

      /* End of Update for Delay: '<S1>/CameraDelay' */
    }

    if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
      /* Update for Memory: '<S1>/Memory' incorporates:
       *  Delay: '<S1>/CameraDelay1'
       */
      simpleObserver2withKalman_DW->Memory_PreviousInput[0] =
        simpleObserver2withKalman_B->CameraDelay1[0];
      simpleObserver2withKalman_DW->Memory_PreviousInput[1] =
        simpleObserver2withKalman_B->CameraDelay1[1];
      simpleObserver2withKalman_DW->Memory_PreviousInput[2] =
        simpleObserver2withKalman_B->CameraDelay1[2];

      /* Update for Delay: '<S1>/CameraDelay1' */
      for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        simpleObserver2withKalman_DW->CameraDelay1_DSTATE[idxDelay * 3] =
          simpleObserver2withKalman_DW->CameraDelay1_DSTATE[(idxDelay + 1) * 3];
        simpleObserver2withKalman_DW->CameraDelay1_DSTATE[idxDelay * 3 + 1] =
          simpleObserver2withKalman_DW->CameraDelay1_DSTATE[(idxDelay + 1) * 3 +
          1];
        simpleObserver2withKalman_DW->CameraDelay1_DSTATE[idxDelay * 3 + 2] =
          simpleObserver2withKalman_DW->CameraDelay1_DSTATE[(idxDelay + 1) * 3 +
          2];
      }

      simpleObserver2withKalman_DW->CameraDelay1_DSTATE[297] =
        simpleObserver2withKalman_B->xHat[0];
      simpleObserver2withKalman_DW->CameraDelay1_DSTATE[298] =
        simpleObserver2withKalman_B->xHat[1];
      simpleObserver2withKalman_DW->CameraDelay1_DSTATE[299] =
        simpleObserver2withKalman_B->xHat[2];

      /* End of Update for Delay: '<S1>/CameraDelay1' */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(simpleObserver2withKalman_M)) {
    rt_ertODEUpdateContinuousStates(simpleObserver2withKalman_M->solverInfo,
      simpleObserver2withKalman_M);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++simpleObserver2withKalman_M->Timing.clockTick0)) {
      ++simpleObserver2withKalman_M->Timing.clockTickH0;
    }

    simpleObserver2withKalman_M->Timing.t[0] = rtsiGetSolverStopTime
      (simpleObserver2withKalman_M->solverInfo);

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
      simpleObserver2withKalman_M->Timing.clockTick1++;
      if (!simpleObserver2withKalman_M->Timing.clockTick1) {
        simpleObserver2withKalman_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void simpleObserver2withKalman_derivatives(RT_MODEL_simpleObserver2withK_T *
  const simpleObserver2withKalman_M)
{
  B_simpleObserver2withKalman_T *simpleObserver2withKalman_B{
    simpleObserver2withKalman_M->blockIO };

  XDot_simpleObserver2withKalma_T *_rtXdot;
  _rtXdot = ((XDot_simpleObserver2withKalma_T *)
             simpleObserver2withKalman_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' incorporates:
   *  Sum: '<S1>/Sum'
   */
  _rtXdot->Integrator_CSTATE[0] = simpleObserver2withKalman_B->Sum[0];
  _rtXdot->Integrator_CSTATE[1] = simpleObserver2withKalman_B->Sum[1];
  _rtXdot->Integrator_CSTATE[2] = simpleObserver2withKalman_B->Sum[2];
}

/* Model initialize function */
void simpleObserver2withKalman_initialize(RT_MODEL_simpleObserver2withK_T *const
  simpleObserver2withKalman_M)
{
  DW_simpleObserver2withKalman_T *simpleObserver2withKalman_DW{
    simpleObserver2withKalman_M->dwork };

  X_simpleObserver2withKalman_T *simpleObserver2withKalman_X{
    simpleObserver2withKalman_M->contStates };

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  if (rtmIsFirstInitCond(simpleObserver2withKalman_M)) {
    simpleObserver2withKalman_X->Integrator_CSTATE[0] = 0.0;
    simpleObserver2withKalman_X->Integrator_CSTATE[1] = 0.0;
    simpleObserver2withKalman_X->Integrator_CSTATE[2] = 0.0;
  }

  simpleObserver2withKalman_DW->Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S1>/Integrator' */

  /* InitializeConditions for Memory: '<S1>/Memory' */
  simpleObserver2withKalman_DW->Memory_PreviousInput[0] = 0.0;
  simpleObserver2withKalman_DW->Memory_PreviousInput[1] = 0.0;
  simpleObserver2withKalman_DW->Memory_PreviousInput[2] = 0.0;

  /* InitializeConditions for Delay: '<S1>/CameraDelay' */
  std::memset(&simpleObserver2withKalman_DW->CameraDelay_DSTATE[0], 0, 300U *
              sizeof(real_T));

  /* InitializeConditions for Delay: '<S1>/CameraDelay1' */
  std::memset(&simpleObserver2withKalman_DW->CameraDelay1_DSTATE[0], 0, 300U *
              sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  simpleObserver2withKalman_DW->init_not_empty = false;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  simpleObserver2withKalman_DW->oldCamData[0] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  simpleObserver2withKalman_DW->xHatOld[0] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  simpleObserver2withKalman_DW->oldCamData[1] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  simpleObserver2withKalman_DW->xHatOld[1] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/CamFlag' */
  simpleObserver2withKalman_DW->oldCamData[2] = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  simpleObserver2withKalman_DW->xHatOld[2] = 0.0;
  std::memset(&simpleObserver2withKalman_DW->P[0], 0, 9U * sizeof(real_T));

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(simpleObserver2withKalman_M)) {
    rtmSetFirstInitCond(simpleObserver2withKalman_M, 0);
  }
}

/* Model terminate function */
void simpleObserver2withKalman_terminate(RT_MODEL_simpleObserver2withK_T
  * simpleObserver2withKalman_M)
{
  rt_FREE(simpleObserver2withKalman_M->solverInfo);

  /* model code */
  rt_FREE(simpleObserver2withKalman_M->blockIO);
  rt_FREE(simpleObserver2withKalman_M->contStates);
  rt_FREE(simpleObserver2withKalman_M->dwork);
  rt_FREE(simpleObserver2withKalman_M->prevZCSigState);
  delete simpleObserver2withKalman_M;
}

/* Model data allocation function */
RT_MODEL_simpleObserver2withK_T *simpleObserver2withKalman(void)
{
  RT_MODEL_simpleObserver2withK_T *simpleObserver2withKalman_M;
  simpleObserver2withKalman_M = new RT_MODEL_simpleObserver2withK_T();
  if (simpleObserver2withKalman_M == (nullptr)) {
    return (nullptr);
  }

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo{ (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo))
    };

    rt_VALIDATE_MEMORY(simpleObserver2withKalman_M,rt_SolverInfo);
    simpleObserver2withKalman_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(simpleObserver2withKalman_M->solverInfo,
                          &simpleObserver2withKalman_M->Timing.simTimeStep);
    rtsiSetTPtr(simpleObserver2withKalman_M->solverInfo, &rtmGetTPtr
                (simpleObserver2withKalman_M));
    rtsiSetStepSizePtr(simpleObserver2withKalman_M->solverInfo,
                       &simpleObserver2withKalman_M->Timing.stepSize0);
    rtsiSetdXPtr(simpleObserver2withKalman_M->solverInfo,
                 &simpleObserver2withKalman_M->derivs);
    rtsiSetContStatesPtr(simpleObserver2withKalman_M->solverInfo, (real_T **)
                         &simpleObserver2withKalman_M->contStates);
    rtsiSetNumContStatesPtr(simpleObserver2withKalman_M->solverInfo,
      &simpleObserver2withKalman_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(simpleObserver2withKalman_M->solverInfo,
      &simpleObserver2withKalman_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(simpleObserver2withKalman_M->solverInfo,
      &simpleObserver2withKalman_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(simpleObserver2withKalman_M->solverInfo,
      &simpleObserver2withKalman_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(simpleObserver2withKalman_M->solverInfo,
                          (&rtmGetErrorStatus(simpleObserver2withKalman_M)));
    rtsiSetRTModelPtr(simpleObserver2withKalman_M->solverInfo,
                      simpleObserver2withKalman_M);
  }

  rtsiSetSolverName(simpleObserver2withKalman_M->solverInfo,"ode1");

  /* block I/O */
  {
    B_simpleObserver2withKalman_T *b{ (B_simpleObserver2withKalman_T *) malloc
      (sizeof(B_simpleObserver2withKalman_T)) };

    rt_VALIDATE_MEMORY(simpleObserver2withKalman_M,b);
    simpleObserver2withKalman_M->blockIO = (b);
  }

  /* states (continuous) */
  {
    X_simpleObserver2withKalman_T *x{ (X_simpleObserver2withKalman_T *) malloc
      (sizeof(X_simpleObserver2withKalman_T)) };

    rt_VALIDATE_MEMORY(simpleObserver2withKalman_M,x);
    simpleObserver2withKalman_M->contStates = (x);
  }

  /* states (dwork) */
  {
    DW_simpleObserver2withKalman_T *dwork{ static_cast<
      DW_simpleObserver2withKalman_T *>(malloc(sizeof
      (DW_simpleObserver2withKalman_T))) };

    rt_VALIDATE_MEMORY(simpleObserver2withKalman_M,dwork);
    simpleObserver2withKalman_M->dwork = (dwork);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_simpleObserver2withKa_T *zc{ (PrevZCX_simpleObserver2withKa_T *)
      malloc(sizeof(PrevZCX_simpleObserver2withKa_T)) };

    rt_VALIDATE_MEMORY(simpleObserver2withKalman_M,zc);
    simpleObserver2withKalman_M->prevZCSigState = (zc);
  }

  {
    B_simpleObserver2withKalman_T *simpleObserver2withKalman_B{
      simpleObserver2withKalman_M->blockIO };

    DW_simpleObserver2withKalman_T *simpleObserver2withKalman_DW{
      simpleObserver2withKalman_M->dwork };

    X_simpleObserver2withKalman_T *simpleObserver2withKalman_X{
      simpleObserver2withKalman_M->contStates };

    PrevZCX_simpleObserver2withKa_T *simpleObserver2withKalm_PrevZCX{
      simpleObserver2withKalman_M->prevZCSigState };

    rtsiSetSimTimeStep(simpleObserver2withKalman_M->solverInfo, MAJOR_TIME_STEP);
    simpleObserver2withKalman_M->intgData.f[0] =
      simpleObserver2withKalman_M->odeF[0];
    simpleObserver2withKalman_M->contStates = ((X_simpleObserver2withKalman_T *)
      simpleObserver2withKalman_X);
    rtsiSetSolverData(simpleObserver2withKalman_M->solverInfo, static_cast<void *>
                      (&simpleObserver2withKalman_M->intgData));
    rtmSetTPtr(simpleObserver2withKalman_M,
               &simpleObserver2withKalman_M->Timing.tArray[0]);
    simpleObserver2withKalman_M->Timing.stepSize0 = 0.01;
    rtmSetFirstInitCond(simpleObserver2withKalman_M, 1);

    /* block I/O */
    (void) std::memset((static_cast<void *>(simpleObserver2withKalman_B)), 0,
                       sizeof(B_simpleObserver2withKalman_T));

    /* states (continuous) */
    {
      (void) std::memset(static_cast<void *>(simpleObserver2withKalman_X), 0,
                         sizeof(X_simpleObserver2withKalman_T));
    }

    /* states (dwork) */
    (void) std::memset(static_cast<void *>(simpleObserver2withKalman_DW), 0,
                       sizeof(DW_simpleObserver2withKalman_T));

    /* previous zero-crossing states */
    {
      simpleObserver2withKalm_PrevZCX->Integrator_Reset_ZCE =
        UNINITIALIZED_ZCSIG;
    }
  }

  return simpleObserver2withKalman_M;
}
