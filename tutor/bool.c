#include <stdio.h>

typedef enum { false = 0, true = 1 } bool;

bool even (int n) {
  return (n % 2) == 0;
}

int main () {
  for (int i = 0; i < 10; i += 1) {
    printf("n == %d, even(%d) == %d\n", i, i, even(i));
  }
}
