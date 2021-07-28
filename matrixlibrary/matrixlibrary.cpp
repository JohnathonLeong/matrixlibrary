/*
 * Copyright:   2021 Johnathon Leong
 *
 * License:     License under LGPL-3.0-or-later.
 *              Please refer to https://www.gnu.org/licenses/lgpl-3.0.txt for more information on the
 *              terms of LGPL-3.0 or relavent website for a later version of the LGPL.
 *
 * Disclaimer:  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
 *              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 *              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 *              WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Author:      Johnathon Leong
 *
 * Note:
 *
 * Version:     1.0.0
 * Date:        2021/07/28 (YYYY/MM/DD)
 * Change Log:  1. Implemented first release version of matrixlibrary.
 */

#include "matrixlibrary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIXLIBRARY_MAJOR 1
#define MATRIXLIBRARY_MINOR 0
#define MATRIXLIBRARY_PATCH 0

/// ================================================================================================
/// STATIC FUNCTIONS
/// ================================================================================================
/**
 * @brief matrixExit - Abort program.
 * @param msg        - Error message.
 */
void matrixExit(const char * msg) {
  printf("MATRIX LIBRARY ERROR:\n  %s\n\n", msg);
  exit(0);
} // void matrixExit(const char * msg) -------------------------------------------------------------

/// ================================================================================================
/// PUBLIC FUNCTIONS
/// ================================================================================================
/**
 * @brief matrix - Default constructor.
 */
matrix::matrix() : mRow(0), mCol(0), mSize(0) {
  mMat = NULL;
} // matrix::matrix() ------------------------------------------------------------------------------

/**
 * @brief matrix - Overloaded constructor to instantiate a square matrix.
 * @param size   - Size of the square matrix.
 */
matrix::matrix(unsigned long size) {
  mMat = NULL;
  this->create(size, size);
} // matrix::matrix(unsigned long size) ------------------------------------------------------------

/**
 * @brief matrix  - Overloaded constructor to instantiate a mxn matrix.
 * @param rowSize - Row size of the matrix.
 * @param colSize - Column size of the matrix.
 */
matrix::matrix(unsigned long row, unsigned long col) {
  mMat = NULL;
  this->create(row, col);
} // matrix::matrix(unsigned long row, unsigned long col) ------------------------------------------

/**
 * @brief matrix - Overloaded copy constructor.
 * @param X      - Matrix to be copied
 */
matrix::matrix(const matrix & X) {
  mMat = NULL;
  if ((mRow != X.getRowSize()) || (mCol != X.getColSize()))
    this->resizeClear(X.getRowSize(), X.getColSize());
  memcpy(this->mMat, X.mMat, sizeof(double) * mSize);
} // matrix::matrix(const matrix & X) --------------------------------------------------------------

/**
 * @brief ~matrix - Default destructor
 */
matrix::~matrix() {
  this->release();
} // matrix::~matrix() -----------------------------------------------------------------------------

/**
 * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
 * @param X          - The value to be stored.
 */
void matrix::operator=(double X) {
  this->resizeClear(1, 1);
  mMat[0] = X;
} // matrix::operator=(double X) -------------------------------------------------------------------

/**
 * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
 * @param X          - The value to be stored.
 */
void matrix::operator=(float X) {
  this->resizeClear(1, 1);
  mMat[0] = (double)X;
} // matrix::operator=(float X) --------------------------------------------------------------------

/**
 * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
 * @param X          - The value to be stored.
 */
void matrix::operator=(int X) {
  this->resizeClear(1, 1);
  mMat[0] = (double)X;
} // matrix::operator=(int X) ----------------------------------------------------------------------

/**
 * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
 * @param X          - The value to be stored.
 */
void matrix::operator=(long X) {
  this->resizeClear(1, 1);
  mMat[0] = (double)X;
} // matrix::operator=(long X) ---------------------------------------------------------------------

/**
 * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
 * @param X          - The value to be stored.
 */
void matrix::operator=(long long X) {
  this->resizeClear(1, 1);
  mMat[0] = (double)X;
} // matrix::operator=(long long X) ----------------------------------------------------------------

