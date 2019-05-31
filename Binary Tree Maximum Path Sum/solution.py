def maxPathSum(self, root: TreeNode) -> int:
    self.maxSum = float('-inf')
    def postSum(node):
        if not node: return 0
        
        left = max(postSum(node.left), 0)
        right = max(postSum(node.right), 0)
        
        self.maxSum = max(self.maxSum, node.val + left + right)
        return node.val + max(left, right)
    postSum(root)
    return self.maxSum
