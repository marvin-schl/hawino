/*
 * sinusfahrt.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sinusfahrt".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Feb  9 16:11:43 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sinusfahrt.h"
#include "sinusfahrt_private.h"

/* Model step function */
void sinusfahrt_step(RT_MODEL_sinusfahrt_T *const sinusfahrt_M)
{
  B_sinusfahrt_T *sinusfahrt_B{ sinusfahrt_M->blockIO };

  DW_sinusfahrt_T *sinusfahrt_DW{ sinusfahrt_M->dwork };

  /* Sin: '<Root>/Sine Wave' */
  sinusfahrt_B->vx = std::sin(static_cast<real_T>(sinusfahrt_DW->counter) * 2.0 *
    3.1415926535897931 / 800.0) * 300.0;

  /* Update for S-Function (TcModuleInOut): '<Root>/vxSLX' */
  if (sinusfahrt_DW->vxSLX_PWORK != NULL) {
    *((real_T*)sinusfahrt_DW->vxSLX_PWORK) = sinusfahrt_B->vx;
  }

  /* Update for Sin: '<Root>/Sine Wave' */
  sinusfahrt_DW->counter++;
  if (sinusfahrt_DW->counter == 800) {
    sinusfahrt_DW->counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void sinusfahrt_initialize(RT_MODEL_sinusfahrt_T *const sinusfahrt_M)
{
  DW_sinusfahrt_T *sinusfahrt_DW{ sinusfahrt_M->dwork };

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  sinusfahrt_DW->counter = 0;
}

/* Model terminate function */
void sinusfahrt_terminate(RT_MODEL_sinusfahrt_T * sinusfahrt_M)
{
  /* model code */
  rt_FREE(sinusfahrt_M->blockIO);
  rt_FREE(sinusfahrt_M->dwork);
  delete sinusfahrt_M;
}

/* Model data allocation function */
RT_MODEL_sinusfahrt_T *sinusfahrt(void)
{
  RT_MODEL_sinusfahrt_T *sinusfahrt_M;
  sinusfahrt_M = new RT_MODEL_sinusfahrt_T();
  if (sinusfahrt_M == (nullptr)) {
    return (nullptr);
  }

  /* block I/O */
  {
    B_sinusfahrt_T *b{ (B_sinusfahrt_T *) malloc(sizeof(B_sinusfahrt_T)) };

    rt_VALIDATE_MEMORY(sinusfahrt_M,b);
    sinusfahrt_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_sinusfahrt_T *dwork{ static_cast<DW_sinusfahrt_T *>(malloc(sizeof
      (DW_sinusfahrt_T))) };

    rt_VALIDATE_MEMORY(sinusfahrt_M,dwork);
    sinusfahrt_M->dwork = (dwork);
  }

  {
    B_sinusfahrt_T *sinusfahrt_B{ sinusfahrt_M->blockIO };

    DW_sinusfahrt_T *sinusfahrt_DW{ sinusfahrt_M->dwork };

    /* block I/O */
    (void) std::memset((static_cast<void *>(sinusfahrt_B)), 0,
                       sizeof(B_sinusfahrt_T));

    /* states (dwork) */
    (void) std::memset(static_cast<void *>(sinusfahrt_DW), 0,
                       sizeof(DW_sinusfahrt_T));
  }

  return sinusfahrt_M;
}
