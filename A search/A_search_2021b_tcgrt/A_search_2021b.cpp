/*
 * A_search_2021b.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "A_search_2021b".
 *
 * Model version              : 1.12
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Mar 23 17:25:46 2023
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "A_search_2021b.h"
#include "A_search_2021b_private.h"

/* Function for MATLAB Function: '<S1>/Graph erstellen' */
real_T A_search_2021bModelClass::A_search_2021b_mod(real_T x)
{
  real_T r;
  if (std::isnan(x) || std::isinf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = std::fmod(x, 18.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 18.0;
    }
  }

  return r;
}

/* Function for MATLAB Function: '<S1>/Startposition' */
real_T A_search_2021bModelClass::A_search_2021b_minimum(const real_T x[144])
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
    while ((!exitg1) && (k < 145)) {
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
    while (idx + 1 < 145) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S1>/Startposition' */
void A_search_2021bModelClass::A_search_2021b_eml_find(const boolean_T x[144],
  int32_T i_data[], int32_T *i_size)
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 144)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 144) {
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

/* Function for MATLAB Function: '<S1>/Startposition' */
real_T A_search_2021bModelClass::A_sear_skip_to_last_equal_value(int32_T *k,
  const real_T x_data[], const int32_T *x_size)
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
void A_search_2021bModelClass::A_search_2021b_do_vectors(const real_T a_data[],
  const int32_T *a_size, const real_T b_data[], const int32_T *b_size, real_T
  c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T
  ib_data[], int32_T *ib_size)
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
    ak = A_sear_skip_to_last_equal_value(&b_ialast, a_data, a_size);
    ialast = b_ialast;
    b_iblast = iblast;
    bk = A_sear_skip_to_last_equal_value(&b_iblast, b_data, b_size);
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

/* Model step function */
void A_search_2021bModelClass::step()
{
  static const uint8_T b_0[12]{ 93U, 96U, 99U, 102U, 111U, 114U, 117U, 120U,
    124U, 125U, 142U, 143U };

  real_T diff_x[144];
  real_T diff_y[144];
  real_T startKnotenArray_data[144];
  real_T neighborList[40];
  real_T openList_data[40];
  real_T b_fmin;
  real_T b_fmin_tmp;
  real_T col;
  real_T f;
  real_T g;
  real_T gprev;
  real_T h;
  real_T h_tmp;
  real_T parentNode;
  real_T row;
  int32_T ia_data[144];
  int32_T ib_data[144];
  int32_T i;
  int32_T ib_size;
  int32_T nodefmin;
  int32_T nrows;
  int32_T tmp_size;
  boolean_T diff_x_0[144];
  boolean_T exitg1;
  boolean_T noHinderance;
  boolean_T overlap;

  /* S-Function (TcModuleInOut): '<Root>/xRobotStart' */
  if (A_search_2021b_DW.xRobotStart_PWORK != NULL) {
    A_search_2021b_B.xRobotStart = *((real_T*)
      A_search_2021b_DW.xRobotStart_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/yRobotStart' */
  if (A_search_2021b_DW.yRobotStart_PWORK != NULL) {
    A_search_2021b_B.yRobotStart = *((real_T*)
      A_search_2021b_DW.yRobotStart_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/xGoalEnd' */
  if (A_search_2021b_DW.xGoalEnd_PWORK != NULL) {
    A_search_2021b_B.xGoalEnd = *((real_T*)A_search_2021b_DW.xGoalEnd_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/yGoalEnd' */
  if (A_search_2021b_DW.yGoalEnd_PWORK != NULL) {
    A_search_2021b_B.yGoalEnd = *((real_T*)A_search_2021b_DW.yGoalEnd_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/endNode' */
  if (A_search_2021b_DW.endNode_PWORK != NULL) {
    A_search_2021b_B.endNode = *((real_T*)A_search_2021b_DW.endNode_PWORK);
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* MATLAB Function: '<S1>/Graph erstellen' */
  for (nrows = 0; nrows < 12; nrows++) {
    A_search_2021b_B.removeNode[nrows] = b_0[nrows];
  }

  std::memset(&A_search_2021b_B.A[0], 0, 20736U * sizeof(real_T));
  for (i = 0; i < 144; i++) {
    if ((i > 0) && (A_search_2021b_mod(static_cast<real_T>(i) + 1.0) != 1.0)) {
      A_search_2021b_B.A[(i + 144 * i) - 1] = 1000.0;
    }

    if ((i + 2 < 145) && (A_search_2021b_mod(static_cast<real_T>(i) + 1.0) !=
                          0.0)) {
      A_search_2021b_B.A[(i + 144 * i) + 1] = 1000.0;
    }

    if (i + 19 < 145) {
      A_search_2021b_B.A[(i + 144 * i) + 18] = 1000.0;
    }

    if (i - 17 > 0) {
      A_search_2021b_B.A[(i + 144 * i) - 18] = 1000.0;
    }

    if ((i + 20 < 145) && (A_search_2021b_mod(static_cast<real_T>(i) + 1.0) !=
                           0.0)) {
      A_search_2021b_B.A[(i + 144 * i) + 19] = 1414.2135623730951;
    }

    if ((i + 18 < 145) && (A_search_2021b_mod(static_cast<real_T>(i) + 1.0) !=
                           1.0)) {
      A_search_2021b_B.A[(i + 144 * i) + 17] = 1414.2135623730951;
    }

    if ((i - 16 > 0) && (A_search_2021b_mod(static_cast<real_T>(i) + 1.0) != 1.0))
    {
      A_search_2021b_B.A[(i + 144 * i) - 17] = 1414.2135623730951;
    }

    if ((i - 18 > 0) && (A_search_2021b_mod(static_cast<real_T>(i) + 1.0) != 0.0))
    {
      A_search_2021b_B.A[(i + 144 * i) - 19] = 1414.2135623730951;
    }
  }

  for (nrows = 0; nrows < 12; nrows++) {
    uint8_T b;
    b = b_0[nrows];
    for (i = 0; i < 144; i++) {
      A_search_2021b_B.A[(b + 144 * i) - 1] = 0.0;
      A_search_2021b_B.A[i + 144 * (b - 1)] = 0.0;
    }
  }

  row = 600.0;
  col = 200.0;
  for (nrows = 0; nrows < 144; nrows++) {
    A_search_2021b_B.xKnoten[nrows] = col;
    A_search_2021b_B.yKnoten[nrows] = row;
    col += 400.0;
    if (A_search_2021b_mod(static_cast<real_T>(nrows) + 1.0) == 0.0) {
      col = 200.0;
      row += 400.0;
    }

    /* MATLAB Function: '<S1>/Startposition' */
    diff_x[nrows] = std::abs(A_search_2021b_B.xRobotStart -
      A_search_2021b_B.xKnoten[nrows]);
    diff_y[nrows] = std::abs(A_search_2021b_B.yRobotStart -
      A_search_2021b_B.yKnoten[nrows]);
  }

  /* End of MATLAB Function: '<S1>/Graph erstellen' */

  /* MATLAB Function: '<S1>/Startposition' */
  row = A_search_2021b_minimum(diff_x);
  col = A_search_2021b_minimum(diff_y);
  for (nrows = 0; nrows < 144; nrows++) {
    diff_x_0[nrows] = (diff_x[nrows] == row);
  }

  A_search_2021b_eml_find(diff_x_0, ia_data, &i);
  for (nrows = 0; nrows < 144; nrows++) {
    diff_x_0[nrows] = (diff_y[nrows] == col);
  }

  A_search_2021b_eml_find(diff_x_0, ib_data, &ib_size);
  nodefmin = i;
  for (nrows = 0; nrows < i; nrows++) {
    diff_x[nrows] = ia_data[nrows];
  }

  tmp_size = ib_size;
  for (nrows = 0; nrows < ib_size; nrows++) {
    diff_y[nrows] = ib_data[nrows];
  }

  A_search_2021b_do_vectors(diff_x, &nodefmin, diff_y, &tmp_size,
    startKnotenArray_data, &nrows, ia_data, &i, ib_data, &ib_size);
  A_search_2021b_B.startKnoten = startKnotenArray_data[0];

  /* MATLAB Function: '<S1>/A-Stern-Algorithmus' */
  ib_size = 8;
  std::memset(&openList_data[0], 0, 40U * sizeof(real_T));
  std::memset(&A_search_2021b_B.closedList[0], 0, 720U * sizeof(real_T));
  row = 1.0;
  overlap = false;
  nodefmin = -1;
  col = A_search_2021b_B.startKnoten;
  parentNode = 0.0;
  g = 0.0;
  gprev = 0.0;
  b_fmin_tmp = A_search_2021b_B.xKnoten[static_cast<int32_T>
    (A_search_2021b_B.startKnoten) - 1];
  b_fmin = b_fmin_tmp - A_search_2021b_B.xGoalEnd;
  h_tmp = A_search_2021b_B.yKnoten[static_cast<int32_T>
    (A_search_2021b_B.startKnoten) - 1];
  h = h_tmp - A_search_2021b_B.yGoalEnd;
  h = std::sqrt(b_fmin * b_fmin + h * h);
  f = h;
  b_fmin = 0.0;
  while (col != A_search_2021b_B.endNode) {
    boolean_T flag;
    nrows = 0;
    exitg1 = false;
    while ((!exitg1) && (nrows < 14)) {
      if (col != A_search_2021b_B.removeNode[nrows]) {
        noHinderance = true;
        nrows++;
      } else {
        noHinderance = false;
        exitg1 = true;
      }
    }

    if (noHinderance) {
      A_search_2021b_B.closedList[static_cast<int32_T>(row) - 1] = col;
      A_search_2021b_B.closedList[static_cast<int32_T>(row) + 143] = g;
      A_search_2021b_B.closedList[static_cast<int32_T>(row) + 287] = h;
      A_search_2021b_B.closedList[static_cast<int32_T>(row) + 431] = f;
      A_search_2021b_B.closedList[static_cast<int32_T>(row) + 575] = parentNode;
      row++;
      ib_size = 8;
      std::memset(&openList_data[0], 0, 40U * sizeof(real_T));
      std::memset(&neighborList[0], 0, 40U * sizeof(real_T));
      parentNode = 1.0;
      for (i = 0; i < 144; i++) {
        if (A_search_2021b_B.A[(144 * i + static_cast<int32_T>(col)) - 1] != 0.0)
        {
          g = A_search_2021b_B.xKnoten[i] - b_fmin_tmp;
          h = A_search_2021b_B.yKnoten[i] - h_tmp;
          g = std::sqrt(g * g + h * h) + gprev;
          h = A_search_2021b_B.xKnoten[i] - A_search_2021b_B.xGoalEnd;
          f = A_search_2021b_B.yKnoten[i] - A_search_2021b_B.yGoalEnd;
          h = std::sqrt(h * h + f * f);
          neighborList[static_cast<int32_T>(parentNode) - 1] =
            static_cast<real_T>(i) + 1.0;
          neighborList[static_cast<int32_T>(parentNode) + 7] = g;
          neighborList[static_cast<int32_T>(parentNode) + 15] = h;
          neighborList[static_cast<int32_T>(parentNode) + 23] = g + h;
          neighborList[static_cast<int32_T>(parentNode) + 31] = col;
          parentNode++;
        }
      }

      for (nrows = 0; nrows < 8; nrows++) {
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 144)) {
          if (neighborList[nrows] == A_search_2021b_B.closedList[i]) {
            overlap = true;
            exitg1 = true;
          } else {
            i++;
          }
        }

        if (!overlap) {
          openList_data[nrows] = neighborList[nrows];
          openList_data[nrows + 8] = neighborList[nrows + 8];
          openList_data[nrows + 16] = neighborList[nrows + 16];
          openList_data[nrows + 24] = neighborList[nrows + 24];
          openList_data[nrows + 32] = neighborList[nrows + 32];
        }

        overlap = false;
      }
    } else {
      int32_T d_i;
      i = ib_size - 2;
      for (tmp_size = 0; tmp_size < 5; tmp_size++) {
        for (d_i = nodefmin; d_i < ib_size - 1; d_i++) {
          nrows = ib_size * tmp_size;
          openList_data[d_i + nrows] = openList_data[(d_i + nrows) + 1];
        }
      }

      if (1 > ib_size - 1) {
        i = -1;
        nrows = -1;
      } else {
        nrows = ib_size - 2;
      }

      tmp_size = nrows + 1;
      for (nrows = 0; nrows < 5; nrows++) {
        for (d_i = 0; d_i < tmp_size; d_i++) {
          openList_data[d_i + (i + 1) * nrows] = openList_data[ib_size * nrows +
            d_i];
        }
      }

      ib_size = i + 1;
    }

    flag = false;
    for (i = 0; i < ib_size; i++) {
      col = openList_data[ib_size * 3 + i];
      if (col != 0.0) {
        if (!flag) {
          b_fmin = col;
          nodefmin = i;
          flag = true;
        }

        if (b_fmin > col) {
          b_fmin = col;
          nodefmin = i;
        }
      }
    }

    col = openList_data[nodefmin];
    g = openList_data[nodefmin + ib_size];
    h = openList_data[(ib_size << 1) + nodefmin];
    f = openList_data[ib_size * 3 + nodefmin];
    parentNode = openList_data[(ib_size << 2) + nodefmin];
    gprev = g;
  }

  A_search_2021b_B.closedList[static_cast<int32_T>(row) - 1] = col;
  A_search_2021b_B.closedList[static_cast<int32_T>(row) + 143] = g;
  A_search_2021b_B.closedList[static_cast<int32_T>(row) + 287] = h;
  A_search_2021b_B.closedList[static_cast<int32_T>(row) + 431] = f;
  A_search_2021b_B.closedList[static_cast<int32_T>(row) + 575] = parentNode;
  std::memset(&A_search_2021b_B.wayPointList[0], 0, 144U * sizeof(real_T));
  for (nodefmin = 0; nodefmin < static_cast<int32_T>(row); nodefmin++) {
    A_search_2021b_B.wayPointList[nodefmin] =
      A_search_2021b_B.closedList[nodefmin];
  }

  /* End of MATLAB Function: '<S1>/A-Stern-Algorithmus' */

  /* MATLAB Function: '<S1>/koordinatenListe' */
  for (i = 0; i < 144; i++) {
    A_search_2021b_B.xKoordinaten[i] = 0.0;
    A_search_2021b_B.yKoordinaten[i] = 0.0;
    overlap = true;
    nodefmin = 0;
    exitg1 = false;
    while ((!exitg1) && (nodefmin < 144)) {
      if (!(A_search_2021b_B.wayPointList[nodefmin] != 0.0)) {
        overlap = false;
        exitg1 = true;
      } else {
        nodefmin++;
      }
    }

    if (overlap) {
      nodefmin = static_cast<int32_T>(A_search_2021b_B.wayPointList[i]) - 1;
      A_search_2021b_B.xKoordinaten[i] = A_search_2021b_B.xKnoten[nodefmin];
      A_search_2021b_B.yKoordinaten[i] = A_search_2021b_B.yKnoten[nodefmin];
    }
  }

  /* End of MATLAB Function: '<S1>/koordinatenListe' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Update for S-Function (TcModuleInOut): '<Root>/xPointList' */
  if (A_search_2021b_DW.xPointList_PWORK != NULL) {
    memcpy(A_search_2021b_DW.xPointList_PWORK, &A_search_2021b_B.xKoordinaten[0],
           1152);
  }

  /* Update for S-Function (TcModuleInOut): '<Root>/yPointList' */
  if (A_search_2021b_DW.yPointList_PWORK != NULL) {
    memcpy(A_search_2021b_DW.yPointList_PWORK, &A_search_2021b_B.yKoordinaten[0],
           1152);
  }
}

/* Model initialize function */
void A_search_2021bModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void A_search_2021bModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
A_search_2021bModelClass::A_search_2021bModelClass() :
  A_search_2021b_B(),
  A_search_2021b_DW(),
  A_search_2021b_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
A_search_2021bModelClass::~A_search_2021bModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_A_search_2021b_T * A_search_2021bModelClass::getRTM()
{
  return (&A_search_2021b_M);
}
