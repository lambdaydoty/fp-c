#include <stdio.h>

int fib (int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

/**
 * succ - succ - succ - succ - zero
 *  |      |      |      |      |
 *  v      v      v      v      v
 *  f   -  f   -  f   -  f   - (0,1)
 *
 *  f (m,n) = (n, m+n)
 */

/* tail-recursion */
int fib_acc (int n, int acc_m, int acc_n) {
  if (n == 0) {
    return acc_n;
  } {
    return fib_acc (n - 1, acc_n, acc_m + acc_n);
  }
}

int fib_loop (int n) {
  int acc_m = 0;
  int acc_n = 1;
  while (n != 0) {
    int _m = acc_n;
    int _n = acc_m + acc_n;
    acc_m = _m;
    acc_n = _n;
    n = n - 1;
  }
  return acc_n;
}

int main (void) {
  int n = 10;
  printf("fib(%d) == %d\n", n, fib(n));
  printf("fib_acc(%d) == %d\n", n, fib_acc(n, 0, 1));
  printf("fib_loop(%d) == %d\n", n, fib_loop(n));
}
