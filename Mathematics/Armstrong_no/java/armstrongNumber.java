import java.io.*;
import java.util.*;

class Armstrong{
    void check(int n) {
        int temp=n, ctr=0, sum=0;
        while(temp>0) {
            temp /= 10;
            ctr++;
        }
        
        temp=n;
        while(temp>0) {
            sum += Math.pow((temp%10),ctr);
            temp /= 10;
        }

        if(sum==n)
            System.out.println("It is an Armstrong no.");
        else
            System.out.println("It is not an Armstrong no.");
    }
}

class MyClass {
    public static void main(String args[]) {
        Armstrong a = new Armstrong();
        int num;
        Scanner sc = new Scanner(System.in);
        num=sc.nextInt();
        a.check(num);
    }
}