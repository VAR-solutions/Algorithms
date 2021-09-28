import java.util.*;  
    
public class AddElementsToLinkedList {  
    
    public static void main(String args[])  
    {  
        LinkedList<String> ll = new LinkedList<>();  
    
        ll.add("Geeks");  
        ll.add("Geeks");  
        ll.add(1, "For");  
    
        System.out.println(ll); 
        //[Geeks, For, Geeks] 
    }  
}