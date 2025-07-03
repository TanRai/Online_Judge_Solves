class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    unordered_map<string,int> index;

    int find(int n)
    {
        int p = n;
        while(p != parent[p])
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool uniond(int n1,int n2)
    {
        int p1 = find(n1), p2 = find(n2);
        if(p1 == p2)
            return false;

        if(rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if(rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }
        return true;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        rank.resize(accounts.size());
        for(int i=0;i<accounts.size();i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(index.count(accounts[i][j]))
                {
                    uniond(i,index[accounts[i][j]]);
                }
                else
                {
                    index[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int,vector<string>> emailGroup;
        for(auto& i:index)
        {
            emailGroup[find(i.second)].push_back(i.first);
        }

        vector<vector<string>> res;
        for(auto& i:emailGroup)
        {
            vector<string> vec = i.second;
            sort(vec.begin(),vec.end());
            vec.insert(vec.begin(),accounts[i.first][0]);
            res.push_back(vec);
        }

        return res;
    }
};