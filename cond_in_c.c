#include <stdio.h>

int sign (int n) {
  return
    (n > 0) ? 1 :
    (n == 0) ? 0 :
    /* otherwise */ -1;
}

int main (void) {
  printf("%d %d %d", sign(123), sign(-123), sign(0));
  return 0;
}
