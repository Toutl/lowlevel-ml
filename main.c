#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Vector *v;
  Matrix *M;
  double a = -3.5f, b;

  v = vec_create(4);
  vec_fill(v, a);
  b = vec_get(v, 2);
  printf("Vector: ");
  vec_print(v);

  M = mat_create(3, 5);
  mat_fill(M, 1.0f);
  mat_set(M, 1, 2, b * b);
  printf("Matrix:\n");
  mat_print(M);

  veclist_free();
  matlist_free();
  return 0;
}
