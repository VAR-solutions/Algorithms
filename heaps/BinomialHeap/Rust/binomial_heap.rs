/// After a lot of trouble implementing this myself in rust, I heavily referenced the following:
/// - https://github.com/apasel422/binomial-heap
use std::mem;

struct Node<T>
where
    T: PartialOrd + Copy,
{
    data: T,
    degree: u64,
    pub sibling: Option<Box<Node<T>>>,
    child: Option<Box<Node<T>>>,
}

#[allow(dead_code)]
impl<T> Node<T>
where
    T: PartialOrd + Copy,
{
    fn new(data: T) -> Self {
        Node {
            data: data,
            degree: 0,
            sibling: None,
            child: None,
        }
    }

    fn push(node: &mut Option<Box<Node<T>>>, data: T) {
        let new_node = Some(Box::new(Node {
            data: data,
            degree: 0,
            sibling: None,
            child: None,
        }));

        match *node {
            None => *node = new_node,
            Some(ref mut node) => {
                Node::insert(node, new_node);
            }
        }
    }

    fn insert(node: &mut Box<Node<T>>, other: Option<Box<Node<T>>>) {
        if let Some(other) = other {
            Node::merge(node, other);
            Node::coalesce(node);
        }
    }

    fn merge(mut a: &mut Box<Node<T>>, mut b: Box<Node<T>>) {
        loop {
            let a_ = a;

            if a_.degree > b.degree {
                mem::swap(a_, &mut b);
            }

            match a_.sibling {
                None => return a_.sibling = Some(b),
                Some(ref mut next) => a = next,
            }
        }
    }

    /// Coalesces nodes in the given sibling list in order to restore the binomial heap property that
    /// no two nodes in the list have the same order.
    ///
    /// The list rooted at `a` must be monotonically increasing by order and its individual nodes must
    /// be valid extremum-heaps.
    ///
    /// This method should always be preceded by `merge`.
    ///
    /// ! the other language implementations checked to maintain this order in `link` and `merge`
    fn coalesce(mut a: &mut Box<Node<T>>) {
        enum Case {
            A,
            B,
            C,
        }

        loop {
            let a_ = a;

            let case = match a_.sibling {
                None => return,
                Some(ref b) => {
                    if a_.degree != b.degree
                        || b.sibling.as_ref().map_or(false, |c| c.degree == b.degree)
                    {
                        Case::A
                    } else if a_.data >= b.data {
                        Case::B
                    } else {
                        Case::C
                    }
                }
            };

            match case {
                Case::A => a = a_.sibling.as_mut().unwrap(),
                Case::B => {
                    let mut b = a_.sibling.take().unwrap();
                    a_.sibling = b.sibling.take();
                    Node::link(a_, b);

                    match a_.sibling {
                        None => return,
                        Some(ref mut c) => a = c,
                    }
                }
                Case::C => {
                    let mut b = a_.sibling.take().unwrap();
                    mem::swap(a_, &mut b);
                    Node::link(a_, b);
                    a = a_;
                }
            }
        }
    }

    fn link(a: &mut Node<T>, mut b: Box<Node<T>>) {
        debug_assert!(a.degree == b.degree);
        debug_assert!(b.sibling.is_none());
        debug_assert!(a.data >= b.data);

        b.sibling = a.child.take();
        a.child = Some(b);
        a.degree += 1;
    }

    fn peek(root: &Option<Box<Node<T>>>) -> Option<&T> {
        root.as_ref().map(|mut node| {
            let mut a = &node.sibling;
            while let Some(ref b) = *a {
                if b.data > node.data {
                    node = b;
                }
                a = &b.sibling;
            }

            &node.data
        })
    }

    fn pop(root: &mut Option<Box<Node<T>>>, len: &mut usize) -> Option<T> {
        Node::remove_max(root).map(|cur| {
            let cur = *cur;
            let Node {
                data,
                child,
                degree: _degree,
                sibling: _next,
            } = cur;

            match *root {
                None => *root = child,
                Some(ref mut root) => {
                    Node::insert(root, child);
                }
            }

            *len -= 1;
            data
        })
    }

    fn remove_max(mut a: &mut Option<Box<Node<T>>>) -> Option<Box<Node<T>>> {
        a.take().map(|mut node| {
            *a = node.sibling.take();

            loop {
                let a_ = a;

                match *a_ {
                    None => return node,
                    Some(ref mut b) => {
                        if b.data > node.data {
                            node.sibling = b.sibling.take();
                            mem::swap(&mut node, b);
                        }
                    }
                }

                a = &mut a_.as_mut().unwrap().sibling;
            }
        })
    }
}

// Binomial Heap with buffer-like hash map
// instead of linked list
pub struct BinomialHeap<T>
where
    T: PartialOrd + Copy,
{
    root: Option<Box<Node<T>>>,
    len: usize,
}

#[allow(dead_code)]
impl<T> BinomialHeap<T>
where
    T: PartialOrd + Copy,
{
    pub fn new() -> Self {
        BinomialHeap { root: None, len: 0 }
    }

    pub fn is_empty(&self) -> bool {
        self.root.is_none()
    }

    pub fn push(&mut self, data: T) {
        Node::push(&mut self.root, data);
        self.len += 1;
    }

    // Gets the top element of the heap
    pub fn peek(&self) -> Option<&T> {
        Node::peek(&self.root)
    }

    pub fn pop(&mut self) -> Option<T> {
        Node::pop(&mut self.root, &mut self.len)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::BinaryHeap;
    #[test]
    fn stress() {
        let mut bh: BinomialHeap<i32> = BinomialHeap::new();
        let mut hq: BinaryHeap<i32> = BinaryHeap::new();

        println!("heaps constructed");

        for _ in 0..100 {
            for _ in 0..10000 {
                let new_data: i32 = rand::random();
                let new_data = new_data % 10000;
                bh.push(new_data);
                hq.push(new_data);
            }

            println!("Push succeeded!");

            for _ in 0..10000 {
                assert_eq!(bh.peek() == hq.peek(), true);
                bh.pop();
                hq.pop();
            }
        }
    }
}
