/*
Postorder Traversal of BT
[https://leetcode.com/problems/binary-tree-postorder-traversal/]
Approach:
    1. Using Recursion
        T(n) = O(N) and S(n) = O(N)
    
    2. Iterative using 2 Stack
        T(n) = O(N) and S(n) = O(2N)

    3. Iterative using 1 Stack
        T(n) = O(N) and S(n) = O(N)
        
*/

// Postorder Traversal using recursion approach
// T(n) = O(N) and S(n) = O(N)
class Solution {
private:
    void postorder(TreeNode* root,vector<int>& ans){
        if(root == NULL){
            return ;
        }
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val); 
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};


// Postorder Traversal using Iteration approach using 2 Stack
// T(n) = O(N) and S(n) = O(2N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        if (!root) return output;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left) st1.push(root->left);
            if (root->right) st1.push(root->right);
        }
        
        while(!st2.empty()){
            root = st2.top();
            st2.pop();
            output.push_back(root->val);
        }
        return output;

    }
};


// Postorder Traversal using Iteration approach using 1 Stack
// T(n) = O(2N) and S(n) = O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        if (!root) return output;
        stack<TreeNode *> st;
        TreeNode *temp;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            
            temp = st.top()->right;
            if (temp == NULL){
                temp = st.top();
                st.pop();
                output.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    output.push_back(temp->val);
                }
            }
            else{
                root = temp;
            }
        }
        return output;
    }
};



// Postorder Traversal using Iteration approach using 1 Stack
// T(n) = O(2N) and S(n) = O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        if (!root) return output;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            output.insert(output.begin(), root->val);
            if (root->left) st.push(root->left);
            if (root->right) st.push(root->right);
        }
        return output;
    }
};
