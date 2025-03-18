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
      TreeNode* minVal(TreeNode* root)
      {
          if(!root)
              return root;
          
          while(root && root->left)
          {
              root = root->left;
          }
  
          return root;
      }
  public:
      TreeNode* deleteNode(TreeNode* root, int key) {
          if(!root)
              return root;
          
          if(root->val < key)
          {
              root->right = deleteNode(root->right,key);
          }
          else if(root->val > key)
          {
              root->left = deleteNode(root->left,key);
          }
          else
          {
              if(root->left == nullptr)
              {
                  return(root->right);
              }
              else if(root->right == nullptr)
              {
                  return(root->left);
              }
              else
              {
                  TreeNode* min = minVal(root->right);
                  cout<<min->val;
                  root->val = min->val;
                  root->right = deleteNode(root->right,min->val);
              }
          }
          return root;
      }
  };