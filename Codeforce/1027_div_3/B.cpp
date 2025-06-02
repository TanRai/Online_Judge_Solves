#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
 
using u128 = unsigned __int128;
using i128 = __int128;
 
void solve() {
  int n,k;
  string s;
  cin>>n>>k;
  cin>>s;
  int total = 0;
  int len = (int)s.size();
  for(int i=0;i<len;i++)
  {
    total += s[i]=='1'?1:0;
  }

  int res = len/2;
  res -= total%2==0?0:1;// max possible  6

  int res2= (len/2) - min(total,len-total);//min possible
  
  if(res>=k && res2<=k && k%2==res%2)
  {
    cout<<"YES"<<endl;
    return;
  }
  cout<<"NO"<<endl;

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