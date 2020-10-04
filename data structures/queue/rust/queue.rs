#[derive(Debug)]
struct Queue<T>(Vec<T>);

impl<T> Queue<T> {
    fn new() -> Queue<T> {
        Queue(Vec::<T>::new())
    }
    fn enqueue(&mut self, item: T) {
        self.0.push(item);
    }
    fn dequeue(&mut self) {
        if !self.0.is_empty() {
            self.0.remove(0);
        }
    }
    fn length(&self) -> usize {
        self.0.len()
    }
}

fn main() {
    let mut queue = Queue::<&str>::new();
    queue.enqueue("T");
    println!("{:?}", queue);
    println!("Length of the queue is: {}", queue.length());
    queue.dequeue();
    println!("{:?}", queue);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn queue_enqueue() {
        let mut queue = Queue::<i32>::new();
        queue.enqueue(5);
        assert_eq!(queue.0, vec![5]);
    }

    #[test]
    fn queue_dequeue() {
        let mut queue = Queue::<i32>::new();
        queue.enqueue(5);
        queue.dequeue();
        assert_eq!(queue.0, vec![]);
    }

    #[test]
    fn queue_length() {
        let mut queue = Queue::<i32>::new();
        queue.enqueue(5);
        queue.enqueue(59);
        assert_eq!(queue.length(), 2);
    }
}