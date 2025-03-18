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
  private:
  vector<int> BFS(TreeNode* root,vector<int>& inOrder)
  {
      if(!root)
          return inOrder;
      BFS(root->left,inOrder);
      inOrder.push_back(root->val);
      BFS(root->right,inOrder);
      return inOrder;
  }
  
  public:
      vector<int> inorderTraversal(TreeNode* root) {
          
          vector<int> v;
          return BFS(root,v);
      }
  };