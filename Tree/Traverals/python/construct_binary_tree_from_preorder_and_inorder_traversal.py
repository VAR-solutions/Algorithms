# Leetcode 105
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if(preorder == None or len(preorder) == 0):
            return None
        root = TreeNode(preorder[0])
        root_index = inorder.index(preorder[0])
        left_preorder = preorder[1:root_index + 1 ]
        left_inorder = inorder[0:root_index]
        root.left = self.dfs(root, left_preorder, left_inorder)
        element_num_in_left_inorder = len(left_inorder)
        right_preorder = preorder[element_num_in_left_inorder + 1:len(preorder)]
        right_inorder = inorder[root_index+1:len(inorder)]
        root.right = self.dfs(root, right_preorder, right_inorder)

        return root

    def dfs(self, root, preorder, inorder):
        if (len(preorder) == 0):
            return
        root = TreeNode(preorder[0])
        if (len(preorder) == 1):
            return root

        root_index = inorder.index(preorder[0])
        left_preorder = preorder[1:root_index + 1]
        left_inorder = inorder[0:root_index]
        root.left = self.dfs(root, left_preorder, left_inorder)
        element_num_in_left_inorder = len(left_inorder)
        right_preorder = preorder[element_num_in_left_inorder + 1:len(preorder)]
        right_inorder = inorder[root_index + 1:len(inorder)]
        root.right = self.dfs(root, right_preorder, right_inorder)
        return root

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

tree = Solution().buildTree(preorder, inorder)

# Return the following binary tree:
#     3
#    / \
#   9  20
#     /  \
#    15   7


