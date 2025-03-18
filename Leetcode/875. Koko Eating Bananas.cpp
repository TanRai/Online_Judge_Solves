/*

*/





class Solution {
  public:
      int minEatingSpeed(vector<int>& piles, int h) {
          
          long long int left = 1;
          long long int right = *max_element(piles.begin(),piles.end());
          long long int hour = right;
  
          while(left<=right)
          {
              long long int mid = (left+right)/2;
  
              long long int reqHour = 0;
              for(int i:piles)
              {
                  reqHour+= i/mid + (i%mid==0 ? 0 : 1);
              }
              if(reqHour<=h)
              {
                  right = mid-1;
                  hour = mid;
              }
              else
              {
                  left = mid+1;
              }
          }
  
          return hour;
      }
  };