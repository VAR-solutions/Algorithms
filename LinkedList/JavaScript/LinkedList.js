class ListNode {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor(head = null) {
        this.head = head;
    }

    // Returns whether the list is empty 
    isEmpty() {
        return this.head === null;
    }

    // Returns the head (first element) of the list
    head() {
        return this.head;
    }

    // Returns the tail (last element) of the list
    tail() {
        let current = this.head;
        while (current.next !== null) {
            current = current.next;
        }
        return current;
    }

    // Empties the list
    clear() {
        this.head = null;
    }

    // Reverses the list
    reverse() {
        if (this.head === null) {
            return;
        }

        let previous = null;
        let current = this.head;
        let next = null;

        while (current !== null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }

        this.head = previous;
    }

    // Returns the size of the list
    size() {
        let size = 0;
        let current = this.head;
        while (current !== null) {
            size++;
            current = current.next;
        }
        return size;
    }

    // Inserts a new node at the end of the list
    insert(data) {
        if (this.head === null) {
            this.head = new ListNode(data);
        } else {
            let current = this.head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new ListNode(data);
        }
    }

    // Returns whether the list contains a node with the given data
    contains(data) {
        let current = this.head;

        while (current !== null) {
            if(current.data === data){
                return true;
            }
            current = current.next;
        }

        return false;
    }

    // Returns the index of the node with the given data, or -1 if it does not exist
    indexOf(data) {
        let current = this.head;
        let i = 0;

        while (current !== null){
            if(current.data === data){
                return i;
            }
            i++;
            current = current.next;
        }

        return -1;
    }

    // Inserts a new node at the given position
    insertAt(position, data) {
        if (position < 0) {
            return;
        }

        if (position === 0 || this.head === null) {
            this.insert(data);
        } else {
            let newNode = new ListNode(data);
            let current = this.head;
            for (let i = 0; i < this.size(); i++) {
                if (i === position - 1) {
                    newNode.next = current.next;
                    current.next = newNode;
                }
                current = current.next;
            }
        }
    }

    // Removes the node from the front of the list
    removeFront() {
        if (this.head !== null) {
            this.head = this.head.next;
        }
    }

    // Removes the node from the end of the list
    removeEnd() {
        let current = this.head;
        if (current !== null) {
            if (current.next === null) {
                this.head = null;
            } else {
                while (current.next.next !== null) {
                    current = current.next;
                }
                current.next = null;
            }
        }
    }

    // Removes the node at the given position
    removeAt(position) {
        if(position >= this.size()){
            return;
        }

        if(position === 0){
            this.removeFront();
        } else {
            let current = this.head;
            let i = 0;
    
            while(current !== null) {
                
                if(i === position - 1){
                    current.next = current.next.next;
                }
    
                i++;
                current = current.next;
            }
        }
    
        
    }

    // Prints out the list on the standard output
    print() {
        if (this.head === null) {
            process.stdout.write("The list is empty.\n");
        } else {
            let current = this.head;
            while (current !== null) {
                process.stdout.write(`${current.data} -> `);
                current = current.next;
            }
            process.stdout.write("null\n");
        }
    }
}

let list = new LinkedList();

list.print();

list.insert(5);
list.insert(7);
list.insert(8);
list.insertAt(1, 6);
list.print();

list.reverse();
list.print();

list.removeAt(3);
list.print();

process.stdout.write(`${list.size()}\n`);
process.stdout.write(`${list.contains(8)}\n`);
process.stdout.write(`${list.indexOf(8)}\n`);

module.exports = { ListNode, LinkedList };