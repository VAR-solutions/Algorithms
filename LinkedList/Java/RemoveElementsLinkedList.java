import java.util.*;  
    
public class RemoveElementsLinkedList {  
    
    public static void main(String args[])  
    {  
        LinkedList<String> ll = new LinkedList<>();  
    
        ll.add("Geeks");  
        ll.add("Geeks");  
        ll.add(1, "For");  
    
        System.out.println(  
            "Initial LinkedList " + ll);  
    
        ll.remove(1);  
    
        System.out.println(  
            "After the Index Removal " + ll);  
    
        ll.remove("Geeks");  
    
        System.out.println(  
            "After the Object Removal " + ll);  
    }  
}