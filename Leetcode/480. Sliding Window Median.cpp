class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> low;
        priority_queue<int,vector<int>,greater<int>> high;
        unordered_map<int,int> d;

        for(int i=0;i<k;i++)
        {
            low.push(nums[i]);
        }
        for (int i = 0; i < k / 2; i++)
        {
            high.push(low.top());
            low.pop();
        }

        vector<double>res;
        res.push_back(k & 1?low.top():(low.top() + 0LL + high.top())/2.0);

        for(int i=k;i<nums.size();i++)
        {
            d[nums[i-k]]++;
            int balance = !low.empty() && nums[i-k]<=low.top()?-1:1;

            if(nums[i]<=low.top())
            {
                low.push(nums[i]);
                balance++;
            }
            else
            {
                high.push(nums[i]);
                balance--;
            }

            if(balance<0)
            {
                low.push(high.top());
                high.pop();
            }
            else if(balance>0)
            {
                high.push(low.top());
                low.pop();
            }

            while(!low.empty() && d[low.top()])
            {
                d[low.top()]--;
                low.pop();
            }

            while(!high.empty() && d[high.top()])
            {
                d[high.top()]--;
                high.pop();
            }

            res.push_back(k & 1?low.top():(low.top() + 0LL + high.top())/2.0);
        }
        return res;
    }
};