#include <stdio.h>
#include <stddef.h>
#include "linear_algebra.h"

int
main(void)
{
  Matrix *A, *B;
  float a = 3.5f;
  size_t n = 3, m = 5;
 
  A = mat_create(2, 3);
  B = mat_create(n, m);

  mat_fill(A, a);
  mat_print(A);
  mat_print(B);

  matlist_free();
  return 0;
}
