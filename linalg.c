#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "linalg.h"

VecList *allvecs = NULL;
MatList *allmats = NULL;

void
veclist_add(Vector *v)
{
  if (!v) return;

  if (allvecs == NULL) {
    allvecs = malloc(sizeof *allvecs);
    if (!allvecs) return;

    allvecs->capacity = 10;
    allvecs->count = 0;
    allvecs->list = calloc(allvecs->capacity, sizeof *allvecs->list);
    if (!allvecs->list) {
      free(allvecs);
      return;
    }
  }

  if (allvecs->count == allvecs->capacity) {
    newcapacity = allvecs->capacity * 2;
    Vector **tmp = realloc(allvecs->list, newcapacity * sizeof *allvecs->list);
    if (!tmp) return;

    allvecs->list = tmp;
    allvecs->capacity = newcapacity;
  }

  allvecs->list[allvecs->count++] = v;
}

void
matlist_add(Matrix *M)
{
  //
}

Vector *
vec_create(size_t size)
{
  if (size == 0) return NULL;

  Vector *v = malloc(sizeof *v);
  if (!v) return NULL;

  v->size = size;
  v->data = calloc(size, sizeof *v->data);
  if (!v->data) {
    free(v);
    return NULL;
  }

  veclist_add(v);
  return v;
}

void
vec_free(Vector *v)
{
  if (!v) return;

  free(v->data);
  free(v);
}

void
vec_print(Vector *v)
{
  if (!v) return;

  printf("[");
  for (size_t i = 0; i < v->size; i++)
    printf(" %6.2f", v->data[i]);
  printf(" ]\n");
}
