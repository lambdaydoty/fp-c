#include <stdlib.h>
#include "c_intlinkedlist.h"

static Node * new_node () {
  Node * x = (Node *)malloc( sizeof (Node *) );
  return x;
}

Node * c_intlinkedlist_init () {
  Node * head = new_node();
  Node * z = new_node();
  head->next = z;
  z->next = z;
  return head;
}

Node * c_intlinkedlist_insertafter (Node * t, int v) {
  Node * x = new_node();
  x->key = v;
  x->next = t->next;
  t->next = x;
  return x;
}

Node * c_intlinkedlist_deletenext (Node * t) {
  t->next = t->next->next;
  return t;
}

