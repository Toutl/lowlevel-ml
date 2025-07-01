#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdlib.h>

// TODO:
// - Matrix

typedef struct {
  float *data;
  size_t size;
} Vector;

Vector *vec_create(size_t n);
void vec_free(Vector *v);
void vec_fill(Vector *v, float value);
void vec_print(Vector *v);
Vector *vec_add(Vector *u, Vector *v);
Vector *vec_scale(Vector *v, float value);
float vec_dot(Vector *u, Vector *u);

#endif
