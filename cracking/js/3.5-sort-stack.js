Array.prototype.peek = function () { // eslint-disable-line no-extend-native
  return this.empty()
    ? Number.MAX_SAFE_INTEGER
    : this[this.length - 1]
}
Array.prototype.empty = function () { // eslint-disable-line no-extend-native
  return this.length === 0
}

var SortedStack = function () {
  Object.assign(this, {
    main: [],
    temp: [],
  })
}

/**
 * @param {number} val
 * @return {void}
 */
SortedStack.prototype.push = function (val) {
  const { main, temp } = this
  while (val > main.peek()) {
    temp.push(main.pop())
  }
  main.push(val)
  while (!temp.empty()) {
    main.push(temp.pop())
  }
}

/**
 * @return {void}
 */
SortedStack.prototype.pop = function () {
  const { main } = this
  return main.empty()
    ? -1
    : main.pop()
}

/**
 * @return {number}
 */
SortedStack.prototype.peek = function () {
  const { main } = this
  return main.empty()
    ? -1
    : main.peek()
}

/**
 * @return {boolean}
 */
SortedStack.prototype.isEmpty = function () {
  const { main } = this
  return main.empty()
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * var obj = new SortedStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.isEmpty()
 */
