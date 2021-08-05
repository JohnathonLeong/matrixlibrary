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
 * Version:     1.0.3
 * Date:        2021/08/05 (YYYY/MM/DD)
 * Change Log:  1. Improved the function "matrixDecompositionLU()" to allow decomposition of non
 *                 sqaure matrix.
 *              2. Resolve a bug when perfomring matrixDecompositionQR()" on a [M x N] non square
 *                 matrix where M < N.
 *
 * Version:     1.0.2
 * Date:        2021/08/04 (YYYY/MM/DD)
 * Change Log:  1. Added the function "matrixDecompositionLU()".
 *
 * Version:     1.0.1
 * Date:        2021/07/30 (YYYY/MM/DD)
 * Change Log:  1. Modified the "matrixDecompositionQR" function to compute the QR for non square
 *                 matrix.
 *
 * Version:     1.0.0
 * Date:        2021/07/28 (YYYY/MM/DD)
 * Change Log:  1. Implemented first release version of matrixlibrarydecomposition.
 */

#ifndef MATRIXLIBRARYDECOMPOSITION_H
#define MATRIXLIBRARYDECOMPOSITION_H

#include "matrixlibrary.h"

/**
 * @brief matrixDecompositionLU - LU decomposition.
 * @param X                     - Matrix for LU decomposition.
 * @param L                     - Resultant L matrix.
 * @param U                     - Resultant U matrix.
 * @return                      - Returns the pivot matrix.
 */
matrix matrixDecompositionLU(const matrix &X, matrix & L, matrix & U);

/**
 * @brief matrixDecompositionQR - QR decomposition.
 * @param X                     - Matrix for QR decomposition.
 * @param Q                     - Resultant Q matrix.
 * @param R                     - Resultant R matrix.
 */
void matrixDecompositionQR(const matrix &X, matrix & Q, matrix & R);

#endif // MATRIXLIBRARYDECOMPOSITION_H
