class Solution {
  private:
      void DFS(int k,int n,int index,vector<vector<int>>& res,vector<int> subset)
      {
          if(n==0 && k==0)
              res.push_back(subset);
          if(k<=0 || n<=0 || index>9 || index>n)
              return;
          
          subset.push_back(index);
          DFS(k-1,n-index,index+1,res,subset);
          subset.pop_back();
          DFS(k,n,index+1,res,subset);
      }
  
  public:
      vector<vector<int>> combinationSum3(int k, int n) {
          vector<vector<int>> res;
          vector<int> v;
          DFS(k,n,1,res,v);
          return res;
      }
  };