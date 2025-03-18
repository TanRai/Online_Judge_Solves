class Solution {
  public:
      int removeDuplicates(vector<int>& nums) {
          long long int last = nums[0];
          long long int k = 1;
  
          for(int i=1;i<nums.size();i++)
          {
              if(last!=nums[i])
              {
                  last = nums[i];
                  nums[k]=last;
                  k++;
              }
          }
          return k;
      }
  };