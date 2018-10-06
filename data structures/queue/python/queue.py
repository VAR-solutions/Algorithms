class Queue:
    
    def __init__(self):
        self.list = []

    def enqueue(self, element):
        self.list.append(element)

    def dequeue(self):
        assert len(self.list) > 0; "Queue is empty"
        return self.list.pop(0)

    def isEmpty(self):
        return len(self.list) == 0
    