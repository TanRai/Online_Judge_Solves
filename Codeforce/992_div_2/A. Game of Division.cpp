#include<bits/stdc++.h>
#define lli long long int

using namespace std;
string a,b,c;

int main()
{
    lli t,n,k,i,temp,j;

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        i=n;
        vector<lli> v;
        while(i--)
        {
            cin>>temp;
            v.push_back(temp);
        }
        lli res=-1;
        for(lli i=0;i<n;i++)
        {
            if(res!=-1)
                break;
            for(lli j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if((abs(v[i]-v[j]))%k==0)
                    {
                        break;
                    }
                }
                if(j==n-1)
                {
                    res=i;
                }
            }
        }
        if(res==-1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<res+1<<endl;
        }
    }

}