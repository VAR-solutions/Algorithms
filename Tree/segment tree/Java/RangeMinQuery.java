package SegmentTree;

//import java.util.stream.IntStream;

public class RangeMinQuery {

	public static void main(String[] args) {

		int a[] = { 1, 3, 2, -2, 4, 5 };
		int n = a.length;

		int[] tree = new int[4 * n + 1];
		
		buildTree(a, tree, 0, 0, n-1);
				
		System.out.println(query(tree, 0, 0, n-1, 1, 4));
		update(tree, 0, 0, n-1, 3, 6);
		System.out.println(query(tree, 0, 0, n-1, 2, 5));

	}

	public static void buildTree(int[] a, int[] tree, int index, int si, int ei) {
		// Base case - Leaf node
		if (si == ei) {
			tree[index] = a[si];
			return;
		}
		
		int mid = (si+ei)/2;
		
		//Left Subtree
		buildTree(a, tree, 2*index+1, si, mid);
		buildTree(a, tree, 2*index+2, mid+1, ei);
		
		int left = tree[2*index+1];  // left child
		int right = tree[2*index+2]; // right child
		
		tree[index] = Math.min(left, right);
	}
	
	public static int query(int[] tree, int index, int si, int ei, int qsi, int qei) {
		// Complete overlap
		if(qsi <= si && qei>=ei)
			return tree[index];
		
		// No overlap
		if(qei < si || qsi > ei)
			return Integer.MAX_VALUE;
		
		// partial overlap
		int mid = (si+ei)/2;
		int leftAns = query(tree, 2*index+1, si, mid, qsi, qei);
		int rightAns = query(tree, 2*index+2, mid+1, ei, qsi, qei);
		return Math.min(leftAns, rightAns);
	}
	
	public static void update(int[] tree, int index, int si, int ei, int i, int val) {
		if(si == i && ei == i) {
			tree[index] = val;
			return;
		}
		if(si>i || ei<i)
			return;
		
		int mid = (si+ei)/2;
		update(tree, 2*index+1, si, mid, i, val);
		update(tree, 2*index+2, mid+1, ei, i, val);
		
		tree[index] = Math.min(tree[2*index+1], tree[2*index+2]);
		
	}

}
