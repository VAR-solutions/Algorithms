import heapq
import random
from math import degrees
from dataclasses import dataclass
from typing import TypeVar

# required for using references to Node in dataclass
Node = TypeVar("Node")


@dataclass
class Node:
    '''
     Node in the binomial heap
     - is as a Node in a forest of binary heaps (which are implemeted as a tree)
     - holds a value of type T
     - keeps a degree metadata, which is the number of children in the forest
     - keeps track of its next neighbor in the forest via `*sibling`
     - keeps track of its parent in the tree via `*parent`

    '''
    value: int = 0
    degree: int = 0
    child: Node = None
    sibling: Node = None

    def __init__(self, value: int):
        self.value = value
        self.degree = 0
        self.child = None


@dataclass
class BinomialHeap:
    root: Node

    def __init__(self):
        self.root = None

    def _link(self, a: Node, b: Node) -> Node:
        '''
        Links two nodes in the forest
        '''
        assert(a.degree == b.degree)
        if a.value <= b.value:
            if not a.child:
                a.child = b
            else:
                temp = a.child
                while temp.sibling:
                    temp = temp.sibling
                temp.sibling = b
            a.degree += 1
            return a
        else:
            return self._link(b, a)

    def _insert(self, cur: Node, sibling: Node) -> Node:
        '''
        Insertion helper for inserting a node into the forest
        @param cur : Node where the insertion should happen
        @param sibling : Node to be inserted
        @returns : root of the inserted forest
        '''
        if not sibling:
            return cur
        if cur.degree == sibling.degree:
            s_sibling, sibling.sibling = sibling.sibling, None
            return self._insert(self._link(cur, sibling), s_sibling)
        else:
            cur.sibling = sibling
            return cur

    def _merge(self, a: Node, b: Node) -> Node:
        '''
        Merges two trees (binary heaps) in the forest
        - this happens when we have too many or too few nodes for
        a single binomial tree
        @param a : Root of the first (sub) tree
        @param b : Root of the second (sub) tree
        @returns : Root of the merged tree
        '''
        if not a:
            return b
        if not b:
            return a

        if a.degree < b.degree:
            a.sibling = self._merge(a.sibling, b)
            return a
        elif a.degree > b.degree:
            b.sibling = self._merge(a, b.sibling)
            return b
        else:  # equal
            sibling = self._merge(a.sibling, b.sibling)
            a.sibling = b.sibling = None
            cur = self._link(a, b)
            return self._insert(cur, sibling)

    def _find_top(self) -> tuple:
        '''
        Finds the top element by traversing (the "linked list")
        of all root nodes of the trees in the forest

        @returns : (min_prev, min_cur) : "next" extrememum of the heap, extrememum of the heap
        '''
        prev, cur = None, self.root
        min_prev, min_cur = None, self.root
        while cur:
            if cur.value < min_cur.value:
                min_cur = cur
                min_prev = prev
            prev = cur
            cur = cur.sibling
        return min_prev, min_cur

    def append(self, value: int) -> None:
        '''
        Enqueue a value to the heap
        @param value : value to append
        '''
        new_node = Node(value)
        self.root = self._merge(self.root, new_node)

    def pop(self) -> int:
        '''
        Dequeue the top element of the heap
        @returns :  value of the top element
        '''
        min_prev, min_cur = self._find_top()
        val = min_cur.value
        if min_prev:
            min_prev.sibling = min_cur.sibling
        else:
            self.root = min_cur.sibling
        self.root = self._merge(min_cur.child, self.root)
        del min_cur  # mark for garbage collection immediately
        return val

    def top(self) -> int:
        '''
        Peek the top (extremum) element of the heap
        @returns : value of the top element
        '''
        min_prev, min_cur = self._find_top()
        return min_cur.value


'''
Tests / usage
'''
if __name__ == "__main__":
    print("Hello, Binomial Heap!")
    bh = BinomialHeap()
    pq = []

    for _ in range(100):
        for i in range(10000):
            data = random.randint(0, 100000)
            bh.append(data)
            heapq.heappush(pq, data)

        for i in range(10000):
            assert(bh.top() == pq[0])
            bh.pop()
            heapq.heappop(pq)
