#include<bits/stdc++.h>
#define lli long long int

using namespace std;

void calc(lli sum,lli c2,lli c3)
{
    int flag=0;

    lli cond1=c2;
    lli cond2=c3;
    if(cond1>8)
        cond1=8;
    if(cond2>8)
        cond2=8;
    for(lli i=0;i<=cond1;i++)
    {
        for(lli j=0;j<=cond2;j++)
        {
            //cout<<"HERE";
            if(((sum+2*i+6*j)%9)==0)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    lli t,n,i,temp,j,sum,c2,c3;
    string s;
    cin>>t;
    while(t--)
    {
        sum=0;
        c2=0;
        c3=0;
        cin>>s;
        for(char c:s)
        {
            temp=(c-'0');
            sum+=temp%9;
            if(temp==2)
                c2++;
            if(temp==3)
                c3++;
        }
        if(sum%9==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        calc(sum,c2,c3);
    }

}
 