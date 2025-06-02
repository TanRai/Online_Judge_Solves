#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
 
using u128 = unsigned __int128;
using i128 = __int128;

 
void solve() {
  int n;
  cin>>n;
  vector<pair<i64,int>> x(n);
  vector<pair<i64,int>> y(n);
  for(int i=0;i<n;i++)
  {
    cin>>x[i].first>>y[i].first;
    x[i].second = y[i].second = i;
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  if(n==1)
  {
    cout<<1<<endl;
    return;
  }

  vector<int> vec = {x[0].second,x[n-1].second,y[0].second,y[n-1].second};
  i64 res = LLONG_MAX;
  for(int i:vec)
  {
    i64 minX = i==x[0].second?x[1].first:x[0].first;
    i64 maxX = i==x[n-1].second?x[n-2].first:x[n-1].first;
    i64 minY = i==y[0].second?y[1].first:y[0].first;
    i64 maxY = i==y[n-1].second?y[n-2].first:y[n-1].first;
    if((maxX-minX+1)*(maxY-minY+1)<n)
    {
      res = min(res,min((maxX-minX+2)*(maxY-minY+1),(maxX-minX+1)*(maxY-minY+2)));
    }
    else
      res = min(res,(maxX-minX+1)*(maxY-minY+1));
  }

  cout<<res<<endl;

}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}