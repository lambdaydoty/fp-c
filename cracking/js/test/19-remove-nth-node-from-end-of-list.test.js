const fn = require('../19-remove-nth-node-from-end-of-list')

test('Examples', () => {
  ;[
    [fromArray([1, 2, 3, 4, 5]), 2, fromArray([1, 2, 3, 5])],
  ].forEach(([x, n, y]) => expect(fn(x, n)).toStrictEqual(y))
})

function node (val, next = null) {
  return { val, next }
}

function fromArray ([x, ...xs]) {
  return x === undefined
    ? null
    : node(x, fromArray(xs))
}
