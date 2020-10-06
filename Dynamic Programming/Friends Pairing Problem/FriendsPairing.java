import java.util.*;
public class FriendsPairing {  
    static int countFriendsPairing(int n) 
    { 
        int a = 1, b = 2, c = 0; 
        if (n <= 2) { 
            return n; 
        } 
        for (int i = 3; i <= n; i++) { 
            c = b + (i - 1) * a; 
            a = b; 
            b = c; 
        } 
        return c; 
    } 
    public static void main(String[] args) 
    { 
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); 
        System.out.println(countFriendsPairing(n)); 
    } 
}
