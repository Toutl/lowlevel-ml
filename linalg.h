#ifndef LINALG_H
#define LINALG_H

#include <stdlib.h>

/* BASICS */

// To do:
// - Matrix multiplication
// - Matrix determinants
// - Matrix row echelon form

typedef struct {
  double *data;
  size_t size;
} Vector;

typedef struct {
  double **data;
  size_t rows;
  size_t cols;
} Matrix;

typedef struct {
  Vector **list;
  size_t count;
  size_t capacity;
} VecList;

typedef struct {
  Matrix **list;
  size_t count;
  size_t capacity;
} MatList;

extern VecList *allvecs;
extern MatList *allmats;

Vector *vec_create(size_t size);
Matrix *mat_create(size_t rows, size_t cols);
void vec_free(Vector *v);
void mat_free(Matrix *M);

void veclist_add(Vector *v);
void matlist_add(Matrix *M);
void veclist_free(void);
void matlist_free(void);

void vec_print(Vector *v);
void mat_print(Matrix *M);

void vec_set(Vector *v, size_t index, double value);
void mat_set(Matrix *M, size_t row, size_t col, double value);
double vec_get(Vector *v, size_t index);
double mat_get(Matrix *M, size_t row, size_t col);
void vec_fill(Vector *v, double value);
void mat_fill(Matrix *M, double value);

// Vector *vec_add(Vector *a, Vector *b);
// Matrix *mat_add(Matrix *A, Matrix *B);
// Vector *vec_scale(Vector *v, double scalar);
// Matrix *mat_scale(Matrix *M, double scalar);

// double vec_dot(Vector *a, Vector *b);
// double vec_norm(Vector *v);
// Vector *vec_normalize(Vector *v);

// Vector *mat_vec_multiply(Matrix *M, Vector *v);

// Matrix *mat_multiply(Matrix *A, Matrix *B);
// Matrix *mat_transpose(Matrix *M);
// Matrix *mat_identity(Matrix *M);

#endif
