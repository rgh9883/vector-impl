#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

#define DEFAULT_CAP 4
#define RESIZE_CAP 2

typedef struct {
  int* data;
  size_t size;
  size_t capacity;
} Vector;


Vector* vector_create();
void vector_push_back(Vector* vec, int value);
int vector_pop_back(Vector* vec);
int vector_get(Vector* vec, size_t index);
void vector_set(Vector* vec, size_t index, int value);
void vector_free(Vector* vec);


#endif
