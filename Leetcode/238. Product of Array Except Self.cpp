class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size());
        vector<int> suf(nums.size());
        vector<int> result(nums.size());
        int total = 1;
        for(int i=0;i<nums.size();i++)
        {
            pref[i]=total;
            total*=nums[i];
        }
        total = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            suf[i]=total;
            total*=nums[i];
        }

        for(int i=0;i<nums.size();i++)
        {
            result[i] = pref[i]*suf[i];
        }
        return result;
    }
};

//Space optimized

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size());
        vector<int> suf(nums.size());
        vector<int> result(nums.size());
        int total = 1;
        for(int i=0;i<nums.size();i++)
        {
            result[i]=total;
            total*=nums[i];
        }
        total = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            result[i]*=total;
            total*=nums[i];
        }
        return result;
    }
};