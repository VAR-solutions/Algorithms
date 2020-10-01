import java.util.*;

class Process
{
    //Process arrival time , CPU burst time and priority
    int atime, cbt, priority;

    // Taking input for the variables
    void input()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Process Priority: ");
        priority=sc.nextInt();
        System.out.println("Enter Process Arrival Time: ");
        atime=sc.nextInt();
        System.out.println("Enter Process CPU Burst Time: ");
        cbt=sc.nextInt();
    }

    public static void main(String[] args)
    {

        //Declaring the queues and the quantum times
        int qt1=2,qt2=4,qt3=6,qt4=8;
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        Queue<Integer> q3 = new LinkedList<>();
        Queue<Integer> q4 = new LinkedList<>();

        //Making queue for the first Round Robin
        Queue<Integer> rrqueue1= new LinkedList<>();


        //Entering the processes
        System.out.println("Enter the number of process:- ");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Process p[]= new Process[n];
        for(int i=0;i<n;i++)
        {
            p[i]=new Process();
            p[i].input();
        }


        // Making Arraylist for all the process parameters
            ArrayList<Integer> arrival=new ArrayList<>();
            for(int i=0;i<n;i++)
                arrival.add(p[i].atime);

            ArrayList<Integer> burst=new ArrayList<>();
            for(int i=0;i<n;i++)
                burst.add(p[i].cbt);

            ArrayList<Integer> prio=new ArrayList<>();
            for(int i=0;i<n;i++)
                prio.add(p[i].priority);

            //Temporary Arraylist
            ArrayList<Integer> temp2=new ArrayList<>();


            //Declaring thread
            Thread thread=new Thread();

            // Storing the sum of all the CPU burst time in sum
            int sum=0;
            for(int i=0;i<burst.size();i++)
            {
                sum+=burst.get(i);
                sum+=arrival.get(i);
            }

            sum =sum + Collections.min(burst);
            System.out.println("The Total time is:- "+ sum);
            System.out.println(arrival+"\n"+burst+"\n"+prio);
            try
            {
                int leq2,leq3,leq4;
            for(int time=0;time<=sum;)
            {

                //Storing in Round Robin Queue
                for(int i=0;i<arrival.size();i++)
                {
                    if (arrival.get(i) <= time && arrival.get(i)>=0)
                    {
                        temp2.add(arrival.get(i));
                    }
                }
                int counter=temp2.size();
                for(int i=0;i<counter;i++)
                {
                    int min =Collections.min(temp2);
                    temp2.remove(temp2.indexOf(min));
                    rrqueue1.add(burst.get(arrival.indexOf(min)));
                    arrival.set(arrival.indexOf(min),-1);
                }

                if(rrqueue1.isEmpty()==false)
                {
                    int len=rrqueue1.size();
                    for(int i=0;i<len;i++)
                        ((LinkedList<Integer>) q1).add(rrqueue1.remove());
                }
                //For Queue 1
                //Following Round Robin
                if(q1.isEmpty()==false)
                 {
                    System.out.println("Processing In Queue 1");
                    System.out.println(q1);
                    int i = 1;
                    if(q1.peek()<qt1)
                        System.out.println("Wait for "+ q1.peek() + " Seconds...");
                    else
                        System.out.println("Wait for 2 Seconds...");
                    for (i = 1; i <= qt1; i++)
                    {
                       thread.sleep(1000);
                        time++;
                        //reducing the burst time by 1
                        int temp3;
                        temp3 = ((LinkedList<Integer>) q1).removeFirst() - 1;
                        ((LinkedList<Integer>) q1).addFirst(temp3);
                        //checking if the time becomes 0
                        if (temp3 == 0)
                        {
                            if(q1.isEmpty()==false)
                            q1.remove();
                            break;
                        }
                    }


                    if (i == qt1+1) {
                        int temp=q1.remove();
                        q2.add(temp);
                    }
                }

                //For Queue 2
                //Following Round Robin
                else if(q2.isEmpty()==false)
                {
                    System.out.println("Processing In Queue 2");
                    System.out.println(q2);
                    if(q2.peek()<qt2)
                        System.out.println("Wait for "+ q2.peek() + " Seconds...");
                    else
                        System.out.println("Wait for 4 Seconds...");
                    int i = 1;
                    for (i = 1; i <= qt2; i++) {
                        thread.sleep(1000);
                        time++;
                        //reducing the burst time by 1
                        int temp3;
                        temp3 = ((LinkedList<Integer>) q2).removeFirst() - 1;
                        ((LinkedList<Integer>) q2).addFirst(temp3);
                        //checking if the time becomes 0
                        if (temp3==0)
                        {
                            if(q2.isEmpty()==false)
                            q2.remove();
                            break;
                        }
                    }

                    if (i == qt2+1) {
                        int temp = q2.remove();
                        q3.add(temp);
                    }

                    leq2=time;
                }

                //For Queue 3
                //Following Round Robin
                else if(q3.isEmpty()==false)
                {
                    System.out.println("Processing In Queue 3");
                    System.out.println(q3);
                    if(q3.peek()<qt3)
                        System.out.println("Wait for "+ q3.peek() + " Seconds...");
                    else
                        System.out.println("Wait for 8 Seconds...");
                    int i = 1;
                    for (i = 1; i <= qt3; i++)
                    {
                       thread.sleep(1000);
                        time++;
                        //reducing the burst time by 1
                        int temp3;
                        temp3 = ((LinkedList<Integer>) q3).removeFirst() - 1;
                        ((LinkedList<Integer>) q3).addFirst(temp3);
                        //checking if the time becomes 0
                        if (temp3==0)
                        {
                            if(q3.isEmpty()==false)
                            q3.remove();
                            break;
                        }
                    }

                    if (i == qt3+1) {
                        int temp = q3.remove();
                        q4.add(temp);
                    }
                    leq3=time;
                }

                //For Queue 4
                //Following First Come First Serve
                else if(q4.isEmpty()==false)
                {
                    System.out.println("Processing In Queue 4");
                    System.out.println(q4);
                    int temp=q4.remove();
                    thread.sleep(temp*1000);

                    time+=temp;
                    leq4=time;
                }
                else
                {
                    time++;
                }
            }
        }
        catch (Exception e)
        {
            System.out.println("There was an Exception");
        }
    }
}
