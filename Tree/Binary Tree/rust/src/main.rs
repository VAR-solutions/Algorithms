#[derive(PartialEq)]

/* Defining a Node Structure */
struct Node<'a> {
    val: &'a str,
    l: Option<Box<Node<'a>>>,
    r: Option<Box<Node<'a>>>,
}

/* Value and create Nodes on the BT */
impl<'a> Node<'a> {
    pub fn insert(&mut self, new_val: &'a str) {
        if self.val == new_val {
            return
        }
        let target_node = if new_val < self.val { &mut self.l } else { &mut self.r };
        match target_node {
            &mut Some(ref mut subnode) => subnode.insert(new_val),
            &mut None => {
                let new_node = Node { val: new_val, l: None, r: None };
                let boxed_node = Some(Box::new(new_node));
                *target_node = boxed_node;
            }
        }
    }
}

fn main () {
    let mut x = Node { val: "m", l: None, r: None };
    x.insert("z");
    x.insert("b");
    x.insert("c");
    assert!(x == Node {
        val: "m",
        l: Some(Box::new(Node {
            val: "b",
            l: None,
            r: Some(Box::new(Node { val: "c", l: None, r: None })),
        })),
        r: Some(Box::new(Node { val: "z", l: None, r: None })),
    });
}
