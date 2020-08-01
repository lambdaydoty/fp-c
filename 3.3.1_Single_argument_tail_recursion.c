#include <stdio.h>

/**
 * (* leap : int -> int *)
 * fun leap y = if y mod 4 <> 0
 *              then leap (y + 1)
 *              else y
 */

int leap_ (int y) {
  if (y % 4 != 0) {
    return leap_(y + 1);
  } else {
    return y;
  }
}

int leap (int y) {
  while (y % 4 != 0) {
    y = y + 1;
  }
  return y;
}

int main (void) {
  printf("leap(%d) == %d\n", 123, leap_(123));
  printf("leap(%d) == %d\n", 123, leap(123));
  return 0;
}
