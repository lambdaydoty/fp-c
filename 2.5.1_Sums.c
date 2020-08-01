#include <stdio.h>

/**
 * (* sum : int -> int -> (int -> real) -> real *)
 * fun sum i n f = if (i > n)
 *                   then 0.0
 *                   else f i + sum (i + 1) n f
 */

double sum (
    int i,
    int n,
    double (*f) (int)
    ) {
  if (i > n) {
    return 0.0;
  } else {
    return f(i) + sum(i + 1, n, f);
  }
}

double id (int n) {
  return (double)n;
}

typedef enum { false = 0, true = 1 } bool;

bool isodd (int n) {
  return n % 2 == 1;
}

double npi (int n) {
  int sign = isodd(n)
    ? 1
    : -1
    ;
  return 1.0 * sign / (2 * n - 1);
}

int main (void) {
  printf("Sum_1^3{x} == %f\n", sum(1, 3, id));
  printf("NEARLY_PI == %f\n", 4.0 * sum(1, 10000, npi)); // exercise 2.11
}
