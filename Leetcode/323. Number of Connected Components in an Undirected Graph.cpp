class Solution {
    void dfs(int i,vector<bool>& visited,vector<vector<int>>& adj)
    {
        visited[i] = true;

        for(auto& node:adj[i])
        {
            if(!visited[node])
                dfs(node,visited,adj);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n,vector<int>());

        for(auto& edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                res++;
                dfs(i,visited,adj);
            }
        }
        return res;
    }
};

// Union-Find solution

class Solution {
    vector<int> parent;
    vector<int> rank;

    int find(int n)
    {
        int p = n;
        while(p!=parent[p])
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

        if(rank[p1]>rank[p2])
        {
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2])
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
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        int res = n;

        for(auto& edge:edges)
        {
            if(uniond(edge[0],edge[1]))
            {
                res--;
            }
        }
        
        return res;
    }
};