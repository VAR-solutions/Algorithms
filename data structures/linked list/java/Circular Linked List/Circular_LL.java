
public class Circular_LL {
	Node head = new Node();
	
	public void print(){
		Node n=head;
		while(n.next!=head){
			System .out.print(n.next.data+ " ");
			n=n.next;
		}
		System.out.println("");

	}
	
	public void insert(int x){
		Node n= head;
		while(n.next!=null){
			n=n.next;
		}
		Node newNode = new Node(x);
		newNode.next=head;
		n.next=newNode;
		
	}
	public void insertm(int x){
		Node n= head;
		while(n.next!=head){
			n=n.next;
		}
		Node newNode = new Node(x);
		newNode.next=head;
		n.next=newNode;
		
	}
	
	public int count(){
		Node n=head;
		int cnt=0;
		while(n.next!=null){
			n=n.next;
			cnt=cnt+1;
		}
		return cnt;
	}
	public void nodeAtPosition(int p){
		if(p>=0){
			System.out.print("Node at a position " +p+": ");
			int cnt=0;
			Node n= head;
			Node temp=head;
			while(n.next!=head){
				n=n.next;
				cnt++;
			}
			Node nnode = head;
			if(n.next==null){
				System.out.println("Empty list");
			}
			else{
				int c;
				c=0;
				while(c<p){
					nnode=nnode.next;
					c=c+1;
				}
				if(c<=cnt){
					System.out.println(nnode.data);
					int sum=0;
					while(c<cnt){
						sum=nnode.next.data+sum;
						nnode=nnode.next;
						c++;
					}
					System.out.println("The sum after node "+p+" is: "+sum);
				}
				else{
					System.out.println("Invalid position");
				}
			}
			
		}
		
	}

}
