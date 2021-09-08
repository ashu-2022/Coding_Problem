"""
Postorder Traversal of BT
[https://leetcode.com/problems/binary-tree-postorder-traversal/]
Approach:
    1. Using Recursion
        T(n) = O(N) and S(n) = O(N)
    
    2. Iterative using 2 Stack
        T(n) = O(N) and S(n) = O(2N)

    3. Iterative using 1 Stack
        T(n) = O(N) and S(n) = O(N)
        
"""

# Postorder Traversal using recursion approach
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def postorderTraversal(self, root: [TreeNode]) -> List[int]:
        ans = []
        def postorder(root):
            if root is None:
                return 
            postorder(root.left)
            postorder(root.right)
            ans.append(root.val)
        postorder(root)
        return ans 

    

# Postorder Traversal using Iterative method using 2 Stack
# T(n) = O(N) and S(n) = O(N)

# steps: --
# 1. Push root to 1st Stack
# 2. while Loop run until S1 is not empty
#       1.) Pop top node of S1 & push to S2
#       2.) Push (node->left , node->right) to S1 
#            by checking  if node exist
# 3. Print contents of stack S2 (Postorder)


# Postorder Traversal using Iteration approach using 2 Stack
# T(n) = O(N) and S(n) = O(2N)
class Solution:
    def postorderTraversal(self, root:[TreeNode]) -> List[int]:
        if root is None : return []
        output, stack1, stack2 = [], [root], []
        while(stack1):
            node = stack1.pop()
            stack2.append(node)
            if node.left: stack1.append(node.left)
            if node.right: stack1.append(node.right)

        while(stack2):
            output.append(stack2.pop().val)

        return output


# Postorder Traversal using Iteration approach using 1 Stack
# T(n) = O(2N) and S(n) = O(N)
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if (not root): return []
        output, stack = [], []
        while(root or stack):
            # Go as left as possible
            while root:
                stack.append(root)
                root = root.left
                
            node = stack[-1].right
            if node is None:
                node = stack.pop()
                output.append(node.val)
                while(stack and stack[-1].right == node):
                    node = stack.pop()
                    output.append(node.val)
            else: 
                root = node
        return output


# Postorder Traversal using Iteration approach using 1 Stack
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if (not root): return []
        output, deque = [], [root]
        while(deque):
            root = deque.pop()
            output.insert(0,root.val)
            if root.left: deque.append(root.left)
            if root.right: deque.append(root.right)
          
        return output
