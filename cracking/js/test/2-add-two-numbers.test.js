const fn = require('../2-add-two-numbers')

test('Examples', () => {
  ;[
    [fromArray([7, 1, 6]), fromArray([5, 9, 2]), fromArray([2, 1, 9])],
    [fromArray([5]), fromArray([5]), fromArray([0, 1])],
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
