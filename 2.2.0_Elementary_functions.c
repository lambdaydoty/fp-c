
/**
 * euclid ∷ (N x N) → N
 *
 * euclid (m, n) = euclid(n, m mod n), if (n > 0)
 *               = m                 , otherwise
 */

#include <stdio.h>

int euclid (int m, int n) {
  if (n > 0) {
    return  euclid (n, m % n);
  } else {
    return m;
  }
}

int main (void) {
  printf("%d %d %d\n",
      euclid(14, 12),
      euclid(14, 11),
      euclid(558, 198)
      );
}

