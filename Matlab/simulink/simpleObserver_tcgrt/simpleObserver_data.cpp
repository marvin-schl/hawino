/*
 * simpleObserver_data.cpp
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

/* Block parameters (default storage) */
P_simpleObserver_T simpleObserver_P{
  /* Expression: 0.6
   * Referenced by: '<Root>/Constant'
   */
  0.6,

  /* Expression: 0.0
   * Referenced by: '<S1>/CameraDelay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay One Step1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: [9 0 0; 0 9 0; 0 0 9]
   * Referenced by: '<Root>/Gain'
   */
  { 9.0, 0.0, 0.0, 0.0, 9.0, 0.0, 0.0, 0.0, 9.0 }
};
