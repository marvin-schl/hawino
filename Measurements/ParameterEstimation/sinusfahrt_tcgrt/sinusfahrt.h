/*
 * sinusfahrt.h
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

#ifndef RTW_HEADER_sinusfahrt_h_
#define RTW_HEADER_sinusfahrt_h_
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "sinusfahrt_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define sinusfahrt_M_TYPE              RT_MODEL_sinusfahrt_T

/* Block signals (default storage) */
struct B_sinusfahrt_T {
  real_T vx;                           /* '<Root>/Sine Wave' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_sinusfahrt_T {
  void *vxSLX_PWORK;                   /* '<Root>/vxSLX' */
  int32_T counter;                     /* '<Root>/Sine Wave' */
};

/* Real-time Model Data Structure */
struct tag_RTM_sinusfahrt_T {
  const char_T *errorStatus;
  B_sinusfahrt_T *blockIO;
  DW_sinusfahrt_T *dwork;
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
  extern RT_MODEL_sinusfahrt_T *sinusfahrt(void);
  extern void sinusfahrt_initialize(RT_MODEL_sinusfahrt_T *const sinusfahrt_M);
  extern void sinusfahrt_step(RT_MODEL_sinusfahrt_T *const sinusfahrt_M);
  extern void sinusfahrt_terminate(RT_MODEL_sinusfahrt_T * sinusfahrt_M);

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
 * '<Root>' : 'sinusfahrt'
 */
#endif                                 /* RTW_HEADER_sinusfahrt_h_ */
