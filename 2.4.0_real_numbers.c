#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = 1 } bool;

double square ( double x ) {
  return x * x;
}

bool isodd ( int x ) {
  return x % 2 == 1;
}

double power ( double r, int p ) {
  if (p == 0) {
    return 1.0;
  } else if (isodd(p)) {
    return r * power( r, p - 1 );
  } else {
    return square( power( r, p / 2 ) );
  }
}

int main ( void ) {
  printf( "%f\n", power( 3, 0 ) );
  printf( "%f\n", power( 5, 4 ) );
  printf( "%f\n", power( 1.037155, 19 ) );

  puts( "" );

  printf( "%f\n", 1.0 + 5.0 / 2.0 );
  printf( "%f\n", 1.0 + 5 / 2.0 );
  printf( "%f\n", 1.0 + 5 / 2 ); // !

  printf( "%f\n", 0.1 );
  exit (0);
}

