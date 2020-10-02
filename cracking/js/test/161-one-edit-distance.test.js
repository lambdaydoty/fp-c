const fn = require('../161-one-edit-distance')

test('Examples', () => {
  ;[
    ['ab', 'acb'],
    ['abcd', 'bcd'],
  ].forEach(([s, t]) => expect(fn(s, t)).toBe(true))

  ;[
    ['xbcd', 'abc'],
    ['', ''],
    ['acbbcda', 'abbdad'],
  ].forEach(([s, t]) => expect(fn(s, t)).toBe(false))
})
