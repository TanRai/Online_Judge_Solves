//DFS solution. Before adding an edge to the graph(adjList), checks if it is already connected or not.

class Solution {
public:
    unordered_map<int,vector<int>> adj;
    bool dfs(int i,int j,vector<vector<int>>& edges,set<int>& visit)
    {
        if(i==j)
            return true;

        visit.insert(i);
        for(auto node:adj[i])
        {
            if(!visit.count(node))
            {
                if(dfs(node,j,edges,visit))
                    return true;
            }
            
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto edge:edges)
        {
            set<int> visit;
            if(dfs(edge[0],edge[1],edges,visit))
                return edge;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return {};
    }
};

//Union-Find solution. Uses union-find to check if the edge is already connected or not.
class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

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
        int p1 = find(n1),p2 = find(n2);
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


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=1;i<edges.size();i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        for(auto edge:edges)
        {
            if(!uniond(edge[0],edge[1]))
                return edge;
        }


        return {};
    }
};