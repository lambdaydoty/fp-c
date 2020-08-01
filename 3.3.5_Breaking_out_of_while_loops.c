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

/**
 * General tail recursion schema
 *
 * (* f : (t_1 ... t_n) -> t_r *)
 * fun f (x_1, ..., x_n)
 *    = let
 *      val y_1 = z_1
 *      ...
 *      val y_j = z_j
 *    in
 *      if p_1 then q_1
 *      ...
 *      if p_k then q_k
 *      else q_{k+1}
 *    end
 *
 *  p_k = p_k(y_i) : bool
 *  q_k = f g_k (continuation with g_k of type (t_1 ... t_n)),  or
 *      = h_k   (termination with h_k of type t_r)
 */

typedef enum { false = 0, true = 1 } bool;

double bisection (
    double (*f) (double),
    double l,
    double h
    ) {
# define EPSILON 0.001
# define DELTA 0.001
# include <math.h>
  while (true) {
    double m = (h + l) / 2.0;
    double f_m = f(m);
    if (fabs(f_m) < EPSILON) {
      return m;
    } else if (fabs(h - l) < DELTA) {
      return m;
    } else if (f_m < 0.0) {
      /* (f, l, h) = (f, m, h) */
      f = f;
      l = m;
      h = h;
    } else {
      /* (f, l, h) = (f, l, m) */
      f = f;
      l = l;
      h = m;
    }
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
