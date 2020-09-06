#include <assert.h>
#include "c_intarray.h"
#include "../common/bool.h"

/**
 *  The sieve of Eratosthenes
 *
 *     1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, ...
 *  1
 *  2     o     x     x     x     x       x
 *  3        o        x        x
 *  4           x
 *  5              o
 *  6                 x
 *  7                   o
 *
 *  array:
 *    * if the INDEX is known, any item can be accessed in constant time.
 *    * the SIZE of the array must be known beforehand.
 *    * they have a direct correspondence with MEMORY systems on virtually all computers.
 *    * mathematically, 1D-array <-> VECTOR; 2D-array <-> MATRIX.
 *
 */

#define N 100

bool divided(int n, int m) { return m % n == 0; }

int main () {
  IntArray prime = intarray_init( N );

  for (int i = 2; i <= N; i++) {
    prime.a[i] = true;
  }

  for (int i = 2; i <= N/2; i++) {
    if (prime.a[i]) {
      for (int m = 2; m <= N/i; m++) {
        prime.a[i * m] = false;
      }
    }
  }

  assert (prime.a[2]);
  assert (prime.a[3]);
  assert (prime.a[5]);
  assert (prime.a[47]);
  assert (prime.a[73]);
  assert (prime.a[89]);
  assert (!prime.a[4]);
  assert (!prime.a[51]);
  assert (!prime.a[99]);
}
