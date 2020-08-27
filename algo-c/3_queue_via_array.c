#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/**
 * max = 6
 *
 *   +---+                   +---+              +---+
 * 0 |   | <- head/tail    0 | -1| <- head    0 | -1|  <- head/tail
 * 1 |   |                 1 |  9|            1 |  9|
 * 2 |   |                 2 |  2|            2 |  2|
 * 3 |   |                 3 |  6|            3 |  6|
 * 4 |   |                 4 |  7|            4 |  7|
 * 5 |   |                 5 |  2|            5 |  2|
 * 6 |   |                 6 |   | <- tail    6 |  7|
 *   +---+                   +---+              +---+
 */
typedef struct {
  int * queue;
  int head;
  int tail;
  int max;
} Queue;

typedef enum { false = 0, true = 1 } bool;

Queue * new_queue (int max) {
  Queue * q = (Queue *) malloc( sizeof(Queue) );
  q->head = 0;
  q->tail = 0;
  q->max = max;
  q->queue = (int *) malloc( sizeof(int) * (1 + max) );
  return q;
}

bool is_queue_empty (Queue * q) {
  return q->head == q->tail;
}

bool enqueue (Queue * q, int v) {
  q->queue[ q->tail ] = v;
  q->tail += 1;
  if (q->tail > q->max) q->tail = 0;
  return q->head == q->tail;
}

int dequeue (Queue * q) {
  int v = q->queue[ q->head ];
  q->head += 1;
  if (q->head > q->max) q->head = 0;
  return v;
}

void print_queue (Queue * q) {
  int i = q->head;
  printf( "[ " );
  while (i != q->tail) {
    printf( "%d ", q->queue[i] );
    i += 1;
    if (i > q->max) i = 0;
  }
  printf( "]\n" );
}

int main () {
  int max = 6;
  Queue * q = new_queue( max );
  if (enqueue( q, -1 )) printf( "full!\n" );
  if (enqueue( q, 9 )) printf( "full!\n" );
  if (enqueue( q, 2 )) printf( "full!\n" );
  if (enqueue( q, 6 )) printf( "full!\n" );
  if (enqueue( q, 7 )) printf( "full!\n" );
  if (enqueue( q, 2 )) printf( "full!\n" );

  print_queue( q );

  if (enqueue( q, 7 )) printf( "full!\n" );

  print_queue( q );

  int v = dequeue( q );

  printf( "v == %d\n", v );

  print_queue( q );
}
