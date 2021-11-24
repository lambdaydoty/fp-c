function nextNumber (n) {
  /**
   *   rightmost non-tailing 0
   *         |
   *         v
   * 11 0110 0111 1100 (13948)
   *         1000 0000
   *         1000 1111
   * 11 0110 1000 1111
   */
  let m = n
  let shifted = 0
  while ((m & 1) === 0) {
    m >>>= 1
    shifted++
  }

  let ones = 0
  while ((m & 1) === 1) {
    m >>>= 1
    ones++
    shifted++
  }

  m |= 1

  for (let i = 0; i < shifted; i++) {
    m <<= 1
  }

  let lowerOnes = 1
  for (let i = 1; i < ones; i++) {
    lowerOnes <<= 1
  }
  lowerOnes -= 1

  return m | lowerOnes
}

const N = 13948
console.log(N, N.toString(2))
console.log(nextNumber(N), nextNumber(N).toString(2))
