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
 * Version:     1.0.1
 * Date:        2021/08/03 (YYYY/MM/DD)
 * Change Log:  1. Added the function "matrixCellOperationsSwapCols()".
 *              2. Added the function "matrixCellOperationsSwapRows()".
 *
 * Version:     1.0.0
 * Date:        2021/07/28 (YYYY/MM/DD)
 * Change Log:  1. Implemented first release version of matrixlibrarycelloperations.
 */

#ifndef MATRIXLIBRARYCELLOPERATIONS_H
#define MATRIXLIBRARYCELLOPERATIONS_H

#include "matrixlibrary.h"

/**
 * @brief matrixCellOperationsDivide - Perform cell to cell division between two matrices.
 * @param X                          - Main matrix.
 * @param Y                          - Divisor matrix.
 * @return                           - Resultant matrix.
 */
matrix matrixCellOperationsDivide(const matrix & X, const matrix & Y);

/**
 * @brief matrixCellOperationsMultiply - Perform cell to cell multiplication between two matrices.
 * @param X                            - Main matrix.
 * @param Y                            - Multiplier matrix.
 * @return                             - Resultant matrix.
 */
matrix matrixCellOperationsMultiply(const matrix & X, const matrix & Y);

/**
 * @brief matrixCellOperationsSwapCols - Swap the elements of two columns.
 * @param X                            - The matrix whose columns are to be swapped.
 * @param col1                         - Index of the first column to be swapped.
 * @param col2                         - Index of the second column to be swapped.
 * @return
 */
matrix matrixCellOperationsSwapCols(const matrix & X, unsigned long col1, unsigned long col2);

/**
 * @brief matrixCellOperationsSwapRows - Swap the elements of two rows.
 * @param X                            - The matrix whose rows are to be swapped.
 * @param col1                         - Index of the first row to be swapped.
 * @param col2                         - Index of the second row to be swapped.
 * @return
 */
matrix matrixCellOperationsSwapRows(const matrix & X, unsigned long row1, unsigned long row2);

#endif // MATRIXLIBRARYCELLOPERATIONS_H
