class Solution {
private:
    void dfs(int i,int n, int k,vector<vector<int>>& res,vector<int>& subset)
    {
        if(subset.size() == k)
        {
            res.push_back(subset);
            return;
        }
        if(i>n)
            return;
        
        for(int j=i;j<=n;j++)
        {
            subset.push_back(j);
            dfs(j+1,n,k,res,subset);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(1,n,k,res,subset);
        return res;
    }
};