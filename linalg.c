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

void
vec_set(Vector *v, size_t index, double value)
{
  if (!v || index >= v->size) return;

  v->data[index] = value;
}

void
mat_set(Matrix *M, size_t row, size_t col, double value)
{
  if (!M || row >= M->rows || col >= M->cols) return;

  M->data[row][col] = value;
}

double
vec_get(Vector *v, size_t index)
{
  if (!v || index >= v->size) return 0.0f;

  return v->data[index];
}

double
mat_get(Matrix *M, size_t row, size_t col)
{
  if (!M || row > M->rows || col > M->cols) return 0.0f;

  return M->data[row][col];
}

void
vec_fill(Vector *v, double value)
{
  if (!v) return;

  for (size_t i = 0; i < v->size; i++)
    v->data[i] = value;
}

void
mat_fill(Matrix *M, double value)
{
  if (!M) return;

  for (size_t i = 0; i < M->rows; i++) {
    for (size_t j = 0; j < M->cols; j++)
      M->data[i][j] = value;
  }
}

Vector *
vec_add(Vector *a, Vector *b)
{
  if (!a || !b || a->size != b->size) return NULL;

  Vector *result = vec_create(a->size);
  if (!result) return NULL;

  for (size_t i = 0; i < result->size; i++)
    result->data[i] = a->data[i] + b->data[i];
  return result;
}

Matrix *
mat_add(Matrix *A, Matrix *B)
{
  if (!A || !B || A->rows != B->rows || A->cols != B->cols) return NULL;

  Matrix *result = mat_create(A->rows, A->cols);
  if (!result) return NULL;

  for (size_t i = 0; i < result->rows; i++) {
    for (size_t j = 0; j < result->cols; j++)
      result->data[i][j] = A->data[i][j] + B->data[i][j];
  }
  return result;
}

Vector *
vec_scale(Vector *v, double scalar)
{
  if (!v) return NULL;

  Vector *result = vec_create(v->size);
  if (!result) return NULL;

  for (size_t i = 0; i < result->size; i++)
    result->data[i] = scalar * v->data[i];
  return result;
}

Matrix *
mat_scale(Matrix *M, double scalar)
{
  if (!M) return NULL;

  Matrix *result = mat_create(M->rows, M->cols);
  if (!result) return NULL;

  for (size_t i = 0; i < result->rows; i++) {
    for (size_t j = 0; j < result->cols; j++)
      result->data[i][j] = scalar * M->data[i][j];
  }
  return result;
}

double
vec_dot(Vector *a, Vector *b)
{
  if (!a || !b || a->size != b->size) return 0.0f;

  double result = 0.0f;

  for (size_t i = 0; i < a->size; i++)
    result += a->data[i] * b->data[i];
  return result;
}

double
vec_norm(Vector *v)
{
  if (!v) return 0.0f;

  double result = 0.0f;

  for (size_t i = 0; i < v->size; i++)
    result += v->data[i] * v->data[i];
  return sqrt(result);
}

Vector *
vec_normalize(Vector *v)
{
  if (!v) return NULL;

  double norm = vec_norm(v);
  if (norm == 0) return NULL;

  Vector *result = vec_create(v->size);
  if (!result) return NULL;

  for (size_t i = 0; i < result->size; i++)
    result->data[i] = v->data[i] / norm;
  return result;
}
