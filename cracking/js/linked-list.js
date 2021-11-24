const Z = { val: undefined, next: null }
Z.next = Z

const L = {
  newList: _ => ({ val: '(H)', next: Z }),
  'insertAfter!': (node, val) => {
    console.log({ node, val })
    const { next } = node
    Object.assign(node, { next: { val, next } })
    return node
  },
  'deleteNext!': node => {
    const { next } = node
    Object.assign(node, { next: next.next })
    return node
  },
  show: function show_ (list) {
    const { val, next } = list
    if (next === list) { return '(Z)' }
    return `${val} -> ${show_(next)}`
  },
}

const l = L.newList()

console.log(L.show(l))

'0926727212'.split('').forEach(x => L['insertAfter!'](l, x))

console.log(L.show(l))

for (let i = 0; i < 3; i++) {
  L['deleteNext!'](l.next.next)
}

console.log(L.show(l))
