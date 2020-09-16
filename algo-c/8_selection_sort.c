#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../common/bool.h"

void print_array (int start, int end, int * a) {
  for (int i = start; i <= end; i++) {
    printf( "%d ", a[i] );
  }
  puts( "" );
}

/* a[1], ..., a[N] */
int * selection_sort (int N, int * a) {
  /* find the index of minimun value */

  /* 0 9 2 6 7 2 7 2 1 2
   * i|<- ith smallest->|
   * 0 9 2 6 7 2 7 2 1 2
   *   i|<------------->|
   *   1 2 6 7 2 7 2 9 2
   *     i|<----------->|
   *     2 6 7 2 7 2 9 2
   *       i|<--------->|
   *       2 7 2 7 2 9 6
   *
   */
  for (int i = 1; i < N; i++) {
    int min = i;
    for (int j = i + 1; j <= N; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int temp = a[min]; a[min] = a[i]; a[i] = temp;
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
  assert_increasing( 1, 3, selection_sort( 3, a ) );
  assert_increasing( 1, 3, selection_sort( 3, b ) );
  assert_increasing( 1, 4, selection_sort( 4, c ) );
}
