#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Vector *u, *v;
  Matrix *M, *N;
  double a = -3.5f, b = 0.0f;

  u = vec_create(5);
  v = vec_create(5);
  vec_fill(u, a);
  vec_fill(v, 1.0f);
  printf("Vector: ");
  vec_print(vec_scale(vec_add(u, v), 2.0f));

  M = mat_create(3, 5);
  N = mat_create(3, 5);
  mat_fill(M, 1.0f);
  mat_fill(N, a);
  mat_set(M, 1, 2, b);
  printf("Matrix:\n");
  mat_print(mat_scale(mat_add(M, N), -1 / 2.5));

  veclist_free();
  matlist_free();
  return 0;
}
