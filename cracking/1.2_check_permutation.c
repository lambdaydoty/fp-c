#include <assert.h>
#include <stdlib.h>
#include "../common/bool.h"

/**
 * #hashtable
 * #map
 * #dictionary
 */

bool check_permutation (char * strA, char * strB) {
  int * map = (int *) calloc( 256,  sizeof (int *));
  for (int i = 0; strA[i] != '\0'; i++) {
    int ix = (int) strA[i];
    map[ix] += 1;
  }

  for (int i = 0; strB[i] != '\0'; i++) {
    int ix = (int) strB[i];
    map[ix] -= 1;
    if (map [ix] < 0) return false;
  }

  return true;
}

int main () {
  assert( check_permutation( "", "" ) );
  assert( check_permutation( "A", "A" ) );
  assert( check_permutation( "a", "a" ) );
  assert( check_permutation( "ab", "ab" ) );
  assert( check_permutation( "ab", "ba" ) );
  assert( check_permutation( "aa", "aa" ) );

  assert( check_permutation( "abc", "abc" ) );
  assert( check_permutation( "abc", "acb" ) );
  assert( check_permutation( "abc", "cab" ) );
  assert( check_permutation( "abc", "cba" ) );
  assert( check_permutation( "abc", "bac" ) );
  assert( check_permutation( "abc", "bca" ) );

  assert( check_permutation( "xxx", "xxx" ) );

  assert( check_permutation( "xxy", "xxy" ) );
  assert( check_permutation( "xxy", "xyx" ) );
  assert( check_permutation( "xxy", "yxx" ) );

  assert( check_permutation( "aaaaAAAAx", "xaAaAaAaA" ) );

  assert( !check_permutation( "", "x" ) );
  assert( !check_permutation( "y", "x" ) );
  assert( !check_permutation( "xx", "xy" ) );
  assert( !check_permutation( "xxxxx", "xxxxX" ) );
}

