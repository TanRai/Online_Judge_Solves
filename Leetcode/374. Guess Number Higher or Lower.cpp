/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 class Solution {
  public:
      int guessNumber(int n) {
          long long int left = 1;
          long long int right = n;
  
          while(left<=right)
          {
              long long int mid = (left+right)/2;
  
              int guess2 = guess(mid);
  
              if(guess2>0)
              {
                  left = mid+1;
              }
              else if(guess2<0)
              {
                  right = mid-1;
              }
              else
              {
                  return mid;
              }
          }
          return -1;
      }
  };