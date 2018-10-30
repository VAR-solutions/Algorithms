# 307. Range Sum Query - Mutable
# https://leetcode.com/problems/range-sum-query-mutable/description/

class SegmentTree:
    def __init__(self, start, end):
        self.val = 0
        self.start = start
        self.end = end
        self.left = None
        self.right = None

class NumArray(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.root = self.build_tree(nums, 0, len(nums)-1)

    def build_tree(self, nums, l, r):
        if l > r:
            return None

        # leaf
        if l == r:
            node = SegmentTree(l, r)
            node.val = nums[l]
            return node

        mid = (l + r) / 2
        node = SegmentTree(l, r)
        node.left = self.build_tree(nums, l, mid)
        node.right = self.build_tree(nums, mid + 1, r)
        node.val = node.left.val + node.right.val

        return node

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        def change_v(node, i, val):
            #leaf
            if(i == node.start and i == node.end):
                node.val = val
                return
            mid = (node.start + node.end) / 2
            if (i >= mid + 1):
                change_v(node.right, i, val)
            else:
                change_v(node.left, i, val)

            node.val = node.left.val + node.right.val
        change_v(self.root, i, val)


    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        def get_val(node, i, j):
            if node.start == i and node.end == j:
                return node.val

            mid = (node.start + node.end) / 2

            if j <= mid:
                return get_val(node.left, i, j)

            elif i >= mid + 1:
                return get_val(node.right, i, j)
            else:
                return get_val(node.left, i, mid) + get_val(node.right, mid + 1, j)

        return get_val(self.root, i, j)


nums = [1,3,5]
obj = NumArray(nums)
print obj.sumRange(0,2)
obj.update(1,2)
print obj.sumRange(0,2)
