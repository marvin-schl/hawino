/*
 * A_search_types.h
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

#ifndef RTW_HEADER_A_search_types_h_
#define RTW_HEADER_A_search_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
#ifndef struct_d_matlab_internal_coder_tabul_T
#define struct_d_matlab_internal_coder_tabul_T

struct d_matlab_internal_coder_tabul_T
{
  int32_T __dummy;
};

#endif                              /* struct_d_matlab_internal_coder_tabul_T */

#ifndef struct_emxArray_int32_T_A_search_T
#define struct_emxArray_int32_T_A_search_T

struct emxArray_int32_T_A_search_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_int32_T_A_search_T */

#ifndef struct_emxArray_real_T_A_search_T
#define struct_emxArray_real_T_A_search_T

struct emxArray_real_T_A_search_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real_T_A_search_T */

#ifndef struct_emxArray_boolean_T_A_search_T
#define struct_emxArray_boolean_T_A_search_T

struct emxArray_boolean_T_A_search_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                /* struct_emxArray_boolean_T_A_search_T */

#ifndef struct_emxArray_real_T_400_A_search_T
#define struct_emxArray_real_T_400_A_search_T

struct emxArray_real_T_400_A_search_T
{
  real_T data[400];
  int32_T size;
};

#endif                               /* struct_emxArray_real_T_400_A_search_T */

/* Custom Type definition for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
#ifndef struct_cell_wrap_0_A_search_T
#define struct_cell_wrap_0_A_search_T

struct cell_wrap_0_A_search_T
{
  emxArray_real_T_400_A_search_T f1;
};

#endif                                 /* struct_cell_wrap_0_A_search_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_A_search_T RT_MODEL_A_search_T;

#endif                                 /* RTW_HEADER_A_search_types_h_ */
