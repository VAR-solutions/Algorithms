package linkedlistint32

import "fmt"

type Element struct {
	Value int32
	Next  *Element
}

type LinkedListInt32 struct {
	First *Element
	Last  *Element
}

func (ll *LinkedListInt32) push(value int32) {
	newElement := Element{Value: value, Next: nil}

	if ll.First == nil {
		ll.First = &newElement
	}
	if ll.Last == nil {
		ll.Last = &newElement
	} else {
		ll.Last.Next = &newElement
		ll.Last = &newElement
	}
}

func print(ll LinkedListInt32) {
	var element = ll.First
	for element.Next != nil {
		fmt.Printf("%v ",element.Value);
		element = element.Next
	}
	fmt.Printf("%v ",element.Value);
}

