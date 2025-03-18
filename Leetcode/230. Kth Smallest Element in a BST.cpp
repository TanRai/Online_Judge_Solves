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
  void BFS(TreeNode* root,vector<int>& inOrder)
  {
      if(!root)
          return;
  
      BFS(root->left,inOrder);
      inOrder.push_back(root->val);
      BFS(root->right,inOrder);
  
      return;
  }
  public:
      int kthSmallest(TreeNode* root, int k) {
          vector<int> v;
          BFS(root,v);
          return v[k-1];
      }
  };