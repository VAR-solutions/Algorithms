/// Nodes in a binomial heap
/// keep a reference to their children and
/// siblings (neighbor to the right)
pub struct Node<T>
where
    T: PartialOrd,
{
    pub data: T,
    degree: u32,
    child: Option<Box<Node<T>>>,
    sibling: Option<Box<Node<T>>>,
}

/// Binomial heap (multiple heaps that are mergeable and searchable)
pub struct BinomialHeap<T>
where
    T: PartialOrd,
{
    root: Option<Box<Node<T>>>,
}

impl<T> BinomialHeap<T>
where
    T: PartialOrd,
{
    /// Create an empty binomial heap
    pub fn new() -> Self {
        BinomialHeap { root: None }
    }

    /// chooses how to link two nodes in relation to each other
    fn link(self, mut a: Option<Box<Node<T>>>, b: Option<Box<Node<T>>>) -> Option<Box<Node<T>>> {
        assert_eq!(a.is_some(), b.is_some());
        if a.is_some() && b.is_some() {
            let mut a = a.as_mut().unwrap();
            let b = b.unwrap();
            if a.degree != b.degree {
                panic!("Cannot link two nodes with different degrees");
            }
            if a.data <= b.data {
                if let Some(c) = &a.child {
                    let mut ptr = c;
                    while ptr.sibling.is_some() {
                        ptr = ptr.sibling.unwrap();
                    }
                    ptr.sibling = Some(b);
                } else {
                    // a is assignbed b as a child in the default case
                    a.child = Option::from(b);
                }
                a.degree += 1;
                let a = &*a;
                return Some(*a);
            } else {
                let a = &*a;
                return self.link(Some(b), Some(*a));
            }
        }
        None
    }

    /// Insertion helper for nodes inside forest
    fn insert(
        self,
        cur: Option<Box<Node<T>>>,
        sibling: Option<Box<Node<T>>>,
    ) -> Option<Box<Node<T>>> {
        if sibling.is_none() {
            return cur;
        }
        if cur.is_some() && sibling.is_some() {
            let mut cur = cur.unwrap();
            let mut sibling = sibling.unwrap();
            if cur.degree == sibling.degree {
                let tmp = sibling.sibling;
                sibling.sibling = None;
                let linked = self.link(Some(cur), Some(sibling)).unwrap();
                return self.insert(Some(linked), tmp);
            } else {
                cur.sibling = Some(sibling);
                return Some(cur);
            }
        }
        None
    }
    /// Merge two heaps or "sub" heaps (treated as forests)
    fn merge(self, a: Option<Box<Node<T>>>, b: Option<Box<Node<T>>>) -> Option<Box<Node<T>>> {
        if a.is_none() {
            return b;
        }
        if b.is_none() {
            return a;
        }
        let mut a = a.unwrap();
        let mut b = b.unwrap();
        if (a.degree < b.degree) {
            a.sibling = self.merge(a.sibling, Some(b));
            return Some(a);
        } else if a.degree > b.degree {
            b.sibling = self.merge(Some(a), b.sibling);
            return Some(b);
        } else {
            let sibling = self.merge(a.sibling, b.sibling);
            a.sibling = None;
            b.sibling = None;
            let c = self.link(Some(a), Some(b));
            return self.insert(c, sibling);
        }
    }

    fn find_top(self, cur: Option<Box<Node<T>>>) -> Option<Box<Node<T>>> {
        if cur.is_none() {
            return None;
        }
        None
    }

    pub fn push(value: T) {}

    pub fn pop(&mut self) -> Option<T> {
        None
    }

    pub fn peek(&self) -> Option<&T> {
        None
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
