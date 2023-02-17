/*
 * DraftSimpleEstimatorANDControl_private.h
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

#ifndef RTW_HEADER_DraftSimpleEstimatorANDControl_private_h_
#define RTW_HEADER_DraftSimpleEstimatorANDControl_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 rtmSetErrorStatus(DraftSimpleEstimatorANDContr_M, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (nullptr)) {\
 free((ptr));\
 (ptr) = (nullptr);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (nullptr)) {\
 free((void *)(ptr));\
 (ptr) = (nullptr);\
 }
#endif
#endif

/* private model entry point functions */
extern void DraftSimpleEstimatorANDControl_derivatives
  (RT_MODEL_DraftSimpleEstimator_T *const DraftSimpleEstimatorANDContr_M);

#endif                /* RTW_HEADER_DraftSimpleEstimatorANDControl_private_h_ */
