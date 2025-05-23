class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int total = 0;
        int length = nums.size()+1;

        for(int R=0;R<nums.size();R++)
        {
            total+=nums[R];
            while(total>=target)
            {
                length = min(length,R-L+1);
                total-=nums[L];
                L++;
            }
        }

        return length == nums.size()+1 ? 0 : length;
    }
};