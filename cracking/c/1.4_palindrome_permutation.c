#include <assert.h>
#include <stdlib.h>
#include "../common/bool.h"

/**
 * #hashtable
 * #map
 * #dictionary
 * #palindrome
 * #leetcode-266
 *
 * tactcoa : 7 = 2 * 3 + 1
 *
 * tacocat
 * atcocta
 *
 *
 */

#define SP ' '
#define LOWERCASE 26
#define is_odd(n) ((n) % 2 != 0)
#define is_even(n) ((n) % 2 == 0)
#define BIT(n) (0x1 << (n))

bool is_palindrome_permutation (char * str) {
  /* int * count = (int *) malloc (sizeof (int *) * LOWERCASE); */
  int count = 0x0;
  int len = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    char c = str[i];
    if (c == SP) {
      /* do nothing */;
    } else if (c >= 'a' && c <= 'z') {
      count ^= BIT( c - 'a' );
      len += 1;
    } else if (c >= 'A' && c <= 'Z') {
      count ^= BIT( c - 'A' );
      len += 1;
    } else {
      abort();
    }
  }

  /* for (int i = 0; i < LOWERCASE; i++) { */
  /*   if (is_odd( count[i] ) && is_even( len )) { return false; } */
  /*   if (is_odd( count[i] ) && is_odd( len )) { len -= 1; } */
  /* } */

  /*
   * two or more 1's    no 1       one 1
   * 0110 0000 x     0000 0000   0000 0100
   * 0101 1111 x-1   1111 1111   0000 0011
   *-----------&    ----------& ----------
   * 0100 0000       0000 0000   000000000
   */
  return count == 0 || (count & (count - 1)) == 0;
  //                   ^^^^^^^^^^^^^^^^^^^^^^^^^^ one bit
}

int main () {
  assert( is_palindrome_permutation("Tact Coa") );
  assert( is_palindrome_permutation("") );
  assert( is_palindrome_permutation("a") );
  assert( is_palindrome_permutation("A") );
  assert( is_palindrome_permutation("Aa") );

  assert( !is_palindrome_permutation("AB") );
  assert( !is_palindrome_permutation("A B") );
  assert( !is_palindrome_permutation(" AB") );
  assert( !is_palindrome_permutation(" AB ") );

  assert( !is_palindrome_permutation("code") );
  assert( is_palindrome_permutation("aab") );
  assert( is_palindrome_permutation("carerac") );
}

