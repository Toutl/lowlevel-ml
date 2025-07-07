#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Matrix *A = mat_create(2, 3), *B = mat_create(3, 2);

  mat_set(A, 0, 0, 1.0f);
  mat_set(A, 0, 1, 2.0f);
  mat_set(A, 0, 2, 3.0f);
  mat_set(A, 1, 0, 4.0f);
  mat_set(A, 1, 1, 5.0f);
  mat_set(A, 1, 2, 6.0f);

  mat_set(B, 0, 0, 10.0f);
  mat_set(B, 0, 1, 11.0f);
  mat_set(B, 1, 0, 20.0f);
  mat_set(B, 1, 1, 21.0f);
  mat_set(B, 2, 0, 30.0f);
  mat_set(B, 2, 1, 31.0f);

  printf("A = \n");
  mat_print(A);
  printf("B = \n");
  mat_print(B);

  printf("\nAB =\n");
  mat_print(mat_multiply(A, B));

  veclist_free();
  matlist_free();
  return 0;
}
