const fn = require('../445-add-two-numbers-ii')

test('Examples', () => {
  ;[
    [fromArray([1, 1, 1]), fromArray([2, 2, 2]), fromArray([3, 3, 3])],
    [fromArray([1, 1, 1]), fromArray([9, 9, 9]), fromArray([1, 1, 1, 0])],
    [fromArray([7, 2, 4, 3]), fromArray([5, 6, 4]), fromArray([7, 8, 0, 7])],
    [fromArray([5]), fromArray([5]), fromArray([1, 0])],
    [fromArray([1]), fromArray([9, 9]), fromArray([1, 0, 0])],
  ].forEach(([a, b, c]) => expect(fn(a, b)).toStrictEqual(c))
})

function node (val, next = null) {
  return { val, next }
}

function fromArray ([x, ...xs]) {
  return x === undefined
    ? null
    : node(x, fromArray(xs))
}
