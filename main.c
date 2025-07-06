#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Vector *u, *v, *w;
  double a = -3.5f, b = 1.0f;

  u = vec_create(3);
  v = vec_create(3);
  w = vec_create(3);
  vec_fill(u, a);
  vec_fill(v, b);
  vec_set(u, 1, 5.0f);


  printf("Vectors:\n");
  vec_print(u);
  vec_print(v);

  printf("\nDot product: %.2f\n", vec_dot(u, v));

  printf("Normalize vector: ");
  w = vec_normalize(u);
  vec_print(w);

  printf("Norm of vector: %.2f\n", vec_norm(w));

  veclist_free();
  return 0;
}
