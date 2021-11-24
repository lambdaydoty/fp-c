/**
 * @param {number[]} birth
 * @param {number[]} death
 * @return {number}
 */
var maxAliveYear = function (birth, death) {
  birth.sort()
  death.sort()
  let [j, k] = [0, 0]
  const [B, D] = [birth.length, death.length]
  let live = 0
  let max = 0
  let ans = -1
  for (let i = 0; i < B + D; i++) {
    // console.log (birth[j], death[k], { i, j, k })

    if (birth[j] <= death[k]) {
      live++
      j++
    } else {
      live--
      k++
    }
    if (live > max) {
      ans = birth[j - 1]
      max = live
    }

    // console.log ({ live, max, ans })
  }
  return ans
}

module.exports = maxAliveYear
