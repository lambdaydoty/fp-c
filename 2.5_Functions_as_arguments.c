#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = 1 } bool;

double sum (
    int i,
    int n,
    double (* f) ( int )
    ) {
  if (i > n) return 0.0;
  return f( i ) + sum( i + 1, n, f );
}

double int2real( int i ) {
  return (double) i;
}

double terminal( int n ) {
  return sum( 1, n, int2real );
}

bool isodd( int x ) {
  return x % 2 == 1;
}

double pi_term( int i ) {
  /**
   * 1 => 1
   * 2 => -1/3
   * 3 => 1/5
   * 4 => -1/7
   * ...
   */
  int sign = isodd( i )
    ? 1
    : -1
    ;
  return sign * 1.0 / (2 * i - 1);
}

double nearly_pi( int n ) {
  return sum( 1, n, pi_term );
}

int main( void ) {
  printf( "%f\n", terminal( 10 ) );
  printf( "%f\n", nearly_pi( 100 ) * 4 );

  exit (0);
}

