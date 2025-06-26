#include <stdio.h>
#include <stddef.h>
#include "linear_algebra.h"

int
main(void)
{
  Vector *u, *v, *w;
  size_t n = 3;

  u = vec_create(n);
  u->data[0] = 3.0f;
  u->data[1] = 5.7f;
  u->data[2] = 7.0f;
  vec_print(u);

  v = vec_create(n);
  vec_fill(v, 3.5);
  vec_print(v);

  printf("\n");
  w = vec_add(u, v);
  vec_print(w);

  vec_free(u);
  vec_free(v);
  vec_free(w);

  return 0;
}

