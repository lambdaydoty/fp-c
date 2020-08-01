#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = 1 } bool;

// ∷ b → (a → b → b) → Int → Int → (Int → a) → b
double repeat (
    double base,
    double (*combinator) (double, double),
    int i,
    int n,
    double (*f) (int)
    ) {
  if (i > n) {
    return base;
  } else {
    return combinator(
        f(i),
        repeat(base, combinator, i + 1, n, f)
        );
  }
}

/* sum */

double add(double x, double y) {
  return x + y;
}

double sum(int i, int n, double (*f) (int)) {
  return repeat(0.0, add, i, n, f);
}

double int2real(int i) {
  return (double)i;
}

/* product */

double mul(double x, double y) {
  return x * y;
}

double product(int i, int n, double (*f) (int)) {
  return repeat(1.0, mul, 1, n, f);
}

/* phi, exercise 2.16 */

double cfrac(double x, double y) {
  return x + 1.0 / y;
}

double ones(int i) {
  return 1.0;
}

double nearly_phi (int n) {
# include <math.h>
  return repeat(INFINITY, cfrac, 1, n, ones);
}

/* e, exercise 2.13 */

double invfac (int i) {
  return 1.0 / product(1, i, int2real);
}

double nearly_e (int n) {
  return sum(0, n, invfac);
}

int main(void) {
  printf("sum_k: %f\n", sum(1, 10, int2real));
  printf("fac_n: %f\n", product(1, 5, int2real));
  printf("fac_n: %f\n", product(1, 0, int2real));
  printf("phi:   %f\n", nearly_phi(10));
  printf("e:     %f\n", nearly_e(10));
  exit(0);
}

