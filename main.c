#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Vector *v = vec_create(3);
  Matrix *M = mat_create(3, 3);

  mat_set(M, 0, 0, 1.0f);
  mat_set(M, 0, 1, 0.0f);
  mat_set(M, 0, 2, -2.0f);
  mat_set(M, 1, 0, 0.0f);
  mat_set(M, 1, 1, 3.0f);
  mat_set(M, 1, 2, -1.0f);
  mat_set(M, 2, 0, 1.0f);
  mat_set(M, 2, 1, 2.0f);
  mat_set(M, 2, 2, 1.0f);

  vec_set(v, 0, 3.0f);
  vec_set(v, 1, -1.0f);
  vec_set(v, 2, 4.0f);

  printf("v = ");
  vec_print(v);
  printf("M = \n");
  mat_print(M);

  printf("\nMv =\n");
  vec_print(mat_vec_multiply(M, v));

  veclist_free();
  matlist_free();
  return 0;
}
