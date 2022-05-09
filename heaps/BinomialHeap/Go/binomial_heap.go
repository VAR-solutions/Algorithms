package main

import (
	"errors"
	"fmt"
	"math/rand"
	"sort"
)

type node struct {
	value   int
	degree  int
	sibling *node
	child   *node
}

type BinomialHeap struct {
	root *node
}

func link(a *node, b *node) (*node, error) {
	if a.degree != b.degree {
		return nil, errors.New("Expected link node degree to match")
	}
	if a.value <= b.value {
		if a.child == nil {
			a.child = b
		} else {
			temp := a.child
			for temp.sibling != nil {
				temp = temp.sibling
			}
			temp.sibling = b
		}
		a.degree += 1
		return a, nil
	} else {
		return link(b, a)
	}
}

func insert(cur *node, sibling *node) (*node, error) {
	if sibling == nil {
		return cur, nil
	}
	if cur.degree == sibling.degree {
		s_sibling := sibling.sibling
		sibling.sibling = nil
		temp_node, err := link(cur, sibling)
		if err != nil {
			return nil, err
		}
		result_node, err := insert(temp_node, s_sibling)
		if err != nil {
			return nil, err
		}
		return result_node, nil
	} else {
		cur.sibling = sibling
		return cur, nil
	}
}

func merge(a *node, b *node) (*node, error) {
	if a == nil {
		return b, nil
	}
	if b == nil {
		return a, nil
	}
	if a.degree < b.degree {
		unpacked_merge_node, err := merge(a.sibling, b)
		if err != nil {
			return nil, err
		}
		a.sibling = unpacked_merge_node
		return a, nil
	} else if a.degree > b.degree {
		unpacked_merge_node, err := merge(a, b.sibling)
		if err != nil {
			return nil, err
		}
		b.sibling = unpacked_merge_node
		return b, nil
	} else {
		sibling, err := merge(a.sibling, b.sibling)
		if err != nil {
			return nil, err
		}
		a.sibling, b.sibling = nil, nil
		c, err := link(a, b)
		if err != nil {
			return nil, err
		}
		insert_res_node, err := insert(c, sibling)
		if err != nil {
			return nil, err
		}
		return insert_res_node, nil
	}
}

func (h *BinomialHeap) find_top() (*node, *node, error) {
	var prev *node
	var min_prev *node
	cur, min_cur := h.root, h.root
	for cur != nil {
		if cur.value < min_cur.value {
			min_cur = cur
			min_prev = prev
		}
		prev = cur
		cur = cur.sibling
	}
	if min_cur == nil {
		return nil, nil, errors.New("Handle empty heap call is up to user")
	}
	return min_prev, min_cur, nil
}

func (h *BinomialHeap) Append(value int) error {
	new_node := &node{value: value, degree: 0, sibling: nil, child: nil}
	merged_root, err := merge(h.root, new_node)
	if err != nil {
		return err
	}
	h.root = merged_root
	return nil
}

func (h *BinomialHeap) Extract() (int, error) {
	min_prev, min_cur, err := h.find_top()
	if err != nil {
		return -1, err
	}
	value := min_cur.value
	if min_prev != nil {
		min_prev.sibling = min_cur.sibling
	} else {
		h.root = min_cur.sibling
	}
	new_root, err := merge(min_cur.child, h.root)
	if err != nil {
		return value, err
	}
	h.root = new_root
	return value, nil
}

func (h *BinomialHeap) Top() (int, error) {
	_, min_cur, err := h.find_top()
	if err != nil {
		return -1, err
	}
	return min_cur.value, nil
}

func NewBinomialHeap() *BinomialHeap {
	return &BinomialHeap{root: nil}
}

func main() {
	println("Hello, Binomial Heap!")
	bh := NewBinomialHeap()
	pq := []int{}

	for T := 0; T < 100; T++ {
		for i := 0; i < 10000; i++ {
			rand_val := rand.Intn(10000)
			err := bh.Append(rand_val)
			if err != nil {
				panic(err)
			}
			pq = append(pq, rand_val)
		}

		sort.Ints(pq)

		for i := 0; i < 10000; i++ {
			bh_val, err := bh.Extract()
			if err != nil {
				panic(err)
			}

			pq_val := pq[0]
			pq = pq[1:]

			if bh_val != pq_val {
				errorStr := fmt.Sprintf("Binomial Heap: %d, Priority Queue: %d", bh_val, pq_val)
				panic(errorStr)
			}
		}
	}

	println("Success!")

}
