const fn = require('../83-remove-duplicates-from-sorted-list')

test('Examples', () => {
  ;[
    [fromArray([1, 1, 2]), fromArray([1, 2])],
    [fromArray('0926727212'.split('')), fromArray('092671'.split(''))],
    [fromArray([]), fromArray([])],
    [fromArray([1]), fromArray([1])],
    [fromArray([1, 1, 1, 1, 1]), fromArray([1])],
  ].forEach(([x, y]) => expect(fn(x)).toStrictEqual(y))
})

function node (val, next = null) {
  return { val, next }
}

function fromArray ([x, ...xs]) {
  return x === undefined
    ? null
    : node(x, fromArray(xs))
}
