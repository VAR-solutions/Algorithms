import java.io.*;
import java.util.*;
  
  class postorder{
 private Node root;
   private class Node{

    private Node left;
    private Node right;
   
    int data;
   
    public Node(int data){
       this.data=data;  
       System.out.print(data+"\t");       
    }
  }

  public void createBinaryTree(){


    Node first = new Node(1);
    Node second = new Node(2);
    Node third = new Node(3);
    Node fourth = new Node(4);
    Node fifth = new Node(5);
   
     root = first;
     first.left = second;
     first.right = third;
     second.left = fourth;
     second.right = fifth;
  }

   public void postorders(Node root){

      if(root == null){
      return ; 
     }
     postorders(root.left);
     postorders(root.right);
     System.out.print(root.data+"\t");
   } 



 public static void main(String args[]){

   postorder obj = new postorder();
   System.out.println("Before post");
   obj.createBinaryTree();
   System.out.println();
   System.out.println("After postorder");
   obj.postorders(obj.root);
 }
}
