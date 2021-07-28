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
 * Note:        To be used together with matrixlibrary.
 *
 * Version:     1.0.0
 * Date:        2021/07/28 (YYYY/MM/DD)
 * Change Log:  1. Implemented first release version of matrixlibrarycelloperations.
 */

#include "matrixlibrarycelloperations.h"

/**
 * @brief matrixCellOperationsDivide - Perform cell to cell division between two matrices.
 * @param X                          - Main matrix.
 * @param Y                          - Divisor matrix.
 * @return                           - Resultant matrix.
 */
matrix matrixCellOperationsDivide(const matrix & X, const matrix & Y) {
  matrix Z;
  if (matrixCheckIsEqualSize(X, Y)) {
    Z.resizeClear(X.getRowSize(), X.getColSize());
    for (unsigned long i = 0; i < X.getSize(); i++)
      Z.mMat[i] = X.mMat[i] / Y.mMat[i];
  }
  return Z;
} // matrixCellOperationsDivide(const matrix & X, const matrix & Y) --------------------------------

/**
 * @brief matrixCellOperationsMultiply - Perform cell to cell multiplication between two matrices.
 * @param X                            - Main matrix.
 * @param Y                            - Multiplier matrix.
 * @return                             - Resultant matrix.
 */
matrix matrixCellOperationsMultiply(const matrix & X, const matrix & Y) {
  matrix Z;
  if (matrixCheckIsEqualSize(X, Y)) {
    Z.resizeClear(X.getRowSize(), X.getColSize());
    for (unsigned long i = 0; i < X.getSize(); i++)
      Z.mMat[i] = X.mMat[i] * Y.mMat[i];
  }
  return Z;
} // matrixCellOperationsMultiply(const matrix & X, const matrix & Y) ------------------------------
