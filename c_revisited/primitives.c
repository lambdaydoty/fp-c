#include <stdio.h>

typedef enum {
  false = 0,
  true = 1,
} bool;

bool not (bool b) {
  return !b;
}

int main (void) {
  int n = 3;
  bool b = true;
  double x = 3.0;
  char c = 'A';

  printf("n == %d\n", n);
  printf("b == %d\n", not(b));
  printf("x == %f\n", x);
  printf("c == %c\n", c);
}


