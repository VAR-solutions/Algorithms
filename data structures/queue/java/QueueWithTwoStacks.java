import java.util.Arrays;
import java.util.Stack;

public class QueueWithTwoStacks {
	
	static class StackQueue{
		private  Stack<Integer> stackOne = new Stack<>();
		private  Stack<Integer> stackTwo = new Stack<>();
		
		/**
	     * @param item to be added in the queue
	     */
		public void enqueue(int item) {
			stackOne.push(item);
		}
		
		/**
	     * @return the item which has been dequeued
	     * @throws IllegalStateException if the queue is empty
	     */
		public int dequeue() {
			if(stackOne.isEmpty())
				throw new IllegalStateException("queue is empty");
			moveOneStackToTwoStack();
			int item = stackTwo.pop();
			moveTwoStackToOneStack();
			return item;
		}
		
		/**
	     * @return the first item of the queue
	     * @throws IllegalStateException if the queue is empty
	     */
		public int peek() {
			if(stackOne.isEmpty())
				throw new IllegalStateException("queue is empty");
			moveOneStackToTwoStack();
			int peek = stackTwo.peek();
			moveTwoStackToOneStack();
			return peek;
		}
		
		private void moveOneStackToTwoStack() {
			if(stackTwo.isEmpty())
				while(!stackOne.isEmpty())
					stackTwo.push(stackOne.pop());
		}
		
		private void moveTwoStackToOneStack() {
				while(!stackTwo.isEmpty())
					stackOne.push(stackTwo.pop());
		}
		
		
		@Override
		public String toString() {
			return Arrays.toString(stackOne.toArray());
		}
		
	}
	
	
	public static void main(String[] args) {
	
		StackQueue queue = new StackQueue();
		queue.enqueue(10);
		queue.enqueue(20);
		queue.enqueue(30);
		queue.enqueue(40);
		
		System.out.println(queue.toString()); // returns [10, 20, 30, 40]
		
		queue.dequeue();

		System.out.println(queue.toString()); // returns [20, 30, 40]
		System.out.println(queue.peek()); //returns 20
	}

}
