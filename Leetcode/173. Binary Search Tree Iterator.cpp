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
class BSTIterator {
    TreeNode* root;
    stack<TreeNode*> st;
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        cur = root;
    }
    
    int next() {
        int val;
        while(!st.empty() || cur)
        {
            
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                val = cur->val;
                cur = cur->right;
                break;
            }
        }
        return val;
    }
    
    bool hasNext() {
        if(st.empty() && cur==nullptr)
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */