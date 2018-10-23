#Class which represents a node of binary tree
class Node:
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 

#Function which add a key to binary tree
def insert(root,node): 
    if root is None: 
        root = node 
    else: 
        if root.val < node.val: 
            if root.right is None: 
                root.right = node 
            else: 
                insert(root.right, node) 
        else: 
            if root.left is None: 
                root.left = node 
            else: 
                insert(root.left, node) 
#Function to do inorder tree traversal
def inorder(root): 
    if root: 
        inorder(root.left) 
        print(root.val) 
        inorder(root.right) 

#Function for searching a key in the tree
def search(root,key): 
      
    # Base Cases: root is null or key is present at root 
    if root is None: 
        return False
    elif root.val == key:
        return True 
  
    # Key is greater than root's key 
    if root.val < key: 
        return search(root.right,key) 
    
    # Key is smaller than root's key 
    return search(root.left,key) 


#Test case

r = Node(50) 
insert(r,Node(30)) 
insert(r,Node(20)) 
insert(r,Node(40)) 
insert(r,Node(70)) 
insert(r,Node(60)) 
insert(r,Node(80)) 

print "Result of traversing"
inorder(r) 


print "Is 25 in the tree?", search(r,25)
print "Is 30 in the tree?", search(r,30)
print "Is 2 in the tree?", search(r,2)

