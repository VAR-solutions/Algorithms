
class Node:
    def __init__(self, item):
        self.data = item
        self.left = None
        self.right = None
     
def rightViewUtil(root, level, max_level):
     
    if root is None:
        return
    if (max_level[0] < level):
        print "%d   " %(root.data),
        max_level[0] = level
    rightViewUtil(root.right, level+1, max_level)
    rightViewUtil(root.left, level+1, max_level)
 
def rightView(root):
    max_level = [0]
    rightViewUtil(root, 1, max_level)
 
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
root.right.left.right = Node(8)
 
rightView(root)

