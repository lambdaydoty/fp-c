var StreamRank = function() {
    this.tree = null
};

/**
 * @param {number} x
 * @return {void}
 */
StreamRank.prototype.track = function(x) {
    function insert (node) {
        if (node === null) return { val: x, leftN: 0, left: null, right: null }
        if (x <= node.val) {
            node.left = insert (node.left)
            node.leftN++
            return node
        }
        if (x > node.val) {
            node.right = insert (node.right)
            return node
        }

    }
    this.tree = insert (this.tree)
    //console.log (`@track(${x})`)
    //console.log (this.tree.leftN)
    //console.log (JSON.stringify (this.tree, null, 2))
};

/**
 * @param {number} x
 * @return {number}
 */
StreamRank.prototype.getRankOfNumber = function(x) {
    function getRank (node) {
        if (node === null) return 0
        if (x === node.val) return 1 + node.leftN
        if (x < node.val) {
            return getRank (node.left)
        }
        if (x > node.val) {
            return getRank (node.right) + 1 + node.leftN
        }
        /* exception */
    }
    return getRank (this.tree)
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * var obj = new StreamRank()
 * obj.track(x)
 * var param_2 = obj.getRankOfNumber(x)
 */
