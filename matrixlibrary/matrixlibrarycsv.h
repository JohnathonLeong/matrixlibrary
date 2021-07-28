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
 * Change Log:  1. Implemented first release version of matrixlibrarycsv.
 */

#ifndef MATRIXLIBRARYCSV_H
#define MATRIXLIBRARYCSV_H

#include "matrixlibrary.h"

/**
 * @brief matrixCsvRead - Read dataset from a CSV file and return as a matrix.
 * @param filename      - Filename, including the path, of the dataset.
 * @return              - Returns the dataset in a matrix form.
 */
matrix matrixCsvRead(const char * filename);

/**
 * @brief matrixCsvWrite - Write a matrix to a CSV file.
 * @param filename       - Filename, including the path, of the CSV file
 * @param X              - The matrix data to be written.
 */
void matrixCsvWrite(const char * filename, const matrix & X);

#endif // MATRIXLIBRARYCSV_H
