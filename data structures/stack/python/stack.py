class Stack:
    def __init__(self):
        self.list = []

    def push(self, element):
        self.list.append(element)
        
    def pop(self):
        assert len(self.list) > 0, "Stack is empty"
        return self.list.pop() 

    def isEmpty(self):
        return len(self.list) == 0
            
