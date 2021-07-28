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
 * Version:     1.0.0
 * Date:        2021/07/28 (YYYY/MM/DD)
 * Change Log:  1. Implemented first release version of matrixlibrarydecomposition.
 */

#include "matrixlibrarydecomposition.h"
#include "matrixlibrarycelloperations.h"
#include "matrixlibrarymaths.h"

/**
 * @brief matrixDecompositionQR - QR decomposition.
 * @param X                     - Matrix for QR decomposition.
 * @param Q                     - Resultant Q matrix.
 * @param R                     - Resultant R matrix.
 */
void matrixDecompositionQR(const matrix & X, matrix & Q, matrix & R) {
  unsigned long RIndex = 0;

  matrix M = X;

  R.resizeClear(M.getRowSize(), M.getColSize());
  Q.resizeClear(M.getRowSize(), M.getColSize());

  for (unsigned long i = 1; i <= M.getColSize(); i++) {
    double VectorMag = matrixMathsVectorSquareRoot(M(1, M.getColSize(), i, i));

    R.mMat[RIndex] = VectorMag;
    Q(1, i, M(1, M.getRowSize(), i, i) / VectorMag);

    matrix QV = Q(1, Q.getRowSize(), i, i);
    for (unsigned long j = i + 1; j <= M.getColSize(); j++) {
      R(i, j) = matrixMathsVectorSum(matrixCellOperationsMultiply(QV, M(1, M.getRowSize(), j, j)));
      M(1, j, M(1, M.getRowSize(), j, j) - Q(1, Q.getRowSize(), i, i) * R(i, j));
    }

    RIndex += M.getColSize() + 1;
  }

  matrixPrint(M, "M");
}