/**
 * @brief operator = - Overloaded operator to assign a matrix to itself.
 * @param X          - The matrix to copy from.
 */
void matrix::operator=(const matrix & X) {
  if ((mRow != X.getRowSize()) || (mCol != X.getColSize()))
    this->resizeClear(X.getRowSize(), X.getColSize());
  memcpy(this->mMat, X.mMat, sizeof(double) * mSize);
} // matrix::operator=(const matrix & X) -----------------------------------------------------------

/**
 * @brief operator << - Assigning of values into the matrix via pushing method.
 *                      Note that the first element value of the matrix will be pushed out.
 * @param X           - The value to be pushed into the last element of the matrix.
 * @return            - Returns the matrix pointer of itself.
 */
matrix& matrix::operator<<(double X) {
  if (mSize > 0) {
    memcpy(mMat, &mMat[1], sizeof(double) * (mSize - 1));
    mMat[mSize - 1] = X;
  }
  else
    matrixExit("Matrix size not yet defined.");
  return * this;
} // matrix& matrix::operator<<(double X) ----------------------------------------------------------

/**
 * @brief operator << - Assigning of values into the matrix via pushing method.
 *                      Note that the first element value of the matrix will be pushed out.
 * @param X           - The value to be pushed into the last element of the matrix.
 * @return            - Returns the matrix pointer of itself.
 */
matrix& matrix::operator<<(float X) {
  if (mSize > 0) {
    memcpy(mMat, &mMat[1], sizeof(double) * (mSize - 1));
    mMat[mSize - 1] = (double)X;
  }
  else
    matrixExit("Matrix size not yet defined.");
  return * this;
} // matrix& matrix::operator<<(float X) -----------------------------------------------------------

/**
 * @brief operator << - Assigning of values into the matrix via pushing method.
 *                      Note that the first element value of the matrix will be pushed out.
 * @param X           - The value to be pushed into the last element of the matrix.
 * @return            - Returns the matrix pointer of itself.
 */
matrix& matrix::operator<<(int X) {
  if (mSize > 0) {
    memcpy(mMat, &mMat[1], sizeof(double) * (mSize - 1));
    mMat[mSize - 1] = (double)X;
  }
  else
    matrixExit("Matrix size not yet defined.");
  return * this;
} // matrix& matrix::operator<<(int X) -------------------------------------------------------------

/**
 * @brief operator << - Assigning of values into the matrix via pushing method.
 *                      Note that the first element value of the matrix will be pushed out.
 * @param X           - The value to be pushed into the last element of the matrix.
 * @return            - Returns the matrix pointer of itself.
 */
matrix& matrix::operator<<(long X) {
  if (mSize > 0) {
    memcpy(mMat, &mMat[1], sizeof(double) * (mSize - 1));
    mMat[mSize - 1] = (double)X;
  }
  else
    matrixExit("Matrix size not yet defined.");
  return * this;
} // matrix& matrix::operator<<(long X) ------------------------------------------------------------

/**
 * @brief operator << - Assigning of values into the matrix via pushing method.
 *                      Note that the first element value of the matrix will be pushed out.
 * @param X           - The value to be pushed into the last element of the matrix.
 * @return            - Returns the matrix pointer of itself.
 */
matrix& matrix::operator<<(long long X) {
  if (mSize > 0) {
    memcpy(mMat, &mMat[1], sizeof(double) * (mSize - 1));
    mMat[mSize - 1] = (double)X;
  }
  else
    matrixExit("Matrix size not yet defined.");
  return * this;
} // matrix& matrix::operator<<(long long X) -------------------------------------------------------

/**
 * @brief operator() - Return the value stored in the element defined by the input arguments.
 * @param rowIndex   - Row index of the element.
 * @param colIndex   - Column index of the element.
 * @return           - Returns the stored value.
 */
double& matrix::operator()(unsigned long rowIndex, unsigned long colIndex) const {
  return mMat[--rowIndex * mCol + --colIndex];
} // matrix::operator()(unsigned long rowIndex, unsigned long colIndex) const ----------------------

/**
 * @brief operator () - Set the input submatrix, with the archoring element defined by the start row
 *                      and column index, into the main matrix.
 * @param startRow    - The anchoring row index of the main matrix.
 * @param startCol    - The anchoring column index of the main matrix.
 * @param X           - The submatrix to be set into the main matrix.
 */
