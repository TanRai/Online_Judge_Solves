class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globMax = nums[0],globMin = nums[0], total = 0, curMax = 0, curMin = 0;
        for(int i:nums)
        {
            total+=i;
            curMax = max(curMax+i,i);
            curMin = min(curMin+i,i);
            globMax = max(globMax,curMax);
            globMin = min(globMin,curMin);
        }

        return globMax>0 ? max(globMax,total-globMin) : globMax;
    }
};