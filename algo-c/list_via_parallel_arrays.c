#include <stdio.h>
#include <stdlib.h>

struct list {
  int head;
  int z;
  int x;
  int * car;
  int * cdr;
};

struct list new_list (int max) {
  struct list l;
  int size = max + 2;
  l.car = (int *) malloc( sizeof(int) * size );
  l.cdr = (int *) malloc( sizeof(int) * size );

  l.head = 0;
  l.z = 1;
  l.x = 2;

  l.cdr[ l.head ] = l.z;
  l.cdr[ l.z ] = l.z;
  return l;
}

void delete_next (struct list l, int t) {
  l.cdr[ t ] = l.cdr[ l.cdr[ t ] ];
}

int insert_after(struct list * l, int v, int t) {
  int x = l->x;
  int * car = l->car;
  int * cdr = l->cdr;
  car[ x ] = v;
  cdr[ x ] = cdr[ t ];
  cdr[ t ] = x;
  l->x += 1;
  return x;
}

void print_list (struct list l) {
  int head = l.head;
  int z = l.z;
  int * car = l.car;
  int * cdr = l.cdr;

  int t = cdr[ head ];
  while (t != z) {
    printf( "%d ", car[ t ] );
    t = cdr[ t ];
  }
}

int main () {
  struct list l = new_list( 100 );
  insert_after( &l, 9, l.head );
  insert_after( &l, 2, l.head );
  insert_after( &l, 6, l.head );
  insert_after( &l, 7, l.head );
  print_list( l );
}
