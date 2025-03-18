#include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli t,n,i,temp,j;
    string s;
    cin>>t;
    while(t--)
    {
        vector<int> v;
        cin>>s;
        for(char c:s)
        {
            v.push_back(c-'0');
        }
        //cout<<"HERE"<<v.size()<<endl;
        i=10;
        while(i--)
        {
            for(j=1;j<=v.size()-1;j++)
            {
                if(v[j-1]+1<v[j])
                {
                    temp=v[j-1];
                    v[j-1]=v[j]-1;
                    v[j]=temp;
                    j--;
                }

            }
        }
        for(lli i:v)
        {
            cout<<i;
        }
        cout<<endl;
    }

}