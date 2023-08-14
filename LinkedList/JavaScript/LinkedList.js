const Node = require("./Node");

module.exports = class LinkedList{
  constructor(){
    this.first=null;
		this.last=null;
		this.size=0;
	}

	addLast(data){
		let node = new Node(data);
		this.size+=1;

		if(this.first==null)
			this.first = this.last = node;
		else{
			this.last.next = node;
			this.last = node;
		}
	}
	
	addFirst(data){
		let node = new Node(data);
		
		if(this.first==null)
		this.first = this.last = node;
		else{
			node.next = this.first;
			this.first = node;
		}
		this.size+=1;
	}

	print(){
		console.log("--------------");
		let node = this.first;

		while(node!=null){
			console.log(node.data);
			node = node.next;
		}
		console.log("--------------");
	}

	indexOf(item){
		let node = this.first;
		let counter=-1;
		let found = false;
		while(node!=null){
			counter++;

			if(node.data === item){
				found=true;
				break;
			}
			
			node = node.next;
		}

		if(found) return counter;
		else return -1;
	}

	contains(item){
		let node = this.first;
		
		while(node!=null){
			if(node.data === item){
				return true;
			}

			node = node.next;
		}
		return false;
	}

	removeFirst(){
		if(this.first!=null){
			let temp = this.first;
	
			this.first = this.first.next;
			temp.next = null;
	
			this.size-=1;
			return temp.data;
		}
	}

	removeLast(){
		if(this.last!=null){
			this.size-=1;
			let one = this.first;
			let two = this.first;
			if(one==null) return -1;
	
			while(one.next != null){
				two = one;
				one = one.next;
			}
	
			let temp = one.data;
			two.next = null;
			this.last = two;
			return temp;
		}
	}

	remove(index){
		let one = this.first;
		let two = this.first;
		let counter=-1;

		if(one==null) return -1;
		while(one.next!=null){
			counter++;

			if(counter == index){
				break;
			}
			
			two = one;
			one = one.next;
		}

		two.next = one.next;
		one.next = null;
		this.size-=1;
		return one.data;
	}

	toArray(){
		let arr = new Array(this.size);
		let index=0;
		let node = this.first;

		while(index<this.size){//for loop can also be used here
			arr[index++] = node.data;
			node=node.next;
		}

		return arr;
	}

	isEmpty(){
		if(this.first == null) return true;
		else return false;
	}

	reverse(){
		if(this.isEmpty()) return;

		let p = this.first, c = this.first.next;
		let n = null;
		while(c!=null){
			n=c.next;
			c.next = p;
			p = c;
			c = n;
		}

		this.last = this.first;
		this.last.next = null;
		this.first = p;
	}

	kthNodeFromEnd(n){
		if(n<0){
			console.log("invalid agr");
			return;
		}
		if(this.isEmpty()) {
			console.log("Empty");
			return;
		}
		let one = this.first;
		let two = one;
		for(let i=1; i<n; i++){
			two = two.next;
			if(two == null) {
				console.log("doesn't exist");
				return;
			}
		}

		while(two!=this.last){
			two = two.next;
			one = one.next;
		}
		return one.data;
	}

	middleNode(){
		if(this.isEmpty()) {
			console.log("Empty");
			return;
		}
		let a = this.first;
		let b = a;

		while(b!=this.last && b.next!=this.last){
			b=b.next.next;
			a=a.next;
		}
	
		console.log(a.data);
		if(b.next==this.last){
			console.log(a.next.data);
		}
	}

	hasLoop(){
		let slow=this.first;
		let fast=this.first;

		while(fast!=null && fast.next!=null){
			fast=fast.next.next;
			slow=slow.next;
			if(fast==slow){
				console.log("Loop found!");
				return;
			}
		}
		console.log("NO LOOP");
		return;
	}
}