public class LinkedStack{

	private class Node{
		private int data;
		private Node next;

		Node(int data){
			this.data = data;
			this.next = null;
		}
	}

	private Node top;
	LinkedStack(){
		top = null;
	}
	public void push(int value){
		Node temp = new Node(value);
		if(this.top == null){
			this.top = temp;
		}
		else{
			temp.next = top;
			top = temp;
		}
	}

	public int pop(){
		if(top==null) throw new IllegalStateException();

		int temp = top.data;
		top = top.next;
		return temp;
	}

	public int peek(){
		if(top==null) throw new IllegalStateException();

		return top.data;
	}

	public Boolean isEmpty(){
		return top==null;
	}

	public void print(){
		Node temp = this.top;

		while(temp!=null){
			System.out.println(temp.data);
			temp = temp.next;
		}
	}
}