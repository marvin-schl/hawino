/*
 * A_search.cpp
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

#include "A_search.h"
#include "A_search_private.h"

/* Forward declaration for local functions */
static real_T A_search_mod(real_T x);
static real_T A_search_minimum_o(const real_T x[20]);
static void A_search_eml_find_l(const boolean_T x[20], int32_T i_data[], int32_T
  *i_size);
static void A_search_emxInit_int32_T(emxArray_int32_T_A_search_T **pEmxArray,
  int32_T numDimensions);
static real_T A_se_skip_to_last_equal_value_p(int32_T *k, const real_T x_data[],
  const int32_T *x_size);
static void A_search_do_vectors_n(const real_T a_data[], const int32_T *a_size,
  const real_T b_data[], const int32_T *b_size, real_T c_data[], int32_T *c_size,
  int32_T ia_data[], int32_T *ia_size, int32_T ib_data[], int32_T *ib_size);
static void A_sea_emxEnsureCapacity_int32_T(emxArray_int32_T_A_search_T
  *emxArray, int32_T oldNumel);
static void A_search_emxFree_int32_T(emxArray_int32_T_A_search_T **pEmxArray);
static void A_search_emxInit_int32_T1(emxArray_int32_T_A_search_T **pEmxArray,
  int32_T numDimensions);
static void A_se_emxEnsureCapacity_int32_T1(emxArray_int32_T_A_search_T
  *emxArray, int32_T oldNumel);
static void A_search_graph_graph(const real_T varargin_1[400],
  emxArray_int32_T_A_search_T *G_Underlying_Ir, int32_T G_Underlying_Jc_data[],
  int32_T *G_Underlying_Jc_size, int32_T G_Underlying_Diag_data[], int32_T
  *G_Underlying_Diag_size, cell_wrap_0_A_search_T *G_EdgeProperties_data,
  B_A_search_T *A_search_B);
static void A_search_emxInit_real_T(emxArray_real_T_A_search_T **pEmxArray,
  int32_T numDimensions);
static void A_search_emxInit_real_T1(emxArray_real_T_A_search_T **pEmxArray,
  int32_T numDimensions);
static void A_search_emxInit_boolean_T(emxArray_boolean_T_A_search_T **pEmxArray,
  int32_T numDimensions);
static void A_search_emxFree_real_T(emxArray_real_T_A_search_T **pEmxArray);
static void A_search_emxFree_boolean_T(emxArray_boolean_T_A_search_T **pEmxArray);
static void A_sea_emxEnsureCapacity_real_T1(emxArray_real_T_A_search_T *emxArray,
  int32_T oldNumel);
static void A_search_graphBase_get_Edges(const emxArray_int32_T_A_search_T
  *G_Underlying_Ir, const int32_T G_Underlying_Jc_data[], const int32_T
  G_Underlying_Diag_data[], const cell_wrap_0_A_search_T *G_EdgeProperties_data,
  int32_T *E_metaDim___dummy, emxArray_real_T_A_search_T *E_data_f1, real_T
  E_data_f2_data[], int32_T *E_data_f2_size);
static real_T A_search_minimum(const real_T x[30]);
static void A_s_emxEnsureCapacity_boolean_T(emxArray_boolean_T_A_search_T
  *emxArray, int32_T oldNumel);
static void A_search_eml_find_c(const boolean_T x[30], int32_T i_data[], int32_T
  *i_size);
static void A_search_eml_find(const emxArray_boolean_T_A_search_T *x,
  emxArray_int32_T_A_search_T *i);
static void A_sear_emxEnsureCapacity_real_T(emxArray_real_T_A_search_T *emxArray,
  int32_T oldNumel);
static void A_search_eml_find_cr(const emxArray_real_T_A_search_T *x, real_T kin,
  int32_T i_data[], int32_T *i_size);
static real_T A_sear_skip_to_last_equal_value(int32_T *k, const
  emxArray_real_T_A_search_T *x);
static void A_search_do_vectors(const emxArray_real_T_A_search_T *a, const
  emxArray_real_T_A_search_T *b, emxArray_real_T_A_search_T *c,
  emxArray_int32_T_A_search_T *ia, emxArray_int32_T_A_search_T *ib);

/* Function for MATLAB Function: '<S1>/Graph erstellen' */
static real_T A_search_mod(real_T x)
{
  real_T r;
  if (std::isnan(x) || std::isinf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = std::fmod(x, 4.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 4.0;
    }
  }

  return r;
}

/* Function for MATLAB Function: '<S1>/Startposition' */
static real_T A_search_minimum_o(const real_T x[20])
{
  real_T ex;
  int32_T idx;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    int32_T k;
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 21)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 < 21) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S1>/Startposition' */
static void A_search_eml_find_l(const boolean_T x[20], int32_T i_data[], int32_T
  *i_size)
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 20)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 20) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

