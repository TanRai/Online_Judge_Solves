#include<bits/stdc++.h>
#define lli long long int

using namespace std;
string a,b,c;

int main()
{
    lli t,n,i,temp,j;

    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        vector<vector<lli>> dp(a.size()+1,vector<lli>(b.size()+1,numeric_limits<lli>::max()));
        dp[0][0]=0;
        for(i=0;i<=a.size();i++)
        {
            for(j=0;j<=b.size();j++)
            {
                lli k=i+j;
                if(i+1<=a.size())
                {
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(a[i]==c[k]?0:1));
                }
                if(j+1<=b.size())
                {
                    dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(b[j]==c[k]?0:1));
                }
            }
        }
        cout<<dp[a.size()][b.size()]<<endl;
    }

}