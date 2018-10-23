// Stack structure

class Stack<T> {
    private var data = [T]()
    
    func push(element: T) {
        data.append(element)
    }
    
    func pop() -> T? {
        return data.popLast()
    }
    
    var isEmpty: Bool {
        return data.isEmpty
    }
    
}

// Tests

let stack = Stack<String>()
assert(stack.isEmpty, "Stack is empty")
stack.push(element: "First")
stack.push(element: "Second")
stack.push(element: "Third")
assert(stack.pop() == "Third", "Popped element Third")
_ = stack.pop()
assert(stack.isEmpty == false, "Stack isn't empty")
