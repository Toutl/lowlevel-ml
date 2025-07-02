#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdlib.h>

// Vectors
// TODO:
// - ???

typedef struct {
  float *data;
  size_t size;
} Vector;

typedef struct {
  Vector **data;
  size_t count;
  size_t capacity;
} VectorList;

extern VectorList *all_vectors;

void veclist_add(Vector *v);
void veclist_free(void);

Vector *vec_create(size_t n);
void vec_free(Vector *v);

void vec_fill(Vector *v, float value);
void vec_print(Vector *v);

Vector *vec_add(Vector *u, Vector *v);
Vector *vec_scale(Vector *v, float value);
float vec_dot(Vector *u, Vector *v);
float vec_norm(Vector *v);
Vector *vec_normalize(Vector *v);


// Matrices
// TODO:
// - Matrix multiplication
// - Matrix determinants
// - Matrix Row echelon form

typedef struct {
  float **data;
  size_t rows;
  size_t columns;
} Matrix;

typedef struct {
  Matrix **data;
  size_t count;
  size_t capacity;
} MatrixList;

extern MatrixList *all_matrices;

void matlist_add(Matrix *A);
void matlist_free(void);

Matrix *mat_create(size_t n, size_t m);
void mat_free(Matrix *A);

void mat_fill(Matrix *A, float value);
void mat_print(Matrix *A);

Matrix *mat_add(Matrix *A, Matrix *B);
Matrix *mat_scale(Matrix *A, float value);

// LinAlg
// TODO:
// - Eigens
// - 

#endif
