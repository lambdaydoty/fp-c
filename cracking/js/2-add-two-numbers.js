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
  /**
   * (a + 10x) + (b + 10y)
   * = (a + b) + 10*(x + y)
   */

  return recur(l1, l2, 0)

  function recur (L1, L2, carry) {
    const { val: A = 0, next: N1 } = (L1 || {})
    const { val: B = 0, next: N2 } = (L2 || {})
    if (!L1 && !L2) return !carry ? null : node(1)
    const sum = A + B + carry
    const r = sum % 10
    const c = Math.floor(sum / 10)
    return node(r, recur(N1, N2, c))
  }

  function node (val, next = null) {
    return ({ val, next })
  }
}
