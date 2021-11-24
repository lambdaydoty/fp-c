console.log = () => {}

/**
 *
*/

const peek = arr => arr[0]
const push = (arr, x) => arr.push(x)
const pop = arr => arr.shift()
const isempty = arr => arr.length === 0

const [CAT, DOG] = [0, 1]
const MAX = Number.MAX_SAFE_INTEGER

var AnimalShelf = function () {
  Object.assign(this, {
    [CAT]: [],
    [DOG]: [],
    order: 0,
  })
}

/**
 * @param {number[]} animal
 * @return {void}
 */
AnimalShelf.prototype.enqueue = function (animal) {
  const [sn, spec] = animal
  const { [spec]: Q, order } = this

  push(Q, { sn, order })

  Object.assign(this, { order: order + 1 })

  console.log(`@enqueue(${animal})`, this)
}

/**
 * @return {number[]}
 */
AnimalShelf.prototype.dequeueAny = function () {
  const { [CAT]: C, [DOG]: D } = this
  const [{ order: cat }, { order: dog }] = [
    peek(C) || { order: MAX },
    peek(D) || { order: MAX },
  ]

  console.log(`@toDequeueAny()`, this)

  return (cat < dog ? [pop(C).sn, CAT]
    : dog < cat ? [pop(D).sn, DOG]
      : /* otherwise */ [-1, -1])
}

/**
 * @return {number[]}
 */
AnimalShelf.prototype.dequeueDog = function () {
  const { [DOG]: D } = this

  console.log(`@toDequeueDOG()`, this)

  return isempty(D)
    ? [-1, -1]
    : [pop(D).sn, DOG]
}

/**
 * @return {number[]}
 */
AnimalShelf.prototype.dequeueCat = function () {
  const { [CAT]: C } = this

  console.log(`@toDequeueCAT()`, this)

  return isempty(C)
    ? [-1, -1]
    : [pop(C).sn, CAT]
}
