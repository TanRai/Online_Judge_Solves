//Memoization approach
class Solution {
    int solve(int n,unordered_map<int,int>& cache)
    {
        if(n<=2)
            return n;
        if(cache.count(n))
            return cache[n];

        cache[n] = solve(n-1,cache)+solve(n-2,cache);

        return cache[n];
    }

public:
    int climbStairs(int n) {

        unordered_map<int,int> cache;

        return solve(n,cache);
        
    }
};

// Dynamic Programming approach

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