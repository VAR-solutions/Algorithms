# Binomial Heap

A priority queue based on a binomial heap.

Like a `BinaryHeap`, `BionmialHeap` is an implementation of a priority queue.

Unlike
`BinaryHeap`, `BionmialHeap` provides an efficient `merge` method, at the cost of greater
memory usage, slower iteration, poor cache locality and inneficient retrieval of the extrememum.

## Time Complexity

| Operation   | Time Complexity        |
| ----------- | ---------------------- |
| [`merge`]   | `O(log n)` (amortized) |
| [`min/max`] | `O(log n)`             |
| [`pop`]     | `O(log n)`             |
| [`push`]    | `O(1)` (amortized)     |

## Motivation

- Used for small datasets < 100000 nodes
- Used when we need to merge many heaps together

## Implementation summary

- We maintain a top level linked list that contains the roots of ordered heaps
- In order that the list of top level nodes is never longer than `O(log n)` and that searching, maintaing and merging these sub-heaps is never greater than `O(log(n))`, we choose that each heap size should follow the binomial coeff, depending on the total size of the heap.

- i.e., in a binomial heap of 6 elements, we would have 3 sub heaps of size 3, 2 and 1. Similarly for a heap of 10 elements, we would have sub heaps of size 6, 3 and 1.

## Visual Example

- Start with an empty binomial heap

```
None
```

- Append 0

```
[0]
```

- Append 1

```
[0] -> [1]
```

- Append 2

```
[2] -> [1]
        |
       [0]
```

- Append 3

```
       [3]
     ---|
     | [2]
    [1]
     |
    [0]
```

- Append 4

```
[4] -> [3]
     ---|
     | [2]
    [1]
     |
    [0]

```