void matrix::operator()(unsigned long startRow, unsigned long startCol, const matrix & X) {
  if (startRow == 0)
    matrixExit("Matrix start row index should be greater than 0.");
  if (startCol == 0)
    matrixExit("Matrix end row index should be greater than 0.");
  if ((startRow + X.getRowSize() - 1) > mRow)
    matrixExit("The sub matrix row size exceeds the main matrix row size.");
  if ((startCol + X.getColSize() - 1) > mCol)
    matrixExit("The sub matrix column size exceeds the main matrix column size.");

  unsigned long rowIndex = (startRow - 1) * mCol;
  unsigned long XRowIndex = 0;

  for (unsigned long i = 0; i < X.getRowSize(); i++) {
    for (unsigned long j = 0; j < X.getColSize(); j++) {
      mMat[rowIndex + startCol + j - 1] = X.mMat[XRowIndex + j];
    }
    rowIndex += mCol;
    XRowIndex += X.getColSize();
  }
} // matrix::operator()(unsigned long startRow, unsigned long startCol, const matrix & X) ----------

/**
 * @brief operator() - Returns the submatrix defined by the input arguments.
 * @param startRow   - Start row index of the submatrix.
 * @param endRow     - End row index of the submatrix.
 * @param startCol   - Start column index of the submatrix.
 * @param endCol     - End column index of the submatrix.
 * @return           - Returns the submatrix.
 */
matrix matrix::operator()(unsigned long startRow, unsigned long endRow, unsigned long startCol, unsigned long endCol) {
  if (startRow == 0)
    matrixExit("Matrix start row index should be greater than 0.");
  if (endRow == 0)
    matrixExit("Matrix end row index should be greater than 0.");
  if (startRow > mRow)
    matrixExit("Matrix start row index exceeds matrix row size.");
  if (endRow > mRow)
    matrixExit("Matrix end row index exceeds matrix row size.");
  if (startRow > endRow)
    matrixExit("Matrix start row index exceeds matrix end row index.");
  if (startCol > mCol)
    matrixExit("Matrix start column index exceeds matrix column size.");
  if (endCol > mCol)
    matrixExit("Matrix end column index exceeds matrix column size.");
  if (startCol > endCol)
    matrixExit("Matrix start column index exceeds matrix end column index.");

  unsigned long rowLength = endRow - startRow + 1;
  unsigned long colLength = endCol - startCol + 1;
  unsigned long rowIndex = (startRow - 1) * mCol;
  unsigned long XRowIndex = 0;

  matrix Z(rowLength, colLength);
  for (unsigned long i = 0; i < rowLength; i++) {
    for (unsigned long j = 0; j < colLength; j++)
      Z.mMat[XRowIndex + j] = mMat[rowIndex + startCol + j - 1];
    rowIndex += mCol;
    XRowIndex += colLength;
  }

  return Z;
} // matrix::operator()(unsigned long startRow, unsigned long endRow, unsigned long startCol, unsigned long endCol)

/**
 * @brief clear - Clears all the matrix elements to zero.
 */
void matrix::clear(void) {
  memset(mMat, 0, sizeof(double) * mSize);
} // matrix::clear(void) ---------------------------------------------------------------------------

/**
 * @brief getColSize - Returns the column size of the matrix.
 * @return           - Column size of the matrix.
 */
unsigned long matrix::getColSize(void) const {
  return mCol;
} // matrix::getColSize(void) ----------------------------------------------------------------------

/**
 * @brief getRowSize - Returns the row size of the matrix.
 * @return           - Row size of the matrix.
 */
unsigned long matrix::getRowSize(void) const {
  return mRow;
} // matrix::getRowSize(void) ----------------------------------------------------------------------

/**
 * @brief getSize - Returns the total number of elements in the matrix.
 * @return        - Size of the matrix.
 */
unsigned long matrix::getSize(void) const {
  return mSize;
} // matrix::getSize(void) -------------------------------------------------------------------------

