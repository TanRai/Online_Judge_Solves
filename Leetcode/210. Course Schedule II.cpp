class Solution {
    bool dfs(int i, vector<vector<int>>& adj,unordered_set<int>& visit,unordered_set<int>& path,vector<int>& topSort)
    {
        if(path.count(i))
            return false;
        if(visit.count(i))
            return true;

        path.insert(i);
        visit.insert(i);

        for(int node:adj[i])
        {
            if(!dfs(node,adj,visit,path,topSort))
                return false;
        }
        topSort.push_back(i);
        path.erase(i);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());

        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }

        vector<int> topSort;
        unordered_set<int> visit;
        unordered_set<int> path;
        for(int i=0;i<numCourses;i++)
        {
            if(!dfs(i,adj,visit,path,topSort))
                return vector<int>();
        }

        return topSort;
    }
};