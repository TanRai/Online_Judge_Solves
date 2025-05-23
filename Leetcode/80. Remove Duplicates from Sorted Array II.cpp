class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)
            return nums.size();
        int L=2;
        int R=2;
        while(R<nums.size())
        {
            if(nums[R-1]!=nums[R] || nums[R-2]!=nums[R] || nums[L-2]!=nums[L-1])
            {
                nums[L++] = nums[R];
            }
            R++;
        }
        return L;
    }
};