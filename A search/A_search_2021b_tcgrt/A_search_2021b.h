/*
 * A_search_2021b.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "A_search_2021b".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Mar 23 10:49:48 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_A_search_2021b_h_
#define RTW_HEADER_A_search_2021b_h_
#include <cmath>
#include <cstring>
#include <math.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "A_search_2021b_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
struct B_A_search_2021b_T {
  real_T closedList[720];
  real_T xRobotStart;                  /* '<Root>/xRobotStart' */
  real_T yRobotStart;                  /* '<Root>/yRobotStart' */
  real_T xGoalEnd;                     /* '<Root>/xGoalEnd' */
  real_T yGoalEnd;                     /* '<Root>/yGoalEnd' */
  real_T endNode;                      /* '<Root>/endNode' */
  real_T xKoordinaten[144];            /* '<S1>/koordinatenListe' */
  real_T yKoordinaten[144];            /* '<S1>/koordinatenListe' */
  real_T startKnoten;                  /* '<S1>/Startposition' */
  real_T A[20736];                     /* '<S1>/Graph erstellen' */
  real_T removeNode[12];               /* '<S1>/Graph erstellen' */
  real_T xKnoten[144];                 /* '<S1>/Graph erstellen' */
  real_T yKnoten[144];                 /* '<S1>/Graph erstellen' */
  real_T wayPointList[144];            /* '<S1>/A-Stern-Algorithmus' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_A_search_2021b_T {
  void *xPointList_PWORK;              /* '<Root>/xPointList' */
  void *yPointList_PWORK;              /* '<Root>/yPointList' */
  void *xRobotStart_PWORK;             /* '<Root>/xRobotStart' */
  void *yRobotStart_PWORK;             /* '<Root>/yRobotStart' */
  void *xGoalEnd_PWORK;                /* '<Root>/xGoalEnd' */
  void *yGoalEnd_PWORK;                /* '<Root>/yGoalEnd' */
  void *endNode_PWORK;                 /* '<Root>/endNode' */
};

/* Real-time Model Data Structure */
struct tag_RTM_A_search_2021b_T {
  const char_T *errorStatus;
};

/* Class declaration for model A_search_2021b */
class A_search_2021bModelClass
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  A_search_2021bModelClass(A_search_2021bModelClass const&) =delete;

  /* Assignment Operator */
  A_search_2021bModelClass& operator= (A_search_2021bModelClass const&) & =
    delete;

  /* Real-Time Model get method */
  RT_MODEL_A_search_2021b_T * getRTM();

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate(); /* TE140x */

  /* Constructor */
  A_search_2021bModelClass();

  /* Destructor */
  ~A_search_2021bModelClass();

  /* private data and function members */
 public:
  /* Block signals */
  B_A_search_2021b_T A_search_2021b_B;

  /* Block states */
  DW_A_search_2021b_T A_search_2021b_DW;

  /* private member function(s) for subsystem '<Root>'*/
  real_T A_search_2021b_mod(real_T x);
  real_T A_search_2021b_minimum(const real_T x[144]);
  void A_search_2021b_eml_find(const boolean_T x[144], int32_T i_data[], int32_T
    *i_size);
  real_T A_sear_skip_to_last_equal_value(int32_T *k, const real_T x_data[],
    const int32_T *x_size);
  void A_search_2021b_do_vectors(const real_T a_data[], const int32_T *a_size,
    const real_T b_data[], const int32_T *b_size, real_T c_data[], int32_T
    *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[], int32_T
    *ib_size);

  /* Real-Time Model */
  RT_MODEL_A_search_2021b_T A_search_2021b_M;
};

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
 * '<Root>' : 'A_search_2021b'
 * '<S1>'   : 'A_search_2021b/Enabled Subsystem'
 * '<S2>'   : 'A_search_2021b/Enabled Subsystem/A-Stern-Algorithmus'
 * '<S3>'   : 'A_search_2021b/Enabled Subsystem/Graph erstellen'
 * '<S4>'   : 'A_search_2021b/Enabled Subsystem/Startposition'
 * '<S5>'   : 'A_search_2021b/Enabled Subsystem/koordinatenListe'
 */
#endif                                 /* RTW_HEADER_A_search_2021b_h_ */
