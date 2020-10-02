/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
module.exports = function isOneEditDistance (S_, T_) {
  const [S, T] = reordering(S_, T_)
  const [lenS, lenT] = [S.length, T.length]
  const lenD = lenS - lenT

  /* Assume: lenS >= lenT, lenD = 0, 1, 2, ... */

  if (lenD >= 2) return false

  /**
    * Start to consume the same prefix of S and T
    * Maintain two index-pointers s, t
    */

  let [s, t] = [0, 0]
  ;[s, t] = consumeSameChars(s, t)

  /**
   * The ending condition for `consumeSameChars()` are either
   * A) s === lenS (the end of S string) or
   * B) t === lenT (the end of T string) or
   * C) S[s] !== T[t] for some middle posistions of strings S, T
   */

  if (s === lenS && t === lenT) return false // same strings

  /**
   * Examples:
   *   lenD | 0      1      1
   *   S    | abcd   xbcd   abcd
   *   T    | xbcd   abc    bcd
   */

  if (lenD === 0) {
    /* We are allowed to replace one by another at position [s, t]; thus skip both  */
    ;[s, t] = consumeSameChars(s + 1, t + 1)
  }
  if (lenD === 1) {
    /* We are allowed to delete S[s]; thus skip it  */
    ;[s, t] = consumeSameChars(s + 1, t)
  }

  return (s === lenS && t === lenT)

  function reordering (a, b) {
    return (a.length >= b.length) ? [a, b] : [b, a]
  }

  /**
   * Consume the same characters from [s, t] and return the new indexed
   */
  function consumeSameChars (s, t) {
    while (s < lenS && t < lenT && S[s] === T[t]) { s++; t++ }
    return [s, t]
  }
}
