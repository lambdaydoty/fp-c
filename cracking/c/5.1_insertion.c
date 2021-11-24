#include <stdio.h>

int main () {
  int m;
  int n;
  int i;
  int j;
  int mask;

  m = 19;
  n = 1024;
  i = 2;
  j = 6;
  /* printf("m, n, i, j:"); */
  /* scanf("%d %d %d %d", &m, &n, &i, &j); */

  printf("m == %d, n == %d, i == %d, j == %d\n", m, n, i, j);
  puts("");

  mask = -1;
  mask = mask << (j - i + 1);
  mask = ~mask;
  mask = mask << i;
  mask = ~mask;

  /**
   * 1000 0000 000 <--- N
   *      j    i
   *      1001 1 <----- M
   *
   * 1111 0000 011 <-- mask
   *
   * shifted
   *        4    0
   * 001000 0000 0 <--- N'
   *        1001 1 <--- M
   *
   * 1000 1001 100
   */

  printf("mask = %X\n", mask);
  puts("");
  printf("n' == %d\n", (n & mask) | (m << 2));
}
