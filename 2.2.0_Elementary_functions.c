
/**
 * euclid ∷ (N x N) → N
 *
 * euclid (m, n) = euclid(n, m mod n), if (n > 0)
 *               =                  m, otherwise
 */

/**
 * (* euclid : int -> int -> int *)
 * fun euclid m n = if n > 0
 *                     then euclid n (m mod n)
 *                     else m;
 */

#include <stdio.h>

int euclid (int m, int n) {
  if (n > 0) {
    return  euclid(n, m % n);
  } else {
    return m;
  }
}

int main (void) {
  printf("%d\n", euclid(14, 12));
  printf("%d\n", euclid(14, 11));
  printf("%d\n", euclid(558, 198));
  return 0;
}

