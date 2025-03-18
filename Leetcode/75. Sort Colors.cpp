class Solution {
  public:
      void sortColors(vector<int>& nums) {
          vector<int> count(3);
          for(int i:nums)
          {
              count[i]++;
          }
  
          int k = 0;
          for(int i=0;i<count.size();i++)
          {
              for(int j=0;j<count[i];j++)
              {
              nums[k] = i;
              k++;
              }
          }
      }
  };