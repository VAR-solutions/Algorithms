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


class Queue:
    def __init__(self,head=None):
        self.head = head
    
    def enqueue(self,data):
        new_item = Node(data)
        current = self.head
        if current is None:
            self.head = new_item
        else:
            while current.get_next():
                current = current.get_next()
            current.set_next(new_item)
   
    def dequeue(self):
        current = self.head
        if current != None:
            self.head = current.get_next()
        else:
            print("Queue is empty")
            
    def size(self):
        current = self.head
        count = 0
        while current:
            count +=1
            current = current.get_next()
        return count

    def print_queue(self):
        current = self.head
        temp = []
        while current:
            temp.append(current.get_data())
            current = current.get_next()
        return temp
    
    def is_empty(self):
        if self.head == None:
            print("Queue is empty!")
        else:
            print("Queue isn't empty!")
