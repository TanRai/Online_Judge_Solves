// Memoization approach

class Solution {
    int solve(vector<int>& nums,int i,unordered_map<int,int>& cache)
    {
        if(i>=nums.size())
            return 0;

        if(cache.count(i))
            return cache[i];

        cache[i] = max(nums[i]+solve(nums,i+2,cache),solve(nums,i+1,cache));

        return cache[i];
    }
public:
    int rob(vector<int>& nums) {
        unordered_map<int,int> cache;
        int amount = 0;
        return solve(nums,0,cache);
    }
};

//Another Memoization approach(Better)

class Solution {
    int solve(vector<int>& nums,int i,unordered_map<int,int>& cache)
    {
        if(i<0)
            return 0;
        if(cache.count(i))
            return cache[i];

        cache[i] = max(nums[i]+solve(nums,i-2,cache),solve(nums,i-1,cache));

        return cache[i];
    }
public:
    int rob(vector<int>& nums) {
        unordered_map<int,int> cache;
        return solve(nums,nums.size()-1,cache);
    }
};

// Dynamic Programming approach
class Solution {
    int solve(vector<int>& nums)
    {
        if(nums.size()==1)
            return nums[0];

        vector<int> dp(nums.size()+1);
        dp[1] = nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            dp[i] = max(nums[i-1]+dp[i-2],dp[i-1]);
        }

        return dp[nums.size()];
    }
public:
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};

// Optimized Dynamic Programming approach with O(1) space complexity

class Solution {
    int solve(vector<int>& nums)
    {
        if(nums.size()==1)
            return nums[0];

        int dp[2] = {0,nums[0]};
        for(int i=2;i<=nums.size();i++)
        {
            int temp = dp[1];
            dp[1] = max(nums[i-1]+dp[0],dp[1]);
            dp[0] = temp;
        }

        return dp[1];
    }
public:
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};
