import java.util.*;

public class QueueArray {
	int arr[];
    int front;
    int rear;
    QueueArray (int size){
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    boolean isEmpty() {
        if((front == -1) && (rear == -1))
            return true;
        else
            return false;
    }
    public void enqueue(int element) {
    	if(rear == arr.length - 1)
            System.out.println("\nOverflow");
        else if (isEmpty()) {
            rear=0;front=0;
            arr[rear]=element;
        }
            else {
                rear= rear+1;
                arr[rear]=element;
            }
    }
    public int dequeue() {
    	 if(isEmpty()) 
             {System.out.println("\nEMPTY");
             return 0;
             }
             
         else if(front == rear) {
        	 int pop= arr[front];
             System.out.println(pop);
             front = -1;
             rear= -1;
             return pop;
             }
    	 else {
    		 int pop= arr[front];
             System.out.println(arr[front]);
             front= front+1;
             return pop;
         }
    }
    public void show() {
    	if(isEmpty()) {
    		System.out.println("\nEMPTY");
    	}
    	else {
		for(int i=front;i<=rear;i++) {
			System.out.println(arr[i]+"");
		}
    	}
	}
    public int peek() {
    	if(isEmpty()) 
        {System.out.println("\nEMPTY");
        return 0;
        }
        
        else {
        int pop= arr[front];
        System.out.println(pop);
        return pop;
    }
    	
    }
    
    public static void main(String[] args) {
		Scanner in =new Scanner(System.in);
		int ex=0;
		QueueArray q;
		System.out.println("Enter length: ");
		ex =-1;
		int n= in.nextInt();
		if (n>0 && n<10000) {
			q= new QueueArray(n);
		}
		else {
			System.out.println("Wrong! Better luck next time");
			ex =-1;
			in.close();
			return;
		}
		do {
		System.out.println("Enter\n 1 - enQueue\n 2 - deQueue \n 3 - Peek \n 4 - Show");
		int str= in.nextInt();
		switch(str) {
		case 0: {
					ex=-1;
					break;
				}
		case 1:	{
					int ele=in.nextInt();
					q.enqueue(ele); 
					break;
				}
		case 2: {
					q.dequeue(); 
					break;
				}
		case 3:	{
					q.peek(); 
					break;
				}
		case 4:	{
					q.show();
					break;
				}
		default:{	System.out.println("Wrong Option");
					break;
				}
		}
		System.out.println("Continue? (1/0)");
		ex= in.nextInt();
		} while(ex==1);
		
		in.close();
	}
}
