#include <stdio.h>
#include <stddef.h>
#include "linear_algebra.h"

int
main(void)
{
  Vector *u, *v, *w;
  float a = 2.0f;
  size_t n = 3;

  u = vec_create(n);
  v = vec_create(n);
  w = vec_create(n);

  u->data[0] = 3.0f;
  u->data[1] = 5.7f;
  u->data[2] = 7.0f;
  vec_fill(v, 1.0);
  vec_print(u);
  vec_print(v);

  w = vec_scale(vec_add(u, v), a);
  vec_print(w);

  veclist_free();
  return 0;
}

