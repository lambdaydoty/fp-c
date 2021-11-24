// function neg (n) {
//   return -n
// }

function negate (n) {
  const inc = n > 0 ? -1 : 1
  let neg = 0
  while (n !== 0) {
    n += inc
    neg += inc
  }
  return neg
}

console.log(
  negate(1),
  negate(10),
  negate(0),
  negate(-1),
)
