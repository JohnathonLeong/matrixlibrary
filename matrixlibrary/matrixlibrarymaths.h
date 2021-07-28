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
 * Change Log:  1. Implemented first release version of matrixlibrarymaths.
 */

#ifndef MATRIXLIBRARYMATHS_H
#define MATRIXLIBRARYMATHS_H

#include "matrixlibrary.h"

/**
 * @brief matrixMathsCumulativeSum - Computes the cumulative sum for each of the vector of the
 *                                   matrix. The vector direction is defined by the input argument.
 * @param X                        - The matrix whose cumulative sum is to be calculated.
 * @param direction                - Defines the direction of the vector;
 *                                   0 -> column vector
 *                                   1 -> row vector
 * @return                         - The resultant cumulative sum vector matrix.
 */
matrix matrixMathsCumulativeSum(const matrix & X, unsigned char direction = 0);

/**
 * @brief matrixMathsRootMeanSquare - Computes the root mean square for each of the vector of the
 *                                    matrix. The vector direction is defined by the input argument.
 * @param X                         - The matrix whose root mean square is to be calculated.
 * @param direction                 - Defines the direction of the vector;
 *                                    0 -> column vector
 *                                    1 -> row vector
 * @return                          - The resultant root mean square vector matrix.
 */
matrix matrixMathsRootMeanSquare(const matrix & X, unsigned char direction = 0);

/**
 * @brief matrixMathsRootMeanSquare - Computes the square root for each of the vector of the matrix.
 *                                    The vector direction is defined by the input argument.
 * @param X                         - The matrix whose RMS is to be calculated.
 * @param direction                 - Defines the direction of the vector;
 *                                    0 -> column vector
 *                                    1 -> row vector
 * @return                          - The resultant square root vector matrix.
 */
matrix matrixMathsSquareRoot(const matrix & X, unsigned char direction = 0);

/**
 * @brief matrixMathsSum - Computes the sum for each of the vector of the matrix. The vector
 *                         direction is defined by the input argument.
 * @param X              - The matrix whose sum is to be calculated.
 * @param direction      - Defines the direction of the vector;
 *                         0 -> column vector
 *                         1 -> row vector
 * @return               - The resultant sum vector matrix.
 */
matrix matrixMathsSum(const matrix & X, unsigned char direction = 0);

/**
 * @brief matrixMathsVectorRootMeanSquare - Computes the root mean square of the input vector. The
 *                                          input vector must be a [N x 1] matrix.
 * @param X                               - The vector whose root mean square is to be calculated.
 * @return                                - The computed root mean squre value.
 */
double matrixMathsVectorRootMeanSquare(const matrix & X);

double matrixMathsVectorSquareRoot(const matrix & X);

double matrixMathsVectorSum(const matrix & X);

#endif // MATRIXLIBRARYMATHS_H
