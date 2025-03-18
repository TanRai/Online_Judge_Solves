#define lli unsigned long long 
class Solution {
public:

    



    lli combinationSum4(vector<int>& nums, lli target) {
        vector<lli> dp(target+1);
        dp[0] = 1;
        for(lli i=0;i<target;i++)
        {
            for(lli j:nums)
            {
                if(i+j<=target)
                {
                    dp[i+j]+=dp[i];
                }
            }
        }
        return dp[target];
    }
};