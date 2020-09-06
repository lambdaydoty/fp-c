#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
  /* x + yi */
  double x;
  double y;
} Complex;

extern Complex complex ( double, double );
extern Complex complex_sub ( Complex, Complex );
extern Complex complex_mult ( Complex, Complex );
extern Complex complex_conjugate ( Complex );
extern double complex_distance ( Complex );
extern double re ( Complex );
extern double im ( Complex );

#endif /* COMPLEX_H */
