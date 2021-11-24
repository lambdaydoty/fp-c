/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
module.exports = function (l1, l2) {
  const L1 = length(l1)
  const L2 = length(l2)
  const D = Math.abs(L1 - L2)

  const [c, result] = (L1 >= L2)
    ? recur(l1, l2, D)
    : recur(l2, l1, D)

  return c ? node(1, result) : result

  function recur (l1, l2, diff) {
    /* Assume length(l1) >= length(l2) */
    if (!l1 || !l2) return [0, null]
    if (diff === 0) {
      const [c, next] = recur(l1.next, l2.next, diff)
      const C = (c + l1.val + l2.val) > 9 ? 1 : 0
      const S = (c + l1.val + l2.val) % 10
      return [C, node(S, next)]
    }
    const [c, next] = recur(l1.next, l2, diff - 1)
    const C = (c + l1.val) > 9 ? 1 : 0
    const S = (c + l1.val) % 10
    return [C, node(S, next)]
  }

  // function insertAfter (x, val) {
  //   const next = x.next
  //   x.next = node(val, next)
  //   return x.next
  // }

  function node (val, next = null) {
    return ({ val, next })
  }

  function length (x) {
    return !x ? 0 : 1 + length(x.next)
  }

  // function show (node) {
  //   return !node ? '(null)' : `${node.val} -> ${show(node.next)}`
  // }
}
