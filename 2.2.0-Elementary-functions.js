/* eslint func-call-spacing: ["error", "always"] */
/* eslint no-multi-spaces: ["error", { ignoreEOLComments: true }] */

/**
 * euclid ∷ (N x N) → N
 *
 * euclid (m, n) = euclid(n, m mod n), if (n > 0)
 *               = m                 , otherwise
 */

const { D, $ } = require ('./sanctuary') ()

//    euclid ∷ Integer → Integer → Integer
const euclid = D.def (
  'euclid',
  {},
  [$.Integer, $.Integer, $.Integer],
  m => n => (n > 0)
    ? euclid (n) (m % n)
    : m
)

console.log (
  euclid (14) (12),
  euclid (14) (11),
  euclid (558) (198),
)

