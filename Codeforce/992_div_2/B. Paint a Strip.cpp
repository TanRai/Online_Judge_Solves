#include<bits/stdc++.h>
#define lli long long int

using namespace std;
string a,b,c;

int main()
{
    lli t,n,k,i,temp,j,res;

    cin>>t;
    while(t--)
    {
        cin>>n;
        i=1;
        res=1;
        while(res<n)
        {
            i++;
            res=(res+1)*2;
        }
        cout<<i<<endl;
    }

}