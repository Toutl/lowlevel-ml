#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  char file[] = "data";
  Vector *u = vec_read(file, 4);
  Vector *v = vec_read(file, 7);
  vec_print(vec_add(u, v));

  veclist_free();
  return 0;
}
