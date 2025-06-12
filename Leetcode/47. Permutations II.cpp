class Solution {
public:
    unordered_map<int,int> map;
    void dfs(vector<vector<int>>& res,vector<int>& perm,vector<int>& nums)
    {
        if(perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }
        for(auto i:map)
        {
            if(i.second)
            {
                perm.push_back(i.first);
                map[i.first]--;
                dfs(res,perm,nums);
                perm.pop_back();
                map[i.first]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        for(auto n:nums)
        {
            map[n]++;
        }
        dfs(res,perm,nums);
        return res;
    }
};