#include <stdio.h>

/* sum of squares */

/**
 *
 *    cons                  cons                    *
 *   /   \                 /   \                   / \
 *  1    cons           f 1    cons               *   f 3
 *       /  \       =>         /  \        =>    /  \
 *     2    cons           f 2    cons          *   f 2
 *          /  \                  /  \         /  \
 *        3    nil            f 3    nil      e   f 1
 *
 */

int sum (int x, int y) {
  return x + y;
}

int square (int x) {
  return x * x;
}

// func h a b = g a (f b)
int h (int a, int b) {
  return sum (a, square(b));
}

int sum_of_sqaures (int N) {
  int (* f) (int, int) = h;
  int acc = 0;
  int m = 1;
  int n = N;
  for (int i = m; i <= n; i += 1) {
    acc = f(acc, i);
    // inline: acc = acc + (i * i);
  }
  return acc;
}

int main (void) {
  printf("sum_of_sqaures(%d) == %d\n", 10, sum_of_sqaures(10));
}
