#include <stdio.h>


int subtractProductAndSum (int n) {
  int prod = 1;
  int sum = 0;
  for (int i = n; i != 0; i = i / 10) {
    int d = i % 10;
    prod = prod * d;
    sum = sum + d;
  }
  return prod - sum;
}

int main (void) {
  printf("%d\n", subtractProductAndSum(234));

  for (;;) {
    puts("123");
  }
  return 0;
}