static void A_search_emxInit_int32_T(emxArray_int32_T_A_search_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_int32_T_A_search_T *emxArray;
  *pEmxArray = (emxArray_int32_T_A_search_T *)std::malloc(sizeof
    (emxArray_int32_T_A_search_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i{0}; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* Function for MATLAB Function: '<S1>/Startposition' */
static real_T A_se_skip_to_last_equal_value_p(int32_T *k, const real_T x_data[],
  const int32_T *x_size)
{
  real_T xk;
  int32_T exponent;
  boolean_T exitg1;
  xk = x_data[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < *x_size)) {
    real_T absx;
    absx = std::abs(xk / 2.0);
    if (!std::isnan(absx)) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = std::ldexp(1.0, exponent - 53);
      }
    } else {
      absx = (rtNaN);
    }

    if (std::abs(xk - x_data[*k]) < absx) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return xk;
}

/* Function for MATLAB Function: '<S1>/Startposition' */
static void A_search_do_vectors_n(const real_T a_data[], const int32_T *a_size,
  const real_T b_data[], const int32_T *b_size, real_T c_data[], int32_T *c_size,
  int32_T ia_data[], int32_T *ia_size, int32_T ib_data[], int32_T *ib_size)
{
  int32_T b_ialast;
  int32_T b_iblast;
  int32_T exponent;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T ncmax;
  if (*a_size <= *b_size) {
    ncmax = *a_size;
  } else {
    ncmax = *b_size;
  }

  *c_size = ncmax;
  *ia_size = ncmax;
  *ib_size = ncmax;
  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= *a_size) && (iblast <= *b_size)) {
    real_T absx;
    real_T ak;
    real_T bk;
    b_ialast = ialast;
    ak = A_se_skip_to_last_equal_value_p(&b_ialast, a_data, a_size);
    ialast = b_ialast;
    b_iblast = iblast;
    bk = A_se_skip_to_last_equal_value_p(&b_iblast, b_data, b_size);
    iblast = b_iblast;
    absx = std::abs(bk / 2.0);
    if (!std::isnan(absx)) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = std::ldexp(1.0, exponent - 53);
      }
    } else {
      absx = (rtNaN);
    }

    if (std::abs(bk - ak) < absx) {
      nc++;
      c_data[nc - 1] = ak;
      ia_data[nc - 1] = iafirst + 1;
      ib_data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else {
      boolean_T tmp;
      if (std::isnan(bk)) {
        tmp = !std::isnan(ak);
      } else {
        tmp = ((!std::isnan(ak)) && (ak < bk));
      }

      if (tmp) {
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast = b_iblast + 1;
        ibfirst = b_iblast;
      }
    }
  }

  if (ncmax > 0) {
    if (1 > nc) {
      *ia_size = 0;
      *ib_size = 0;
      *c_size = 0;
    } else {
      *ia_size = nc;
      *ib_size = nc;
      *c_size = nc;
    }
  }
}

