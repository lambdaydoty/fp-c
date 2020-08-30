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

int cal (Node * root) {
  char c = root->info;
  if (isdigit(c)) return c - '0';
  if (c == '*') return cal(root->l) * cal(root->r);
  if (c == '+') return cal(root->l) + cal(root->r);
  abort();
}

int main () {
  Stack * s = new_stack(100);
  char c;
  for (; scanf("%1s", &c) != EOF;) {
    Node * x = new_node();
    Node * z = new_z_node();
    x->info = c;
    x->l = z;
    x->r = z;
    if (x->info == '+' || x->info == '*') {
      x->r = pop(s);
      x->l = pop(s);
    }
    push(s, x);
  }

  Node * r = pop(s);
  printf("%d\n", cal(r));
}
