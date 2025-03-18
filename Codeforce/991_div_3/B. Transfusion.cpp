#include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli t,n,i,temp;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        i=0;
        lli flag=0;
        lli oddSum=0;
        lli evenSum=0;
        while(i<n)
        {
            cin>>temp;
            if(flag==0)
            {
                oddSum+=temp;
                flag=1;
            }
            else
            {
                evenSum+=temp;
                flag=0;
            }
            i++;
        }
        lli odd = ceil(n/2.0);
        lli even = floor(n/2.0);

        if((oddSum/odd)==(evenSum/even) && oddSum%odd==0 && evenSum%even==0)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }

}