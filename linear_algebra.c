#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "linear_algebra.h"

Vector *
vec_create(size_t n)
{
  Vector *v = malloc(sizeof(Vector));

  v->size = n;
  v->data = calloc(n, sizeof(float));
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
vec_scale(Vector *v, float value){
  Vector *reslut = vec_create(v->size);
  size_t i;

  for(i = 0; i < v->size; i++)
    result->data[i] = value * v->data[i];
  return result;
}

float 
vec_dot(Vector *u, Vector *v){
  float result;
  size_t i;

  if(u->size != v->size){
    printf("\nERROR: Size mismatch in vec_dot\n\n");
    return 0;
  }
  for (i = 0; i < v->size ; i++)
    result += u->data[i] * v->data[i];
  return result;
}

//norm_vect(Vector *v)
//norm 
