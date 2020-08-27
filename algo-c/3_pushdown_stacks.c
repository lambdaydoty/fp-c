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
  Node * head = new_node();
  Node * z = new_node();
  head->next = z;
  z->next = z;
  return head;
}

void delete_next (Node * n) {
  n->next = n->next->next;
}

Node * insert_after (int val, Node * n) {
  Node * x = new_node();
  x->key = val;
  x->next = n->next;
  n->next = x;
  return x;
}

/* void print_list (Node * head, Node * z) { */
/*   for (Node * p = head->next; p != z; p = p->next) { */
/*     printf("%d ", p->key); */
/*   } */
/* } */

//////////////////////////////////////////////////

Node * new_stack () {
  return new_list();
}

Node * push (Node * head, int v) {
  insert_after( v, head );
  return head;
}

int pop (Node * head) {
  int v = head->next->key;
  delete_next( head );
  return v;
}

typedef enum { false = 0, true = 1 } bool;

bool is_stack_empty (Node * head) {
  return head->next->next == head->next;
}

void print_stack (Node * h) {
  for (
      Node * t = h->next;
      t != t->next;
      t = t->next) {
    printf( "%d ", t->key );
  }
  puts( "" );
}

void demo1 () {
  Node * h = new_stack();
  push( h, -1 );
  push( h, 9 );
  push( h, 2 );
  push( h, 6 );
  print_stack( h );

  printf("is_stack_empty? %s\n", is_stack_empty( h ) ? "true" : "false" );

  pop( h ); print_stack( h );
  pop( h ); print_stack( h );
  pop( h ); print_stack( h );
  pop( h ); print_stack( h );

  printf("is_stack_empty? %s\n", is_stack_empty( h ) ? "true" : "false" );
}

#include <ctype.h>

void demo2_reverse_polish () {
  Node * h = new_stack();
  char c;
  for (; scanf("%1s", &c) != EOF;) {
    if (c == ')') printf( "%1c", (char) pop( h ) );
    if (c == '+') push( h, (int) c );
    if (c == '*') push( h, (int) c );
    while (isdigit( c )) {
      printf( "%1c", c );
      scanf("%1c", &c );
    }
    if (c != '(') printf( " " );
  }
}

void demo2_eval () {
  Node * h = new_stack();
  char c;
  for (; scanf("%1s", &c) != EOF;) {
    int x = 0;
    if (c == ')') x = pop( h );
    if (c == '+') x = pop( h ) + pop( h );
    if (c == '*') x = pop( h ) * pop( h );
    while (isdigit( c )) {
      x = 10 * x + (c - '0');
      scanf("%1c", &c );
    }
    push( h, x );
  }

  printf( "ans: %d\n", pop( h ) );
}

int main () {
  /* demo2_reverse_polish( "( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )" ); */
  demo2_eval ();
}
