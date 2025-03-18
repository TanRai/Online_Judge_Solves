// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
  public:
      int firstBadVersion(int n) {
          int bad = n;
  
          long long int left = 1;
          long long int right = n;
          while(left<=right)
          {
              long long int mid = (left+right)/2;
  
              if(isBadVersion(mid))
              {
                  bad = mid;
                  right = mid-1;
              }
              else
              {
                  left=mid+1;
              }
          }
          return bad;
      }
  };