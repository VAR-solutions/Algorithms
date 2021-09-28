public class Heap {
	private Object[] elements;
	private int qtd = 0;
	
	public Heap(int size) {
		elements = new Object[size];
	}

	public boolean isEmpty() {
		return (qtd == 0);
	}

	public Object size() {	
		return qtd;
	}

	public void stackUp(Object element) {
		if(qtd == elements.length)
			throw new FullStackException("It is not possible to stack! Full Stack!");
		this.elements[qtd] = element;
		qtd++;
		
	}

	public Object top() {
		return elements[qtd - 1];
	}

	public Object unstack() {
		if(isEmpty())
			throw new EmptyHeapException("It is not possible to unstack! Empty Heap!");
		Object top = top();
		qtd--;
		return top;
	}
}
