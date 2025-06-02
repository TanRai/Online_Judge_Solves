/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //TreeNode* cur;
        stack<pair<TreeNode*,bool>> st;
        st.push(make_pair(root,false));
        vector<int> res;
        while(!st.empty())
        {
            pair<TreeNode*,bool> cur = st.top();
            st.pop();
            if(cur.first)
            {
                if(cur.second)
                    res.push_back(cur.first->val);
                else
                {
                    st.push(make_pair(cur.first,true));
                    st.push(make_pair(cur.first->right,false));
                    st.push(make_pair(cur.first->left,false));
                }
            }
        }
        return res;
    }
};