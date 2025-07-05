#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Vector *v;
  Matrix *M;
  // double = 1.0f;

  v = vec_create(4);
  printf("Vector: ");
  vec_print(v);

  M = mat_create(3, 5);
  printf("Matrix:\n");
  mat_print(M);


  veclist_free();
  matlist_free();
  return 0;
}
