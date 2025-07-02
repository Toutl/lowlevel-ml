#include <stdio.h>
#include <stddef.h>
#include "linear_algebra.h"

int
main(void)
{
  Vector *u, *v, *w, *z;
  float a = 2.0f;
  size_t n = 3;

  u = vec_create(n);
  v = vec_create(n);
  w = vec_create(n);
  z = vec_create(n);

  u->data[0] = 3.0f;
  u->data[1] = 5.7f;
  u->data[2] = 7.0f;
  vec_fill(v, 1.0);
  vec_print(u);
  vec_print(v);

  w = vec_scale(vec_add(u, v), a);
  printf("Scaled added: ");
  vec_print(w);

  z = vec_normalize(w);
  printf("Norm %.2f\n", vec_norm(w));
  printf("Normalized: ");
  vec_print(z);

  a = vec_norm(z);
  printf("Norm: %.2f\n", a);

  veclist_free();
  return 0;
}

