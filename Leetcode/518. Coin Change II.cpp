#define lli unsigned long long
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<lli>> dp(amount+1,vector<lli>(coins.size()+1,0));
        dp[0][0]=1;
        for(lli i=0;i<=amount;i++)
        {
            for(lli j=0;j<=coins.size();j++)
            {
                if(j>0 && i+coins[j-1]<=amount)
                {
                    dp[i+coins[j-1]][j]+=dp[i][j];
                }
                if(j+1<=coins.size())
                {
                    dp[i][j+1]+=dp[i][j];
                }
            }
        }
        return dp[amount][coins.size()];
    }
};