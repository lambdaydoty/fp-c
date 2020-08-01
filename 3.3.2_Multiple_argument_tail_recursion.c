#include <stdio.h>

/**
 * (* Multiple argument tail recursion *)
 *
 * (* f : (t_1 ... t_n) -> t_r *)
 *
 * fun f (x_1, ..., x_n)
 *   = if p
 *      then f g
 *      else h
 *
 * p = p(x_1, ..., x_n)
 * g = g(x_1, ..., x_n)
 * h = h(x_1, ..., x_n)
 */

/**
 * C: Multiple argument while-schema
 *
 * t_r f (t_1 x_1, ..., t_n x_n) {
 *     while (p) {
 *         (x_1, ..., x_n) = g;
 *     }
 *     return h;
 * }
 */

/* modulus */

/**
 * (* modulus : int -> int -> int *)
 * fun modulus m n = if m >= n
 *                    then modulus (m - n) n
 *                    else m
 */

int modulus (int m, int n) {
  while (m >= n) {
    /* (m, n) = (m - n, n) */
    m = m - n;
    n = n;
  }
  return m;
}

/* euclid */

/**
 * (* euclid : int -> int -> int *)
 * fun euclid m n = if n != 0
 *                  then euclid n (m % n)
 *                  else m
 */

int euclid (int m, int n) {
  while (n != 0) {
    /* (m, n) = (n, m % n) */
    int _m = n;
    int _n = m % n;
    m = _m;
    n = _n;
  }
  return m;
}

int main (void) {
  printf("modulus(%d,%d) == %d\n", 1234, 17, modulus(1234, 17));
  printf("euclid(%d,%d)  == %d\n", 90, 60, euclid(90, 60));
}

