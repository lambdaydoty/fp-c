#include <assert.h>
#include "bool.h"
#include "complex.h"

Complex complex (double re, double im) {
  Complex z = { re, im };
  return z;
}

Complex complex_square ( Complex c ) {
  return complex_mult( c, c );
}

bool complex_eq ( Complex c, Complex d ) {
  double E = 0.00001;
  Complex e = complex_sub( c, d );
  double dist = complex_distance( e );
  return dist < E;
}

int main () {
  Complex z = complex( 1.0, 1.0 ); // 1 + i
  Complex z_sq = complex_square( z );
  Complex w = complex( 0, 2.0 );
  assert( complex_eq( w, z_sq ) );
}
