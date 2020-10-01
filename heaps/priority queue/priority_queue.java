// Java code to implement Priority Queue  
// using Linked List  
import java.util.* ; 
  
class Solution 
{ 
    
    
// Node  
 static class Node {  
    int data;  
    
    // Lower values indicate higher priority  
    int priority;  
    
     Node next;  
    
} 
  
static Node node = new Node(); 
    
// Function to Create A New Node  
static Node newNode(int d, int p)  
{  
    Node temp = new Node();  
    temp.data = d;  
    temp.priority = p;  
    temp.next = null;  
    
    return temp;  
}  
    
// Return the value at head  
static int peek(Node head)  
{  
    return (head).data;  
}  
    
// Removes the element with the  
// highest priority form the list  
static Node pop(Node head)  
{  
    Node temp = head;  
    (head)  = (head).next;  
    return head; 
}    
    
// Function to push according to priority  
static Node push(Node head, int d, int p)  
{  
    Node start = (head);  
    
    // Create new Node  
    Node temp = newNode(d, p);  
    
    // Special Case: The head of list has lesser  
    // priority than new node. So insert new  
    // node before head node and change head node.  
    if ((head).priority > p) {  
    
        // Insert New Node before head  
        temp.next = head;  
        (head) = temp;  
    }  
    else {  
    
        // Traverse the list and find a  
        // position to insert new node  
        while (start.next != null &&  
               start.next.priority < p) {  
            start = start.next;  
        }  
    
        // Either at the ends of the list  
        // or at required position  
        temp.next = start.next;  
        start.next = temp;  
    }  
    return head; 
}  
    
// Function to check is list is empty  
static int isEmpty(Node head)  
{  
    return ((head) == null)?1:0;  
}  
    
// Driver code  
public static void main(String args[]) 
{  
    // Create a Priority Queue  
    // 7.4.5.6  
    Node pq = newNode(4, 1);  
    pq =push(pq, 5, 2);  
    pq =push(pq, 6, 3);  
    pq =push(pq, 7, 0);  
    
    while (isEmpty(pq)==0) {  
        System.out.printf("%d ", peek(pq));  
        pq=pop(pq);  
    }  
    
}  
}
