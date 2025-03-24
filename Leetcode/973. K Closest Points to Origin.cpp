class Solution {
  public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          vector<vector<int>> res;
          struct CustomCompare{
              bool operator()(const vector<int>& a,const vector<int>& b){
                  return (a[0]*a[0]+a[1]*a[1]) < (b[0]*b[0]+b[1]*b[1]);
              }
          };
  
          priority_queue<vector<int>,vector<vector<int>>,CustomCompare> pq;
          for(auto i:points)
          {
              if(pq.size()<k)
              {
                  pq.push(i);
              }
              else
              {
                  vector<int> top = pq.top();
                  if((top[0]*top[0]+top[1]*top[1]) > (i[0]*i[0]+i[1]*i[1]))
                  {
                      pq.pop();
                      pq.push(i);
                  }
              }
          }
  
          while(!pq.empty())
          {
              res.push_back(pq.top());
              pq.pop();
          }
  
          return res;
      }
  };