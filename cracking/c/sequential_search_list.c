#include <stdlib.h>
#define maxN 10000

/**
 * Linked-list Implementation
 * (keep sorted)
 */
struct node {
  int key;
  int info;
  struct node * next;
};
struct node * head;
struct node * z;
void list_init () {
  head = (struct node *) malloc (sizeof *head);
  z = (struct node *) malloc (sizeof *z);
  head->next = z;
  z->next = z;
  z->info = -1; //
}
void list_insert (int k, int info) {
  struct node * p;
  p = head;
  z->key = k; // sentinal
  while (k > p->next->key) { p = p->next; }
  struct node * x = malloc (sizeof *x);
  x->key = k;
  x->info = info;
  x->next = p->next;
  p->next = x;
}
int list_search (int k) {
  struct node * p;
  p = head->next; // <---- !!!?
  z->key = k;
  while (k > p->key) { p = p->next; }
  if (k != p->key) return z->info;
  return p->info;
}
