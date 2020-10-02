#include <stdio.h>
#include <stdlib.h>

/* #define DEF_NODE (T_KEY, T_NODE, T_LIST)    \ */
/*   typedef struct T_NODE {                   \ */
/*     T_KEY key;                              \ */
/*     struct T_NODE * next;                   \ */
/*   } * T_LIST */

typedef struct node {
  int key;
  struct node * next;
} Node;

Node * new_node () {
  Node * x = (Node *)malloc(sizeof *x);
  x->next = NULL;
  return x;
}

Node * new_list () {
  /**
   *
   * dummy node linked list:
   *  1) head points to an empty node (whose next points to the first node)
   *     -> o.w. the insertion would need a null-test at the beginning of the list.
   *  2) z points to an empty node (whose next points to itself)
   *     -> o.w. the deletion would need a null-test check
   *
   * head:[.] -> [ |.]      head:[.] -> [ |.]
   *                |                      |
   *                v                      v
   *    z:[.] -> [ |.]                  [3|.]
   *                                       |
   *                                       v
   *                           z:[.] -> [ |.]
   *
   * vs. --------------------------------------------------
   *
   * head:[@]               head:[.] -> [3|@]        head:[.] -> [4|.] -> [3|@]
   *
   * see. Aho [6.4]
   *
   *
   */

  Node * head = new_node();
  Node * z = new_node();
  head->next = z;
  z->next = z;
  return head;
}

void delete_next (Node * n) {
  /* works for empty list ! */
  // TODO: free
  n->next = n->next->next;
}

Node * insert_after (int val, Node * n) {
  Node * x = new_node();
  x->key = val;
  x->next = n->next;
  n->next = x;
  return x;
}

// TODO
int length (Node * t) {
  return t->next == t->next->next
    ? 0
    : 1 + length (t->next)
    ;
}

void print_list (Node * head, Node * z) {
  for (Node * p = head->next; p != z; p = p->next) {
    printf("%d ", p->key);
  }
}

/**
 * Josephus Problem
 *
 * 5 6 7 8 9 1 2 3 4
 * x . . . . x . . .
 *   . x . .   . . x
 *   .   . .   . x
 *   .   . .   .
 *   x   . .   .
 *       . x   .
 *       .     .
 *       .     x
 *       o
 */

int josephus (int N, int M) {
  Node * x = NULL;
  Node * t = NULL;
  x = t = new_node();
  /*
   * x ->
   * t -> [.|\]
   */
  t->key = 1;
  for (int i = 2; i <= N; i++) {
    t->next = new_node();
    t->next->key = i;
    t = t->next;
  }
  t->next = x;

  /**
   * x -> [1|.]
   *    /    |
   *   |     v
   *   |  [2|.]
   *   |     |
   *   |     v
   *   |  [3|.]
   *   |     |
   *   +-----+
   */

  /* now t points to the final node */
  while (t->next != t) {
    for (int i = 1; i < M; i++) { t = t->next; }
    printf( "to be delete %d\n", t->next->key );
    delete_next(t);
  }

  printf( "final %d\n", t->key );
  return t->key;
}

int main () {
  Node * t = new_list();
  Node * z = t->next;
  insert_after( 0, t );
  insert_after( 9, t );
  insert_after( 2, t );
  insert_after( 6, t );
  delete_next( t );
  print_list( t, z );
  printf( "length == %d\n", length( t ) );

  int * a = (int *)malloc(sizeof(int) * 10);
  a[0] = -1;
  a[1] = 9;
  a[2] = 2;
  a[3] = 6;

  puts( "" );
  printf( "t                        == %p\n", t );
  printf( "t->key                   == %d\n", t->key );
  printf( "t->next->key             == %d\n", t->next->key );
  printf( "t->next->next->key       == %d\n", t->next->next->key );
  printf( "t->next->next->next->key == %d\n", t->next->next->next->key );

  puts( "" );
  printf( "a    == %p\n", a );
  printf( "a[0] == %d\n", a[0] );
  printf( "a[1] == %d\n", a[1] );
  printf( "a[2] == %d\n", a[2] );
  printf( "a[3] == %d\n", a[3] );

  puts( "" );
  josephus( /* N */ 9, /* M */ 5 );
}

