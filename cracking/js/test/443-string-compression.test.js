const fn = require('../443-string-compression')

test('Examples', () => {
  ;[
    [['a', 'a', 'b', 'b', 'c', 'c', 'c'], ['a', '2', 'b', '2', 'c', '3']],
    [['a'], ['a']],
    [['a', 'b', 'c'], ['a', 'b', 'c']],
    [['a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'], ['a', 'b', '1', '2']],
    [['a', 'a', 'a', 'b', 'b', 'a', 'a'], ['a', '3', 'b', '2', 'a', '2']],
    [['o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'], ['o', '1', '0']],
  ].forEach(([x, y]) => {
    const N = fn(x)
    expect(x.slice(0, N)).toStrictEqual(y)
  })
})
