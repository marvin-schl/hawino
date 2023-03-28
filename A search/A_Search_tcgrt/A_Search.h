/*
 * A_Search.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "A_Search".
 *
 * Model version              : 1.26
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sat Mar 25 15:22:51 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_A_Search_h_
#define RTW_HEADER_A_Search_h_
#include <cmath>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "A_Search_types.h"

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

#define A_Search_M_TYPE                RT_MODEL_A_Search_T

/* Block signals (default storage) */
struct B_A_Search_T {
  real_T xRobotStart;                  /* '<Root>/xRobotStart' */
  real_T yRobotStart;                  /* '<Root>/yRobotStart' */
  real_T xRobotEnd;                    /* '<Root>/xRobotEnd' */
  real_T yRobotEnd;                    /* '<Root>/yRobotEnd' */
  real_T endNode;                      /* '<Root>/endNode' */
  real_T startNode;                    /* '<S1>/Start pose of robot' */
  real_T xKoordinaten[101];            /* '<S1>/List of coordinates' */
  real_T yKoordinaten[101];            /* '<S1>/List of coordinates' */
  real_T wayPointList[101];            /* '<S1>/A Search' */
  real_T matrix[20736];                /* '<S1>/ Create the matrix' */
  real_T removeNode[12];               /* '<S1>/ Create the matrix' */
  real_T xNode[144];                   /* '<S1>/ Create the matrix' */
  real_T yNode[144];                   /* '<S1>/ Create the matrix' */
  boolean_T enable;                    /* '<Root>/enable' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_A_Search_T {
  void *xCoordinates_PWORK;            /* '<Root>/xCoordinates' */
  void *yCoordinates_PWORK;            /* '<Root>/yCoordinates' */
  void *xRobotStart_PWORK;             /* '<Root>/xRobotStart' */
  void *yRobotStart_PWORK;             /* '<Root>/yRobotStart' */
  void *xRobotEnd_PWORK;               /* '<Root>/xRobotEnd' */
  void *yRobotEnd_PWORK;               /* '<Root>/yRobotEnd' */
  void *endNode_PWORK;                 /* '<Root>/endNode' */
  void *enable_PWORK;                  /* '<Root>/enable' */
};

/* Real-time Model Data Structure */
struct tag_RTM_A_Search_T {
  const char_T *errorStatus;
  B_A_Search_T *blockIO;
  DW_A_Search_T *dwork;
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
  extern RT_MODEL_A_Search_T *A_Search(void);
  extern void A_Search_initialize(RT_MODEL_A_Search_T *const A_Search_M);
  extern void A_Search_step(RT_MODEL_A_Search_T *const A_Search_M);
  extern void A_Search_terminate(RT_MODEL_A_Search_T * A_Search_M);

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
 * '<Root>' : 'A_Search'
 * '<S1>'   : 'A_Search/Enabled Subsystem'
 * '<S2>'   : 'A_Search/Enabled Subsystem/ Create the matrix'
 * '<S3>'   : 'A_Search/Enabled Subsystem/A Search'
 * '<S4>'   : 'A_Search/Enabled Subsystem/List of coordinates'
 * '<S5>'   : 'A_Search/Enabled Subsystem/Start pose of robot'
 */
#endif                                 /* RTW_HEADER_A_Search_h_ */
