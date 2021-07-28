#include "matrixlibrary.h"
#include "matrixlibrarydecomposition.h"
#include "matrixlibrarymaths.h"

int main(void) {
  matrix a(4, 4);
  a << 0.421761282626275 << 0.655740699156587  << 0.678735154857774	<< 0.655477890177557
    << 0.915735525189067 << 0.0357116785741896 <<	0.757740130578333	<< 0.171186687811562
    << 0.792207329559554 << 0.849129305868777	 << 0.743132468124916 << 0.706046088019609
    << 0.959492426392903 << 0.933993247757551	 << 0.392227019534168 << 0.0318328463774207;

  matrixPrint(a, "a");

  matrix q, r;
  matrixDecompositionQR(a, q, r);

  matrixPrint(q, "q");
  matrixPrint(r, "r");
  return 1;
}
