/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
module.exports = function (head, x) {
  /**
   * list
   *  |
   *  v
   * (und, next) -> (1, next) -> (4, next) -> (3, next) -> (2, next) -> ...
   *
   * listL
   *  |
   *  v
   * (und, null)
   *  ^
   *  |
   * tailL
   *
   */

  const listL = ({ val: undefined, next: null })
  const listR = ({ val: undefined, next: null })
  let tailL = listL
  let tailR = listR

  function insertAfter (node, val) {
    const next = node.next
    node.next = ({ val, next })
    return node.next
  }

  for (let p = head; p !== null; p = p.next) {
    if (p.val < x) tailL = insertAfter(tailL, p.val)
    if (p.val >= x) tailR = insertAfter(tailR, p.val)
  }

  tailL.next = listR.next // concate

  return listL.next

  // function show (p) { return !p ? '(null)' : `${p.val} -> ${show(p.next)}` }
}
