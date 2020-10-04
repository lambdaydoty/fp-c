const fn = require('../86-partition-list')

test('Examples', () => {
  ;[
    [fromArray([1, 4, 3, 2, 5, 2]), 3, fromArray([1, 2, 2, 4, 3, 5])],
  ].forEach(([head, x, result]) => expect(fn(head, x)).toStrictEqual(result))
})

function node (val, next = null) {
  return { val, next }
}

function fromArray ([x, ...xs]) {
  return x === undefined
    ? null
    : node(x, fromArray(xs))
}