/**
 * @brief resizeClear - Resize the matrix to a new dimension with all existing elements cleared.
 * @param row         - Row size of the resize matrix.
 * @param col         - Column size of the resize matrix.
 */
void matrix::resizeClear(unsigned long row, unsigned long col) {
  this->release();
  this->create(row, col);
} // matrix::resizeClear(unsigned long row, unsigned long col) -------------------------------------

/**
 * @brief resizeRetain - Resize the matrix to a new dimension with all existing elements retained.
 *                       If the resized matrix dimension is bigger than itself, the additional
 *                       elements will be set to zero.
 *                       If the resized matrix dimension is smaller than itself, the rest of the
 *                       elements will be discarded.
 * @param row          - Row size of the resize matrix.
 * @param col          - Column size of the resize matrix.
 */
void matrix::resizeRetain(unsigned long row, unsigned long col) {
  matrix t(mRow, mCol);
  memcpy(t.mMat, mMat, sizeof(double) * mSize);

  this->release();
  this->create(row, col);

  matrix a = t(1, t.getRowSize() > row ? row : t.getRowSize(), 1, t.getColSize() > col ? col : t.getColSize());
  this->operator ()(1, 1, a);
} // matrix::resizeRetain(unsigned long row, unsigned long col)  -----------------------------------

/// ================================================================================================
/// PRIVATE FUNCTIONS
/// ================================================================================================
/**
 * @brief create - Creates a square matrix.
 * @param size   - Size of the square matrix.
 */
void matrix::create(unsigned long size) {
  this->create(size, size);
} // matrix::create(unsigned long size) ------------------------------------------------------------

/**
 * @brief create - Creates a mxn matrix.
 * @param row    - Row size of the matrix.
 * @param col    - Column size of the matrix.
 */
void matrix::create(unsigned long row, unsigned long col) {
  mRow = row;
  mCol = col;
  mSize = row * col;
  mMat = (double *)malloc(sizeof(double) * mSize);
  clear();
} // matrix::create(unsigned long row, unsigned long col) ------------------------------------------

/**
 * @brief release - Free up the memory allocated for the matrix elements.
 */
void matrix::release(void) {
  if (mMat != NULL) {
    free(mMat);
    mMat = NULL;
  }
  mRow = 0;
  mCol = 0;
  mSize = 0;
} // matrix::release(void) -------------------------------------------------------------------------

/// ================================================================================================
/// EXTERNAL FUNCTIONS
/// ================================================================================================
/**
 * @brief operator + - Overloading of the addition operatior between a matrix and a double type value.
 * @param X          - Main matrix for addition.
 * @param Y          - Addition value.
 * @return           - The resultant matrix.
 */
matrix operator+(const matrix & X, const double & Y) {
  matrix Z(X.getRowSize(), X.getColSize());
  for (unsigned long i = 0; i < X.getSize(); i++)
    Z.mMat[i] = X.mMat[i] + Y;
  return Z;
} // operator+(const matrix & X, const double & Y) -------------------------------------------------

/**
 * @brief operator + - Overloading of the addition operatior between two matrices.
 * @param X          - Main matrix for addition.
 * @param Y          - Addition matrix.
 * @return           - The resultant matrix.
 */
matrix operator+(const matrix & X, const matrix & Y) {
  matrix Z;
  if (matrixCheckIsEqualSize(X, Y)) {
    Z.resizeClear(X.getRowSize(), X.getColSize());
    for (unsigned long i = 0; i < X.getSize(); i++)
      Z.mMat[i] = X.mMat[i] + Y.mMat[i];
  }
  return Z;
} // operator+(const matrix & X, const matrix & Y) -------------------------------------------------

/**
 * @brief operator - - Overloading of the subtraction operatior between a matrix and a double type
 *                     value.
 * @param X          - Main matrix for subtraction.
 * @param Y          - Subtraction value.
 * @return           - The resultant matrix.
 */
matrix operator-(const matrix & X, const double & Y) {
  matrix Z(X.getRowSize(), X.getColSize());
  for (unsigned long i = 0; i < X.getSize(); i++)
    Z.mMat[i] = X.mMat[i] - Y;
  return Z;
} // operator-(const matrix & X, const double & Y) -------------------------------------------------

