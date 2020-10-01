import java.io.*;

public class BinaryTree{

   private TreeNode root;
   private class TreeNode{
       
       private TreeNode right;
       private TreeNode left;
       private int data; //genric we can store any data
    public TreeNode(int data){
         this.data = data; 
         System.out.println(data);
      }
    }
    public void createBinaryTree(){
          
          TreeNode first = new TreeNode(1);
          TreeNode second = new TreeNode(2);
          TreeNode third = new TreeNode(3);
          TreeNode fourth = new TreeNode(4);
          TreeNode fifth = new TreeNode(5);
                 
           root = first;
           first.left = second;
           first.right = third;
           second.left = fourth;
           second.right = fifth;
       
       
     }
   public static void main(String args[]){     
       BinaryTree obj = new BinaryTree();
       obj.createBinaryTree();
  }
}