class Solution {
  public:
      int lastStoneWeight(vector<int>& stones) {
          priority_queue<int> pq(stones.begin(),stones.end());
  
          while(pq.size() > 1)
          {
              int top = pq.top();
              pq.pop();
              int top2 = pq.top();
              pq.pop();
              if(top!=top2)
              {
                  pq.push(top-top2);
              }
          }
  
          if(pq.empty())
              return 0;
  
          return pq.top();
      }
  };