#ifndef C_INTLINKEDLIST_H
#define C_INTLINKEDLIST_H

typedef struct node {
  int key;
  struct node * next;
} Node;


extern Node * c_intlinkedlist_init ();
extern Node * c_intlinkedlist_insertafter (Node * t, int v);
extern Node * c_intlinkedlist_deletenext (Node * t);

#endif /* C_INTLINKEDLIST_H */
