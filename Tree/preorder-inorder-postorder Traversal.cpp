
// Preorder-Inorder-Postorder in one code
// T(n) = O(3N) and S(n) = O(3N)
class Solution{
public:
    vector<vector<int>>PreorderInorderPostorder(TreeNode *root){
        vector<vector<int>> output;
        if (!root) return output;
        stack<pair<TreeNode *, int>> st;
        vector<int> pre, in, post;
        st.push({root,1});
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            
            // preorder Traversal
            if (it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left){
                    st.push({it.first->left, 1});
                }
            }
            // Inorder Traversal
            if (it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->right){
                    st.push({it.first->right, 1});
                }
            }

            // Postorder Traversal
            if (it.second == 3){
                post.push_back(it.first->val);
            }
        }
        output.push_back(pre);
        output.push_back(in);
        output.push_back(post);
        return output;
    }
};



