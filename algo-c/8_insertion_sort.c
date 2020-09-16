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
int * insertion_sort (int N, int * a) {
  /* find the index of minimun value */

  /* 0 9 2 6 7 2 7 2 1 2
   * i ^
   * 0 9 2 6 7 2 7 2 1 2
   *   i ^
   * 0 2 9 6 7 2 7 2 1 2
   *     i ^
   * 0 2 6 9 7 2 7 2 1 2
   *       i ^
   * 0 2 6 7 9 2 7 2 1 2
   *         i ^
   * 0 2 2 6 7 9 7 2 1 2
   */
  a[0] = -1; // sentinel
  for (int i = 2; i <= N; i++) {
    int v = a[i];
    int j = i;
    while (a[j-1] > v) {
      a[j] = a[j-1];
      j--;
    }
    /* a[j] <= v */
    a[j] = v;
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
  assert_increasing( 1, 3, insertion_sort( 3, a ) );
  assert_increasing( 1, 3, insertion_sort( 3, b ) );
  assert_increasing( 1, 4, insertion_sort( 4, c ) );
  assert_increasing( 1, 10, insertion_sort( 10, d ) );
}
