/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
module.exports = function (node) {
  /**
   * head -> (4, next) -> (5, next) -> (1, next) -> (9, null)
   *                       ^
   *                       |
   *                       node         node.next    node.next.next
   */

  let p = node
  while (p.next.next) {
    p.val = p.next.val
    p = p.next
  }
  p.val = p.next.val
  p.next = null

  /**
   * NOTE: If we use a dummy tail node, we can even delete the last node!
   */
}
