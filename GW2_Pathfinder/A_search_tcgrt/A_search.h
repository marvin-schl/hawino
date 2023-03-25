/*
 * A_search.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "A_search".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Mar  9 13:24:27 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_A_search_h_
#define RTW_HEADER_A_search_h_
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "A_search_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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

#define A_search_M_TYPE                RT_MODEL_A_search_T

/* Block signals (default storage) */
struct B_A_search_T {
  cell_wrap_0_A_search_T Graph_EdgeProperties_data;
  cell_wrap_0_A_search_T q;
  real_T expl_temp_data[400];
  real_T TCModuleInput1;               /* '<Root>/TC Module Input1' */
  real_T TCModuleInput2;               /* '<Root>/TC Module Input2' */
  real_T TCModuleInput3;               /* '<Root>/TC Module Input3' */
  real_T TCModuleInput4;               /* '<Root>/TC Module Input4' */
  real_T TCModuleInput5;               /* '<Root>/TC Module Input5' */
  real_T TCModuleInput6;               /* '<Root>/TC Module Input6' */
  real_T xKoordinaten[20];             /* '<S1>/koordinatenListe' */
  real_T yKoordinaten[20];             /* '<S1>/koordinatenListe' */
  real_T startKnoten;                  /* '<S1>/Startposition' */
  real_T A[400];                       /* '<S1>/Graph erstellen' */
  real_T xKnoten[20];                  /* '<S1>/Graph erstellen' */
  real_T yKnoten[20];                  /* '<S1>/Graph erstellen' */
  real_T wayPointList[20];             /* '<S1>/A-Stern-Algorithmus' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_A_search_T {
  void *TCModuleOutput_PWORK;          /* '<Root>/TC Module Output' */
  void *TCModuleOutput1_PWORK;         /* '<Root>/TC Module Output1' */
  void *TCModuleInput1_PWORK;          /* '<Root>/TC Module Input1' */
  void *TCModuleInput2_PWORK;          /* '<Root>/TC Module Input2' */
  void *TCModuleInput3_PWORK;          /* '<Root>/TC Module Input3' */
  void *TCModuleInput4_PWORK;          /* '<Root>/TC Module Input4' */
  void *TCModuleInput5_PWORK;          /* '<Root>/TC Module Input5' */
  void *TCModuleInput6_PWORK;          /* '<Root>/TC Module Input6' */
};

/* Real-time Model Data Structure */
struct tag_RTM_A_search_T {
  const char_T *errorStatus;
  B_A_search_T *blockIO;
  DW_A_search_T *dwork;
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
  extern RT_MODEL_A_search_T *A_search(void);
  extern void A_search_initialize(RT_MODEL_A_search_T *const A_search_M);
  extern void A_search_step(RT_MODEL_A_search_T *const A_search_M);
  extern void A_search_terminate(RT_MODEL_A_search_T * A_search_M);

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
 * '<Root>' : 'A_search'
 * '<S1>'   : 'A_search/Enabled Subsystem'
 * '<S2>'   : 'A_search/Enabled Subsystem/A-Stern-Algorithmus'
 * '<S3>'   : 'A_search/Enabled Subsystem/Graph erstellen'
 * '<S4>'   : 'A_search/Enabled Subsystem/Startposition'
 * '<S5>'   : 'A_search/Enabled Subsystem/koordinatenListe'
 */
#endif                                 /* RTW_HEADER_A_search_h_ */
