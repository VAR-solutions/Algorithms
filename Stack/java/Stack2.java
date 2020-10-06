
import java.util.*;

public class Stack2{
	private	int top1;
	private	int top2;
	private	int[] stack;
	public Stack2(){
		top1 = -1;
		stack = new int[10];
		top2 = stack.length;
	}

	public void push1(int value){
		if(this.top1 == this.top2+1) {
			throw new StackOverflowError();
		}
		else{
			if(this.top1==-1 && this.top2!=0) this.top1++;
			this.stack[this.top1++]=value;
		}
	}

	public void push2(int value){
		if(this.top1-1 == this.top2) {
			throw new StackOverflowError();
		}
		else{
			if(this.top2 == stack.length && this.top1!=stack.length-1) this.top2--;
			this.stack[this.top2--]=value;
		}
	}

	public int pop1(){
		if(this.top1 == -1) {
			throw new IllegalStateException();
		}
		else{
			return this.stack[this.top1--];
		}
	}

	public int pop2(){
		if(this.top2 == stack.length) {
			throw new IllegalStateException();
		}
		else{
			return this.stack[this.top2++];
		}
	}

	public Boolean isEmpty1(){
		return this.top1==-1;
	}

	public Boolean isEmpty2(){
		return this.top2==stack.length;
	}

	public Boolean isFull1(){
		return this.top2==this.top1;
	}
	public Boolean isFull2(){
		return this.top2==this.top1;
	}

	@Override
	public String toString(){
		return Arrays.toString(stack);
	}
}