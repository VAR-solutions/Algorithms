class Node:
    """Class to create nodes for a linked list"""
    
    def __init__(self,data = None,next = None):
        self.data = data
        self.next = next

class LinkedList:
    """Class to create the actual linked list with several nodes"""
    
    def __init__(self):
        # initializes the head of the linked list
        self.head = None

    def addNodeAtEnd(self,value):
        """Adds a node containing given value to the end of the list"""
        if self.head is None:
            self.head = Node(value)
        else:
            # iterate to the end of the list and add the node
            CurrentNode = self.head
            
            while CurrentNode.next is not None:
                CurrentNode = CurrentNode.next

            CurrentNode.next = Node(value)

        return True

    def addNodeAtBeginning(self,value):
        """Adds a node containing given value to the beginning of the list"""
        if self.head is None:
            self.head = Node(value)
        else:
            # rearranging the references to the nodes
            temp = Node(value)
            temp.next = self.head
            self.head = temp

    def searchValue(self,value):
        """searches for the given value and returns a boolean"""
        flag = 0
        
        if self.head is None:
            return False
        else:
            CurrentNode = self.head

            while CurrentNode is not None:
                if CurrentNode.data == value:
                    return True

                CurrentNode = CurrentNode.next

            return False

    def printList(self,seperator = ' '):
        """simply prints all the elements currently present in the list"""
        if self.head is None:
            return False
        else:
            CurrentNode = self.head

            while CurrentNode is not None:
                print(CurrentNode.data,end = seperator)
                CurrentNode = CurrentNode.next

            print()

            return True

    def deleteNodeByValue(self,value):
        """searches for the node containing the value and deletes that node"""
        if self.head is None:
            return False
        elif self.head.data == value:
            self.head = self.head.next
            return True
        else:
            CurrentNode = self.head

            while CurrentNode is not None:
                if CurrentNode.next.data == value:
                    CurrentNode.next = CurrentNode.next.next
                    return True

                CurrentNode = CurrentNode.next

    def deleteNodeByPosition(self,pos):
        """deletes a node at the given position"""
        if self.head is None:
            return False
        elif pos == 0:
            self.head = self.head.next
            return True
        else:
            CurrentNode = self.head

            while pos > 1:
                CurrentNode = CurrentNode.next
                pos -= 1

            CurrentNode.next = CurrentNode.next.next

            return True

    def getLength(self):
        """returns the length of the current list"""
        if self.head is None:
            return 0
        else:
            NodeCount = 0
            CurrentNode = self.head

            while CurrentNode is not None:
                NodeCount += 1
                CurrentNode = CurrentNode.next

            return NodeCount

    def getMaxElement(self):
        """returns the maximum element in the list"""
        MaxElement = self.head.data
        CurrentNode = self.head

        while CurrentNode is not None:
            if MaxElement < CurrentNode.data:
                MaxElement = CurrentNode.data

            CurrentNode = CurrentNode.next

        return MaxElement

    def getMinElement(self):
        """returns the minimum element in the list"""
        MinElement = self.head.data
        CurrentNode = self.head

        while CurrentNode is not None:
            if MinElement > CurrentNode.data:
                MinElement = CurrentNode.data

            CurrentNode = CurrentNode.next

        return MinElement

    def getNodeCount(self,value):
        """returns the number of nodes containing a particular value"""
        CurrentNode = self.head
        NodeCount = 0

        while CurrentNode is not None:
            if CurrentNode.data == value:
                NodeCount += 1

            CurrentNode = CurrentNode.next

        return NodeCount
