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
      vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>> v;
          if(!root)
              return v;
          
          queue<TreeNode*> q;
          q.push(root);
          int level = 0;
          while(!q.empty())
          {
              vector<int> l;
              int size = q.size();
              for(int i=0;i<size;i++)
              {
                  TreeNode* root = q.front();
                  q.pop();
                  l.push_back(root->val);
                  if(root->left)
                      q.push(root->left);
                  if(root->right)
                      q.push(root->right);
              }
              level++;
              v.push_back(l);
          }
  
          return v;
      }
  };