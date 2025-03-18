#include<bits/stdc++.h>
#define lli long long int

using namespace std;

lli bin_search(vector<lli> arr,lli target)
{
    lli l,r,mid,ans;
    l=0;
    r=arr.size()-1;
    ans=-1;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        //cout<<"debug"<<endl;
        //cout<<l<<" "<<r<<" "<<mid<<endl;
        //cout<<"debug"<<endl;
        if(arr[mid]<=target)
        {
            ans = mid;
            l=mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return ans+1;
}

int main()
{
    lli t,n,m,i;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<lli> v;
        i=0;
        while(i<n)
        {
            cin>>s;
            if(i==0)
                v.push_back(s.size());
            else
                v.push_back(s.size()+v[i-1]);
            i++;
        }
        cout<<bin_search(v,m)<<endl;
    }

}