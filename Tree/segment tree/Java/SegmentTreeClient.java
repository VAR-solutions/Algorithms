package SegmentTree;

public class SegmentTreeClient {

	public static void main(String[] args) {
		
		int[] arr = {3,8,7,6,-2,-8,4,9};
		SegmentTree st = new SegmentTree(arr);
		st.display();
		System.out.println("--------------------------------");
		System.out.println(st.query(2, 6));
		System.out.println(st.query(1, 5));
		st.update(3, 14);
		st.display();
		System.out.println(st.query(2, 6));
	}

}
