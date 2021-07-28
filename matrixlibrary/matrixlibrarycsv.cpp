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

#include "matrixlibrarycsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// ================================================================================================
/// STATIC FUNCTIONS
/// ================================================================================================
/**
 * @brief matrixCsvReadIsNumeric - Check if the string is a valid numerical number.
 * @param str                    - String interpretation of the number.
 * @return                       - Status of check.
 */
unsigned char matrixCsvReadIsNumeric(const char * str) {
  if (((str[0] < '0') || (str[0] > '9')) &&
      (str[0] != '.') &&
      (str[0] != '+') &&
      (str[0] != '-'))
    return 0;

  short ECounter = 0;
  short PeriodCounter = 0;
  short EIndex = 0;
  short PeriodIndex = 0;

  short NumericIndex = 0;
  for (unsigned long i = 0; str[i] != 0; i++) {
    if ((str[i] != '+') && (str[i] != '-')) {
      NumericIndex = i;
      break;
    }
  }

  for (int i = NumericIndex; str[i] != 0; i++)
  {
    // check for non numeric characters, signs and symbols
    if (((str[i] < '0') || (str[i] > '9')) &&
        (str[i] != 'e') &&
        (str[i] != 'E') &&
        (str[i] != '.') &&
        (str[i] != '-') &&
        (str[i] != '+'))
      return 0;

    // check if '+' and '-' signs exist directly after 'e'/'E'
    if ((str[i] == '-') || (str[i] == '+'))
      if ((str[i - 1] != 'e') && (str[i - 1] != 'E'))
        return 0;

    // check the occurrence of 'e'/'E'
    if ((str[i] == 'e') || (str[i] == 'E'))
    {
      ECounter++;
      if (ECounter >= 2)
        return 0;
      EIndex = i;
    }

    // check the occurrence of '.'
    if (str[i] == '.')
    {
      PeriodCounter++;
      if (PeriodCounter >= 2)
        return 0;
      PeriodIndex = i;
    }

    // check if '.' appears after 'e'/'E'
    if ((PeriodIndex != 0) && (EIndex != 0) && (PeriodIndex > EIndex))
      return 0;
  }
  return 1;
} // matrixCsvReadIsNumeric(const char* str) -------------------------------------------------------

/**
 * @brief matrixCsvReadExtract - Extract numbers from a string data line of the csv file.
 * @param dataLine             - Buffer that contains the string data line.
 * @param X                    - The matrix to store the extracted numbers.
 */
void matrixCsvReadExtract(const char * dataLine, matrix & X) {
  unsigned long XIndex = 1;

  char buff[64] = {0};
  unsigned long buffIndex = 0;
  unsigned long buffSize = sizeof(buff);
  unsigned long buffLen = strlen(dataLine);
  unsigned long i = 0;

  while(i < buffLen) {
    if ((dataLine[i] == ',') || (dataLine[i] == 0) || (dataLine[i] == '\n')) {
      buffIndex = 0;
      if (matrixCsvReadIsNumeric(buff) == 1) {
        X(1, XIndex) = atof(buff);
        if ((dataLine[i] == 0) || (dataLine[i] == '\n')) {
          break;
        }
        memset(buff, 0, buffSize);
        XIndex++;
      }
    }
    else {
      buff[buffIndex] = dataLine[i];
      buffIndex++;
    }
    i++;
  }
} // matrixCsvReadExtract(const char * dataLine, matrix & X) ---------------------------------------

/// ================================================================================================
/// EXTERNAL FUNCTIONS
/// ================================================================================================
/**
 * @brief matrixCsvRead - Read dataset from a CSV file and return as a matrix.
 * @param filename      - Filename, including the path, of the dataset.
 * @return              - Returns the dataset in a matrix form.
 */
matrix matrixCsvRead(const char * filename) {
  FILE * ptr = fopen(filename, "r");
  unsigned long rowSize = 0;
  unsigned long colSize = 0;
  unsigned char flagColSizeFound = 0;

  char buff[1500];
  unsigned long buffSize = sizeof(buff);

  // determine the row and column size of the dataset
  memset(buff, 0, buffSize);
  unsigned long i = 0;
  while (fgets(buff, buffSize, ptr)) {
    if (buff[0] != '%') {
      while ((flagColSizeFound == 0) && (buff[i] != 0)) {
        if ((buff[i] == ',') || (buff[i] == 0) || (buff[i] == '\n')) {
          colSize++;
        }
        i++;
      }
      flagColSizeFound = 1;
      rowSize++;
    }
  }

  // reset file pointer to beginning of file
  fseek(ptr, 0, SEEK_SET);

  // instatiate and initialize variables
  matrix data(rowSize, colSize);
  matrix X(1, colSize);
  unsigned long currentRowIndex = 1;

  while (fgets(buff, buffSize, ptr)) {
    if (buff[0] != '%') {
      matrixCsvReadExtract(buff, X);
      data(currentRowIndex, 1, X);
      memset(buff, 0, buffSize);
      currentRowIndex++;
    }
  }

  return data;
} // matrixCsvRead(const char * filename) ----------------------------------------------------------

/**
 * @brief matrixCsvWrite - Write a matrix to a CSV file.
 * @param filename       - Filename, including the path, of the CSV file
 * @param X              - The matrix data to be written.
 */
void matrixCsvWrite(const char * filename, const matrix & X) {
  FILE * ptr = fopen(filename, "w");
  unsigned long index = X.getColSize() - 1;

  for (unsigned long i = 0; i < X.getSize(); i++) {
    if (i < index) {
      fprintf(ptr, "%.12f,", X.mMat[i]);
    }
    else {
      fprintf(ptr, "%.12f\n", X.mMat[i]);
      index += X.getColSize();
    }
  }

  fclose(ptr);
} // matrixCsvVersion(unsigned char & major, unsigned char & minor, unsigned char & patch) ---------
