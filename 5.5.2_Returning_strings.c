#include <stdio.h>
#include <string.h>

struct wrapperg {
  int n[3];
};

int main (void) {
  char s[3] = { '1', '2', 'a' };
  char t[3] = { '3', '4' };
  /* char * greeting = "Hello, world"; */

  struct test A = { {'a', 'b', '\0'}, {1, 2, 3} };
  struct test B = A;

  printf("%s %s\n", s, t);
  printf("%s %d\n", A.c, A.n[0]);
  A.n[0] = 999;
  printf("%s %d\n", A.c, A.n[0]);
  printf("%s %d\n", B.c, B.n[0]);

  /* strncpy(s, greeting, 1); */
  /* printf("%s %s\n", s, t); */
  return 0;
}
