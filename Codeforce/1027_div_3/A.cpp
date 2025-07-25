#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
 
using u128 = unsigned __int128;
using i128 = __int128;
 
void solve() {
  string s;
  cin>>s;
  int n = stoi(s);
  int root = sqrt(n);
  if(root*root!=n)
  {
    cout<<"-1"<<endl;
    return;
  }
  if(n==0)
  {
    cout<<0<<" "<<0<<endl;
    return;
  }
  cout<<root-1<<" "<<1<<endl;
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