#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100000
typedef struct {
  int *arr;
  int N;
  int (*cmp) (int, int);
} Heap;

Heap *  heapCreate (int (*cmp) (int, int)) {
  Heap * h = (Heap *)malloc(sizeof (Heap *));
  h->N = 0;
  h->arr = (int *)malloc(MAX_HEAP + 1);
  h->cmp = cmp;
  return h;
}

/**
 *         0             level: 0
 *     1        2        level: 1
 *   3  4     5   6      level: 2
 * 7 ...            14
 */

void upheap (Heap *h, int n) {
  int *arr = h->arr;
  int (*cmp) (int, int) = h->cmp;
  int val = arr[n];
  while ((n - 1) >= 0) {
    int up = (n - 1) / 2;
    if (cmp(arr[up], val) >= 0) break;
    arr[n] = arr[up];
    n = up;
  }
  arr[n] = val;
}

void downheap (Heap *h, int n) {
  int *arr = h->arr;
  int (*cmp) (int, int) = h->cmp;
  int N = h->N; // by value
  int val = arr[n];
  while (2 * n + 1 < N) {
    int downl = n * 2 + 1;
    int downr = n * 2 + 2;
    int down = (downr == N - 1) ? downl
      : (cmp(arr[downl], arr[downr]) >= 0) ? downl
      : downr
      ;
    if (cmp(val, arr[down]) >= 0) break;
    arr[n] = arr[down];
    n = down;
  }
  arr[n] = val;
}

void heapInsert (Heap *h, int val) {
  int *arr = h->arr;
  int N = h->N; // by value
  arr[N] = val;
  h->N++;
  upheap(h, N);
}

int heapRemove (Heap *h) {
  int *arr = h->arr;
  int N = h->N; // by value
  int val = arr[0];
  arr[0] = arr[N - 1];
  h->N--;
  downheap(h, 0);
  return val;
}

void heapDeleteValue (Heap *h, int val) {
  int *arr = h->arr;
  int N = h->N;
  int i = 0;
  while (i < N && arr[i] != val) { i++; }
  if (i == N) return;
  arr[i] = arr[N - 1];
  h->N--;
  downheap(h, i);
}

int gt (int x, int y) { return x - y; }
int lt (int x, int y) { return y - x; }

extern void print_heap(Heap *);

int main () {
  Heap * maxH = heapCreate(gt);
  Heap * minH = heapCreate(lt);
  int numbers[] = { 0, 9, 2, 6, 7, 2, 7, 2, 1, 2 };
  for (int i = 0; i < 10; i++) {
    heapInsert(maxH, numbers[i]);
    heapInsert(minH, numbers[i]);
    printf("insert (%d): ", numbers[i]);
    /* print_heap(maxH); */
  }
  puts("");
  for (int i = 0; i < 10; i++) { printf("%d\n", heapRemove(maxH)); }
  for (int i = 0; i < 10; i++) { printf("%d\n", heapRemove(minH)); }
}

void print_heap (Heap * maxH) {
  int *a = maxH->arr;
  int N = maxH->N;
  printf("(heap): ");
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  puts("");
}
