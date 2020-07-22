#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = 1 } bool;

// ∷ b → (a → b → b) → Int → Int → (Int → a) → b
double repeat (
    double base,
    double (* combine) ( double, double ),
    int i,
    int n,
    double (* f) ( int )
    ) {
  if (i > n) return base;
  return combine (
      f( i ),
      repeat( base, combine, i + 1, n, f )
      );
}

double add( double x, double y ) {
  return x + y;
}

double int2real( int i ) {
  return (double) i;
}

double terminal( int n ) {
  return repeat( 0.0, add, 1, n, int2real );
}

double cfrac( double x, double y ) {
  return x + 1.0 / y;
}

double ones( int i ) {
  return 1.0;
}

/* exercise 2.16 */
double nearly_phi ( int n ) {
#include <math.h>
  return repeat( INFINITY, cfrac, 1, n, ones );
}

int main( void ) {
  printf( "sum: %f\n", terminal( 10 ) );
  printf( "phi: %f\n", nearly_phi( 10 ) );

  exit (0);
}

