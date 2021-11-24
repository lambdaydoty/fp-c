/**
 * Cracking - Problem #3.5 Sort Stack
 */
const util = require('util')

function check (x) {
  if (x <= 0) throw new Error(`only accept positive numbers ${x}`)
}

class Stack {
  constructor () {
    Object.assign(this, { s: [] })
  }

  push (x) {
    check(x)
    const { s } = this
    s.push(x)
    return this
  }

  pop () {
    const { s } = this
    return s.pop() || -1
  }

  peek () {
    const { s } = this
    return s[s.length - 1] || -1
  }

  empty () {
    const { s } = this
    return s.length === 0
  }

  [util.inspect.custom] () {
    const { s } = this
    return `|${s.toString()}(top)|`
  }

  sort () {
    const t = new Stack()
    while (!this.empty()) {
      const curr = this.pop()
      // console.log(this, { curr }, t)
      while (curr < t.peek()) {
        this.push(t.pop())
      }
      /* curr >= t.peek() */
      t.push(curr)
    }
    // console.log('@@')
    // console.log(this, t)
    while (t.peek() !== -1) {
      this.push(t.pop())
    }
    return this
  }
}

const s = new Stack()
;[1, 9, 2, 6, 7, 2, 7, 2, 1, 2].forEach(x => s.push(x))
console.log(s)
console.log(s.sort())
