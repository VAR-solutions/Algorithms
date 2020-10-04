class Node:

    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

class Tree:
    
    def insert(self, node, data):
        for i in range(31, -1, -1):
            val = (data >> i) & 1

            if val:
                if node.right is None:
                    node.right = Node(val)
                
                node = node.right
            else:
                if node.left is None:
                    node.left = Node(val)
                
                node = node.left

    def maxXORpair(self, node, arr, n):
        max_xor = 0
        for i in range(n):
            curr_xor = 0
            M = 2 ** 31
            curr = node

            for j in range(31, -1, -1):
                val = (arr[i] >> j) & 1

                if val:
                    if curr.left:
                        curr_xor += M
                        curr = curr.left
                    else:
                        curr = curr.right
                else:
                    if curr.right:
                        curr_xor += M
                        curr = curr.right
                    else:
                        curr = curr.left
                
                M //= 2
            
            max_xor = max(max_xor, curr_xor)
        
        return max_xor
 
    def traversalPreorder(self, root):
        if root is not None:
            print(root.data)
            self.traversalPreorder(root.left)
            self.traversalPreorder(root.right)


n = int(input())

arr = list(map(int, input().split()))

tree = Tree()
root = Node('*')

for i in range(n):
    tree.insert(root, arr[i])

#tree.traversalPreorder(root)

m = tree.maxXORpair(root, arr, n)

print(m)