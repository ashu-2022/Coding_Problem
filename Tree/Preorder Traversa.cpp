/*
Preorder Traversal Of BT 
[https://leetcode.com/problems/binary-tree-preorder-traversal/]
Approach:
    1. Using Recursion
        T(n) = O(N) and S(n) = O(N)
    
    2. By Iterative using Stack (or without Recursion)
        T(n) = O(N) and S(n) = O(N)

*/
 

// Preorder Traversal using Recursive Approach
// T(n) = O(N) and S(n) = O(N)
class Solution {
private:
    void preorder(TreeNode* root, vector<int> &ans){
        if (root==NULL){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);   
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};


/*
Preorder Traversal using Iterative Approach
T(n) = O(N) and S(n) = O(N)

steps:---
1. Push the root in STACK
2. while(stack is not empty)
      1.)Pop & Store top node from Stack
      2.)Print it
      3.)Push right (if curr->right exist)
      4.)Push left (if curr->left exist)

*/


// Preorder Traversal using Iterative Approach
// T(n) = O(N) and S(n) = O(N)
// Classical usage of stack's LIFO feature
class Solution {    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        if (!root) return output;
        stack<TreeNode *> st;
        st.push(root);
        
        while(!st.empty()){
            root = st.top();
            st.pop();
            output.push_back(root->val);
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        return output;
    }
};

