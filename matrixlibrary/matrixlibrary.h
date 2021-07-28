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


#ifndef CMATRIXLIBRARY_H
#define CMATRIXLIBRARY_H

class matrix
{
public:
  /**
   * @brief matrix - Default constructor.
   */
  explicit matrix();

  /**
   * @brief matrix - Overloaded constructor to instantiate a square matrix.
   * @param size   - Size of the square matrix.
   */
  explicit matrix(unsigned long size);

  /**
   * @brief matrix  - Overloaded constructor to instantiate a mxn matrix.
   * @param rowSize - Row size of the matrix.
   * @param colSize - Column size of the matrix.
   */
  explicit matrix(unsigned long rowSize, unsigned long colSize);

  /**
   * @brief matrix - Overloaded copy constructor.
   * @param X      - Matrix to be copied
   */
  matrix(const matrix &X);

  /**
   * @brief ~matrix - Default destructor
   */
  virtual ~matrix();

  /**
   * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
   * @param X          - The value to be stored.
   */
  void operator=(double X);

  /**
   * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
   * @param X          - The value to be stored.
   */
  void operator=(float X);

  /**
   * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
   * @param X          - The value to be stored.
   */
  void operator=(int X);

  /**
   * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
   * @param X          - The value to be stored.
   */
  void operator=(long X);

  /**
   * @brief operator = - Resize itself to be a 1x1 matrix and stores the input value.
   * @param X          - The value to be stored.
   */
  void operator=(long long X);

  /**
   * @brief operator = - Overloaded operator to assign a matrix to itself.
   * @param X          - The matrix to copy from.
   */
  void operator=(const matrix & X);

  /**
   * @brief operator << - Assigning of values into the matrix via pushing method.
   *                      Note that the first element value of the matrix will be pushed out.
   * @param X           - The value to be pushed into the last element of the matrix.
   * @return            - Returns the matrix pointer of itself.
   */
  matrix& operator<<(double X);

  /**
   * @brief operator << - Assigning of values into the matrix via pushing method.
   *                      Note that the first element value of the matrix will be pushed out.
   * @param X           - The value to be pushed into the last element of the matrix.
   * @return            - Returns the matrix pointer of itself.
   */
  matrix& operator<<(float X);

  /**
   * @brief operator << - Assigning of values into the matrix via pushing method.
   *                      Note that the first element value of the matrix will be pushed out.
   * @param X           - The value to be pushed into the last element of the matrix.
   * @return            - Returns the matrix pointer of itself.
   */
  matrix& operator<<(int X);

  /**
   * @brief operator << - Assigning of values into the matrix via pushing method.
   *                      Note that the first element value of the matrix will be pushed out.
   * @param X           - The value to be pushed into the last element of the matrix.
   * @return            - Returns the matrix pointer of itself.
   */
  matrix& operator<<(long X);

  /**
   * @brief operator << - Assigning of values into the matrix via pushing method.
   *                      Note that the first element value of the matrix will be pushed out.
   * @param X           - The value to be pushed into the last element of the matrix.
   * @return            - Returns the matrix pointer of itself.
   */
  matrix& operator<<(long long X);

  /**
   * @brief operator() - Return the value stored in the element defined by the input arguments.
   * @param rowIndex   - Row index of the element.
   * @param colIndex   - Column index of the element.
   * @return           - Returns the stored value.
   */
  double& operator()(unsigned long RowIndex, unsigned long ColIndex) const;

  /**
   * @brief operator () - Set the input submatrix, with the archoring element defined by the start row
   *                      and column index, into the main matrix.
   * @param startRow    - The anchoring row index of the main matrix.
   * @param startCol    - The anchoring column index of the main matrix.
   * @param X           - The submatrix to be set into the main matrix.
   */
  void operator()(unsigned long startRow, unsigned long startCol, const matrix & X);

  /**
   * @brief operator() - Returns the submatrix defined by the input arguments.
   * @param startRow   - Start row index of the submatrix.
   * @param endRow     - End row index of the submatrix.
   * @param startCol   - Start column index of the submatrix.
   * @param endCol     - End column index of the submatrix.
   * @return           - Returns the submatrix.
   */
  matrix operator()(unsigned long startRow, unsigned long endRow, unsigned long startCol, unsigned long endCol);

