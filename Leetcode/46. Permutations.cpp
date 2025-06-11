//Backtracking
class Solution {
    void dfs(vector<int> nums,vector<vector<int>>& res,vector<int>& perm)
    {
        if(nums.empty())
        {
            res.push_back(perm);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            perm.push_back(num);
            nums.erase(nums.begin()+i);
            dfs(nums,res,perm);
            perm.pop_back();
            nums.insert(nums.begin()+i,num);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        dfs(nums,res,perm);
        return res;
    }
};

//Backtracking alternative
class Solution {
    vector<vector<int>> dfs(int i,vector<int>& nums)
    {
        if(i==nums.size())
        {
            return vector<vector<int>>(1,vector<int>());
        }

        vector<vector<int>> resPerms;
        vector<vector<int>> perms = dfs(i+1,nums);
        for(auto p:perms)
        {
            for(int j=0;j<=p.size();j++)
            {
                vector<int> pCopy = p;
                pCopy.insert(pCopy.begin()+j,nums[i]);
                resPerms.push_back(pCopy);
            }
        }
        return resPerms;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return dfs(0,nums);
    }
};

//Iterative
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> perms(1,vector<int>());   

        for(auto n:nums)
        {
            vector<vector<int>> nextPerms;
            for(auto p:perms)
            {
                for(int j=0;j<=p.size();j++)
                {
                    vector<int> pCopy = p;
                    pCopy.insert(pCopy.begin()+j,n);
                    nextPerms.push_back(pCopy);
                }
            }
            swap(perms,nextPerms);
        }
        return perms;
    }
};