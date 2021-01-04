# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        def findBottomLeftValueR(root: TreeNode, level: int) -> (int, int):
            if root.left == None and root.right == None:
                return root.val, level

            leftLevel = 0
            rightLevel = 0
            if root.left != None:
                leftValue, leftLevel = findBottomLeftValueR(root.left, level+1)
            if root.right != None:
                rightValue, rightLevel = findBottomLeftValueR(root.right, level+1)

            if leftLevel >= rightLevel:
                return leftValue, leftLevel
            else:
                return rightValue, rightLevel

        return findBottomLeftValueR(root, 0)[0]
