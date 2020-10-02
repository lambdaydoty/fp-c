/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
module.exports = function (head) {
  /**
   * head: null
   * head -> ({ val, next: null })
   * head -> ({ val, next }) -> ({ val, next: null })
   * ...
   */

  for (let p = head; p; p = p.next) {
    console.log(showNodes(p))

    const list = headToList(p.next)

    deleteNode(list, p.val)

    p.next = listToHead(list)
  }

  return head

  // ∷ !Node → Undefined
  function deleteNode (list, V) {
    /**
     * PURE NODE POINTERS             | DUMMY NODE represents LIST                       | int * ptr = (int *)malloc(N)
     * -------------------------------+--------------------------------------------------+--------------------------------
     * head === null                  | list -> (undef, null)                            | ptr:       0x....
     * head -> (1, null)              | list -> (undef, next) ->  (1, null)              | ptr[0..0]: 0x.... -> |1|
     * head -> (1, next) -> (2, null) | list -> (undef, next) ->  (1, next) -> (2, null) | ptr[0..1]: 0x.... -> |1|2|
     * ...
     */
    let q = list
    while (q.next) {
      if (q.next.val === V) {
        deleteNext(q)
        continue
      }
      q = q.next
    }
  }

  function headToList (head) { return ({ val: undefined, next: head }) }
  function listToHead (list) { return list.next }

  // ∷ !Node → Undefined
  function deleteNext (node) { node.next = node.next.next }
  function showNodes (p) { return !p ? '(null)' : `${p.val} -> ${showNodes(p.next)}` }
}
