/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
module.exports = function isOneEditDistance (s_, t_) {
  const [s, t] = reordering(s_, t_)
  const lenS = s.length
  const lenT = t.length
  let lenD = lenS - lenT
  /* lenS >= lenT */
  if (lenD >= 2) return false

  let i = 0; let j = 0
  while (s[i] === t[j] && j < lenT) { i++; j++ }

  /*
   * abcd   xbcd   abcd
   * xbcd   abc    bcd
   */
  for (; i < lenS; i++) {
    if (s[i] !== t[j] && lenD === 0) {
      j++
      lenD = -1
      continue
    }
    if (s[i] !== t[j] && lenD === 1) {
      lenD = -1
      continue
    }
    if (s[i] !== t[j] && lenD === -1) {
      return false
    }
    j++
  }
  return (lenD === -1)

  function reordering (a, b) {
    return (a.length >= b.length)
      ? [a, b]
      : [b, a]
  }
}
