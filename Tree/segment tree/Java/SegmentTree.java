package SegmentTree;

public class SegmentTree {
	private class Node{
		int data;
		int startInterval, endInterval;
		Node left, right;
	}
	
	Node root; 
	
	public SegmentTree(int[] arr) {
		this.root = constructTree(arr, 0, arr.length-1);
	}
	
//	O(n) Time
	private Node constructTree(int[] arr, int si, int ei) {
		if(si == ei) {
			Node ln = new Node();
			ln.data = arr[si];
			ln.startInterval = si;
			ln.endInterval = ei;
			return ln;
		}
		Node node = new Node();
		node.startInterval = si;
		node.endInterval = ei;
		int mid = (si+ei)/2;
		node.left = constructTree(arr, si, mid);
		node.right = constructTree(arr, mid+1, ei);
		node.data = node.left.data + node.right.data;
		return node;
	}
	
	public void display() {
		display(root);
	}

	private void display(Node node) {
		if(node == null)
			return;
		
		String left = "";
		if(node.left != null)
			left = "["+node.left.startInterval+"-"+node.left.endInterval+"]" + ":"+node.left.data;
		else
			left = null;
		
		String right = "";
		if(node.right != null)
			right = "["+node.right.startInterval+"-"+node.right.endInterval+"]" + ":"+node.right.data;
		else
			right = null;
		
		String curr = "["+node.startInterval+"-"+node.endInterval+"]" + ":"+node.data;
		String str = left + "->" + curr + "<-" + right;
		System.out.println(str);
		
		display(node.left);
		display(node.right);
		
	}
	
	public int query(int qsi, int qei) {
		return query(root, qsi, qei);
	}

	private int query(Node node, int qsi, int qei) {
		// node the conpletely lying inside query so will contribute to the answer
		if(node.startInterval >= qsi && node.endInterval <= qei)
			return node.data;
		else if(node.startInterval > qei || node.endInterval < qsi)
			// node interval is completely outside query interval
			return 0;
		else {
			// node interval is overlapping with query interval
			return query(node.left, qsi, qei) + query(node.right, qsi, qei); 
		}
		
	}
	
	public void update(int index, int value) {
		root.data = update(root, index, value);
	}

	private int update(Node node, int index, int value) {
		if(node.startInterval <= index && node.endInterval >= index) {
			if(node.startInterval == index && node.endInterval == index) {
				node.data = value;
			}else {
				node.data = update(node.left, index, value) + update(node.right, index, value);
			}
		}
		return node.data;
	}
}
