import java.util.LinkedList;
import java.util.Scanner;

public class GenericTreePractise {
	static Scanner s = new Scanner(System.in);

	static GenericTreeNode<Integer> createGenericTree() {

		System.out.println("Enter data");
		int data = s.nextInt();
		GenericTreeNode<Integer> root = new GenericTreeNode<>(data);
		System.out.println("Enter no of children of " + data + "th Node");
		int noOfChildren = s.nextInt();
		for (int i = 0; i < noOfChildren; i++) {
			GenericTreeNode<Integer> child = createGenericTree();
			root.children.add(child);
		}
		return root;
	}

	static void printGenericTree(GenericTreeNode<Integer> root) {
		String toBePrinted = root.data + ": ";
		for (int i = 0; i < root.children.size(); i++) {
			toBePrinted = toBePrinted + root.children.get(i).data + ", ";
		}

		System.out.println(toBePrinted);

		for (int i = 0; i < root.children.size(); i++) {
			printGenericTree(root.children.get(i));
		}
	}
	
	int height(GenericTreeNode<Integer> root){
		int height = 0;
		for(int i =0;i<root.children.size();i++){
			int tempHeight = height(root.children.get(i));
			if(tempHeight>height){
				height = tempHeight;
			}
		}
		return height+1;
		
	}
	
	GenericTreeNode<Integer> createQueue(){
		
		LinkedList<GenericTreeNode<Integer>> queue = new LinkedList<>();
		int root_data = s.nextInt();
		GenericTreeNode<Integer> root = new GenericTreeNode<>(root_data);
		queue.addLast(root);
		while(queue.isEmpty()){
			GenericTreeNode<Integer> currentNode = queue.removeFirst();
			System.out.println("Enter no. of children "+currentNode.data);
			int noOfChildren = s.nextInt();
			for(int i=0;i<noOfChildren;i++){
				int childData = s.nextInt();
				GenericTreeNode<Integer> child = new GenericTreeNode<>(childData);
				queue.addLast(child);
				currentNode.children.add(child);
			}
		}
		return root;
	}
		
	
	GenericTreeNode<Integer> fun(GenericTreeNode<Integer> root){
		GenericTreeNode<Integer> maxNode = root;
		for(int i =0;i<root.children.size();i++){
			GenericTreeNode<Integer> tempMaxNode = fun(root.children.get(i));
			if(tempMaxNode.data.compareTo(maxNode.data)>0){
				maxNode = tempMaxNode;
			}
		}
		return maxNode;
		
	}

	public static void main(String[] args) {

		GenericTreeNode<Integer> root = createGenericTree();
		printGenericTree(root);
	}
}
