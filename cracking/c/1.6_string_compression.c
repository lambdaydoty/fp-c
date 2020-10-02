#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "../common/bool.h"

/**
 * #string
 * #edit
 * #hashtable
 * #map
 * #dictionary
 *
 */

bool is_replace (int n, char * a, char * b) {
  int diff = 0;
  for (int i = 0; i < n; i++) {
    diff += (a[i] == b[i]) ? 0 : 1;
  }
  return diff == 1;
}

bool is_insert (int n, char * a, char * b) {
  char * p = a;
  char * q = b;
  int diff = 0;
  while (*p != '\0' && *q != '\0') {
    /* printf("%c, %c\n", *p, *q); */
    if (*p != *q) {
      diff += 1;
      p++;
    }
    p++;
    q++;
  }

  if (*p != *q) { diff += 1; }

  return diff == 1;
}

/* v
 * aaaabbc
 * 1
 *
 *  v
 * aaaabbc
 * 2
 *
 *   v
 * aaaabbc
 * 3
 *
 *    v
 * aaaabbc
 * 4->0
 *
 *     v
 * aaaabbc
 * 1
 *
 *      v
 * aaaabbc
 * 2->0
 *
 *       v
 * aaaabbc
 *
 */
char * compress (char * in) {
  int len = 0;
  for (int i = 0; in[i] != '\0'; i++) { len += 1; }

  char * out = (char *) calloc (sizeof (char *), len);

  int count = 0;
  int j = 0;
  for (int i = 0; i < len; i++) {
    /* printf("%d %s %s\n", i, in, out); */
    count += 1;
    if (in[i] != in[i + 1]) {
      out[j] = in[i];
      out[j+1] = '0' + count;
      j += 2;
      count = 0;
    }
  }
  return j < len ? out : in;
}

int main () {
  assert( !strcmp( compress("aabcccccaaa"), "a2b1c5a3" ) );
  assert( !strcmp( compress("abc"), "abc" ) );
  assert( !strcmp( compress("aa"), "aa" ) );
  assert( !strcmp( compress("aaa"), "a3" ) );
}

