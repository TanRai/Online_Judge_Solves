class Solution {
  public:
      int climbStairs(int n) {
          vector<int> arr(n+1);
          arr[0]=1;
          for(int i=0;i<n;i++)
          {
              if(i+1<=n)
              {
                  arr[i+1]+=arr[i];
              }
              if(i+2<=n)
              {
                  arr[i+2]+=arr[i];
              }
          }
          return arr[n];
      }
      
  };