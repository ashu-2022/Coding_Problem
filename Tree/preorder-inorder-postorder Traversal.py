

# Preorder-Inorder-Postorder in one code
# T(n) = O(3N) and S(n) = O(3N)
class Solution:
    def PreorderInorderPostorder(self, root:[TreeNode]) -> List[int]:
        if root is None:
            return []
        preorder, inorder, postorder = [], [], []
        stack =[[root,1]]
        while stack:
            root = stack.pop()
            # for preorder traversal
            if root[-1] == 1:
                root[-1]+=1
                preorder.append(root[0].val)
                stack.append(root)
                if root[0].left:
                    stack.append([root[0].left,1])

            # for inorder traversal
            elif root[-1] == 2:
                root[-1]+=1
                inorder.append(root[0].val)
                stack.append(root)
                if root[0].right:
                    stack.append([root[0].right,1])

            # for postorder traversal
            elif root[-1] ==3:
                postorder.append(root[0].val)

        return(preorder,inorder,postorder)


# All DFS traversals (preorder, inorder, postorder) in 1 line
# T(n) = O(N) and S(n) = O(N)

def preorder(root):
  return [root.val] + preorder(root.left) + preorder(root.right) if root else []

def inorder(root):
  return  inorder(root.left) + [root.val] + inorder(root.right) if root else []

def postorder(root):
  return  postorder(root.left) + postorder(root.right) + [root.val] if root else []
    
      
        
