#include <stdio.h>

int euclid (int m, int n) {
  /* assume m >= n */

  /* printf("> m == %d, n == %d\n", m, n); */

  if (n > 0) {
    return euclid(n, m % n);
  } else {
    return m;
  }
}

int main () {
  printf("(%d,%d) == %d\n", 558, 198, euclid(558, 198));
  puts("");
  printf("(%d,%d) == %d\n", 14, 11, euclid(14, 11));
  return 0;
}
