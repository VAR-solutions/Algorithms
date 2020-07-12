class Node:
    def __init__(self,data=None,next_node=None):
        self.data = data
        self.next_node = next_node
    
    def get_data(self):
        return self.data
    
    def get_next(self):
        return self.next_node
    
    def set_next(self,new_node):
        self.next_node = new_node


class Stack:
    def __init__(self,head=None):
        self.head = head
    
    def push(self,data):
        new_item  = Node(data)
        current = self.head 
        if current is None:
            self.head = new_item
        else:
            while current.get_next():
                current = current.get_next()
            current.set_next(new_item)
    
    def pop(self):
        current = self.head 
        prev = None
        if current is not None:
            while current.get_next():
                prev = current
                current = current.get_next()
            if prev:
                prev.set_next(current.get_next())
            else:
                self.head = current.get_next()
        else:
            print("Empty stack!")

    def print_stack(self):
        current = self.head
        temp = []
        while current:
            temp.append(current.get_data())
            current = current.get_next()
        return temp
