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

func (ll *LinkedListInt32) DeleteByValue(value int32) {
	if ll == nil {
		return
	}

	if ll.First.Value == value {
		ll.First = ll.First.Next
		return

	}

	previousToDelete := ll.First
	/*
		We do not want to compare the data of the node in to delete,
		we are going to	compare the data of the next node.
		To skip the node with the input value, we need to make modifications
		in the previous node next.
	*/
	for previousToDelete.Next.Value != value {
		if previousToDelete.Next.Next == nil {
			return

		}
		previousToDelete = previousToDelete.Next

	}
	previousToDelete.Next = previousToDelete.Next.Next

}

func (ll *LinkedListInt32) DeleteByIndex(value int32) {
	if ll == nil {
		return
	}

	if value == 0 {
		ll.First = ll.First.Next
		return

	}

	previousNode := ll.First
	var count int32
	count = 0

	// Normal case
	for count < value-1 {
		count += 1
		previousNode = previousNode.Next

	}
	previousNode.Next = previousNode.Next.Next
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
		fmt.Printf("%v ", element.Value)
		element = element.Next
	}
	fmt.Printf("%v ", element.Value)
}
