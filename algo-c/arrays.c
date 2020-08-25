#include <stdio.h>

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

typedef enum { false = 0, true = 1 } bool;

bool divided(int n, int m) { return m % n == 0; }

int main () {
  bool prime[N + 1];

  for (int i = 1; i <= N; i++) {
    prime[i] = true;
  }

  for (int i = 2; i <= N/2; i++) {
    if (prime[i]) {
      for (int m = 2; m <= N/i; m++) {
        prime[i * m] = false;
      }
    }
  }

  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      printf("%d ", i);
    }
  }
}
