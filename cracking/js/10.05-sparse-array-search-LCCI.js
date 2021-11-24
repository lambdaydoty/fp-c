/**
 * @param {string[]} words
 * @param {string} s
 * @return {number}
 */
var findString = function (words, s) {
  function binSearch (l, r) {
    if (l > r) return -1

    const m = Math.floor((l + r) / 2)
    const M = words[m]
    let n = null

    if (M === '') {
      n = m
      while (words[--n] === '') {}
      if (n === -1) return binSearch(m + 1, r)
      const N = words[n]
      if (N === s) return n
      if (N < s) return binSearch(m + 1, r)
      return binSearch(l, n - 1)
    }

    if (M === s) return m
    if (M < s) return binSearch(m + 1, r)
    return binSearch(l, m - 1)
  }
  return binSearch(0, words.length - 1)
}

module.exports = findString
