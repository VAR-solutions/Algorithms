
import java.util.*; 

public class Stack{
	private	int top;
	private	int[] stack;
	public Stack(){
		top = 0;
		stack = new int[5];
	}

	public void push(int value){
		if(this.top == stack.length) {
			throw new StackOverflowError();
		}
		else{
			this.stack[top++]=value;
		}
	}
	
	public int pop(){
		if(top == 0) {
			throw new IllegalStateException();
		}
		else{
			return this.stack[top--];
		}
	}

	public int peek(){
		if(top == 0) {
			throw new IllegalStateException();
		}
		else{
			return this.stack[top-1];
		}
	}

	public Boolean isEmpty(){
		return top==0;
	}

	@Override
	public String toString(){
		int[] content = Arrays.copyOfRange(stack, 0, top);
		return Arrays.toString(content);
	}
}