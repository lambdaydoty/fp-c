/**
 * @param {number[]} array
 * @return {number[]}
 */
var subSort = function(array) {
  const N = array.length
  if (N <= 1) return [-1, -1]

  let l = 0
  while (array[l] <= array[l + 1]) l++

  let r = N - 1
  while (array[r] >= array[r - 1]) r--

  if (l + 1 > r - 1) return [-1, -1]

  let { min, max } = minmax(l + 1, r - 1)

  while (array[r] < max) {
    min = Math.min(min, array[r])
    r++
  }

  while (array[l] > min) {
    max = Math.max(max, array[l])
    l--
  }

  // console.log({ r, l, min, max })

  function minmax (i, j) {
    if (i > j) throw new Error(JSON.stringify({ i, j }))
    let min = Number.MAX_SAFE_INTEGER
    let max = Number.MIN_SAFE_INTEGER
    for (let k = i; k <= j; k++) {
      min = Math.min(min, array[k])
      max = Math.max(max, array[k])
    }
    return { min, max }
  }

  return [l + 1, r - 1]
}
