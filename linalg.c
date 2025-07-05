#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "linalg.h"

VecList *allvecs = NULL;
MatList *allmats = NULL;

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

Matrix *
mat_create(size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) return NULL;

  Matrix *M = malloc(sizeof *M);
  if (!M) return NULL;

  M->rows = rows;
  M->cols = cols;

  M->data = calloc(rows, sizeof *M->data);
  if (!M->data) {
    free(M);
    return NULL;
  }

  for (size_t i = 0; i < rows; i++) {
    M->data[i] = calloc(cols, sizeof *M->data[i]);
    if (!M->data[i]) {
      while (i)
        free(M->data[--i]);
      free(M->data);
      free(M);
      return NULL;
    }
  }

  matlist_add(M);
  return M;
}

void
vec_free(Vector *v)
{
  if (!v) return;

  free(v->data);
  free(v);
}

void
mat_free(Matrix *M)
{
  if (!M) return;

  for (size_t i = 0; i < M->rows; i++)
    free(M->data[i]);
  free(M->data);
  free(M);
}

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
    size_t newcapacity = allvecs->capacity * 2;
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
  if (!M) return;

  if (allmats == NULL) {
    allmats = malloc(sizeof *allmats);
    if (!allmats) return;

    allmats->capacity = 10;
    allmats->count = 0;
    allmats->list = calloc(allmats->capacity, sizeof *allmats->list);
    if (!allmats->list) {
      free(allmats);
      return;
    }
  }

  if (allmats->count == allmats->capacity) {
    size_t newcapacity = allmats->capacity * 2;
    Matrix **tmp = realloc(allmats->list, newcapacity * sizeof *allmats->list);
    if (!tmp) return;

    allmats->list = tmp;
    allmats->capacity = newcapacity;
  }

  allmats->list[allmats->count++] = M;
}

void
veclist_free(void)
{
  if (!allvecs) return;

  for (size_t i = 0; i < allvecs->count; i++)
    vec_free(allvecs->list[i]);
  free(allvecs->list);
  free(allvecs);
  allvecs = NULL;
}

void
matlist_free(void)
{
  if (!allmats) return;

  for (size_t i = 0; i < allmats->count; i++)
    mat_free(allmats->list[i]);
  free(allmats->list);
  free(allmats);
  allmats = NULL;
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

void
mat_print(Matrix *M)
{
  if (!M) return;

  printf("[");
  for (size_t i = 0; i < M->rows; i++) {
    for (size_t j = 0; j < M->cols; j++)
      printf(" %6.2f", M->data[i][j]);
    if (i < M->rows - 1)
      printf("\n ");
  }
  printf(" ]\n");
}
