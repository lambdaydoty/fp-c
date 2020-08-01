#include <stdio.h>


/**
 * (* fac : int -> int *)
 * fun fac n = if n > 1
 *              then n * fac (n - 1)
 *              else 1
 */


/**
 * n! = n * ((n-1) * ((n-2) * ... * 1))
 *
 * n! = (((n * (n-1)) * (n-2)) * ...) * 1
 */

int nontailrec_fac (int n) {
  if (n > 1) {
    return n * nontailrec_fac(n - 1);
  } else {
    return 1;
  }
}

int tailrec_fac (int n, int acc) {
  if (n > 1) {
    return tailrec_fac(n - 1, acc * n);
  } else {
    return acc;
  }
}

int whileloop_fac (int n, int acc) {
  while (n > 1) {
    /* (n, acc) = (n - 1, acc * n) */
    acc = acc * n;
    n = n - 1;
  }
  return acc;
}

int inlining_fac (int n) {
  /* return whileloop_fac(n, 1) */
  int acc = 1;
  while (n > 1) {
    acc = acc * n;
    n = n - 1;
  }
  return acc;
}

int main (void) {
  printf("nontailrec_fac(%d) == %d\n", 5, nontailrec_fac(5));
  printf("tailrec_fac(%d)    == %d\n", 5, tailrec_fac(5, 1));
  printf("whileloop_fac(%d)  == %d\n", 5, whileloop_fac(5, 1));
  printf("inlining_fac(%d)   == %d\n", 5, inlining_fac(5));
}
