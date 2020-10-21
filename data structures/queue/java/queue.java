class Queue
{
	int arr[];
	int front, rear;

	Queue(int size)
	{
	arr=new int[size];  front = -1;  rear = -1;
	}

	void insert(int n)
	{
	if (rear==arr.length-1)
	  System.out.println("Overflow!");

	else if(front == -1 && rear == -1)
	{
	arr[++rear] = n;
	front++;
	}

	else
	{
	arr[++rear] = n;
	}
	}

	int delete()
	{
	if(front<0 || front>rear)
	  {System.out.println("Underflow!");  return -1;}
	else
	{
	int temp=arr[front];
	front++;
	return temp;
	}
	}

	void display()
	{
	int i=front;
	System.out.println("\nQueue:\n");
	while(i<=rear)
	{
	System.out.println(arr[i]);
	i++;
	}
	}
}

class MyClass{
	public static void main(String args[]){
		Queue q=new Queue(10);
		for(int i=0; i<5; i++)
		{
			q.insert(i);
		}
		
		q.display();
		System.out.println("\nDeleted Element: "+q.delete());
		q.display();
	}
}