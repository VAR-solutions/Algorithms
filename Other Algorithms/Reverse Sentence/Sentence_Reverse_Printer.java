import java.io.*;
class Sentence_Reverse_Printer
{
   public static void main()throws IOException
   {
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       System.out.println("Enter a string:");
       String s=br.readLine();
       String st1="",st2="";
       s=s+" ";
       int d=0;
       int x=s.length();
       for(int i=0;i<x;i++)
       {
           char b=s.charAt(i);
           if(b==' ')
           {
               d++;
               if(d==1)
               {st1=st1+st2;
               st2="";}
               if(d>1)
               {st1=st1+" "+st2;
               st2="";}
           }
           else
           {
               st2=b+st2;
           }
       }
       System.out.println(st1);
   }
}
