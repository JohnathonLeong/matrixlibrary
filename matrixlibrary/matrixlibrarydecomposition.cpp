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
 * Note:        To be used together with: matrixlibrary,
 *                                        matrixlibrarycelloperations, and
 *                                        matrixlibrarymaths
 *
 * Version:     1.0.2
 * Date:        2021/08/04 (YYYY/MM/DD)
 * Change Log:  1. Added the function "matrixDecompositionLU()".
 *
 * Version:     1.0.1
 * Date:        2021/07/30 (YYYY/MM/DD)
 * Change Log:  1. Modified the "matrixDecompositionQR" function to compute the QR for non squared
 *                 matrix.
 *
 * Version:     1.0.0
 * Date:        2021/07/28 (YYYY/MM/DD)
 * Change Log:  1. Implemented first release version of matrixlibrarydecomposition.
 */

#include "matrixlibrarydecomposition.h"
#include "matrixlibrarycelloperations.h"
#include "matrixlibrarymaths.h"

/**
 * @brief matrixDecompositionLU - LU decomposition.
 * @param X                     - Matrix for LU decomposition.
 * @param L                     - Resultant L matrix.
 * @param U                     - Resultant U matrix.
 * @return                      - Returns the pivot matrix.
 */
matrix matrixDecompositionLU(const matrix &X, matrix & L, matrix & U) {
  matrix R = X;
  matrix T1, T2, T3;
  matrix P = matrixIdentity(X.getRowSize(), X.getColSize());

  L = matrixIdentity(X.getRowSize(), X.getColSize());
  U.resizeClear(X.getRowSize(), X.getColSize());

  double temp = 0;
  for (unsigned long i = 1; i <= X.getRowSize(); i++) {

    // perform LU decomposition pivoting
    T1 = R(i, X.getRowSize(), 1, X.getColSize());
    T3 = matrixMathsAbsMax(T1, T2);
    R = matrixCellOperationsSwapRows(R, i, T3(1, i) + (1 * (i-1)));
    P = matrixCellOperationsSwapRows(P, i, T3(1, i) + (1 * (i-1)));

    // compute LU decomposition
    for (unsigned long j = 1; j <= X.getColSize(); j++) {
      temp = 0;

      // check for lower triangle matrix indices
      if (j < i) {
        for (unsigned long k = 1; k <= X.getColSize(); k++)
          temp += L(i, k) * U(k, j);
        // determine L elements
        L(i, j) = (R(i, j) - temp) / U(j, j);
      }

      temp = 0;
      // check for upper triangle matrix indices
      if (j >= i) {
        for (unsigned long k = 1; k <= X.getColSize(); k++)
          temp += L(i, k) * U(k, j);
        // determine U elements
        U(i, j) = (R(i, j) - temp) / L(i, i);
      }
    }
  }

  return P;
}

/**
 * @brief matrixDecompositionQR - QR decomposition.
 * @param X                     - Matrix for QR decomposition.
 * @param Q                     - Resultant Q matrix.
 * @param R                     - Resultant R matrix.
 */
void matrixDecompositionQR(const matrix & X, matrix & Q, matrix & R) {
  matrix M = X;
  Q.resizeClear(X.getRowSize(), X.getRowSize());
  R.resizeClear(X.getRowSize(), X.getColSize());

  for (unsigned long i = 1; i <= X.getColSize(); i++) {
    R(i, i) = matrixMathsVectorSquareRoot(M(1, X.getRowSize(), i, i));
    Q(1, i, M(1, X.getRowSize(), i, i) / R(i, i));

    for (unsigned long j = i + 1; j <= X.getColSize(); j++) {
      R(i, j) = matrixMathsVectorSum(matrixCellOperationsMultiply(Q(1, X.getRowSize(), i, i), M(1, X.getRowSize(), j, j)));
      M(1, j, M(1, X.getRowSize(), j, j) - Q(1, X.getRowSize(), i, i) * R(i, j));
    }
  }
}

