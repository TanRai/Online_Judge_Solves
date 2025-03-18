class Solution {
  private:
  void DFS(vector<int>& candidates, int target,int index,vector<int>& subset,vector<vector<int>>& res)
  {
      if(target==0)
      {
          res.push_back(subset);
          return;
      }
      if(index==candidates.size() || target<0)
          return;
  
      subset.push_back(candidates[index]);
      DFS(candidates,target-candidates[index],index+1,subset,res);
      subset.pop_back();
      while((index+1)<candidates.size() && candidates[index]==candidates[index+1])
      {
          index++;
      }
      if((index+1)==candidates.size())
          return;
      DFS(candidates,target,index+1,subset,res);
  }
  
  public:
      vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<vector<int>> res;
          vector<int> subset;
          sort(candidates.begin(),candidates.end());
          DFS(candidates,target,0,subset,res);
          return res;
      }
  };