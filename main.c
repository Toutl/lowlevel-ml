#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Matrix *A = mat_create(2, 3), *I = mat_identity(3);

  mat_set(A, 0, 0, 1.0f);
  mat_set(A, 0, 1, 2.0f);
  mat_set(A, 0, 2, 3.0f);
  mat_set(A, 1, 0, 4.0f);
  mat_set(A, 1, 1, 5.0f);
  mat_set(A, 1, 2, 6.0f);
 
  printf("A = \n");
  mat_print(A);

  printf("\nA^T =\n");
  mat_print(mat_transpose(A));

  printf("\nI =\n");
  mat_print(I);

  veclist_free();
  matlist_free();
  return 0;
}
