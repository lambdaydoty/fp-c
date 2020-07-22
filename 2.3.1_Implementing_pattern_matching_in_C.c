#include <stdio.h>
#include <stdlib.h>

int eval (int x, char o1, int y, int o2, int z) {
  if (o1 == '+' && o2 == '+') {
    return (x + y) + z;
  } else if (o1 == '+' && o2 == '*') {
    return x + (y * z);
  } else if (o1 == '*' && o2 == '+') {
    return (x * y) + z;
  } else if (o1 == '*' && o2 == '*') {
    return (x * y) * z;
  } else {
    abort();
    /**
     * abort() is called to signal a programmer error
     *
     * exit() is called to signal a user error (or just stop the program)
     */
  }
}

int main (void) {
  printf("%d\n", eval(1, '+', 2, '*', 3));
  printf("%d\n", eval(1, '+', 2, '/', 3));
  exit(0);
}
