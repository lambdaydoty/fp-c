#include <stdio.h>
#include <stdlib.h>

/**
 * ------------+--+--+--+--+
 * x:0x....904:|00|00|01|02|
 * ------------+--+--+--+--+
 * y:0x....900:|00|00|00|00|
 * ------------+--+--+--+--+
 *  ...
 * ------------+--+--+--+--+
 * p:0x.......:|0x....904  |
 * ------------+--+--+--+--+
 * q:0x.......:|0x....904  |
 * ------------+--+--+--+--+
 */

int *new_int_array (int size) {
  return (int *)malloc(sizeof(int) * size);
}

int main (void) {
  int A[2] = { 0, 1 };
  int size = 0;
  int *sequence = NULL;

  scanf("%d", &size);
  printf("sizeof(int) == %ld\n", sizeof(int));
  printf("size == %d\n", size);

  sequence = new_int_array(size);

  for (int i = 0; i < size; i += 1) {
    sequence[i] = i + 1; // i[sequence]
  }

  for (int i = 0; i < size; i+= 1) {
    printf("sequence[%d] == %d\n", i, sequence[i]);
  }

  puts("");
  printf("&size:    %p\n", &size);
  printf("sequence: %p\n", sequence);
  printf("sequence':%p\n", sequence + 1);
  printf("A:        %p\n", A);
  printf("A':       %p\n", A + 1);
  printf("main:     %p\n", main);
  printf("main':    %p\n", main + 1);
}

/* int main (void) { */
/*   /1* int temp[4] = { 1, 2, 3, 4 }; *1/ */
/*   int x =  0x02 + 0x100; */

/*   int *p = NULL; */
/*   char *q = NULL; */

/*   printf("x == %d\n", x); */

/*   p = &x; */
/*   q = (char *)&x; */

/*   printf("p   == %p\n", p); */
/*   printf("q   == %p\n", q); */
/*   printf("p+1 == %p\n", p + 1); */
/*   printf("q+1 == %p\n", q + 1); */

/*   printf("*p== %d\n", *p); */
/*   printf("*q== %d\n", *q); */

/*   puts(""); */
/*   for (int i = 0; i < 4; i += 1) { */
/*     /1* printf("temp[%d] == %d\n", i, temp[i]); *1/ */
/*   } */

/*   p = temp; */
/*   q = temp; */

/*   for (int i = 0; i < 4; i += 1) { */
/*     puts(""); */
/*     printf("p[%d] == %d\n", i, p[i]); */
/*     printf("q[%d] == %d\n", i, q[i]); */
/*   } */
/* } */


