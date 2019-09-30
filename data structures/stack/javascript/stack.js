// Stack structure

class Stack {
    constructor() {
        this.data = [];
    }
    
    push(item) {
        this.data.push(item);
    }

    pop() {
        return this.data.pop();
    }

    isEmpty() {
        return this.data.length == 0;
    }
}

// Tests

let stack = new Stack();
console.assert(stack.isEmpty(), "Stack is empty");
stack.push("First");
stack.push("Second");
stack.push("Third");
console.assert(stack.pop(), "Popped element Third");
stack.pop();
console.assert(stack.isEmpty() == false, "Stack isn't empty");
