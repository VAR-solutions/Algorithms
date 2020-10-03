package main

import (
	"fmt"
	"math/rand"
)

type Node struct {
	num  int
	prev *Node
	next *Node
}

type List struct {
	tail  *Node
	start *Node
}

func main() {
	items := &List{}
	size := 10
	for i := 0; i < size; i++ {
		node := Node{num: rand.Intn(100)}
		if node.num == 0 {
			i = i - 1
			continue

		}
		items.insertNode(&node)
		fmt.Printf("%v and number is %v\n", i, node.num)
	}
	items.Display()
	items.DisplayReverse()
}

func (l *List) Display() {
	list := l.start
	for list != nil {
		fmt.Printf("value = %v and prev = %v and next= %v\n", list.num, list.prev, list.next)
		list = list.next
	}
	fmt.Println()
}

func (l *List) DisplayReverse() {
	list := l.tail
	for list != nil {
		fmt.Printf("value = %v\n", list.num)
		list = list.prev
	}
	fmt.Println()
}

func (l *List) insertNode(newNode *Node) {
	if l.start == nil {
		l.start = newNode
		l.tail = newNode
	} else {
		currentNode := l.start
		for currentNode.next != nil {
			currentNode = currentNode.next
		}
		newNode.prev = currentNode
		currentNode.next = newNode
		l.tail = newNode
	}
}
