package linkedlist

type node struct {
	value interface{}
	prev  *node
	next  *node
}

// LinkedList - a doubly linked list implementation
type LinkedList struct {
	head  *node
	tail  *node
	count int
}

func (list *LinkedList) validateIndex(index int) {
	if index < 0 || index >= list.count {
		panic("Index out of range")
	}
}

// New - creates an empty linkedlist
func New() *LinkedList {
	newList := &LinkedList{}
	return newList
}

// Size - returns number of items in list
func (list *LinkedList) Size() int {
	return list.count
}

// PushEnd - adds an item at the end
func (list *LinkedList) PushEnd(value interface{}) {
	new := &node{value: value, prev: list.tail}
	if list.count == 0 {
		list.head = new
	} else {
		list.tail.next = new
	}
	list.tail = new
	list.count++
}

// ValueAt - returns the value of the nth item (starting at 0 for first)
func (list *LinkedList) ValueAt(index int) interface{} {
	list.validateIndex(index)
	tmp := list.head
	for i := 0; i < index; i++ {
		tmp = tmp.next
	}
	return tmp.value
}

// PushFront - adds an item to the front of the list
func (list *LinkedList) PushFront(value interface{}) {
	new := &node{value: value, next: list.head}
	if list.head == nil {
		list.tail = new
	} else {
		list.head.prev = new
	}
	list.head = new
	list.count++
}

// PopEnd - removes end item and returns its value
func (list *LinkedList) PopEnd() interface{} {
	if list.count == 0 {
		panic("pop called on an empty list")
	}
	result := list.tail.value
	list.tail = list.tail.prev
	if list.tail != nil {
		list.tail.next = nil
	} else {
		list.head = nil
	}
	list.count--
	return result
}

// PopFront - remove front item and return its value
func (list *LinkedList) PopFront() interface{} {

	if list.count == 0 {
		panic("pop called on an empty list")
	}
	result := list.head.value
	list.head = list.head.next

	if list.head != nil {
		list.head.prev = nil
	} else {
		list.tail = nil
	}

	list.count--
	return result
}

// Insert - insert value at index
func (list *LinkedList) Insert(index int, value interface{}) {
	if index == list.count {
		list.PushEnd(value)
	} else if index == 0 {
		list.PushFront(value)
	} else {
		list.validateIndex(index)

		curr := list.head
		// TODO choose the closest side to seek
		for index > 0 {
			curr = curr.next
			index--
		}
		// [prev] <->  [curr]  <->  [next]  <-> ...
		//             [new]
		new := &node{value: value, prev: curr.prev, next: curr}

		// aralanın mən də oturum
		curr.prev.next = new
		curr.prev = new
		list.count++
	}

}

// Iterate yields elements as buffered channel
func (list *LinkedList) Iterate() chan interface{} {
	ch := make(chan interface{}, list.count)

	for curr := list.head; curr != nil; curr = curr.next {
		ch <- curr.value
	}
	close(ch)
	return ch
}

// RemoveAt - removes node at given index
func (list *LinkedList) RemoveAt(index int) {
	list.validateIndex(index)
	if index == 0 {
		list.PopFront()
	} else if index == list.count-1 {
		list.PopEnd()
	}
	curr := list.head
	for index > 0 {
		curr = curr.next
		index--
	}
	// əl çəkin mənnən
	curr.prev.next = curr.next
	curr.next.prev = curr.prev
	list.count--
}

// Reverse - reverses the list
func (list *LinkedList) Reverse() {
	if list.count < 2 {
		return
	}
	list.head, list.tail = list.tail, list.head
	for curr := list.head; curr != nil; curr = curr.next {
		curr.prev, curr.next = curr.next, curr.prev
	}
}

// RemoveValue - removes the first occurence
func (list *LinkedList) RemoveValue(value interface{}) bool {
	if list.count == 0 {
		return false
	} else if value == list.head.value {
		list.PopFront()
		return true
	} else if value == list.tail.value {
		list.PopEnd()
		return true
	}

	for curr := list.head.next; curr != nil; curr = curr.next {
		if curr.value == value {
			curr.prev.next = curr.next
			curr.next.prev = curr.prev
			list.count--
			return true
		}
	}
	return false
}
