class Solution {
  bool searchList(vector<int>& list, int target)
  {
      int left = 0;
      int right = list.size()-1;
  
      while(left<=right)
      {
          int mid = (left+right)/2;

          if(list[mid]==target)
          {
              return true;
          }
          else if(list[mid]>target)
          {
              right = mid - 1;
          }
          else
          {
              left = mid + 1;
          }
      }
      return false;
  }
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      cout<<n<<endl;
      int left = 0;
      int right = m - 1;

      while(left<=right)
      {
          int mid = (left+right)/2;

          if(matrix[mid][0]>target)
          {
              right = mid - 1;
          }
          else if(matrix[mid][n-1]<target)
          {
              left = mid + 1;
          }
          else
          {
              return searchList(matrix[mid],target);
          }
      }


      return false;
  }
};