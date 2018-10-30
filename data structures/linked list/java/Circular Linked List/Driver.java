
public class Driver {
	public static void main(String[] args){
		Circular_LL list = new Circular_LL();
		list.insert(23);
		System.out.println("After inseting first element: ");
		list.print();
		list.insertm(24);
		list.insertm(35);
		list.insertm(14);
		list.insertm(25);
		System.out.println("After inseting more element: ");

		list.print();
		list.nodeAtPosition(0);
	}

}
