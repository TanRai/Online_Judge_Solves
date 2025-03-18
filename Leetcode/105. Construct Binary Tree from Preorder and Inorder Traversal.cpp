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

  TreeNode* createTree(vector<int> preorder, vector<int> inorder)
  {
      if(preorder.empty())
          return nullptr;
  
      TreeNode* root = new TreeNode(preorder[0]);
  
      auto mid = find(inorder.begin(),inorder.end(),preorder[0]) - inorder.begin();
  
      root->left = createTree(vector<int>(preorder.begin()+1,preorder.begin()+mid+1),
      vector<int>(inorder.begin(),inorder.begin()+mid));
      root->right = createTree(vector<int>(preorder.begin()+mid+1,preorder.end()),
      vector<int>(inorder.begin()+mid+1,inorder.end()));
      
      return root;
  
  }
  public:
      TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          return createTree(preorder,inorder);
      }
  };