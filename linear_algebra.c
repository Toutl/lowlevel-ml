#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "linear_algebra.h"

//Vectors
VectorList *all_vectors = NULL;

void
veclist_add(Vector *v)
{
  if (all_vectors == NULL) {
    all_vectors = malloc(sizeof *all_vectors);
    all_vectors->capacity = 10;
    all_vectors->count = 0;
    all_vectors->data = calloc(all_vectors->capacity, sizeof *all_vectors->data);
  }
  if (all_vectors->count == all_vectors->capacity) {
    all_vectors->capacity *= 2;
    all_vectors->data = realloc(all_vectors->data,
                                all_vectors->capacity * sizeof *all_vectors->data);
  }
  all_vectors->data[all_vectors->count++] = v;
}

void
veclist_free(void)
{
  size_t i;

  for (i = 0; i < all_vectors->count; i++)
    vec_free(all_vectors->data[i]);
  free(all_vectors->data);
  free(all_vectors);
  all_vectors = NULL;
}

Vector *
vec_create(size_t n)
{
  Vector *v = malloc(sizeof(Vector));

  v->size = n;
  v->data = calloc(n, sizeof(float));
  veclist_add(v);
  return v;
}

void
vec_free(Vector *v)
{
  free(v->data);
  free(v);
}

void
vec_fill(Vector *v, float value)
{
  size_t i;

  for (i = 0; i < v->size; i++)
    v->data[i] = value;
}

void
vec_print(Vector *v)
{
  size_t i;

  printf("[");
  for (i = 0; i < v->size; i++)
    printf(" %5.2f", v->data[i]);
  printf(" ]\n");
}

Vector *
vec_add(Vector *u, Vector *v) {
  Vector *result = vec_create(u->size);
  size_t i;

  if (u->size != v->size) {
    printf("\nERROR: Size mismatch in vec_add\n\n");
    return vec_create(u->size);
  }
  for (i = 0; i < u->size; i++)
    result->data[i] = u->data[i] + v->data[i];
  return result;
}

Vector *
vec_scale(Vector *v, float value)
{
  Vector *result = vec_create(v->size);
  size_t i;

  for (i = 0; i < v->size; i++)
    result->data[i] = value * v->data[i];
  return result;
}

float
vec_dot(Vector *u, Vector *v)
{
  float result = 0.0f;
  size_t i;

  if (u->size != v->size){
    printf("\nERROR: Size mismatch in vec_dot\n\n");
    return 0;
  }
  for (i = 0; i < v->size; i++)
    result += u->data[i] * v->data[i];
  return result;
}

float
vec_norm(Vector *v)
{
  float result = 0.0f;

  for (size_t i = 0; i < v->size; i++)
    result += v->data[i] * v->data[i];
  return sqrt(result);
}

Vector *
vec_normalize(Vector *v)
{
  Vector *result = vec_create(v->size);
  float norm = vec_norm(v);

  if (norm == 0) {
    printf("\nERROR: Zero vector can't be normalized\n\n");
    return result;
  }
  for (size_t i = 0; i < v->size; i++)
    result->data[i] = v->data[i] / norm;
  return result;
}


// Matrices
MatrixList *all_matrices = NULL;

void
matlist_add(Matrix * A)
{
  if (all_matrices == NULL) {
    all_matrices = malloc(sizeof *all_matrices);
    all_matrices->capacity = 10;
    all_matrices->count = 0;
    all_matrices->data = calloc(all_matrices->capacity, sizeof *all_matrices->data);
  }
  if (all_matrices->count == all_matrices->capacity) {
    all_matrices->capacity *= 2;
    all_matrices->data = realloc(all_matrices->data,
                                 all_matrices->capacity * sizeof *all_matrices->data);
  }
  all_matrices->data[all_matrices->count++] = A;
}

void
matlist_free(void)
{
  size_t i;

  for (i = 0; i < all_matrices->count; i++)
    mat_free(all_matrices->data[i]);
  free(all_matrices->data);
  free(all_matrices);
  all_matrices = NULL;
}

Matrix *
mat_create(size_t n, size_t m)
{
  Matrix *A = malloc(sizeof(Matrix));
  size_t i;

  A->rows = n;
  A->columns = m;
  A->data = (float**)malloc(A->rows * sizeof(float*));
  for (i = 0; i < A->rows; i++)
    A->data[i] = (float*)calloc(A->columns, sizeof(float));
  matlist_add(A);
  return A;
}

void
mat_free(Matrix *A)
{
  size_t i;

  for (i = 0; i < A->rows; i++)
    free(A->data[i]);
  free(A->data);
  free(A);
}

void
mat_fill(Matrix *A, float value)
{
  size_t i, j;

  for (i = 0; i < A->rows; i++) {
    for (j = 0; j < A->columns; j++)
      A->data[i][j] = value;
  }
}

void
mat_print(Matrix *A)
{
  size_t i, j;

  printf("[");
  for (i = 0; i < A->rows; i++) {
    for (j = 0; j < A->columns; j++)
      printf(" %5.2f", A->data[i][j]);
    if (i < A->rows - 1)
      printf("\n ");
  }
  printf(" ]\n");
}
