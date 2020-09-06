#ifndef C_INTARRAY_H
#define C_INTARRAY_H

typedef struct {
  int * a;
  int n;
} IntArray;

extern IntArray intarray_init (int size);

/* #define retrieve (arr, i) arr.a[(i)] */
/* #define set_array (arr, i, x) arr.a[(i)] = x */

#endif /* C_INTARRAY_H */
