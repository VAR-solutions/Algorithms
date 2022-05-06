use std::collections::BinaryHeap;
use std::collections::LinkedList;

#[derive(Debug)]
struct Node<T>
where
    T: PartialOrd,
{
    data: T,
    degree: u32,
    next: Option<Box<Node<T>>>,
}

impl<T> Node<T>
where
    T: PartialOrd,
{
    /// Constructor for Node in BinomialHeap
    fn new(data: T, next: Option<Box<Node<T>>>) -> Node<T> {
        Node {
            data: data,
            degree: 0,
            next: next,
        }
    }

    /// Helper for setting the next node
    fn link(&mut self, other: &mut Node<T>) {
        self.next = Some(other.next.take().unwrap());
    }

    /// Rebalance the heap contained in the other tree with the elements of this tree
    fn add_subtree(&mut self, other: &mut Node<T>) {
        // FIXME : implement this function
        self.link(other);
    }
}

/// Binomial Heap (implementation on any type that can be ordered)
#[derive(Debug)]
pub struct BinomialHeap<T>
where
    T: PartialOrd,
{
    data: Vec<Node<T>>,
}

impl<T> BinomialHeap<T>
where
    T: PartialOrd,
{
    /// Create a new binomial heap
    /// # Examples
    pub fn new() -> Self {
        BinomialHeap { data: Vec::new() }
    }

    pub fn is_empty(&self) -> bool {
        self.data.is_empty()
    }

    pub fn insert(&self, k: T) -> Self {
        let mut new_heap = Self::new();
        new_heap.data.push(Node::new(k, None));
        new_heap
    }

    // merges two heaps and rebalances them
    // Assumes both nodes are root nodes of a heap within the binomial heap
    fn merge_tree(p: &mut Node<T>, q: &mut Node<T>) {
        if p.data <= q.data {
            p.add_subtree(q);
        } else {
            q.add_subtree(p);
            // std::mem::swap(p, q);
        }
    }

    fn merge(p: &mut Node<T>, q: &mut Node<T>) -> Result<(), ()> {
        /// FIXME: implement this function
        Ok(())
    }

    pub fn get_min(&self) -> Option<&T> {
        self.data.first().map(|x| &x.data)
    }

    pub fn extract_min(&mut self) -> Option<T> {
        self.data.pop().map(|x| x.data)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_insert() {
        let mut heap: BinomialHeap<f64> = BinomialHeap::new();
    }
}
