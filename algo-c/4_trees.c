#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
  char info;
  struct node *l;
  struct node *r;
} Node;

Node * new_node () {
  return (Node *)malloc(sizeof(Node *));
}

Node * new_z_node () {
  Node * z = new_node();
  z->l = z;
  z->r = z;

  return z;
}

typedef enum { false = 0, true = 1 } bool;

typedef struct stack {
  Node ** arr;
  int n;
} Stack;

Stack * new_stack (int max) {
  Stack * s = (Stack *)malloc(sizeof(Stack));
  s->n = 0;
  s->arr = (Node **)malloc(sizeof(Node *) * (max + 1));
  return s;
}

Stack * push (Stack * s, Node * x) {
  s->arr[s->n] = x;
  s->n += 1;
  return s;
}

Node * pop (Stack * s) {
  s->n -= 1;
  return s->arr[s->n];
}

Node * peek (Stack * s) {
  return s->arr[s->n - 1];
}

bool empty (Stack * s) {
  return s->n == 0;
}

void print_stack (Stack * s) {
  int n = s->n;
  printf("[");
  for (int i = n - 1; i >= 0; i--) {
    printf("%c", s->arr[i]->info);
    printf("%c", i == 0 ? ']' : ' ');
  }
}

int cal (Node * root) {
  char c = root->info;
  if (isdigit(c)) return c - '0';
  if (c == '*') return cal(root->l) * cal(root->r);
  if (c == '+') return cal(root->l) + cal(root->r);
  abort();
}

#define INPUT "9 1 2 + 4 * 5 +"

Node * constructor (char, Node *, Node *);

void visit (Node * x) {
 printf("%c ", x->info);
}

#define Z(x) ((x->l == x) && (x->r == x))

void preorder (Node * x) {
  /*
  if (!Z( x )) {
    visit( x );
    preorder( x->l );
    preorder( x->r );
  }
  */

  /*
  while (!Z( x )) {
    visit( x );
    preorder( x-> l );
    x = x->r;
  }
  */

  /*
  Stack * ctx = new_stack(100);
  while (!Z( x ) || !empty( ctx )) {
    if (!Z( x )) {
      visit( x );
      push( ctx, x ); x = x->l;
    } else {
      x = pop( ctx ); x = x->r;
    }
  }
  */


  Stack * ctx = new_stack(100);
  while (true) {
    if (!Z( x )) {
      visit( x );
      push( ctx, x ); x = x->l;
      continue;
    } else if (!empty( ctx )){
      x = pop( ctx ); x = x->r;
    } else {
      break;
    }
  }
}

void inorder (Node * x) {
  /*
  if (!Z( x )) {
     inorder( x->l );
     visit( x );
     inorder( x->r );
  }
  */

  /*
  while (!Z( x )) {
    inorder( x->l );
    visit( x );
    x = x->r;
  }
  */

  Stack * ctx = new_stack( 100 );
  while (!Z( x ) || !empty( ctx )) {
    if (!Z( x )) {
      /* recurse */
      push( ctx, x ); x = x->l;
    } else {
      /* returning */
      x = pop( ctx );
      visit(x);
      x = x->r;
    }
  }
}

void postorder (Node * x) {
  /*
  if (!Z( x )) {
     postorder( x->l );
     postorder( x->r );
     visit( x );
  }
  */

  Stack * ctx1 = new_stack( 100 );
  Node * last = NULL;
  while (!Z( x ) || !empty( ctx1 )) {
    ///
    printf("(x: %c) ", x->info);
    printf("(last: %c) ", last == NULL ? ' ' : last->info);
    print_stack( ctx1 );
    getchar();
    ///
    if (!Z( x )) {
      push( ctx1, x ); x = x->l;
    } else {
      Node * p = peek( ctx1 );
      if (!Z( p->r ) && p->r != last) {
        x = p->r;
      } else {
        visit( pop( ctx1 ) );
        last = p;
      }
    }
  }

  /* Stack * ctx1 = new_stack( 100 ); */
  /* Node * last = NULL; */
  /* while (!Z( x ) || !empty( ctx1 )) { */
  /*   getchar(); */
  /*   printf("x == %c ", x->info); */
  /*   print_stack( ctx1 ); */
  /*   puts(""); */
  /*   if (!Z( x )) { */
  /*     push( ctx1, x ); x = x->l; */
  /*   } else { */
  /*     Node * savex = x; */
  /*     Node * x = pop( ctx1 ); */
  /*     if (!Z( x->r ) && x->r != last) { */
  /*       push( ctx1, x ); x = x->r; */
  /*     } else { */
  /*       visit( x ); */
  /*       last = x; */
  /*       x = savex; */
  /*     } */
  /*   } */
  /* } */
}

int main () {
  /* Stack * s = new_stack(100); */
  /* char c; */
  /* for (; scanf("%1s", &c) != EOF;) { */
  /*   Node * x = new_node(); */
  /*   Node * z = new_z_node(); */
  /*   x->info = c; */
  /*   x->l = z; */
  /*   x->r = z; */
  /*   if (x->info == '+' || x->info == '*') { */
  /*     x->r = pop(s); */
  /*     x->l = pop(s); */
  /*   } */
  /*   push(s, x); */
  /* } */

  /* Node * r = pop(s); */
  /* printf("%d\n", cal(r)); */

  ///

  Node * z = new_z_node();
  Node * t = constructor('*',
      constructor('A', z, z),
      constructor('+',
        constructor('*',
          constructor('+',
            constructor('B', z, z),
            constructor('C', z, z)),
          constructor('*',
            constructor('D', z, z),
            constructor('E', z, z))),
        constructor('F', z, z)));

  // preorder
  Stack * st = new_stack(100);
  push(st, t);
  while (!empty( st )) {
    Node * x = pop( st );
    visit(x);
    if (x->r != z) push(st, x->r);
    if (x->l != z) push(st, x->l);
  }

  puts("");
  preorder( t );

  puts("");
  inorder( t );

  puts("");
  postorder( t );
}

Node * constructor (char info, Node * l, Node * r) {
  Node * x = new_node();
  x->info = info;
  x->l = l;
  x->r = r;
  return x;
}