/**
 * @brief operator - - Overloading of the subtraction operatior between two matrices.
 * @param X          - Main matrix for subtraction.
 * @param Y          - Subtraction matrix.
 * @return           - The resultant matrix.
 */
matrix operator-(const matrix & X, const matrix & Y) {
  matrix Z;
  if (matrixCheckIsEqualSize(X, Y)) {
    Z.resizeClear(X.getRowSize(), X.getColSize());
    for (unsigned long i = 0; i < X.getSize(); i++)
      Z.mMat[i] = X.mMat[i] - Y.mMat[i];
  }
  return Z;
} // operator-(const matrix & X, const matrix & Y) -------------------------------------------------

/**
 * @brief operator * - Overloading of the multiplication operatior between a matrix and a double type value.
 * @param X          - Main matrix for multiplication.
 * @param Y          - Multiplication value.
 * @return           - The resultant matrix.
 */
matrix operator*(const matrix & X, const double & Y) {
  matrix Z(X.getRowSize(), X.getColSize());
  for (unsigned long i = 0; i < X.getSize(); i++)
    Z.mMat[i] = X.mMat[i] * Y;
  return Z;
} // operator*(const matrix & X, const double & Y) -------------------------------------------------

/**
 * @brief operator * - Overloading of the multiplication operatior between two matrices.
 * @param X          - Main matrix for multiplication.
 * @param Y          - Multiplication matrix.
 * @return           - The resultant matrix.
 */
matrix operator*(const matrix & X, const matrix & Y) {
  matrix Z;
  if (matrixCheckIsEqualInnerSize(X, Y)) {
    Z.resizeClear(X.getRowSize(), Y.getColSize());
    double sum = 0.0;
    unsigned long XRowIndex = 0;
    unsigned long YRowIndex = 0;
    unsigned long ZRowIndex = 0;

    for (unsigned long i = 0; i < X.getRowSize(); i++) {
      for (unsigned long j = 0; j < Y.getColSize(); j++) {
        sum = 0.0;
        YRowIndex = 0;
        for (unsigned long k = 0; k < X.getColSize(); k++) {
          sum += X.mMat[XRowIndex + k] * Y.mMat[YRowIndex + j];
          YRowIndex += Y.getColSize();
        }
        Z.mMat[ZRowIndex + j] = sum;
      }
      XRowIndex += X.getColSize();
      ZRowIndex += Y.getColSize();
    }
  }
  return Z;
} // operator*(const matrix & X, const matrix & Y) -------------------------------------------------

/**
 * @brief operator / - Overloading of the division operatior between a matrix and a double type
 *                     value.
 * @param X          - Main matrix for division.
 * @param Y          - Division value.
 * @return           - The resultant matrix.
 */
matrix operator/(const matrix & X, const double & Y) {
  matrix Z(X.getRowSize(), X.getColSize());
  for (unsigned long i = 0; i < X.getSize(); i++)
    Z.mMat[i] = X.mMat[i] / Y;
  return Z;
} // operator/(const matrix & X, const double & Y) -------------------------------------------------

/**
 * @brief operator / - Overloading of the division operatior between two matrices.
 * @param X          - Main matrix for division.
 * @param Y          - Division matrix.
 * @return           - The resultant matrix.
 */
matrix operator/(const matrix & X, const matrix & Y) {
  matrix Z;
  if (matrixCheckIsEqualInnerSize(X, Y) && matrixCheckIsSquare(Y)) {
    Z = X * matrixInverse(Y);
  }
  return Z;
} // operator/(const matrix & X, const matrix & Y) -------------------------------------------------

/**
 * @brief operator += - Overloading of the addition equal operatior between a matrix and a double
 *                      type value.
 * @param X           - Main matrix for addition.
 * @param Y           - Addition value.
 */
void operator+=(matrix & X, const double & Y) {
  for (unsigned long i = 0; i < X.getSize(); i++)
    X.mMat[i] += Y;
} // operator+=(matrix & X, const double & Y) ------------------------------------------------------

/**
 * @brief operator += - Overloading of the addition equal operatior between two matrices.
 * @param X           - Main matrix for addition.
 * @param Y           - Addition matrix.
 */
