/*
 * A_Search.cpp
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

#include "A_Search.h"
#include "A_Search_private.h"

/* Forward declaration for local functions */
static real_T A_Search_mod(real_T x);
static real_T A_Search_minimum(const real_T x[144]);
static void A_Search_eml_find(const boolean_T x[144], int32_T i_data[], int32_T *
  i_size);
static real_T A_Sear_skip_to_last_equal_value(int32_T *k, const real_T x_data[],
  const int32_T *x_size);
static void A_Search_do_vectors(const real_T a_data[], const int32_T *a_size,
  const real_T b_data[], const int32_T *b_size, real_T c_data[], int32_T *c_size,
  int32_T ia_data[], int32_T *ia_size, int32_T ib_data[], int32_T *ib_size);

/* Function for MATLAB Function: '<S1>/ Create the matrix' */
static real_T A_Search_mod(real_T x)
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

/* Function for MATLAB Function: '<S1>/Start pose of robot' */
static real_T A_Search_minimum(const real_T x[144])
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

/* Function for MATLAB Function: '<S1>/Start pose of robot' */
static void A_Search_eml_find(const boolean_T x[144], int32_T i_data[], int32_T *
  i_size)
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

/* Function for MATLAB Function: '<S1>/Start pose of robot' */
static real_T A_Sear_skip_to_last_equal_value(int32_T *k, const real_T x_data[],
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

/* Function for MATLAB Function: '<S1>/Start pose of robot' */
static void A_Search_do_vectors(const real_T a_data[], const int32_T *a_size,
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
    ak = A_Sear_skip_to_last_equal_value(&b_ialast, a_data, a_size);
    ialast = b_ialast;
    b_iblast = iblast;
    bk = A_Sear_skip_to_last_equal_value(&b_iblast, b_data, b_size);
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
void A_Search_step(RT_MODEL_A_Search_T *const A_Search_M)
{
  B_A_Search_T *A_Search_B{ A_Search_M->blockIO };

  DW_A_Search_T *A_Search_DW{ A_Search_M->dwork };

  static const uint8_T b_0[12]{ 93U, 96U, 99U, 102U, 111U, 114U, 117U, 120U,
    124U, 125U, 142U, 143U };

  real_T closedList[505];
  real_T diff_x[144];
  real_T diff_y[144];
  real_T startNodeArray_data[144];
  real_T neighborList[40];
  real_T openList_data[40];
  int32_T ia_data[144];
  int32_T ib_data[144];
  int32_T i;
  int32_T i_0;
  int32_T nodefmin;
  int32_T nrows;
  int32_T tmp_size;
  boolean_T diff_x_0[144];
  boolean_T noHinderance;

  /* S-Function (TcModuleInOut): '<Root>/xRobotStart' */
  if (A_Search_DW->xRobotStart_PWORK != NULL) {
    A_Search_B->xRobotStart = *((real_T*)A_Search_DW->xRobotStart_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/yRobotStart' */
  if (A_Search_DW->yRobotStart_PWORK != NULL) {
    A_Search_B->yRobotStart = *((real_T*)A_Search_DW->yRobotStart_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/xRobotEnd' */
  if (A_Search_DW->xRobotEnd_PWORK != NULL) {
    A_Search_B->xRobotEnd = *((real_T*)A_Search_DW->xRobotEnd_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/yRobotEnd' */
  if (A_Search_DW->yRobotEnd_PWORK != NULL) {
    A_Search_B->yRobotEnd = *((real_T*)A_Search_DW->yRobotEnd_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/endNode' */
  if (A_Search_DW->endNode_PWORK != NULL) {
    A_Search_B->endNode = *((real_T*)A_Search_DW->endNode_PWORK);
  }

  /* S-Function (TcModuleInOut): '<Root>/enable' */
  if (A_Search_DW->enable_PWORK != NULL) {
    A_Search_B->enable = *((boolean_T*)A_Search_DW->enable_PWORK);
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (A_Search_B->enable) {
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
    boolean_T overlap;

    /* MATLAB Function: '<S1>/ Create the matrix' */
    for (i_0 = 0; i_0 < 12; i_0++) {
      A_Search_B->removeNode[i_0] = b_0[i_0];
    }

    std::memset(&A_Search_B->matrix[0], 0, 20736U * sizeof(real_T));
    for (i_0 = 0; i_0 < 144; i_0++) {
      if ((i_0 > 0) && (A_Search_mod(static_cast<real_T>(i_0) + 1.0) != 1.0)) {
        A_Search_B->matrix[(i_0 + 144 * i_0) - 1] = 1000.0;
      }

      if ((i_0 + 2 < 145) && (A_Search_mod(static_cast<real_T>(i_0) + 1.0) !=
                              0.0)) {
        A_Search_B->matrix[(i_0 + 144 * i_0) + 1] = 1000.0;
      }

      if (i_0 + 19 < 145) {
        A_Search_B->matrix[(i_0 + 144 * i_0) + 18] = 1000.0;
      }

      if (i_0 - 17 > 0) {
        A_Search_B->matrix[(i_0 + 144 * i_0) - 18] = 1000.0;
      }

      if ((i_0 + 20 < 145) && (A_Search_mod(static_cast<real_T>(i_0) + 1.0) !=
           0.0)) {
        A_Search_B->matrix[(i_0 + 144 * i_0) + 19] = 1414.2135623730951;
      }

      if ((i_0 + 18 < 145) && (A_Search_mod(static_cast<real_T>(i_0) + 1.0) !=
           1.0)) {
        A_Search_B->matrix[(i_0 + 144 * i_0) + 17] = 1414.2135623730951;
      }

      if ((i_0 - 16 > 0) && (A_Search_mod(static_cast<real_T>(i_0) + 1.0) != 1.0))
      {
        A_Search_B->matrix[(i_0 + 144 * i_0) - 17] = 1414.2135623730951;
      }

      if ((i_0 - 18 > 0) && (A_Search_mod(static_cast<real_T>(i_0) + 1.0) != 0.0))
      {
        A_Search_B->matrix[(i_0 + 144 * i_0) - 19] = 1414.2135623730951;
      }
    }

    for (i = 0; i < 12; i++) {
      uint8_T b;
      b = b_0[i];
      for (i_0 = 0; i_0 < 144; i_0++) {
        A_Search_B->matrix[(b + 144 * i_0) - 1] = 0.0;
        A_Search_B->matrix[i_0 + 144 * (b - 1)] = 0.0;
      }
    }

    row = 600.0;
    col = 200.0;
    for (i = 0; i < 144; i++) {
      A_Search_B->xNode[i] = col;
      A_Search_B->yNode[i] = row;
      col += 400.0;
      if (A_Search_mod(static_cast<real_T>(i) + 1.0) == 0.0) {
        col = 200.0;
        row += 400.0;
      }

      /* MATLAB Function: '<S1>/Start pose of robot' */
      diff_x[i] = std::abs(A_Search_B->xRobotStart - A_Search_B->xNode[i]);
      diff_y[i] = std::abs(A_Search_B->yRobotStart - A_Search_B->yNode[i]);
    }

    /* End of MATLAB Function: '<S1>/ Create the matrix' */

    /* MATLAB Function: '<S1>/Start pose of robot' */
    row = A_Search_minimum(diff_x);
    col = A_Search_minimum(diff_y);
    for (i_0 = 0; i_0 < 144; i_0++) {
      diff_x_0[i_0] = (diff_x[i_0] == row);
    }

    A_Search_eml_find(diff_x_0, ia_data, &i);
    for (i_0 = 0; i_0 < 144; i_0++) {
      diff_x_0[i_0] = (diff_y[i_0] == col);
    }

    A_Search_eml_find(diff_x_0, ib_data, &nrows);
    tmp_size = i;
    for (i_0 = 0; i_0 < i; i_0++) {
      diff_x[i_0] = ia_data[i_0];
    }

    nodefmin = nrows;
    for (i_0 = 0; i_0 < nrows; i_0++) {
      diff_y[i_0] = ib_data[i_0];
    }

    A_Search_do_vectors(diff_x, &tmp_size, diff_y, &nodefmin,
                        startNodeArray_data, &i_0, ia_data, &i, ib_data, &nrows);
    A_Search_B->startNode = startNodeArray_data[0];

    /* MATLAB Function: '<S1>/A Search' */
    tmp_size = 8;
    std::memset(&openList_data[0], 0, 40U * sizeof(real_T));
    std::memset(&closedList[0], 0, 505U * sizeof(real_T));
    row = 1.0;
    overlap = false;
    nodefmin = -1;
    col = A_Search_B->startNode;
    parentNode = 0.0;
    g = 0.0;
    gprev = 0.0;
    b_fmin_tmp = A_Search_B->xNode[static_cast<int32_T>(A_Search_B->startNode) -
      1];
    b_fmin = b_fmin_tmp - A_Search_B->xRobotEnd;
    h_tmp = A_Search_B->yNode[static_cast<int32_T>(A_Search_B->startNode) - 1];
    h = h_tmp - A_Search_B->yRobotEnd;
    h = std::sqrt(b_fmin * b_fmin + h * h);
    f = h;
    b_fmin = 0.0;
    while (col != A_Search_B->endNode) {
      boolean_T exitg1;
      boolean_T flag;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 12)) {
        if (col != A_Search_B->removeNode[i]) {
          noHinderance = true;
          i++;
        } else {
          noHinderance = false;
          exitg1 = true;
        }
      }

      if (noHinderance) {
        closedList[static_cast<int32_T>(row) - 1] = col;
        closedList[static_cast<int32_T>(row) + 100] = g;
        closedList[static_cast<int32_T>(row) + 201] = h;
        closedList[static_cast<int32_T>(row) + 302] = f;
        closedList[static_cast<int32_T>(row) + 403] = parentNode;
        row++;
        tmp_size = 8;
        std::memset(&openList_data[0], 0, 40U * sizeof(real_T));
        std::memset(&neighborList[0], 0, 40U * sizeof(real_T));
        parentNode = 1.0;
        for (i_0 = 0; i_0 < 144; i_0++) {
          if (A_Search_B->matrix[(144 * i_0 + static_cast<int32_T>(col)) - 1] !=
              0.0) {
            g = A_Search_B->xNode[i_0] - b_fmin_tmp;
            h = A_Search_B->yNode[i_0] - h_tmp;
            g = std::sqrt(g * g + h * h) + gprev;
            h = A_Search_B->xNode[i_0] - A_Search_B->xRobotEnd;
            f = A_Search_B->yNode[i_0] - A_Search_B->yRobotEnd;
            h = std::sqrt(h * h + f * f);
            neighborList[static_cast<int32_T>(parentNode) - 1] =
              static_cast<real_T>(i_0) + 1.0;
            neighborList[static_cast<int32_T>(parentNode) + 7] = g;
            neighborList[static_cast<int32_T>(parentNode) + 15] = h;
            neighborList[static_cast<int32_T>(parentNode) + 23] = g + h;
            neighborList[static_cast<int32_T>(parentNode) + 31] = col;
            parentNode++;
          }
        }

        for (i = 0; i < 8; i++) {
          i_0 = 0;
          exitg1 = false;
          while ((!exitg1) && (i_0 < 101)) {
            if (neighborList[i] == closedList[i_0]) {
              overlap = true;
              exitg1 = true;
            } else {
              i_0++;
            }
          }

          if (!overlap) {
            openList_data[i] = neighborList[i];
            openList_data[i + 8] = neighborList[i + 8];
            openList_data[i + 16] = neighborList[i + 16];
            openList_data[i + 24] = neighborList[i + 24];
            openList_data[i + 32] = neighborList[i + 32];
          }

          overlap = false;
        }
      } else {
        int32_T loop_ub;
        i = tmp_size - 2;
        for (i_0 = 0; i_0 < 5; i_0++) {
          for (loop_ub = nodefmin; loop_ub < tmp_size - 1; loop_ub++) {
            nrows = tmp_size * i_0;
            openList_data[loop_ub + nrows] = openList_data[(loop_ub + nrows) + 1];
          }
        }

        if (1 > tmp_size - 1) {
          i = -1;
          i_0 = -1;
        } else {
          i_0 = tmp_size - 2;
        }

        loop_ub = i_0 + 1;
        for (i_0 = 0; i_0 < 5; i_0++) {
          for (nrows = 0; nrows < loop_ub; nrows++) {
            openList_data[nrows + (i + 1) * i_0] = openList_data[tmp_size * i_0
              + nrows];
          }
        }

        tmp_size = i + 1;
      }

      flag = false;
      for (i_0 = 0; i_0 < tmp_size; i_0++) {
        col = openList_data[tmp_size * 3 + i_0];
        if (col != 0.0) {
          if (!flag) {
            b_fmin = col;
            nodefmin = i_0;
            flag = true;
          }

          if (b_fmin > col) {
            b_fmin = col;
            nodefmin = i_0;
          }
        }
      }

      col = openList_data[nodefmin];
      g = openList_data[nodefmin + tmp_size];
      h = openList_data[(tmp_size << 1) + nodefmin];
      f = openList_data[tmp_size * 3 + nodefmin];
      parentNode = openList_data[(tmp_size << 2) + nodefmin];
      gprev = g;
    }

    closedList[static_cast<int32_T>(row) - 1] = col;
    closedList[static_cast<int32_T>(row) + 100] = g;
    closedList[static_cast<int32_T>(row) + 201] = h;
    closedList[static_cast<int32_T>(row) + 302] = f;
    closedList[static_cast<int32_T>(row) + 403] = parentNode;
    std::memset(&A_Search_B->wayPointList[0], 0, 101U * sizeof(real_T));
    for (nodefmin = 0; nodefmin < static_cast<int32_T>(row); nodefmin++) {
      A_Search_B->wayPointList[nodefmin] = closedList[nodefmin];
    }

    /* End of MATLAB Function: '<S1>/A Search' */

    /* MATLAB Function: '<S1>/List of coordinates' */
    for (i_0 = 0; i_0 < 101; i_0++) {
      A_Search_B->xKoordinaten[i_0] = 0.0;
      A_Search_B->yKoordinaten[i_0] = 0.0;
      if (A_Search_B->wayPointList[i_0] != 0.0) {
        i = static_cast<int32_T>(A_Search_B->wayPointList[i_0]) - 1;
        A_Search_B->xKoordinaten[i_0] = A_Search_B->xNode[i];
        A_Search_B->yKoordinaten[i_0] = A_Search_B->yNode[i];
      }
    }

    /* End of MATLAB Function: '<S1>/List of coordinates' */
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Update for S-Function (TcModuleInOut): '<Root>/xCoordinates' */
  if (A_Search_DW->xCoordinates_PWORK != NULL) {
    memcpy(A_Search_DW->xCoordinates_PWORK, &A_Search_B->xKoordinaten[0], 808);
  }

  /* Update for S-Function (TcModuleInOut): '<Root>/yCoordinates' */
  if (A_Search_DW->yCoordinates_PWORK != NULL) {
    memcpy(A_Search_DW->yCoordinates_PWORK, &A_Search_B->yKoordinaten[0], 808);
  }
}

/* Model initialize function */
void A_Search_initialize(RT_MODEL_A_Search_T *const A_Search_M)
{
  B_A_Search_T *A_Search_B{ A_Search_M->blockIO };

  /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S1>/xCoordinates' */
  std::memset(&A_Search_B->xKoordinaten[0], 0, 101U * sizeof(real_T));

  /* SystemInitialize for Outport: '<S1>/yCoordinates' */
  std::memset(&A_Search_B->yKoordinaten[0], 0, 101U * sizeof(real_T));

  /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */
}

/* Model terminate function */
void A_Search_terminate(RT_MODEL_A_Search_T * A_Search_M)
{
  /* model code */
  rt_FREE(A_Search_M->blockIO);
  rt_FREE(A_Search_M->dwork);
  delete A_Search_M;
}

/* Model data allocation function */
RT_MODEL_A_Search_T *A_Search(void)
{
  RT_MODEL_A_Search_T *A_Search_M;
  A_Search_M = new RT_MODEL_A_Search_T();
  if (A_Search_M == (nullptr)) {
    return (nullptr);
  }

  /* block I/O */
  {
    B_A_Search_T *b{ (B_A_Search_T *) malloc(sizeof(B_A_Search_T)) };

    rt_VALIDATE_MEMORY(A_Search_M,b);
    A_Search_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_A_Search_T *dwork{ static_cast<DW_A_Search_T *>(malloc(sizeof
      (DW_A_Search_T))) };

    rt_VALIDATE_MEMORY(A_Search_M,dwork);
    A_Search_M->dwork = (dwork);
  }

  {
    B_A_Search_T *A_Search_B{ A_Search_M->blockIO };

    DW_A_Search_T *A_Search_DW{ A_Search_M->dwork };

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));

    /* block I/O */
    (void) std::memset((static_cast<void *>(A_Search_B)), 0,
                       sizeof(B_A_Search_T));

    /* states (dwork) */
    (void) std::memset(static_cast<void *>(A_Search_DW), 0,
                       sizeof(DW_A_Search_T));
  }

  return A_Search_M;
}
