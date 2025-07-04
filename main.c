#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Vector *v;
  // double = 1.0f;

  v = vec_create(4);
  vec_print(v);

  vec_free(v);

  return 0;
}