void operator+=(matrix & X, const matrix & Y) {
  if (matrixCheckIsEqualSize(X, Y)) {
    for (unsigned long i = 0; i < X.getSize(); i++)
      X.mMat[i] += Y.mMat[i];
  }
} // operator+=(matrix & X, const matrix & Y) ------------------------------------------------------

/**
 * @brief operator -= - Overloading of the subtraction equal operatior between a matrix and a double
 *                      type value.
 * @param X           - Main matrix for subtraction.
 * @param Y           - Subtraction value.
 */
void operator-=(matrix & X, const double & Y) {
  for (unsigned long i = 0; i < X.getSize(); i++)
    X.mMat[i] -= Y;
} // operator-=(matrix & X, const double & Y) ------------------------------------------------------

/**
 * @brief operator -= - Overloading of the subtraction equal operatior between two matrices.
 * @param X           - Main matrix for subtraction.
 * @param Y           - Subtraction matrix.
 */
void operator-=(matrix & X, const matrix & Y) {
  if (matrixCheckIsEqualSize(X, Y)) {
    for (unsigned long i = 0; i < X.getSize(); i++)
      X.mMat[i] -= Y.mMat[i];
  }
} // operator-=(matrix & X, const matrix & Y) ------------------------------------------------------

/**
 * @brief operator *= - Overloading of the multiplication operatior between a matrix and a double
 *                      type value.
 * @param X           - Main matrix for multiplication.
 * @param Y           - Multiplication value.
 */
void operator*=(matrix & X, const double & Y) {
  for (unsigned long i = 0; i < X.getSize(); i++)
    X.mMat[i] *= Y;
} // operator*=(matrix & X, const double & Y) ------------------------------------------------------

/**
 * @brief operator /= - Overloading of the division operatior between a matrix and a double type
 *                      value.
 * @param X           - Main matrix for division.
 * @param Y           - Division value.
 */
void operator/=(matrix & X, const double & Y) {
  for (unsigned long i = 0; i < X.getSize(); i++)
    X.mMat[i] /= Y;
} // operator/=(matrix & X, const double & Y) ------------------------------------------------------

/**
 * @brief matrixCheckIsEqualInnerSize - Checks the inner size of the matrices.
 * @param X                           - Main matrix to be check.
 * @param Y                           - First matrix to be check.
 * @return                            - Return status of check.
 */
unsigned char matrixCheckIsEqualInnerSize(const matrix & X, const matrix & Y) {
  if (X.getColSize() != Y.getRowSize()) {
    matrixExit("Matrices inner size mismatch.");
  }
  return 1;
} // matrixCheckIsEqualInnerSize(const matrix & X, const matrix & Y) -------------------------------

/**
 * @brief matrixCheckIsEqualInnerSize - Checks the size of the matrices.
 * @param X                           - Main matrix to be check.
 * @param Y                           - First matrix to be check.
 * @return                            - Return status of check.
 */
unsigned char matrixCheckIsEqualSize(const matrix & X, const matrix & Y) {
  if ((X.getColSize() != Y.getColSize()) || (X.getRowSize() != Y.getRowSize())) {
    matrixExit("Matrices size mismatch.");
  }
  return 1;
} // matrixCheckIsEqualSize(const matrix & X, const matrix & Y) ------------------------------------

/**
 * @brief matrixCheckIsEqualInnerSize - Checks for square matrix
 * @param X                           - Main matrix to be check.
 * @return                            - Return status of check.
 */
unsigned char matrixCheckIsSquare(const matrix & X) {
  if (X.getColSize() != X.getRowSize()) {
    matrixExit("Matrix is not a square matrix.");
  }
  return 1;
} // matrixCheckIsSquare(const matrix & X) ---------------------------------------------------------

/**
 * @brief matrixIdentity - Create a square identity matrix defined by the input argument.
 * @param size           - Defines the size of the square identity matrix.
 * @return               - The identity matrix.
 */
matrix matrixIdentity(unsigned long size) {
  matrix Z(size, size);
  for (unsigned long i = 0; i < Z.getSize(); i = i + size + 1)
    Z.mMat[i] = 1;
  return Z;
} // matrix matrixIdentity(unsigned long size) -----------------------------------------------------

