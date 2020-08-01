#include <stdio.h>

/**
 * (* bisection : (real -> real) -> real -> real -> real *)
 * fun bisection f l h = let
 *                        val m = (l + h) / 2.0
 *                        val f_m = f m
 *                      in
 *                        if absolute f_m < epsilon
 *                          then m
 *                        else if absolute (h - l) < delta
 *                          then m
 *                        else if f_m < 0.0
 *                          then bisection f m h
 *                        else   bisection f l m
 */

double bisection (
    double (*f) (double),
    double l,
    double h
    ) {
# define EPSILON 0.001
# define DELTA 0.001
# include <math.h>
  double m = (h + l) / 2.0;
  double f_m = f(m);
  if (fabs(f_m) < EPSILON) {
    return m;
  } else if (fabs(h - l) < DELTA) {
    return m;
  } else if (f_m < 0.0) {
    return bisection(f, m, h);
  } else {
    return bisection(f, l, m);
  }
}

double parabola(double x) {
  return x * x - 2.0;
}

int main(void) {
  printf("%f\n", bisection(parabola, 1.0, 2.0 )) ;
  printf("%f\n", bisection(parabola, 0.0, 200.0)) ;
  printf("%f\n", bisection(parabola, 1.2, 1.5)) ;
  return 0 ;
}
