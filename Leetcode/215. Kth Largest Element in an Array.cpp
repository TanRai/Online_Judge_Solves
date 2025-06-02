//Explanation
//Keep inserting in the min heap. If heap size > k then pop from heap the top value as it can't be kth largest value, if there is a value less than it and all the k value in the heap is less than it.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i: nums)
        {
            pq.push(i);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};