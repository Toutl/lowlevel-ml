#include <stdio.h>
#include <stddef.h>

#include "linalg.h"

int
main(void)
{
  char file[] = "data";
  Matrix *M = mat_read(file, 15);
  mat_print(M);

  veclist_free();
  return 0;
}
