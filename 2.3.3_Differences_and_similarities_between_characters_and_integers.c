#include <stdio.h>
#include <ctype.h>

char invertcase (char c) {
  if (islower(c)) {
    return toupper(c);
  } else if (isupper(c)) {
    return tolower(c);
  } else {
    return c;
  }
}

int main (void) {
  const char *message = "Hello World\n";

  for (int i = 0; message[i] != '\0'; i += 1) {
    printf("%c", invertcase(message[i]));
  }
}
