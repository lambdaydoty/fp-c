/**
 * @param {number} shorter
 * @param {number} longer
 * @param {number} k
 * @return {number[]}
 */
var divingBoard = function(shorter, longer, k) {
  // S + L = k
  // (0, k), (1, k-1), (2, k-2), (3, k-3), ..., (k-1, 1), (k, 0)
  if (k === 0) return []
  const map = {}
  for (let i = 0; i <= k; i++) {
    const [s, l] = [i, k - i]
    map[s * shorter + l * longer] = true
  }
  return Object
    .keys(map)
    .map(Number)
    .sort((x, y) => x - y)
}
