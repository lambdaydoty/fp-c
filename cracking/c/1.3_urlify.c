#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../common/bool.h"
#include <stdio.h>

/**
 * #inplace
 * #string
 */

/**
 * "Mr John Smith    ", 13
 *  0      ^    ^
 *         |    |   16 = 12 + #space * 2
 *         7    12  |
 *                  v
 * "Mr%20John%20Smith", 13
 *           ^
 *           +-- 9
 */

#define SP ' '
#define SHIFT(j, sp) ((j) + (sp) * 2)

void urlify (char * str, int properLen) {
  /* count spaces */
  int spcount = 0;
  for (int i = 0; i < properLen; i++) {
    if (str[i] == SP) spcount++;
  }

  for (int j = properLen - 1; j >= 0; j--) {
    if (str[j] != SP) {
      str[SHIFT(j, spcount)] = str[j];
    } else {
      spcount--;
      str[SHIFT(j, spcount)] = '%';
      str[SHIFT(j, spcount) + 1] = '2';
      str[SHIFT(j, spcount) + 2] = '0';
    }
  }
}

int main () {
  char * buff = (char *) malloc (100);

  strcpy( buff, "Mr John Smith    " );
  urlify( buff, 13 );
  assert( !strcmp( buff, "Mr%20John%20Smith" ) );

  strcpy( buff, "   " );
  urlify( buff, 1 );
  assert( !strcmp( buff, "%20" ) );

  strcpy( buff, "      " );
  urlify( buff, 2 );
  assert( !strcmp( buff, "%20%20" ) );
}
