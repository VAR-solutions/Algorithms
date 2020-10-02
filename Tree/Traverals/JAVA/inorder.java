/*when you are compiling your program change the .java class file to inorder because the class declared as public*/

import java.io.*;
import java.util.*;
 public class inorder{
 
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

 /* public void inorders(Node root){

         if(root == null){
        return ; 
        }
       inorders(root.left);
       System.out.print(root.data+"\t");
       inorders(root.right);
   } */

/* this is using the stack concept*/

  public void inorders(){

  if(root == null){
    return; 
  }
 Stack<Node> stack = new Stack<>();
  Node temp = root;
  while(!stack.isEmpty() || (temp!=null)){
     if(temp!=null){
      stack.push(temp);
      temp = temp.left;
      }else{
        temp = stack.pop();
        System.out.print(temp.data+"\t");
        temp = temp.right;
      }
   }  
}

 public static void main(String args[]){

   inorder obj = new inorder();
   System.out.println("Before inorder");
   obj.createBinaryTree();
   System.out.println(); 
   System.out.println("After inorder");
   obj.inorders();
  }
}