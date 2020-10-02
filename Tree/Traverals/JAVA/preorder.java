import java.io.*;
import java.util.*;

 public class preorder{
   private Node root;
    private class Node{      
       int data;
       private Node right;
       private Node left;
   
   private Node(int data){
   this.data = data;
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
/* public void preorders(Node root){
     if(root == null){
     return ;
   }
   System.out.print(root.data+"\t");
   preorders(root.left);
   preorders(root.right);
 } */

    public void preorders(){

      if(root == null){
        return;
      }
    Stack<Node> stack = new Stack<>();
    stack.push(root);
   
    while(!stack.isEmpty()){
      
        Node temp = stack.pop();
        System.out.print(temp.data+"\t");
        if(temp.right!= null){
         stack.push(temp.right);   
          }
       if(temp.left!=null){
       stack.push(temp.left); 
       }
    }

}
    
   public static void main(String args[]){   
   preorder obj = new preorder();
   System.out.println("Before preorders");
   obj.createBinaryTree();
    System.out.println();
    System.out.println("After preorders");
   obj.preorders();
 }
}
