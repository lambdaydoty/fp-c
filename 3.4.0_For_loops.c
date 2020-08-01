#include <stdio.h>
/**
 * (* foldl : (a -> b -> a) -> a -> b list -> a *)
 *
 *    cons                      f
 *   /   \                     / \
 *  b1   cons                 f   b3
 *       /  \         =>     /  \        =    (((e * b1) * b2) * b3)
 *     b2   cons            f   b2
 *          /  \           /  \
 *        b3   nil        e   b1
 *
 *  fun foldl f e []     = e
 *   |  foldl f e (b:bs) = foldl f (f e b) bs
 */

/* Specialized to increasing/decreasing arithmetic sequences:
 *
 * [b1, b2, b3, ...] = [m, m+1, m+2, ..., n], or
 *                   = [m, m-1, m-2, ..., n]
 *
 *    cons                      f
 *   /   \                     / \
 *  m    cons                 f   m+2
 *       /  \         =>     /  \        =    (((e * b1) * b2) * b3)
 *    m+1   cons            f   m+1
 *          /  \           /  \
 *       m+2   nil        e   m
 */

double mul (double x, int y) {
  return x * y;
}

double fac (int N) {
  double (*f) (double, int) = mul; // a -> b -> a
  double acc = 1.0; // a
  int m = 1; // b list
  int n = N; // b list

  for (int i = m; i <= n; i += 1) { // increasing
    acc = f(acc, i);
  }

  return acc;
}

int main (void) {
  printf("fac(%d) == %f\n", 6, fac(6));
  return 0;
}
