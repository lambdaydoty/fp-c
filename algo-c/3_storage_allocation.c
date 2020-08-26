#include <stdio.h>
#include <stdlib.h>

/**
 * Use `parallel arrays` to implement `linked lists`
 *
 */
#define KEY_T double

typedef struct List {
  int head;
  int z;
  int * n;
  int * cdr;
  KEY_T * car;
} List;

List new_list (int max) {
  List l;
  int size = max + 2;
  l.car = (KEY_T *) malloc( sizeof(KEY_T) * size );
  l.cdr = (int *) malloc( sizeof(int) * size );
  l.n = (int *) malloc ( sizeof(int) );

  l.head = 0;
  l.z = 1;
  *(l.n) = 2;

  l.cdr[ l.head ] = l.z;
  l.cdr[ l.z ] = l.z;
  return l;
}

void delete_next (List l, int t) {
  int * cdr = l.cdr;
  /* int temp = cdr[ t ]; */
  cdr[ t ] = cdr[ cdr[ t ] ];
  /* cdr[ temp ] = -1; */
}

int insert_after(List l, int v, int t) {
  int * n = l.n;
  int * cdr = l.cdr;
  KEY_T * car = l.car;
  car[ *n ] = v;
  cdr[ *n ] = cdr[ t ];
  cdr[ t ] = *n;
  *(l.n) += 1;
  return *n;
}

void print_list (List l) {
  int head = l.head;
  int z = l.z;
  KEY_T * car = l.car;
  int * cdr = l.cdr;

  int t = cdr[ head ];
  while (t != z) {
    printf( "%f ", car[ t ] );
    t = cdr[ t ];
  }
}

int main () {
  List l = new_list( 100 );

  insert_after( l, 9.0, l.head );
  insert_after( l, 2.0, l.head );
  insert_after( l, 6.0, l.head );
  insert_after( l, 7.0, l.head );
  delete_next( l, l.head );

  int * N = (l.n);
  int * cdr = l.cdr;
  KEY_T * car = l.car;
  puts( "i | cdr | car" );
  for (int i = 0; i < *N; i++) {
    printf( "%d | %d | %f\n", i, cdr[i], car[i] );
  }

  /**
   * head: 0
   * z   : 1
   * n   : *
   *
   *     cdr    car
   * +--+---+  +---+
   * |0 | 4 |  | * |
   * |1 | 1 |  | * |
   * +--+---+  +---+
   * |2 | 1 |  |9.0|
   * |3 | 2 |  |2.0|
   * |4 | 3 |  |6.0|
   * |5 | * |  |7.0|
   * +--+---+  +---+
   */

  print_list( l );
}
