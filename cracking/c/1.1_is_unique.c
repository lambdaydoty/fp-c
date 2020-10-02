#include <assert.h>
#include <stdlib.h>
#include "../common/bool.h"

/**
 * #hashtable
 * #map
 * #dictionary
 */

bool is_unique (char * str) {
  int * map = (int *) calloc( 256,  sizeof (int *));
  for (int i = 0; str[i] != '\0'; i++) {
    int ix = (int) str[i];
    map[ix] += 1;
    if (map[ix] > 1) return false;
  }
  return true;
}

int main () {
  assert( is_unique( "" ) );
  assert( is_unique( "a" ) );
  assert( is_unique( "ABCD" ) );
  assert( is_unique( "xyz987" ) );
  assert( is_unique( "ABCDabcd" ) );
  assert( !is_unique( "xyz98x" ) );
  assert( !is_unique( "xxx" ) );
  assert( !is_unique( "  " ) );
  assert( !is_unique( "ABCdabcd" ) );
}

