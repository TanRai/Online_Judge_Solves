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
  vector<int> vec(n);
  int k = 1;
  int res = 0;
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
    if(vec[i]>=k)
    {
      res += 1;
      k = vec[i]+2;
    }
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