/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
module.exports = function (head, n) {
  const list = headToList(head)

  /* list -> (undefined, next) -> (1, next) -> (2, next) -> (3, null) */

  let R = list; while (n--) { R = R.next }
  let L = list

  while (R.next) {
    R = R.next
    L = L.next
  }

  deleteNext(L)

  return listToHead(list)

  function headToList (h) { return ({ val: undefined, next: h }) }
  function listToHead (l) { return l.next }
  function deleteNext (p) { p.next = p.next.next }
}
