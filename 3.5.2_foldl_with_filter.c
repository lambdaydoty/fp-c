#include <stdio.h>

/* sum of squares */

/**
 *
 *    cons                  cons p                  +
 *   /   \                 /   \                   / \
 *  1    cons             1    cons p             +   3
 *       /  \       =>         /  \        =>    /  \
 *     2    cons             2    cons p        +   2
 *          /  \                  /  \         /  \
 *        3    nil              3    nil      e   1

 */

/**
 * filter p [] = []
 * filter p (x:xs) = (p x) ? (x:filter p xs) : filter p xs
 */

typedef enum { false = 0, true = 1 } bool;

double sum (double x, int y) {
  return x + y;
}

// func h a b = g a (f b)
bool rel_prime (int n, int i) {
  return n % i == 0;
}

int h (int n, double a, int b) {
  if (rel_prime (n, b)) {
    return sum (a, b);
  } else {
    return a;
  }
}

double sum_of_factors (int N) {
  int (* f) (int, double, int) = h;
  int acc = 0.0;
  int m = 1;
  int n = N - 1;
  for (int i = m; i <= n; i += 1) {
    acc = f(N, acc, i);
    /**
     * inline:
     * if (N % i == 0) {
     *   acc = acc + i;
     * }
     *
     */
  }
  return acc;
}

int main (void) {
  int pn = 28;
  printf("sum_of_factors(%d) == %f\n", pn, sum_of_factors(pn));
}
