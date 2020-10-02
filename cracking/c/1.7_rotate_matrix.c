#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "../common/bool.h"

/**
 * #array
 * #in-place
 * #leetcode-48
 *
 * L = side-length
 *
 * x + yi => (x - L/2) + (y - L/2)i  // shift
 *        => (L/2 - y) + (x - L/2)i  // rotate 90
 *        => (L - y) + xi            // shift back
 *
 * x + yi => (x - L/2) + (y - L/2)i  // shift
 *        => (y - L/2) + (L/2 - x)i  // rotate -90
 *        => y + (L - x)i            // shift back
 */

typedef struct pair {
  int x;
  int y;
} Pair;

Pair rotate_n90 (int L, Pair p) {
  Pair q;
  q.x = p.y;
  q.y = L - p.x;
  return q;
}

Pair rotate_90 (int L, Pair p) {
  Pair q;
  q.x = L - p.y;
  q.y = p.x;
  return q;
}

int get (int ** matrix, Pair p) {
  return matrix[p.x][p.y];
}

void set (int ** matrix, Pair p, int v) {
  matrix[p.x][p.y] = v;
}

void rotate (int ** matrix, int matrixSize, int * matrixColSize) {
  int N = matrixSize;
  int L = N - 1;
  for (int x = 0; x < N / 2; x++) {
    for (int y = x; y < L - x; y++) {
      Pair p0 = {x, y};
      Pair p1 = rotate_90(L, p0);
      Pair p2 = rotate_90(L, p1);
      Pair p3 = rotate_90(L, p2);
      int temp = get(matrix, p0);
      set(matrix, p0, get(matrix, p1));
      set(matrix, p1, get(matrix, p2));
      set(matrix, p2, get(matrix, p3));
      set(matrix, p3, temp);
    }
  }
}

/**
 * N = 3, L = 2
 *
 * [[*, @, 3],   i=0, j=0,1  < L-i=2
 *  [4, 5, 6],   i=1, j=1 < L-i=1
 *  [7, 8, 9]]
 *
 * N = 4, L = 3
 * [[*,   @,  &,  4],  i=0, j=0,1,2 < L-i=3
 *  [5,   %,  7,  8],  i=1, j=1 < L-i=2
 *  [9,  10, 11, 12],
 *  [13, 14, 15, 16]]
 *
 */
void assert_matrix_eq (int dim, int **a, int **b) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      /* printf("%d %d\n", a[i][j], b[i][j]); */
      assert(a[i][j] == b[i][j]);
    }
  }
}

void print_matrix (int dim, int **a) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
}

int **new_matrix (int dim) {
  int ** p = (int **) malloc (sizeof (int **) * dim);
  for (int i = 0; i < dim; i++) {
    p[i] = (int *) malloc (sizeof (int *) * dim);
  }
  return p;
}

void matrix_cp (int dim, int **a, int b[][3]) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      a[i][j] = b[i][j];
    }
  }
}

int main () {
  int _x[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  int _y[3][3] = {
    {7, 4, 1},
    {8, 5, 2},
    {9, 6, 3},
  };
  int ** x = new_matrix(3);
  int ** y = new_matrix(3);
  matrix_cp(3, x, _x);
  matrix_cp(3, y, _y);

  print_matrix(3, x); puts("");

  rotate(x, 3, NULL);

  print_matrix(3, x); puts("");

  assert_matrix_eq(3, x, y);
}

