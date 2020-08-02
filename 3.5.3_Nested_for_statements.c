#include <stdio.h>

/**
 * sum_of_powers: int -> int -> int
 *
 * fun sum_of_powers x b
 *    = sum (map (power b) [0..x])
 *
 * sum_of_sum_of_powers: int -> int -> int
 *
 * fun sum_of_powers x y
 *    = sum (map (sum_of_powers x) [0..y])
 */

# include <math.h>

/**
 *    x^y |   0  1  2  3  4  5
 * ----------------------------------------------------
 *     0  |   1  0  0  0  0  0
 *     1  |   1  1  1  1  1  1
 *     2  |   1  2  4  8 16 32   <- 1 + 2 + .. + 32 = s_o_p(5,2)
 *     3  |   1  3  9 27 81 243
 *
 *
 */
double sum_of_powers (int y, int x) {
  int acc = 0.0;
  int m = 0;
  int n = y;
  for (int i = m; i <= n; i += 1) {
    acc = acc + pow((double)x, (double)i);
  }
  return acc;
}

double sum_of_sum_of_powers (int y, int x) {
  int acc = 0.0;
  int m = 0;
  int n = x;
  for (int i = m; i <= n; i += 1) {
    acc = acc + sum_of_powers(y, i);
  }
  return acc;
}

double sosop_inline (int y, int x) {
  int acc = 0.0;
  for (int i = 0; i <= x; i += 1) {
    for (int j = 0; j <= y; j += 1) {
      acc = acc + pow((double) i, (double) j);
    }
  }
  return acc;
}

int main (void) {
  printf("h=%d w=%d sum=%f\n",
      4,
      5,
      sum_of_sum_of_powers(5, 4)
      );
  printf("h=%d w=%d inl=%f\n",
      4,
      5,
      sosop_inline(5, 4)
      );
  return 0;
}
