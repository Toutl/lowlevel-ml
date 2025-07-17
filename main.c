#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  Vector *u = vec_read("test_data.csv", 4);
  Vector *v = vec_read("test_data.csv", 1);
  vec_print(u);
  vec_print(v);

  veclist_free();
  return 0;
}
