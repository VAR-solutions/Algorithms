# Leetcode 112

class Solution(object):

    def __init__(self):
        self.result = False

    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False
        if(not root.left and not root.right and root.val == sum):
            return True

        sum -= root.val

        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)


