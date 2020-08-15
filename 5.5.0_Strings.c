#include <stdio.h>
#include <string.h>

/**
 * # 3.5.1
 *
 * function size (str) { return sum (S.map (S.K (1)) (str)) }
 * function size (str) { return foldl (add) (0) (S.map (S.K (1)) (str)) }
 * function size (str) {
 *   const b = 0
 *   const f = S.K (1)
 *   const g = add
 *   const h = x => y =>  g (x) (f (y))
 *   return fold (h) (b) (str)
 * }
 */
// long add (long m, long n) {
//   return m + n;
// }
// long K1 (char c) {
//   return 1;
// }
long size (const char *s) {
  long acc = 0;
  for (long i = 0; s[i] != '\0'; i += 1) {
    /* acc = add(acc, K1(s[i])); */
    acc = acc + 1; // inline
  }
  return acc;
}

int main (void) {
  const char *s = "Hello, world!";
  printf("strlen(\"%s\") == %ld\n", s, strlen(s));
  printf("strlen(\"%s\") == %ld\n", s, size(s));
  return 0;
}
