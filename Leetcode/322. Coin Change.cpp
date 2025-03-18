#define lli unsigned long long


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<lli> dp(amount+1,numeric_limits<lli>::max());
        dp[0]=0;
        for(lli i=0;i<amount;i++)
        {
            for(lli j:coins)
            {
                if(i+j<=amount)
                {
                    if(dp[i]!=numeric_limits<lli>::max())
                        dp[i+j]=min(dp[i]+1,dp[i+j]);
                }
            }
        }
        if(dp[amount]==numeric_limits<lli>::max())
            return -1;
        return dp[amount];
    }
};