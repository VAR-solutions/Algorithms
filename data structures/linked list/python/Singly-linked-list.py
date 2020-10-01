class Node:
    def __init__(self,data,next_node=None):
        self.data = data
        self.next_node = next_node
    
    def get_data(self):
        return self.data
    
    def get_next(self):
        return self.next_node
    
    def set_next(self,new_node):
        self.next_node = new_node
        

class Linked_list:
    def __init__(self,head=None):
        self.head = head
        
    def insert_head(self,data):
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node
    
    def insert_tail(self,data):
        new_node = Node(data)
        current = self.head
        if current is None:
            self.head = new_node
        else:
            while current.get_next():
                current = current.get_next()
            current.set_next(new_node)
    
    def delete(self,data):
        current = self.head
        prev = None
        while current:
            if current.get_data() == data:
                if prev:
                    prev.set_next(current.get_next())
                else:
                    self.head = current.get_next()
                break
            else:
                prev = current
                current = current.get_next()
    
    def search(self,data):
        current = self.head
        while current:
            if current.get_data() == data:
                return True
            else:
                current = current.get_next()
        return False
    
    def print_list(self):
        current = self.head
        self.temp = []
        while current:
            self.temp.append(current.get_data())
            current = current.get_next()
        print(self.temp) 

    def __len__(self):
        return len(self.temp)
