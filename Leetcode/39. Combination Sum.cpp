class Solution {
  void combSum(vector<int>& candidates,int target,int index,vector<int>& subset,vector<vector<int>>& res)
  {
      if(target==0)
      {
          res.push_back(subset);
          return;
      }
      if(index==candidates.size() || target<0)
          return;
  
      subset.push_back(candidates[index]);
      combSum(candidates,target-candidates[index],index,subset,res);
      subset.pop_back();
      combSum(candidates,target,index+1,subset,res);
  }
  
  public:
      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> res;
          vector<int> subset;
          combSum(candidates,target,0,subset,res);
          return res;
      }
  };