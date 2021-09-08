/*
Inorder Traversal of Binary Tree
[https://leetcode.com/problems/binary-tree-inorder-traversal/]
Approach:
    1. with Recursion
        T(n) = O(N) and S(n) = O(N)

    2. Without Recursion(or Iterative using Stack)
        T(n) = O(N) and S(n) = O(N)

*/


// Recursive Approach
// T(n) = O(N) and S(n) = O(N)
class Solution {
private:
    void inorder(TreeNode* root, vector<int>&v){
        if(root == NULL){
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }
};



// Iterating method using Stack
// T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        stack <TreeNode *> st;
        while (root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            output.push_back(root->val);
            root = root->right;
        }
        return output;
    }
};
