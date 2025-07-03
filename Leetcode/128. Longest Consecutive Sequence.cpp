class Solution {
    int dfs(int num,unordered_set<int>& seq,unordered_map<int,int>& con)
    {
        if(!seq.count(num))
            return 0;

        if(con.count(num))
            return con[num];

        int numConsec = 1 + dfs(num+1,seq,con);

        con[num] = numConsec;

        return numConsec;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> seq;
        unordered_map<int,int> con;
        for(auto num:nums)
        {
            seq.insert(num);
        }

        for(auto num:nums)
        {
            res = max(res,dfs(num,seq,con));
        }

        return res;
    }
};

// More optimized solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> con;

        for(auto num:nums)
        {
            if(!con[num])
            {
                con[num] = con[num-1]+con[num+1]+1;
                con[num-con[num-1]] = con[num];
                con[num+con[num+1]] = con[num];
                res = max(res,con[num]);
            }
        }

        return res;
    }
};