static void A_sea_emxEnsureCapacity_int32_T(emxArray_int32_T_A_search_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(int32_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void A_search_emxFree_int32_T(emxArray_int32_T_A_search_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T_A_search_T *)nullptr) {
    if (((*pEmxArray)->data != (int32_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T_A_search_T *)nullptr;
  }
}

static void A_search_emxInit_int32_T1(emxArray_int32_T_A_search_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_int32_T_A_search_T *emxArray;
  *pEmxArray = (emxArray_int32_T_A_search_T *)std::malloc(sizeof
    (emxArray_int32_T_A_search_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i{0}; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void A_se_emxEnsureCapacity_int32_T1(emxArray_int32_T_A_search_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(int32_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static void A_search_graph_graph(const real_T varargin_1[400],
  emxArray_int32_T_A_search_T *G_Underlying_Ir, int32_T G_Underlying_Jc_data[],
  int32_T *G_Underlying_Jc_size, int32_T G_Underlying_Diag_data[], int32_T
  *G_Underlying_Diag_size, cell_wrap_0_A_search_T *G_EdgeProperties_data,
  B_A_search_T *A_search_B)
{
  emxArray_int32_T_A_search_T *d;
  emxArray_int32_T_A_search_T *irNew;
  emxArray_int32_T_A_search_T *listOfSelfLoops;
  real_T s[400];
  int32_T c_i_data[400];
  int32_T e_data[21];
  int32_T b_l;
  int32_T i;
  int32_T idx;
  int32_T ii;
  int32_T jj;
  int32_T loop_ub;
  int16_T c[21];
  int8_T b_j_data[400];
  boolean_T exitg1;
  idx = -1;
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 20)) {
    boolean_T guard1{ false };

    guard1 = false;
    if (varargin_1[((jj - 1) * 20 + ii) - 1] != 0.0) {
      idx++;
      c_i_data[idx] = ii;
      b_j_data[idx] = static_cast<int8_T>(jj);
      if (idx + 1 >= 400) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 20) {
        ii = 1;
        jj++;
      }
    }
  }

  if (1 > idx + 1) {
    idx = -1;
  }

  A_search_B->q.f1.size = idx + 1;
  for (i = 0; i <= idx; i++) {
    A_search_B->q.f1.data[i] = c_i_data[i];
  }

  for (i = 0; i < 21; i++) {
    c[i] = 0;
  }

  jj = idx;
  for (i = 0; i <= idx; i++) {
    c_i_data[i] = static_cast<int32_T>(A_search_B->q.f1.data[i]);
  }

  idx = 0;
  for (ii = 0; ii < 20; ii++) {
    while ((idx < A_search_B->q.f1.size) && (b_j_data[idx] < ii + 2)) {
      idx++;
    }

    c[ii + 1] = static_cast<int16_T>(idx);
  }

  loop_ub = G_Underlying_Ir->size[0] * G_Underlying_Ir->size[1];
  G_Underlying_Ir->size[0] = 1;
  G_Underlying_Ir->size[1] = A_search_B->q.f1.size;
  A_sea_emxEnsureCapacity_int32_T(G_Underlying_Ir, loop_ub);
  for (i = 0; i <= jj; i++) {
    G_Underlying_Ir->data[i] = static_cast<int32_T>(A_search_B->q.f1.data[i]);
  }

  for (i = 0; i < 21; i++) {
    e_data[i] = c[i];
  }

  A_search_emxInit_int32_T(&d, 2);
  A_search_emxInit_int32_T(&listOfSelfLoops, 2);
  listOfSelfLoops->size[0] = 1;
  listOfSelfLoops->size[1] = 0;
  loop_ub = d->size[0] * d->size[1];
  d->size[0] = 1;
  d->size[1] = A_search_B->q.f1.size;
  A_sea_emxEnsureCapacity_int32_T(d, loop_ub);
  for (i = 0; i <= jj; i++) {
    d->data[i] = static_cast<int32_T>(A_search_B->q.f1.data[i]);
  }

  for (jj = 0; jj < 20; jj++) {
    b_l = listOfSelfLoops->size[1];
    i = e_data[jj];
    exitg1 = false;
    while ((!exitg1) && (i + 1 <= e_data[jj + 1])) {
      if (jj + 1 == G_Underlying_Ir->data[i]) {
        idx = listOfSelfLoops->size[1];
        loop_ub = listOfSelfLoops->size[0] * listOfSelfLoops->size[1];
        listOfSelfLoops->size[1]++;
        A_sea_emxEnsureCapacity_int32_T(listOfSelfLoops, loop_ub);
        listOfSelfLoops->data[idx] = i + 1;
        i++;
      } else if (G_Underlying_Ir->data[i] > jj + 1) {
        exitg1 = true;
      } else {
        i++;
      }
    }

    e_data[jj] += b_l;
  }

  e_data[20] += listOfSelfLoops->size[1];
  ii = 0;
  jj = 1;
  if (listOfSelfLoops->size[1] != 0) {
    if (G_Underlying_Ir->size[1] == 0) {
      idx = 0;
    } else {
      idx = G_Underlying_Ir->size[1];
    }

    A_search_emxInit_int32_T1(&irNew, 1);
    loop_ub = irNew->size[0];
    irNew->size[0] = idx + listOfSelfLoops->size[1];
    A_se_emxEnsureCapacity_int32_T1(irNew, loop_ub);
    loop_ub = idx + listOfSelfLoops->size[1];
    for (i = 0; i < loop_ub; i++) {
      irNew->data[i] = 0;
    }

    for (b_l = 0; b_l < listOfSelfLoops->size[1]; b_l++) {
      if (jj > listOfSelfLoops->data[b_l]) {
        idx = 0;
        i = 0;
      } else {
        idx = jj - 1;
        i = listOfSelfLoops->data[b_l];
      }

      loop_ub = i - idx;
      for (i = 0; i < loop_ub; i++) {
        irNew->data[i + ii] = G_Underlying_Ir->data[idx + i];
      }

      ii = (ii + listOfSelfLoops->data[b_l]) - jj;
      jj = listOfSelfLoops->data[b_l];
      irNew->data[ii] = c_i_data[listOfSelfLoops->data[b_l] - 1];
      ii++;
    }

    if (jj > A_search_B->q.f1.size) {
      idx = 0;
      jj = 0;
    } else {
      idx = jj - 1;
      jj = G_Underlying_Ir->size[1];
    }

    if (ii + 1 > irNew->size[0]) {
      ii = 0;
    }

    loop_ub = jj - idx;
    for (i = 0; i < loop_ub; i++) {
      irNew->data[ii + i] = G_Underlying_Ir->data[idx + i];
    }

    loop_ub = d->size[0] * d->size[1];
    d->size[0] = irNew->size[0];
    d->size[1] = 1;
    A_sea_emxEnsureCapacity_int32_T(d, loop_ub);
    loop_ub = irNew->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      d->data[i] = irNew->data[i];
    }

    A_search_emxFree_int32_T(&irNew);
  }

  A_search_emxFree_int32_T(&listOfSelfLoops);
  loop_ub = G_Underlying_Ir->size[0] * G_Underlying_Ir->size[1];
  G_Underlying_Ir->size[0] = d->size[0];
  G_Underlying_Ir->size[1] = d->size[1];
  A_sea_emxEnsureCapacity_int32_T(G_Underlying_Ir, loop_ub);
  loop_ub = d->size[0] * d->size[1];
  for (i = 0; i < loop_ub; i++) {
    G_Underlying_Ir->data[i] = d->data[i];
  }

  *G_Underlying_Jc_size = 21;
  *G_Underlying_Diag_size = 21;
  for (i = 0; i < 21; i++) {
    loop_ub = e_data[i];
    G_Underlying_Jc_data[i] = loop_ub;
    G_Underlying_Diag_data[i] = loop_ub;
  }

  for (jj = 0; jj < 20; jj++) {
    b_l = G_Underlying_Diag_data[jj];
    while ((b_l + 1 <= e_data[jj + 1]) && (jj + 1 == d->data[b_l])) {
      b_l += 2;
    }

    while (b_l + 1 <= e_data[jj + 1]) {
      G_Underlying_Diag_data[d->data[b_l] - 1]++;
      b_l++;
    }
  }

  A_search_emxFree_int32_T(&d);
  std::memcpy(&s[0], &varargin_1[0], 400U * sizeof(real_T));
  idx = 1;
  for (ii = 0; ii < 19; ii++) {
    for (jj = 0; jj < idx; jj++) {
      s[jj + 20 * (ii + 1)] = 0.0;
    }

    if (idx < 20) {
      idx++;
    }
  }

  idx = 0;
  for (ii = 0; ii < 400; ii++) {
    if (s[ii] != 0.0) {
      idx++;
    }
  }

  A_search_B->q.f1.size = idx;
  idx = -1;
  for (ii = 0; ii < 400; ii++) {
    real_T s_0;
    s_0 = s[ii];
    if (s_0 != 0.0) {
      idx++;
      A_search_B->q.f1.data[idx] = s_0;
    }
  }

  *G_EdgeProperties_data = A_search_B->q;
}

static void A_search_emxInit_real_T(emxArray_real_T_A_search_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_real_T_A_search_T *emxArray;
  *pEmxArray = (emxArray_real_T_A_search_T *)std::malloc(sizeof
    (emxArray_real_T_A_search_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i{0}; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void A_search_emxInit_real_T1(emxArray_real_T_A_search_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_real_T_A_search_T *emxArray;
  *pEmxArray = (emxArray_real_T_A_search_T *)std::malloc(sizeof
    (emxArray_real_T_A_search_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i{0}; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void A_search_emxInit_boolean_T(emxArray_boolean_T_A_search_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_boolean_T_A_search_T *emxArray;
  *pEmxArray = (emxArray_boolean_T_A_search_T *)std::malloc(sizeof
    (emxArray_boolean_T_A_search_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i{0}; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void A_search_emxFree_real_T(emxArray_real_T_A_search_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_A_search_T *)nullptr) {
    if (((*pEmxArray)->data != (real_T *)nullptr) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_A_search_T *)nullptr;
  }
}

static void A_search_emxFree_boolean_T(emxArray_boolean_T_A_search_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_A_search_T *)nullptr) {
    if (((*pEmxArray)->data != (boolean_T *)nullptr) && (*pEmxArray)
        ->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_A_search_T *)nullptr;
  }
}

static void A_sea_emxEnsureCapacity_real_T1(emxArray_real_T_A_search_T *emxArray,
  int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(real_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static void A_search_graphBase_get_Edges(const emxArray_int32_T_A_search_T
  *G_Underlying_Ir, const int32_T G_Underlying_Jc_data[], const int32_T
  G_Underlying_Diag_data[], const cell_wrap_0_A_search_T *G_EdgeProperties_data,
  int32_T *E_metaDim___dummy, emxArray_real_T_A_search_T *E_data_f1, real_T
  E_data_f2_data[], int32_T *E_data_f2_size)
{
  real_T e;
  int32_T ll;
  int32_T n;
  if ((G_Underlying_Ir->size[0] == 0) || (G_Underlying_Ir->size[1] == 0)) {
    n = 0;
  } else if (G_Underlying_Ir->size[0] >= G_Underlying_Ir->size[1]) {
    n = G_Underlying_Ir->size[0];
  } else {
    n = G_Underlying_Ir->size[1];
  }

  e = static_cast<real_T>(n) / 2.0;
  n = E_data_f1->size[0] * E_data_f1->size[1];
  E_data_f1->size[0] = static_cast<int32_T>(e);
  E_data_f1->size[1] = 2;
  A_sea_emxEnsureCapacity_real_T1(E_data_f1, n);
  n = (static_cast<int32_T>(e) << 1) - 1;
  for (ll = 0; ll <= n; ll++) {
    E_data_f1->data[ll] = 0.0;
  }

  e = 1.0;
  for (n = 0; n < 20; n++) {
    ll = G_Underlying_Diag_data[n];
    while (ll + 1 <= G_Underlying_Jc_data[n + 1]) {
      E_data_f1->data[static_cast<int32_T>(e) - 1] = static_cast<real_T>(n) +
        1.0;
      E_data_f1->data[(static_cast<int32_T>(e) + E_data_f1->size[0]) - 1] =
        G_Underlying_Ir->data[ll];
      e++;
      if (n + 1 == G_Underlying_Ir->data[ll]) {
        ll += 2;
      } else {
        ll++;
      }
    }
  }

  *E_data_f2_size = G_EdgeProperties_data->f1.size;
  n = G_EdgeProperties_data->f1.size;
  for (ll = 0; ll < n; ll++) {
    E_data_f2_data[ll] = G_EdgeProperties_data->f1.data[ll];
  }

  *E_metaDim___dummy = 0;
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static real_T A_search_minimum(const real_T x[30])
{
  real_T ex;
  int32_T idx;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    int32_T k;
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 31)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 < 31) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

static void A_s_emxEnsureCapacity_boolean_T(emxArray_boolean_T_A_search_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(boolean_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static void A_search_eml_find_c(const boolean_T x[30], int32_T i_data[], int32_T
  *i_size)
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 30)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 30) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static void A_search_eml_find(const emxArray_boolean_T_A_search_T *x,
  emxArray_int32_T_A_search_T *i)
{
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  nx = x->size[0] << 1;
  idx = 0;
  ii = i->size[0];
  i->size[0] = nx;
  A_se_emxEnsureCapacity_int32_T1(i, ii);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x->data[ii]) {
      idx++;
      i->data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (nx == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else if (1 > idx) {
    i->size[0] = 0;
  } else {
    ii = i->size[0];
    i->size[0] = idx;
    A_se_emxEnsureCapacity_int32_T1(i, ii);
  }
}

static void A_sear_emxEnsureCapacity_real_T(emxArray_real_T_A_search_T *emxArray,
  int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(real_T));
    if (emxArray->data != nullptr) {
      std::memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static void A_search_eml_find_cr(const emxArray_real_T_A_search_T *x, real_T kin,
  int32_T i_data[], int32_T *i_size)
{
  int32_T idx;
  int32_T ii;
  int32_T k;
  int32_T nx;
  boolean_T exitg1;
  nx = x->size[0] << 1;
  if (kin <= nx) {
    k = static_cast<int32_T>(kin);
  } else {
    k = nx;
  }

  idx = 0;
  *i_size = k;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x->data[ii] != 0.0) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= k) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (k == 1) {
    if (idx == 0) {
      *i_size = 0;
    }
  } else if (1 > idx) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static real_T A_sear_skip_to_last_equal_value(int32_T *k, const
  emxArray_real_T_A_search_T *x)
{
  real_T xk;
  int32_T exponent;
  boolean_T exitg1;
  xk = x->data[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x->size[0])) {
    real_T absx;
    absx = std::abs(xk / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = std::ldexp(1.0, exponent - 53);
    }

    if (std::abs(xk - x->data[*k]) < absx) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return xk;
}

/* Function for MATLAB Function: '<S1>/A-Stern-Algorithmus' */
static void A_search_do_vectors(const emxArray_real_T_A_search_T *a, const
  emxArray_real_T_A_search_T *b, emxArray_real_T_A_search_T *c,
  emxArray_int32_T_A_search_T *ia, emxArray_int32_T_A_search_T *ib)
{
  int32_T b_ialast;
  int32_T b_iblast;
  int32_T exponent;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T ncmax;
  if (a->size[0] <= b->size[0]) {
    ncmax = a->size[0];
  } else {
    ncmax = b->size[0];
  }

  iafirst = c->size[0];
  c->size[0] = ncmax;
  A_sear_emxEnsureCapacity_real_T(c, iafirst);
  iafirst = ia->size[0];
  ia->size[0] = ncmax;
  A_se_emxEnsureCapacity_int32_T1(ia, iafirst);
  iafirst = ib->size[0];
  ib->size[0] = ncmax;
  A_se_emxEnsureCapacity_int32_T1(ib, iafirst);
  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= a->size[0]) && (iblast <= b->size[0])) {
    real_T absx;
    real_T ak;
    real_T bk;
    b_ialast = ialast;
    ak = A_sear_skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    b_iblast = iblast;
    bk = A_sear_skip_to_last_equal_value(&b_iblast, b);
    iblast = b_iblast;
    absx = std::abs(bk / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = std::ldexp(1.0, exponent - 53);
    }

    if (std::abs(bk - ak) < absx) {
      nc++;
      c->data[nc - 1] = ak;
      ia->data[nc - 1] = iafirst + 1;
      ib->data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
    } else {
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  if (ncmax > 0) {
    if (1 > nc) {
      ia->size[0] = 0;
      ib->size[0] = 0;
      c->size[0] = 0;
    } else {
      iafirst = ia->size[0];
      ia->size[0] = nc;
      A_se_emxEnsureCapacity_int32_T1(ia, iafirst);
      iafirst = ib->size[0];
      ib->size[0] = nc;
      A_se_emxEnsureCapacity_int32_T1(ib, iafirst);
      iafirst = c->size[0];
      c->size[0] = nc;
      A_sear_emxEnsureCapacity_real_T(c, iafirst);
    }
  }
}

/* Model step function */
void A_search_step(RT_MODEL_A_search_T *const A_search_M)
{
  B_A_search_T *A_search_B{ A_search_M->blockIO };

  DW_A_search_T *A_search_DW{ A_search_M->dwork };

  static const int8_T b_h[20]{ 7, 6, 5, 4, 6, 5, 4, 3, 5, 4, 3, 2, 4, 3, 2, 1, 3,
    2, 1, 0 };

  d_matlab_internal_coder_tabul_T expl_temp;
  emxArray_boolean_T_A_search_T *assign_temp_data_f1_1;
  emxArray_int32_T_A_search_T *Graph_Underlying_Ir;
  emxArray_int32_T_A_search_T *ia;
  emxArray_int32_T_A_search_T *ib;
  emxArray_real_T_A_search_T *assign_temp_data_f1;
  emxArray_real_T_A_search_T *assign_temp_data_f1_0;
  emxArray_real_T_A_search_T *searchedRow;
  emxArray_real_T_A_search_T *tmp;
  emxArray_real_T_A_search_T *tmp_0;
  real_T closedList[120];
  real_T openList[120];
  real_T Z[30];
  real_T diff_x[20];
  real_T diff_y[20];
  real_T startKnotenArray_data[20];
  int32_T tmp_data[30];
  int32_T Graph_Underlying_Diag_data[21];
  int32_T Graph_Underlying_Jc_data[21];
  int32_T ia_data[20];
  int32_T ib_data[20];
  int32_T actualNeighbor;
  int32_T h;
  int32_T i;
  int32_T tmp_size;
  int32_T tmp_size_0;
  int8_T c_data[30];
  int8_T d_data[30];
  int8_T e_data[30];
  int8_T f_data[30];
  boolean_T openList_0[30];
  boolean_T diff_x_0[20];

  /* S-Function (TcModuleInOut): '<Root>/TC Module Input1' */
  if (A_search_DW->TCModuleInput1_PWORK != NULL) {
    A_search_B->TCModuleInput1 = *((real_T*)A_search_DW->TCModuleInput1_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/TC Module Input2' */
  if (A_search_DW->TCModuleInput2_PWORK != NULL) {
    A_search_B->TCModuleInput2 = *((real_T*)A_search_DW->TCModuleInput2_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/TC Module Input3' */
  if (A_search_DW->TCModuleInput3_PWORK != NULL) {
    A_search_B->TCModuleInput3 = *((real_T*)A_search_DW->TCModuleInput3_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/TC Module Input4' */
  if (A_search_DW->TCModuleInput4_PWORK != NULL) {
    A_search_B->TCModuleInput4 = *((real_T*)A_search_DW->TCModuleInput4_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/TC Module Input5' */
  if (A_search_DW->TCModuleInput5_PWORK != NULL) {
    A_search_B->TCModuleInput5 = *((real_T*)A_search_DW->TCModuleInput5_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/TC Module Input6' */
  if (A_search_DW->TCModuleInput6_PWORK != NULL) {
    A_search_B->TCModuleInput6 = *((real_T*)A_search_DW->TCModuleInput6_PWORK);
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (A_search_B->TCModuleInput6 > 0.0) {
    real_T actualNode;
    real_T col;
    real_T nextNode;
    real_T row;
    boolean_T exitg1;
    boolean_T inClosedList;
    boolean_T inOpenList;

    /* MATLAB Function: '<S1>/Graph erstellen' */
    std::memset(&A_search_B->A[0], 0, 400U * sizeof(real_T));
    for (i = 0; i < 20; i++) {
      if ((i > 0) && (A_search_mod(static_cast<real_T>(i) + 1.0) != 1.0)) {
        A_search_B->A[(i + 20 * i) - 1] = 1.0;
      }

      if ((i + 2 < 21) && (A_search_mod(static_cast<real_T>(i) + 1.0) != 0.0)) {
        A_search_B->A[(i + 20 * i) + 1] = 1.0;
      }

      if (i + 5 < 21) {
        A_search_B->A[(i + 20 * i) + 4] = 1.0;
      }

      if (i - 3 > 0) {
        A_search_B->A[(i + 20 * i) - 4] = 1.0;
      }

      if ((i + 6 < 21) && (A_search_mod(static_cast<real_T>(i) + 1.0) != 0.0)) {
        A_search_B->A[(i + 20 * i) + 5] = 1.4142135623730951;
      }

      if ((i + 4 < 21) && (A_search_mod(static_cast<real_T>(i) + 1.0) != 1.0)) {
        A_search_B->A[(i + 20 * i) + 3] = 1.4142135623730951;
      }

      if ((i - 4 > 0) && (A_search_mod(static_cast<real_T>(i) + 1.0) != 1.0)) {
        A_search_B->A[(i + 20 * i) - 5] = 1.4142135623730951;
      }

      if ((i - 2 > 0) && (A_search_mod(static_cast<real_T>(i) + 1.0) != 0.0)) {
        A_search_B->A[(i + 20 * i) - 3] = 1.4142135623730951;
      }
    }

    row = 600.0;
    col = 200.0;
    for (i = 0; i < 20; i++) {
      A_search_B->A[20 * i + 2] = 0.0;
      A_search_B->A[i + 40] = 0.0;
      A_search_B->A[20 * i + 6] = 0.0;
      A_search_B->A[i + 120] = 0.0;
      A_search_B->xKnoten[i] = col;
      A_search_B->yKnoten[i] = row;
      col += 400.0;
      if (A_search_mod(static_cast<real_T>(i) + 1.0) == 0.0) {
        col = 200.0;
        row += 400.0;
      }

      /* MATLAB Function: '<S1>/Startposition' */
      diff_x[i] = std::abs(A_search_B->TCModuleInput2 - A_search_B->xKnoten[i]);
      diff_y[i] = std::abs(A_search_B->TCModuleInput3 - A_search_B->yKnoten[i]);
    }

    /* End of MATLAB Function: '<S1>/Graph erstellen' */

    /* MATLAB Function: '<S1>/Startposition' */
    row = A_search_minimum_o(diff_x);
    col = A_search_minimum_o(diff_y);
    for (h = 0; h < 20; h++) {
      diff_x_0[h] = (diff_x[h] == row);
    }

    A_search_eml_find_l(diff_x_0, ia_data, &actualNeighbor);
    for (h = 0; h < 20; h++) {
      diff_x_0[h] = (diff_y[h] == col);
    }

    A_search_eml_find_l(diff_x_0, ib_data, &i);
    tmp_size = actualNeighbor;
    for (h = 0; h < actualNeighbor; h++) {
      diff_x[h] = ia_data[h];
    }

    tmp_size_0 = i;
    for (h = 0; h < i; h++) {
      diff_y[h] = ib_data[h];
    }

    A_search_emxInit_int32_T(&Graph_Underlying_Ir, 2);

    /* MATLAB Function: '<S1>/Startposition' */
    A_search_do_vectors_n(diff_x, &tmp_size, diff_y, &tmp_size_0,
                          startKnotenArray_data, &h, ia_data, &actualNeighbor,
                          ib_data, &i);
    A_search_B->startKnoten = startKnotenArray_data[0];

    /* MATLAB Function: '<S1>/A-Stern-Algorithmus' */
    A_search_graph_graph(A_search_B->A, Graph_Underlying_Ir,
                         Graph_Underlying_Jc_data, &actualNeighbor,
                         Graph_Underlying_Diag_data, &i,
                         &A_search_B->Graph_EdgeProperties_data, A_search_B);
    std::memset(&openList[0], 0, 120U * sizeof(real_T));
    openList[0] = A_search_B->startKnoten;
    std::memset(&closedList[0], 0, 120U * sizeof(real_T));
    openList[30] = 0.0;
    std::memset(&diff_x[0], 0, 20U * sizeof(real_T));
    diff_x[static_cast<int32_T>(A_search_B->startKnoten) - 1] = 0.0;
    openList[60] = 0.0;
    row = 0.0;
    col = 1.0;
    nextNode = A_search_B->startKnoten;
    actualNode = 0.0;
    inClosedList = false;
    inOpenList = false;
    A_search_emxInit_real_T(&searchedRow, 1);
    A_search_emxInit_int32_T1(&ia, 1);
    A_search_emxInit_int32_T1(&ib, 1);
    A_search_emxInit_real_T1(&assign_temp_data_f1, 2);
    A_search_emxInit_real_T1(&assign_temp_data_f1_0, 2);
    A_search_emxInit_boolean_T(&assign_temp_data_f1_1, 2);
    A_search_emxInit_real_T(&tmp, 1);
    A_search_emxInit_real_T(&tmp_0, 1);
    exitg1 = false;
    while ((!exitg1) && (nextNode != A_search_B->TCModuleInput1)) {
      real_T b_fmin;
      i = 0;
      while ((i < 30) && (openList[i] != 0.0)) {
        actualNode = openList[i];
        if (openList[i] > 1.0) {
          A_search_graphBase_get_Edges(Graph_Underlying_Ir,
            Graph_Underlying_Jc_data, Graph_Underlying_Diag_data,
            &A_search_B->Graph_EdgeProperties_data, &expl_temp.__dummy,
            assign_temp_data_f1, A_search_B->expl_temp_data, &actualNeighbor);
          A_search_graphBase_get_Edges(Graph_Underlying_Ir,
            Graph_Underlying_Jc_data, Graph_Underlying_Diag_data,
            &A_search_B->Graph_EdgeProperties_data, &expl_temp.__dummy,
            assign_temp_data_f1_0, A_search_B->expl_temp_data, &actualNeighbor);
          h = assign_temp_data_f1_1->size[0] * assign_temp_data_f1_1->size[1];
          assign_temp_data_f1_1->size[0] = assign_temp_data_f1->size[0];
          assign_temp_data_f1_1->size[1] = 2;
          A_s_emxEnsureCapacity_boolean_T(assign_temp_data_f1_1, h);
          tmp_size = assign_temp_data_f1->size[0] << 1;
          for (h = 0; h < tmp_size; h++) {
            assign_temp_data_f1_1->data[h] = (assign_temp_data_f1->data[h] ==
              nextNode);
          }

          A_search_eml_find(assign_temp_data_f1_1, ia);
          b_fmin = openList[i];
          h = assign_temp_data_f1_1->size[0] * assign_temp_data_f1_1->size[1];
          assign_temp_data_f1_1->size[0] = assign_temp_data_f1_0->size[0];
          assign_temp_data_f1_1->size[1] = 2;
          A_s_emxEnsureCapacity_boolean_T(assign_temp_data_f1_1, h);
          tmp_size = assign_temp_data_f1_0->size[0] << 1;
          for (h = 0; h < tmp_size; h++) {
            assign_temp_data_f1_1->data[h] = (assign_temp_data_f1_0->data[h] ==
              b_fmin);
          }

          A_search_eml_find(assign_temp_data_f1_1, ib);
          h = tmp->size[0];
          tmp->size[0] = ia->size[0];
          A_sear_emxEnsureCapacity_real_T(tmp, h);
          tmp_size = ia->size[0];
          for (h = 0; h < tmp_size; h++) {
            tmp->data[h] = ia->data[h];
          }

          h = tmp_0->size[0];
          tmp_0->size[0] = ib->size[0];
          A_sear_emxEnsureCapacity_real_T(tmp_0, h);
          tmp_size = ib->size[0];
          for (h = 0; h < tmp_size; h++) {
            tmp_0->data[h] = ib->data[h];
          }

          A_search_do_vectors(tmp, tmp_0, searchedRow, ia, ib);
          if (openList[i + 30] == 0.0) {
            A_search_graphBase_get_Edges(Graph_Underlying_Ir,
              Graph_Underlying_Jc_data, Graph_Underlying_Diag_data,
              &A_search_B->Graph_EdgeProperties_data, &expl_temp.__dummy,
              assign_temp_data_f1, A_search_B->expl_temp_data, &actualNeighbor);
            h = static_cast<int32_T>(openList[i]) - 1;
            diff_x[h] = A_search_B->expl_temp_data[static_cast<int32_T>
              (searchedRow->data[0]) - 1] + row;
            openList[i + 30] = diff_x[h] + static_cast<real_T>(b_h[h]);
          }
        }

        i++;
      }

      if (actualNode > 1.0) {
        for (i = 0; i < 30; i++) {
          row = openList[i + 30];
          if (row == 0.0) {
            row = (rtNaN);
          }

          Z[i] = row;
        }

        b_fmin = A_search_minimum(Z);
        for (h = 0; h < 30; h++) {
          openList_0[h] = (openList[h + 30] == b_fmin);
        }

        A_search_eml_find_c(openList_0, tmp_data, &tmp_size);
        nextNode = openList[tmp_data[0] - 1];
        row = diff_x[static_cast<int32_T>(nextNode) - 1];
      } else {
        b_fmin = 0.0;
        nextNode = A_search_B->startKnoten;
        row = 0.0;
      }

      if (nextNode == A_search_B->TCModuleInput1) {
        exitg1 = true;
      } else {
        closedList[static_cast<int32_T>(col) - 1] = nextNode;
        closedList[static_cast<int32_T>(col) + 29] = b_fmin;
        closedList[static_cast<int32_T>(col) + 59] = row;
        if (col > 1.0) {
          closedList[static_cast<int32_T>(col) + 89] = closedList
            [static_cast<int32_T>(col - 1.0) - 1];
        }

        for (h = 0; h < 30; h++) {
          openList_0[h] = (openList[h] == nextNode);
        }

        A_search_eml_find_c(openList_0, tmp_data, &actualNeighbor);
        for (h = 0; h < 4; h++) {
          for (tmp_size = 0; tmp_size < actualNeighbor; tmp_size++) {
            openList[(tmp_data[tmp_size] + 30 * h) - 1] = 0.0;
          }
        }

        col++;
        i = Graph_Underlying_Jc_data[static_cast<int32_T>(nextNode) - 1];
        h = Graph_Underlying_Jc_data[static_cast<int32_T>(nextNode + 1.0) - 1];
        if (i + 1 > h) {
          i = 0;
          h = 0;
        }

        A_search_graphBase_get_Edges(Graph_Underlying_Ir,
          Graph_Underlying_Jc_data, Graph_Underlying_Diag_data,
          &A_search_B->Graph_EdgeProperties_data, &expl_temp.__dummy,
          assign_temp_data_f1, A_search_B->expl_temp_data, &actualNeighbor);
        A_search_eml_find_cr(assign_temp_data_f1, nextNode, ia_data,
                             &actualNeighbor);
        h = (h - i) - 1;
        if (0 <= h) {
          A_search_graphBase_get_Edges(Graph_Underlying_Ir,
            Graph_Underlying_Jc_data, Graph_Underlying_Diag_data,
            &A_search_B->Graph_EdgeProperties_data, &expl_temp.__dummy,
            assign_temp_data_f1, A_search_B->expl_temp_data, &actualNeighbor);
        }

        for (tmp_size_0 = 0; tmp_size_0 <= h; tmp_size_0++) {
          int32_T actualNeighbor_tmp;
          actualNeighbor_tmp = i + tmp_size_0;
          actualNeighbor = Graph_Underlying_Ir->data[actualNeighbor_tmp];
          b_fmin = A_search_B->expl_temp_data[ia_data[tmp_size_0] - 1] + row;
          for (tmp_size = 0; tmp_size < 30; tmp_size++) {
            inClosedList = ((closedList[tmp_size] == actualNeighbor) ||
                            inClosedList);
            inOpenList = ((openList[tmp_size] == actualNeighbor) || inOpenList);
          }

          if ((b_fmin < row) && inClosedList) {
            int32_T Graph_Underlying_Ir_0;
            boolean_T y;
            Graph_Underlying_Ir_0 = Graph_Underlying_Ir->data[actualNeighbor_tmp];
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              y = (closedList[tmp_size] == Graph_Underlying_Ir_0);
              if (y) {
                actualNeighbor++;
              }

              openList_0[tmp_size] = y;
            }

            Graph_Underlying_Ir_0 = actualNeighbor;
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              if (openList_0[tmp_size]) {
                c_data[actualNeighbor] = static_cast<int8_T>(tmp_size + 1);
                actualNeighbor++;
              }
            }

            for (tmp_size = 0; tmp_size < Graph_Underlying_Ir_0; tmp_size++) {
              closedList[c_data[tmp_size] + 59] = b_fmin;
            }

            Graph_Underlying_Ir_0 = Graph_Underlying_Ir->data[actualNeighbor_tmp];
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              y = (closedList[tmp_size] == Graph_Underlying_Ir_0);
              if (y) {
                actualNeighbor++;
              }

              openList_0[tmp_size] = y;
            }

            actualNeighbor_tmp = actualNeighbor;
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              if (openList_0[tmp_size]) {
                e_data[actualNeighbor] = static_cast<int8_T>(tmp_size + 1);
                actualNeighbor++;
              }
            }

            for (tmp_size = 0; tmp_size < actualNeighbor_tmp; tmp_size++) {
              closedList[e_data[tmp_size] + 89] = nextNode;
            }
          } else if ((b_fmin < row) && inOpenList) {
            int32_T Graph_Underlying_Ir_0;
            boolean_T y;
            Graph_Underlying_Ir_0 = Graph_Underlying_Ir->data[actualNeighbor_tmp];
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              y = (openList[tmp_size] == Graph_Underlying_Ir_0);
              if (y) {
                actualNeighbor++;
              }

              openList_0[tmp_size] = y;
            }

            Graph_Underlying_Ir_0 = actualNeighbor;
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              if (openList_0[tmp_size]) {
                d_data[actualNeighbor] = static_cast<int8_T>(tmp_size + 1);
                actualNeighbor++;
              }
            }

            for (tmp_size = 0; tmp_size < Graph_Underlying_Ir_0; tmp_size++) {
              openList[d_data[tmp_size] + 59] = b_fmin;
            }

            Graph_Underlying_Ir_0 = Graph_Underlying_Ir->data[actualNeighbor_tmp];
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              y = (openList[tmp_size] == Graph_Underlying_Ir_0);
              if (y) {
                actualNeighbor++;
              }

              openList_0[tmp_size] = y;
            }

            actualNeighbor_tmp = actualNeighbor;
            actualNeighbor = 0;
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              if (openList_0[tmp_size]) {
                f_data[actualNeighbor] = static_cast<int8_T>(tmp_size + 1);
                actualNeighbor++;
              }
            }

            for (tmp_size = 0; tmp_size < actualNeighbor_tmp; tmp_size++) {
              openList[f_data[tmp_size] + 89] = nextNode;
            }
          } else {
            int32_T Graph_Underlying_Ir_0;
            boolean_T exitg2;
            boolean_T guard1{ false };

            boolean_T y;
            Graph_Underlying_Ir_0 = Graph_Underlying_Ir->data[actualNeighbor_tmp];
            for (tmp_size = 0; tmp_size < 30; tmp_size++) {
              openList_0[tmp_size] = (closedList[tmp_size] ==
                Graph_Underlying_Ir_0);
            }

            y = false;
            tmp_size = 0;
            exitg2 = false;
            while ((!exitg2) && (tmp_size < 30)) {
              if (openList_0[tmp_size]) {
                y = true;
                exitg2 = true;
              } else {
                tmp_size++;
              }
            }

            guard1 = false;
            if (y) {
              Graph_Underlying_Ir_0 = Graph_Underlying_Ir->
                data[actualNeighbor_tmp];
              for (tmp_size = 0; tmp_size < 30; tmp_size++) {
                openList_0[tmp_size] = (openList[tmp_size] ==
                  Graph_Underlying_Ir_0);
              }

              y = false;
              tmp_size = 0;
              exitg2 = false;
              while ((!exitg2) && (tmp_size < 30)) {
                if (openList_0[tmp_size]) {
                  y = true;
                  exitg2 = true;
                } else {
                  tmp_size++;
                }
              }

              if (y) {
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              for (tmp_size = 0; tmp_size < 30; tmp_size++) {
                openList_0[tmp_size] = (openList[tmp_size] == 0.0);
              }

              A_search_eml_find_c(openList_0, tmp_data, &actualNeighbor);
              openList[tmp_data[0] - 1] = Graph_Underlying_Ir->
                data[actualNeighbor_tmp];
              openList[tmp_data[0] + 59] = b_fmin;
            }
          }
        }
      }
    }

    A_search_emxFree_real_T(&tmp_0);
    A_search_emxFree_real_T(&tmp);
    A_search_emxFree_boolean_T(&assign_temp_data_f1_1);
    A_search_emxFree_real_T(&assign_temp_data_f1_0);
    A_search_emxFree_real_T(&assign_temp_data_f1);
    A_search_emxFree_int32_T(&ib);
    A_search_emxFree_int32_T(&ia);
    A_search_emxFree_real_T(&searchedRow);
    A_search_emxFree_int32_T(&Graph_Underlying_Ir);

    /* MATLAB Function: '<S1>/A-Stern-Algorithmus' */
    closedList[static_cast<int32_T>(col) - 1] = A_search_B->TCModuleInput1;
    std::memset(&A_search_B->wayPointList[0], 0, 20U * sizeof(real_T));
    for (i = 0; i < static_cast<int32_T>(col); i++) {
      A_search_B->wayPointList[i] = closedList[i];
    }

    /* MATLAB Function: '<S1>/koordinatenListe' */
    for (i = 0; i < 20; i++) {
      h = static_cast<int32_T>(A_search_B->wayPointList[i]) - 1;
      A_search_B->xKoordinaten[i] = A_search_B->xKnoten[h];
      A_search_B->yKoordinaten[i] = A_search_B->yKnoten[h];
    }

    /* End of MATLAB Function: '<S1>/koordinatenListe' */
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Update for S-Function (TcModuleInOut): '<Root>/TC Module Output' */
  if (A_search_DW->TCModuleOutput_PWORK != NULL) {
    memcpy(A_search_DW->TCModuleOutput_PWORK, &A_search_B->xKoordinaten[0], 160);
  }

  /* Update for S-Function (TcModuleInOut): '<Root>/TC Module Output1' */
  if (A_search_DW->TCModuleOutput1_PWORK != NULL) {
    memcpy(A_search_DW->TCModuleOutput1_PWORK, &A_search_B->yKoordinaten[0], 160);
  }
}

/* Model initialize function */
void A_search_initialize(RT_MODEL_A_search_T *const A_search_M)
{
  B_A_search_T *A_search_B{ A_search_M->blockIO };

  /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S1>/xKoordinaten' */
  std::memset(&A_search_B->xKoordinaten[0], 0, 20U * sizeof(real_T));

  /* SystemInitialize for Outport: '<S1>/yKoordinaten' */
  std::memset(&A_search_B->yKoordinaten[0], 0, 20U * sizeof(real_T));

  /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */
}

/* Model terminate function */
void A_search_terminate(RT_MODEL_A_search_T * A_search_M)
{
  /* model code */
  rt_FREE(A_search_M->blockIO);
  rt_FREE(A_search_M->dwork);
  delete A_search_M;
}

/* Model data allocation function */
RT_MODEL_A_search_T *A_search(void)
{
  RT_MODEL_A_search_T *A_search_M;
  A_search_M = new RT_MODEL_A_search_T();
  if (A_search_M == (nullptr)) {
    return (nullptr);
  }

  /* block I/O */
  {
    B_A_search_T *b{ (B_A_search_T *) malloc(sizeof(B_A_search_T)) };

    rt_VALIDATE_MEMORY(A_search_M,b);
    A_search_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_A_search_T *dwork{ static_cast<DW_A_search_T *>(malloc(sizeof
      (DW_A_search_T))) };

    rt_VALIDATE_MEMORY(A_search_M,dwork);
    A_search_M->dwork = (dwork);
  }

  {
    B_A_search_T *A_search_B{ A_search_M->blockIO };

    DW_A_search_T *A_search_DW{ A_search_M->dwork };

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));

    /* block I/O */
    (void) std::memset((static_cast<void *>(A_search_B)), 0,
                       sizeof(B_A_search_T));

    /* states (dwork) */
    (void) std::memset(static_cast<void *>(A_search_DW), 0,
                       sizeof(DW_A_search_T));
  }

  return A_search_M;
}
