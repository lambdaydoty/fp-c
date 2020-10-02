const fn = require('../237-delete-node-in-a-linked-list')

test('Examples', () => {
  const head1 = fromArray([4, 5, 1, 9])
  const five = head1.next
  fn(five)
  expect(head1).toStrictEqual(fromArray([4, 1, 9]))

  const head2 = fromArray([4, 5, 1, 9])
  const one = head2.next.next
  fn(one)
  expect(head2).toStrictEqual(fromArray([4, 5, 9]))
})

function node (val, next = null) {
  return { val, next }
}

function fromArray ([x, ...xs]) {
  return x === undefined
    ? null
    : node(x, fromArray(xs))
}
