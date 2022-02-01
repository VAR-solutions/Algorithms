package Scala

class LinkedList[A] {
	private var _head: LinkedListNode[A] = null
	private var _length = 0

	def apply(index: Int): A = {
		findObj(index)._value
	}

	def findObj(index: Int): LinkedListNode[A] = {
		var i = 0
		var currentObj = _head
		while (i < index && currentObj != null) {
			currentObj = currentObj._next
			i += 1
		}
		currentObj
	}

	def insert(index: Int, value: A): Unit = {
		if (index == 0 || _head == null) {
			_head = new LinkedListNode[A](value, _head)
		}
		else if (index == _length - 1) {
			findObj(_length - 1)._next = new LinkedListNode[A](value, null)
		}
		else {
			val newNode = new LinkedListNode[A](value, findObj(index))
			findObj(index - 1)._next = newNode
		}
		_length += 1
	}

	def remove(index: Int): Unit = {
		if (index == 0) _head = _head._next
		else if (index == _length - 1) findObj(_length - 2)._next = null
		else findObj(index - 1)._next = findObj(index - 1)._next._next

		_length -= 1
	}

	def replace(index: Int, value: A): Unit = {
		findObj(index)._value = value
	}

	def append(value: A): Unit = insert(length, value)

	def prepend(value: A): Unit = insert(0, value)

	def iterator: Iterator[A] = new Iterator[A] {
		var _currentNode: LinkedListNode[A] = _head

		def hasNext: Boolean = _currentNode != null

		def next(): A = {
			val retVal = _currentNode
			_currentNode = _currentNode._next
			retVal._value
		}
	}

	def length: Int = _length
}
