class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L=1;
        int R=1;
        while(R<nums.size())
        {
            if(nums[R-1]!=nums[R])
            {
                nums[L++] = nums[R];
            }
            R++;
        }
        return L;
    }
};