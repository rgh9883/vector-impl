#include <stdio.h>

#include "vector.h"

int main() {
  Vector* vec = vector_create();
  vector_push_back(vec, 4);
  vector_push_back(vec, 5);
  vector_push_back(vec, 19);
  vector_push_back(vec, -23);

  int test_pop = vector_pop_back(vec);
  int test_get = vector_get(vec, 1);
  vector_set(vec, 0, 12);
  int test_set = vector_get(vec, 0);

  printf("%d = %d\n", test_pop, -23);
  printf("%d = %d\n", test_get, 5);
  printf("%d = %d\n", test_set, 12);
  
  vector_free(vec);

  return 1;
}
