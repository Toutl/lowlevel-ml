#include <stdio.h>
#include <stddef.h>
#include "linear_algebra.h"

int
main(void)
{
  float f = 2.0f, dot;
  Vector *u, *v, *w, *z;
  size_t n = 3;

  u = vec_create(n);
  u->data[0] = 3.0f;
  u->data[1] = 5.7f;
  u->data[2] = 7.0f;
  vec_print(u);

  v = vec_create(n);
  vec_fill(v, 1.0);
  vec_print(v);

  z = vec_scale(v,f);
  vec_print(z);

  printf("\n");
  w = vec_add(u, v);
  vec_print(w);

  printf("\ndot\n");
  dot = vec_dot(v,z);
  printf("%f\n", dot);

  vec_free(u);
  vec_free(v);
  vec_free(w);
  vec_free(z);
  
  return 0;
}

