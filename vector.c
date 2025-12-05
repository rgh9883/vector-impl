#include <stdio.h>
#include <stdlib.h>

#include "vector.h"


Vector* vector_create() {
  Vector* vec = (Vector*) malloc(sizeof(Vector));
  vec->size = 0;
  vec->capacity = DEFAULT_CAP;
  vec->data = (int*) malloc(DEFAULT_CAP * sizeof(int));

  return vec;
}

void vector_push_back(Vector* vec, int value) {
  if(vec->capacity == vec->size) {
    vec->data = (int*) realloc((void*) vec->data, RESIZE_CAP * vec->capacity * sizeof(int));  
  }
  
  vec->data[vec->size] = value;
  vec->size++;
}

int vector_pop_back(Vector* vec) {
  if(vec->size == 0) {
    fprintf(stderr, "Vector is Empty");
    return -1;
  }
  
  int value = vec->data[vec->size-1];
  vec->data[vec->size-1] = -1;
  vec->size--;

  return value;
}

int vector_get(Vector* vec, size_t index) {
  if(vec->size <= index) {
    fprintf(stderr, "Index out of bounds");
    return -1;
  }

  return vec->data[index];
}

void vector_set(Vector* vec, size_t index, int value) {
  if(vec->size <= index) {
    fprintf(stderr, "Index out of bounds");
    return;
  }
  
  vec->data[index] = value;
}

void vector_free(Vector* vec){
  free(vec->data);
  free(vec);
}
