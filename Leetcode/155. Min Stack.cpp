class MinStack {
  public:
      vector<pair<int,int>> st;
      MinStack() {
          
      }
      
      void push(int val) {
          long long int minVal = getMin();
          if(st.empty() || val<minVal)
              minVal = val;
  
          st.push_back(make_pair(val,minVal));
      }
      void pop() {
          st.pop_back();
      }
      int top() {
          return st.empty() ? NULL : st.back().first;
      }
      
      int getMin() {
          return st.empty() ? NULL : st.back().second;
      }
  };
  
  /**
   * Your MinStack object will be instantiated and called as such:
   * MinStack* obj = new MinStack();
   * obj->push(val);
   * obj->pop();
   * int param_3 = obj->top();
   * int param_4 = obj->getMin();
   */