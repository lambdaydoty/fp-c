/**
 * @param {character[]} chars
 * @return {number}
 */
module.exports = function (chars) {
  const L = chars.length

  let runs = 1
  let N = 0

  for (let i = 0; i < L; i++) {
    if (chars[i] === (chars[i + 1] || null)) {
      runs++
      continue
    }

    chars[N++] = chars[i]

    if (runs > 1) {
      toCharArray(runs).forEach(c => { chars[N++] = c })
    }

    runs = 1
  }
  return N

  function toCharArray (runs) {
    return `${runs}`.split('')
  }
}
