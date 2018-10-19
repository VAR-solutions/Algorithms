package linkedlistint32

import (
	_ "testing"
	"testing"
)

func Test(t *testing.T) {
	var ll LinkedListInt32
	ll.push(11)
	ll.push(12)
	ll.push(55)
	ll.push(67)
	print(ll)

	if ll.First == nil {
		t.Error("first element is empty")
	}
	if ll.First.Value != 11 {
		t.Error("first element is not 11")
	}

	if ll.First.Next.Value != 12 {
		t.Error("second element is not 12")
	}

	if ll.First.Next.Next.Value != 55 {
		t.Error("third element is not 55")
	}

	if (ll.Last.Value != 67){
		t.Error("last element is not 67")
	}
}
