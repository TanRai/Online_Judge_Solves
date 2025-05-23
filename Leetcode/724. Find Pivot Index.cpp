class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>postfix(nums.size());
        int total = 0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
            prefix[i] = total;
        }
        total = 0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            total+=nums[i];
            postfix[i] = total;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int pre = i>0?prefix[i-1]:0;
            int post = i<nums.size()-1?postfix[i+1]:0;
            if(pre==post)
                return i;
        }
        return -1;
    }
};

//Optimal Memory

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        int leftSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            int rightSum = total - nums[i] - leftSum;
            if(leftSum==rightSum)
                return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};