#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../common/bool.h"

int * bubble3_sort (int * a) {
  if (a[0] > a[1]) {
    int temp = a[0]; a[0] = a[1]; a[1] = temp;
    bubble3_sort(a);
  }
  /* a[0] <= a[1] */
  if (a[1] > a[2]) {
    int temp = a[1]; a[1] = a[2]; a[2] = temp;
    bubble3_sort(a);
  }
  return a;
}

/* a[1], ..., a[N] */
int * bubble_sort (int N, int * a) {
  for (int i = N; i > 1; i--) {
    for (int j = 1; j < i; j++) {
      if (a[j] > a[j+1]) {
        int temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
      }
    }
  }
  return a;
}

void assert_increasing (int start, int end, int * a) {
  for (int i = start; i < end; i++) {
    /* printf( "(%d,%d) ", a[i], a[i+1] ); */
    assert( a[i] <= a[i+1] );
  }
}

int main () {
  int a[4] = {' ', 'c', 'b', 'a'};
  int b[4] = {' ', 'c', 'a', 'b'};
  int c[5] = {' ', 'c', 'z', 'b', 'a'};
  int d[11] = {' ', 0, 9, 2, 6, 7, 2, 7, 2, 1, 2};
  assert_increasing( 0, 2, bubble3_sort( a + 1 ) );
  assert_increasing( 0, 2, bubble3_sort( b + 1 ) );
  assert_increasing( 1, 4, bubble_sort( 4, c ) );
  assert_increasing( 1, 10, bubble_sort( 10, d ) );
}
