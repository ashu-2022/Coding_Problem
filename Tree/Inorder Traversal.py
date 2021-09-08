"""
Inorder Traversal of Binary Tree
[https://leetcode.com/problems/binary-tree-inorder-traversal/]
Approach:
    1. with Recursion
        T(n) = O(N) and S(n) = O(N)

    2. Without Recursion(or Iterative using Stack)
        T(n) = O(N) and S(n) = O(N)

"""


# Recursive Approach
# T(n) = O(N) and S(n) = O(N) 
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        def inorder(root):
            if root is None:
                return 
            inorder(root.left)
            ans.append(root.val)
            inorder(root.right)
        inorder(root)
        return ans
    
"""
Iterating method using Stack
T(n) = O(N) and S(n) = O(N)

Steps:---
1. Create an empty STACK
2. Initialize current node to root
3. Push current node to Stack & Set (curr = curr->left) until curr is NULL
4. If curr is NULL & Stack is not empty (loop stoping condition)
      1.)Pop top of Stack & print it
      2.)Set curr = Popped_node ->right
      3.)Goto step 3
5. If (curr == NULL and Stack is Empty) then we get answer

"""

# Iterating method using Stack
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans, stack = [], []
        while(root or len(stack) !=0):
            # Reach leftmost Node
            while(root):
                stack.append(root)
                root = root.left
            # Current root must be Null
            root = stack.pop()
            ans.append(root.val)
            root = root.right

        return ans
    


# Iterating method using Stack
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        output, stack = [], []
        while True:
            # Reach leftmost Node
            while root:
                stack.append(root)
                root = root.left
            if(len(stack)<=0): break
            # Current root must be Null
            root = stack.pop()
            output.append(root.val)
            root = root.right

        return output


