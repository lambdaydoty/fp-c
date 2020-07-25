#include <stdio.h>

typedef enum { true = 1, false = 0 } bool;

bool even (int n) {
  return (n % 2) == 0;
}

double square (double x) {
  return x * x;
}

double power (double r, int p) {
  /* assume p >= 0 */

  printf("> r == %f, p == %d\n", r, p);

  if (p == 0) {
    return 1.0;
  } else if (even(p)) {
    return square( power( r, p/2 ) );
  } else {
    return r * power( r, p-1 );
  }
}

int main () {
  double r = 3.0;
  int p = 7;

  printf("%f^%d == %f\n", r, p, power(r, p));

  return 0;
}