/**
 * @brief matrixIdentity - Create a square identity matrix defined by the input arguments.
 * @param row            - Defines the row size of the identity matrix.
 * @param col            - Defines the column size of the identity matrix.
 * @return               - The identity matrix.
 */
matrix matrixIdentity(unsigned long row, unsigned long col) {
  unsigned long size = row < col ? row * col : col * col;
  matrix Z(row, col);
  for (unsigned long i = 0; i < size; i = i + col + 1)
    Z.mMat[i] = 1;
  return Z;
} // matrix matrixIdentity(unsigned long row, unsigned long col) -----------------------------------

/**
 * @brief matrixInverse - Compute the inverse of a square matrix by linear row reduction method.
 * @param X             - Matrix whose inverse is to be calculated.
 * @return              - Resultant matrix.
 */
matrix matrixInverse(const matrix & X) {
  matrix m = matrixIdentity(X.getRowSize(), X.getColSize());

  if (matrixCheckIsSquare(X)) {
    matrix a = X;
    unsigned long i, j;
    unsigned long size = X.getColSize();
    for (i = 1; i <= size; i++) {             // the variable i defines the row/column in focus
      for (j = 1; j <= size; j++) {
        double divider = a(j, i);
        // make the matrix element of the focus row and focused column to be of value 1.
        // correspondingly compute the M matrix value
        a(j, 1, a(j, j, 1, size) / divider);
        m(j, 1, m(j, j, 1, size) / divider);
      }
      for (j = 1; j <= size; j++) {
        if (i != j) {
          // subtract non-focus rows with focus row such that the focus columns of non-focus row will
          // be zeros. correspondingly compute the M matrix value
          a(j, 1, a(j, j, 1, size) - a(i, i, 1, size));
          m(j, 1, m(j, j, 1, size) - m(i, i, 1, size));
        }
      }
    }

    for (i = 1; i <= size; i++) {
      // divided the focus row of M matrix by the corresponding A matrix diagonal to complete
      // computation of the inverse matrix.
      double divider = a(i, i);
      m(i, 1, m(i, i, 1, size) / divider);
    }
  }
  return m;
} // matrix matrixInverse(const matrix & X) --------------------------------------------------------

/**
 * @brief matrixPrint - Print the size information and values of each element in the matrix.
 * @param mat         - Matrix size infomation and elements to be printed.
 * @param msg         - Message to be print along with the abovementioned information.
 */
void matrixPrint(const matrix & X, const char * msg) {
  unsigned long colCount = 0;

  if (msg[0] != 0)
    printf("%s[%ldx%ld]:\n", msg, X.getRowSize(), X.getColSize());

  for (unsigned short i = 0; i < X.getSize(); i++) {
    if (colCount == X.getColSize()) {
      colCount = 0;
      printf("\n");
    }
    printf("%18.15f ", X.mMat[i]);

    colCount++;
  }
  printf("\n\n");
} // matrixPrint(const matrix & X, const char * msg) -----------------------------------------------

/**
 * @brief matrixTranspose - Create a transpose copy of the input matrix.
 * @param X               - The matrix to be transposed.
 * @return                - The transposed matrix.
 */
matrix matrixTranspose(const matrix & X) {
  matrix Z(X.getColSize(), X.getRowSize());
  for (unsigned long i = 1; i <= X.getRowSize(); i++) {
    for (unsigned long j = 1; j <= X.getColSize(); j++) {
      Z(j, i) = X(i, j);
    }
  }
  return Z;
} // matrix matrixTranspose(const matrix & X) ------------------------------------------------------

/**
 * @brief matrixVersion - Retrieve version number of this library
 * @param major         - Major revision number.
 * @param minor         - Minor revision number.
 * @param patch         - Patch revision number.
 */
void matrixVersion(unsigned char & major, unsigned char & minor, unsigned char & patch) {
  major = MATRIXLIBRARY_MAJOR;
  minor = MATRIXLIBRARY_MINOR;
  patch = MATRIXLIBRARY_PATCH;
} // matrixVersion(unsigned char & major, unsigned char & minor, unsigned char & patch) ------------
