#include <stdio.h>
/**
 * (* foldr : (b -> a -> a) -> a -> b list -> a *)
 *
 *    cons                   f
 *   /   \                 /   \
 *  b1   cons             b1    f
 *       /  \         =>       /  \           =  (b1 * (b2 * (b3 * e)))
 *     b2   cons             b2    f
 *          /  \                  /  \
 *        b3   nil              b3    e
 *
 *  fun foldr f e []     = e
 *   |  foldr f e (b:bs) = f b (foldr f e bs)
 */

/* Specialized to increasing/decreasing arithmetic sequences:
 *
 * [b1, b2, b3, ...] = [m, m+1, m+2, ..., n], or
 *                   = [m, m-1, m-2, ..., n]
 *
 *    cons                    f
 *   /   \                  /   \
 *  m    cons              m     f
 *       /  \         =>        /  \
 *    m+1   cons             m+1    f
 *          /  \                   /  \
 *       m+2   nil              m+2   nil
 */

double mul (int x, double y) {
  return x * y;
}

double fac (int N) {
  double (*f) (int, double) = mul; // a -> b -> a
  double acc = 1.0; // a
  int m = 1; // b list
  int n = N; // b list

  for (int i = n; i >= m; i -= 1) { // increasing
    acc = f(i, acc);
  }

  return acc;
}

int main (void) {
  printf("fac(%d) == %f\n", 6, fac(6));
  return 0;
}
