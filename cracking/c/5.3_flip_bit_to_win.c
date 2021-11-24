#include <stdio.h>
#include <assert.h>

#define N 32

extern int max (int *, int);
extern void print_array (int *, int);
extern int flip (int);

int main () {
  assert(flip(1775) == 8);
  assert(flip(12) == 3);
  assert(flip(15) == 5);
  assert(flip(71) == 4);
}

int flip (int n) {
  int bits[N];

  /* printf("n = %d\n", n); */

  for (int i = 0; i < N; i++) {
    bits[i] = ((1 << i) & n) >> i;
  }
  /* print_array(bits, N); */

  int j = 0;
  for (int i = 0; i < N; i++) {
    int len = 0;
    while (i < N && bits[i] == 1) {
      i++;
      len++;
    }
    bits[j++] = len;
  }
  while (j < N) { bits[j++] = 0; }

  /* print_array(bits, N); */

  for (int k = 0; k+1 < N; k++) {
    bits[k] = bits[k] + bits[k+1];
  }

  /* print_array(bits, N); */

  return 1 + max(bits, N);
  /* printf("max flipped len == %d\n", 1 + max(bits, N)); */
}

int max (int *arr, int n) {
  int m = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] > m) m = arr[i];
  }
  return m;
}

void print_array (int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if ((i + 1) % 4 == 0) printf(" ");
  }
  puts("");

}

