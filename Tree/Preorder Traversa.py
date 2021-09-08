"""
Preorder Traversal Of BT 
[https://leetcode.com/problems/binary-tree-preorder-traversal/]
Approach:
    1. Using Recursion
        T(n) = O(N) and S(n) = O(N)
    
    2. By Iterative using Stack (or without Recursion)
        T(n) = O(N) and S(n) = O(N)

"""
 
# Preorder Traversal using Recursive Approach
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        def preorder(root):
            if root is None:
                return 
            ans.append(root.val)
            preorder(root.left)
            preorder(root.right)
        preorder(root)
        return ans 


"""    
Preorder Traversal using Iterative Approach
T(n) = O(N) and S(n) = O(N)

steps:---
1. Push the root in STACK
2. while(stack is not empty)
      1.)Pop & Store top node from Stack
      2.)Print it
      3.)Push right (if curr->right exist)
      4.)Push left (if curr->left exist)

"""


# Preorder Traversal using Iterative Approach
# T(n) = O(N) and S(n) = O(N)
# Classical usage of stack's LIFO feature
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if (not root): return []
        stack, output = [root], []

        while stack:
            node = stack.pop()
            output.append(node.val)
            if node.right: 
                stack.append(node.right)
            if node.left: 
                stack.append(node.left)
        return output

