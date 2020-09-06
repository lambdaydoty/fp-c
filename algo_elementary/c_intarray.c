#include <stdio.h>
#include <stdlib.h>
#include "c_intarray.h"

#define N 100

IntArray intarray_init (int size) {
  IntArray x;
  x.a = (int *) malloc( (size + 1) * sizeof( int * ) );
  x.n = size + 1;
  return x;
}
