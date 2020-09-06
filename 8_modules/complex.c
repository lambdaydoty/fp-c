#include <math.h>
#include "complex.h"

Complex complex (double re, double im) {
  Complex z = { re, im };
  return z;
}

Complex complex_sub ( Complex c, Complex d ) {
  Complex r;
  r.x = c.x - d.x;
  r.y = c.y - d.y;
  return r;
}

Complex complex_mult ( Complex c, Complex d ) {
  Complex r;
  r.x = c.x * d.x - c.y * d.y;
  r.y = c.x * d.y + c.y * d.x;
  return r;
}

Complex complex_conjugate ( Complex c ) {
  Complex r;
  r.x = c.x;
  r.y = -c.y;
  return r;
}

double re ( Complex c ) { return c.x; }
double im ( Complex c ) { return c.y; }

double complex_distance ( Complex c ) {
  return (
      sqrt(
        re(
          complex_mult(
            c,
            complex_conjugate( c )))));
}
