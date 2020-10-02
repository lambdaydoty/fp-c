const fn = require('../161-one-edit-distance')

test('Examples', () => {
  ;[
    ['ab', 'acb'],
  ].forEach(([s, t]) => expect(fn(s, t)).toBe(true))

  ;[
    ['', ''],
  ].forEach(([s, t]) => expect(fn(s, t)).toBe(false))
})
