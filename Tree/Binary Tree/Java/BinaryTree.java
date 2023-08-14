import java.util.*;
// Binary Tree implementation using array.
class Tree {
	int size;
	int ar[] ;
	Tree(int size) {
		this.size = size;
		ar = new int[size];
	}

	void setRoot(int data) {
		ar[0] = data;
	}

	void setLeft(int data, int parent) {
		if(ar[parent] == 0) {
			System.out.println("Invalid");
			return;
		}
		int child = 2*parent + 1;
		if(child < 10) {
			ar[child] = data;
			return;
		}
		System.out.println("Overflow");
	}

	void setRight(int data, int parent) {
		if(ar[parent] == 0) {
			System.out.println("Invalid");
			return;
		}
		int child = 2*parent + 2;
		if(child < 10) {
			ar[child] = data;
			return;
		}
		System.out.println("Overflow");
	}
	public void printTree(int size){ 
        for (int i = 0; i < size; i++) { 
            if (ar[i] != 0) 
                System.out.print(ar[i]+" "); 
            else 
            	System.out.print("_"+" ");
    	} 
    }
}
class BinaryTree {
	public static void main(String[] args) {
		Scanner Sc = new Scanner(System.in);
		System.out.println("Enter the size: ");
		int size = Sc.nextInt();
		Tree T = new Tree(size);
		T.setRoot(1);
		T.setLeft(2,0);
		T.setRight(5,0);
		T.setLeft(20,1);
		T.setRight(10,1);
		T.setLeft(23,3);
		T.printTree(size);
	}
}
