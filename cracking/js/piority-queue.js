function PQ (cmp/* cmp(x, y) > 0 iff x `>` y */) {
  Object.assign(this, { Q: [null], N: 0, cmp })
  // console.log(`@PQ()`, this.Q, this.N, this.cmp)
}

PQ.prototype.upheap = function (n) {
  const { Q, cmp } = this
  const v = Q[n]
  while (n > 1) {
    const next = n >> 1
    if (cmp(Q[next], v) >= 0) break
    Q[n] = Q[next]
    n = next
  }
  /* n === 1 or Q[n] `<=` Q[n/2]` */
  Q[n] = v
}

PQ.prototype.downheap = function (n) {
  const { Q, cmp, N } = this
  const v = Q[n]
  while (2 * n <= N) {
    const [l, r] = [2 * n, 2 * n + 1]
    const next = (l === N) ? l // node n have only one child!
      : cmp(Q[l], Q[r]) >= 0 ? l // node n have two children w. l >= r
        : /* otherwise */ r // node n have two children w. r > l
    if (cmp(Q[next], v) <= 0) break
    Q[n] = Q[next]
    n = next
  }
  Q[n] = v
}

PQ.prototype.insert = function (v) {
  const { Q } = this
  Q.push(v)
  this.N++
  this.upheap(this.N)
  // console.log(`@insert(${v})`, this.N, Q)
}

PQ.prototype.remove = function () {
  const { Q, N } = this
  if (N === 0) return null
  ;[Q[1], Q[N]] = [Q[N], Q[1]]
  const v = Q.pop()
  this.N--
  this.downheap(1)
  // console.log(`@remove()`, this.N, Q)
  return v
}

const q = new PQ((x, y) => x - y)

;[0, 9, 2, 6, 7, 2, 7, 2, 1, 2].forEach(x => {
  q.insert(x)
})

let v = null
do {
  v = q.remove()
  console.log({ v })
} while (v !== null)
