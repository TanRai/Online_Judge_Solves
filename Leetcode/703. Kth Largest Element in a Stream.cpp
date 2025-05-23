class KthLargest {

  priority_queue<int,vector<int>,greater<int>> pq;
  int size = 0;
public:
  KthLargest(int k, vector<int>& nums) {
      size = k;
      if(nums.empty())
          return;
      for(int i:nums)
      {
          if(pq.size() < k)
          {
              pq.push(i);
          }
          else
          {
              if(pq.top() < i)
              {
                  pq.pop();
                  pq.push(i);
              }
          }
      }
  }
  
  int add(int val) {
      if(pq.size() < size)
      {
          pq.push(val);
      }
      else if(pq.top() < val)
      {
          pq.pop();
          pq.push(val);
      }
      return pq.top();
  }
};

/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest* obj = new KthLargest(k, nums);
* int param_1 = obj->add(val);
*/