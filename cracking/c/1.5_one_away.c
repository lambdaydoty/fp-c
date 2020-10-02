#include <stdio.h>
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
 * A) insert a character
 * D) remove a character
 * R) replace a character
 *
 * pale -> ple (D, 'a')
 * pales -> pale (D, 's')
 * pale -> bale (R, 'p'->'b')
 * pale -> bake ()
 *
 * lenA == lenB, ...
 * lenA > lenB, ...
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

bool is_one_way (char * strA, char * strB) {
  int lenA = 0;
  int lenB = 0;
  for (int i = 0; strA[i] != '\0'; i++) { lenA += 1; }
  for (int i = 0; strB[i] != '\0'; i++) { lenB += 1; }
  if (lenA == lenB) return is_replace (lenA, strA, strB);
  if (lenA == lenB + 1) return is_insert (lenA, strA, strB);
  if (lenB == lenA + 1) return is_insert (lenB, strB, strA);
  return false;
}

int main () {
  assert( is_one_way("pale", "ple") );
  assert( is_one_way("pales", "pale") );
  assert( is_one_way("pale", "bale") );
  assert( !is_one_way("pale", "bake") );
}

