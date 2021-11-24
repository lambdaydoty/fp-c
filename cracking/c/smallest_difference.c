#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * ref:
 * https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/
 */

void print (int *, int);
void sort (int *, int, int);
int smallest_diff (int , int * , int , int *);

int main () {
  int a1[] = {1, 3, 15, 11, 2}; // N = 5
  int a2[] = {23, 127, 235, 19, 8}; // N = 5
  /* assert(smallest_diff(5, a1, 5, a2) == 3); */
  assert(smallest_diff(5, a1, 5, a2) == 3);

  int b1[] = {1, 2, 11, 15}; // N = 4
  int b2[] = {4, 12, 19, 23, 127, 235}; // N = 6
  assert(smallest_diff(4, b1, 6, b2) == 1);

  int c1[] = {10, 5, 40}; // N = 3
  int c2[] = {50, 90, 80}; // N = 3
  assert(smallest_diff(3, c1, 3, c2) == 10);

  printf("*ok*");
}

void print (int * arr, int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}

int smallest_diff (int lenA, int * A, int lenB, int * B) {
# define MIN(x, y) ((x) < (y) ? (x) : (y))
  sort(A, 0, lenA - 1);
  sort(B, 0, lenB - 1);

  int m = 999999999; // MAX

  int j = 0;
  for (int i = 0; i < lenA; i++) {
    /* puts(""); */
    /* printf("A[%d] = %d, B[%d] = %d\n", i, A[i], j, B[j]); */
    while (B[j] < A[i]) { j++; }

    if (j < lenB) { m = MIN(m, abs(A[i] - B[j])); }
    if (j-1 >= 0) { m = MIN(m, abs(A[i] - B[j-1])); }
    /* printf("min = %d with (i,j) = (%d,%d)\n", m, i, j); */
  }

  /* puts("*done*"); */
  return m;
}

void sort (int * arr, int l, int r) {
  if (r > l) {
    /* puts(""); */
    /* puts(""); */
    /* printf("(r, l) = (%d,%d)\n", r, l); */
    /* print(arr, 10); */
    int i = l - 1;
    int j = r;
    int p = arr[r];
    for (;;) {
      while (arr[++i] < p);
      while (arr[--j] > p);
      if (i >= j) break;
      /* arr[i] > p > arr[j] */
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    sort(arr, l, i - 1);
    sort(arr, i + 1, r);
  }
}

/* int smallest_diff (int lenA, int * A, int lenB, int * B) { */
/*   sort(A, 0, lenA - 1); */
/*   sort(B, 0, lenB - 1); */
/*   int i = 0; */
/*   int j = 0; */

/*   int min = 999999999; // MAX */

/*   /1* print(A, 5); *1/ */
/*   /1* print(B, 5); *1/ */
/*   while (i < lenA && j < lenB) { */
/*     if (abs(A[i] - B[j]) < min) { */
/*       min = abs(A[i] - B[j]); */
/*     } */
/*     /1* printf("A[%d], B[%d], min = %d\n", i, j, min); *1/ */
/*     if (min == 0) return 0; */
/*     if (A[i] < B[j]) { */
/*       i++; */
/*     } else { */
/*       j++; */
/*     } */
/*   } */
/*   return min; */
/* } */
