#include <stdio.h>

double foldl (
    double (*op) (double, double),
    double e,
    int m, /* inclusive */
    int n /* ! inclusive */
    ) {
  double acc = e;
  for (int i = m; i <= n; i += 1) {
    acc = op(acc, (double) i);
  }
  return acc;
}

double foldr (
    double (*op) (double, double),
    double e,
    int m, /* inclusive */
    int n /* ! inclusive */
    ) {
  double acc = e;
  for (int i = n; i >= m; i -= 1) {
    acc = op((double) i, acc);
  }
  return acc;
}

double add (double x, double y) { return x + y; }
double mul (double x, double y) { return x * y; }
double div (double x, double y) { return x / y; }

int main (void) {
  int m = 1;
  int n = 5;
  printf("%d %d %f\n", m, n, foldl(add, 0.0, m, n));
  printf("%d %d %f\n", m, n, foldl(mul, 1.0, m, n));
  printf("%d %d %f\n", 1, 3, foldl(div, 1.0, 1, 3));
  printf("%d %d %f\n", 1, 3, foldr(div, 1.0, 1, 3));
  return 0;
}
