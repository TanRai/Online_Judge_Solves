class Solution {
  private:
  void createSubsets(vector<int>& nums,int index,vector<vector<int>>& res,vector<int>& subset)
  {
      if(index==nums.size())
      {
          res.push_back(subset);
          return;
      }
  
      subset.push_back(nums[index]);
      createSubsets(nums,index+1,res,subset);
  
      subset.pop_back();
      createSubsets(nums,index+1,res,subset);
  }
  
  
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>> res;
          vector<int> susbet;
          createSubsets(nums,0,res,susbet);
          return res;
      }
  };