  /**
   * @brief clear - Clears all the matrix elements to zero.
   */
  void clear(void);

  /**
   * @brief getColSize - Returns the column size of the matrix.
   * @return           - Column size of the matrix.
   */
  unsigned long getColSize(void) const;

  /**
   * @brief getRowSize - Returns the row size of the matrix.
   * @return           - Row size of the matrix.
   */
  unsigned long getRowSize(void) const;

  /**
   * @brief getSize - Returns the total number of elements in the matrix.
   * @return        - Size of the matrix.
   */
  unsigned long getSize(void) const;

  /**
   * @brief resizeClear - Resize the matrix to a new dimension with all existing elements cleared.
   * @param row         - Row size of the resize matrix.
   * @param col         - Column size of the resize matrix.
   */
  void resizeClear(unsigned long row, unsigned long col);

  /**
   * @brief resizeRetain - Resize the matrix to a new dimension with all existing elements retained.
   *                       If the resized matrix dimension is bigger than itself, the additional
   *                       elements will be set to zero.
   *                       If the resized matrix dimension is smaller than itself, the rest of the
   *                       elements will be discarded.
   * @param row          - Row size of the resize matrix.
   * @param col          - Column size of the resize matrix.
   */
  void resizeRetain(unsigned long row, unsigned long col);

  /**
   * @brief mMat - "double" type pointer to the memory allocated for the matrix.
   *               IMPORTANT NOTE: THIS ATTRIBUTE IS NOT "PRIVATE" FOR EFFICIENCY. DO NOT ACCESS AND
   *                               CHANGE THE CONTENT OF THE POINTER. ANY CHANGES MAY RESULT IN
   *                               CATASTROPHIC FAILURE OF THE MATRIX LIBRARY AND/OR THE SOFTWARE
   *                               USING IT.
   */
  double * mMat;

private:
  /**
   * @brief mRow - To store the row size of the matrix.
   */
  unsigned long mRow;

  /**
   * @brief mCol - To store the column size of the matrix.
   */
  unsigned long mCol;

  /**
   * @brief mSize - To store the total element size of the matrix.
   */
  unsigned long mSize;

  /**
   * @brief create - Creates a square matrix.
   * @param size   - Size of the square matrix.
   */
  void create(unsigned long size);

  /**
   * @brief create - Creates a mxn matrix.
   * @param row    - Row size of the matrix.
   * @param col    - Column size of the matrix.
   */
  void create(unsigned long row, unsigned long col);

  /**
   * @brief release - Free up the memory allocated for the matrix elements.
   */
  void release(void);
};

/**
 * @brief operator + - Overloading of the addition operatior between a matrix and a double type value.
 * @param X          - Main matrix for addition.
 * @param Y          - Addition value.
 * @return           - The resultant matrix.
 */
matrix operator+(const matrix & X, const double & Y);

/**
 * @brief operator + - Overloading of the addition operatior between two matrices.
 * @param X          - Main matrix for addition.
 * @param Y          - Addition matrix.
 * @return           - The resultant matrix.
 */
matrix operator+(const matrix & X, const matrix & Y);

/**
 * @brief operator - - Overloading of the subtraction operatior between a matrix and a double type value.
 * @param X          - Main matrix for subtraction.
 * @param Y          - Subtraction value.
 * @return           - The resultant matrix.
 */
matrix operator-(const matrix & X, const double & Y);

/**
 * @brief operator - - Overloading of the subtraction operatior between two matrices.
 * @param X          - Main matrix for subtraction.
 * @param Y          - Subtraction matrix.
 * @return           - The resultant matrix.
 */
matrix operator-(const matrix & X, const matrix & Y);

/**
 * @brief operator * - Overloading of the multiplication operatior between a matrix and a double type value.
 * @param X          - Main matrix for multiplication.
 * @param Y          - Multiplication value.
 * @return           - The resultant matrix.
 */
matrix operator*(const matrix & X, const double & Y);

/**
 * @brief operator * - Overloading of the multiplication operatior between two matrices.
 * @param X          - Main matrix for multiplication.
 * @param Y          - Multiplication matrix.
 * @return           - The resultant matrix.
 */
matrix operator*(const matrix & X, const matrix & Y);

/**
 * @brief operator / - Overloading of the division operatior between a matrix and a double type
 *                     value.
 * @param X          - Main matrix for division.
 * @param Y          - Division value.
 * @return           - The resultant matrix.
 */
