#include <stdio.h>

int temp;

#define swap(x, y) \
  temp = x; \
  x = y; \
  y = temp

extern void print (int [], int);
extern void quicksort (int [], int, int);

int main () {
  int a[] = {0, 9, 2, 6, 7, 2, 7, 2, 1, 2};
  int N = sizeof(a) / sizeof(int);
  print(a, N);
  puts("");
  quicksort(a, 1, N - 1);
  print(a, N);
  puts("");
}

void quicksort (int a[], int l, int r) {
  if (r > l) {
    int v = a[r];
    int i = l - 1;
    int j = r;
    for (;;) {
      while (a[++i] < v);
      while (v < a[--j]);
      if (i >= j) break;
      swap(a[i], a[j]);
      /* printf("i, j = %d %d |", i, j); */
      /* print(a, r - l + 2); */
      /* puts(""); */
    }
    swap(a[i], a[r]);
    /* print(a, r - l + 2); */
    /* puts(""); */
    /* puts(""); */
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
  }
}

void print (int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}
