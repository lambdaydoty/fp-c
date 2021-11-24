/**
 * @param {string} solution
 * @param {string} guess
 * @return {number[]}
 */
var masterMind = function(solution, guess) {
  const sol = solution.split('')
  const gue = guess.split('')

  let hit = 0
  for (let i = 0; i < 4; i++) {
    if (gue[i] === sol[i]) {
      hit++
      sol[i] = '*'
      gue[i] = '@'
    }
  }

  let pshit = 0
  for (let i = 0; i < 4; i++) {
    const j = sol.findIndex(x => x === gue[i])
    if (j !== -1) {
      pshit++
      sol[j] = '*'
    }
  }
  return [hit, pshit]
}
