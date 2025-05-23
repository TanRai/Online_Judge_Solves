class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count = 0;
        long long int total = 0;
        map[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
            if(map.count(total-k)>0)
                count+=map[total-k];
            map[total]+=1;
        }
        return count;
    }
};