matrix operator/(const matrix & X, const double & Y);

/**
 * @brief operator / - Overloading of the division operatior between two matrices.
 * @param X          - Main matrix for division.
 * @param Y          - Division matrix.
 * @return           - The resultant matrix.
 */
matrix operator/(const matrix & X, const matrix & Y);

/**
 * @brief operator += - Overloading of the addition equal operatior between a matrix and a double
 *                      type value.
 * @param X           - Main matrix for addition.
 * @param Y           - Addition value.
 */
void operator+=(matrix & X, const double & Y);

/**
 * @brief operator += - Overloading of the addition equal operatior between two matrices.
 * @param X           - Main matrix for addition.
 * @param Y           - Addition matrix.
 */
void operator+=(matrix & X, const matrix & Y);

/**
 * @brief operator -= - Overloading of the subtraction equal operatior between a matrix and a double
 *                      type value.
 * @param X           - Main matrix for subtraction.
 * @param Y           - Subtraction value.
 */
void operator-=(matrix & X, const double & Y);

/**
 * @brief operator -= - Overloading of the subtraction equal operatior between two matrices.
 * @param X           - Main matrix for subtraction.
 * @param Y           - Subtraction matrix.
 */
void operator-=(matrix & X, const matrix & Y);

/**
 * @brief operator *= - Overloading of the multiplication operatior between a matrix and a double
 *                      type value.
 * @param X           - Main matrix for multiplication.
 * @param Y           - Multiplication value.
 */
void operator*=(matrix & X, const double & Y);

/**
 * @brief operator /= - Overloading of the division operatior between a matrix and a double type
 *                      value.
 * @param X           - Main matrix for division.
 * @param Y           - Division value.
 */
void operator/=(matrix & X, const double & Y);

/**
 * @brief matrixCheckIsEqualInnerSize - Checks the inner size of the matrices.
 * @param X                           - Main matrix to be check.
 * @param Y                           - First matrix to be check.
 * @return                            - Return status of check.
 */
unsigned char matrixCheckIsEqualInnerSize(const matrix & X, const matrix & Y);

/**
 * @brief matrixCheckIsEqualInnerSize - Checks the size of the matrices.
 * @param X                           - Main matrix to be check.
 * @param Y                           - First matrix to be check.
 * @return                            - Return status of check.
 */
unsigned char matrixCheckIsEqualSize(const matrix & X, const matrix & Y);

/**
 * @brief matrixCheckIsEqualInnerSize - Checks for square matrix
 * @param X                           - Main matrix to be check.
 * @return                            - Return status of check.
 */
unsigned char matrixCheckIsSquare(const matrix & X);

/**
 * @brief matrixIdentity - Create a square identity matrix defined by the input argument.
 * @param size           - Defines the size of the square identity matrix.
 * @return               - The identity matrix.
 */
matrix matrixIdentity(unsigned long size);

/**
 * @brief matrixIdentity - Create a square identity matrix defined by the input arguments.
 * @param row            - Defines the row size of the identity matrix.
 * @param col            - Defines the column size of the identity matrix.
 * @return               - The identity matrix.
 */
matrix matrixIdentity(unsigned long row, unsigned long col);

/**
 * @brief matrixInverse - Compute the inverse of a square matrix.
 * @param X             - Matrix whose inverse is to be calculated.
 * @return              - Resultant matrix.
 */
matrix matrixInverse(const matrix & X);

/**
 * @brief matrixPrint - Print the size information and values of each element in the matrix.
 * @param mat         - Matrix size infomation and elements to be printed.
 * @param msg         - Message to be print along with the abovementioned information.
 */
void matrixPrint(const matrix & mat, const char * msg = "");

/**
 * @brief matrixTranspose - Create a transpose copy of the input matrix.
 * @param X               - The matrix to be transposed.
 * @return                - The transposed matrix.
 */
matrix matrixTranspose(const matrix & X);

/**
 * @brief matrixVersion - Retrieve version number of this library
 * @param major         - Major revision number.
 * @param minor         - Minor revision number.
 * @param patch         - Patch revision number.
 */
void matrixVersion(unsigned char & major, unsigned char & minor, unsigned char & patch);

#endif // CMATRIXLIBRARY_H
