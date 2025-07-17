class Solution {
    class UnionFind{
        vector<int> parent;
        vector<int> rank;
    public:
        void reset()
        {
            for(int i=0;i<parent.size();i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        UnionFind(int n)
        {
            parent = vector<int>(n);
            rank = vector<int>(n);
            reset();
        }
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
            int p1 = find(n1),p2 = find(n2);
            if(p1 == p2)
                return false;

            if(rank[p1]<rank[p2])
            {
                parent[p2] = p1;
            }
            else if(rank[p2]<rank[p1])
            {
                parent[p1] = p2;
            }
            else{
                parent[p1] = p2;
                rank[p2]++;
            }
            return true;
        }
    };
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        UnionFind* uf = new UnionFind(n);

        vector<vector<int>> edges2;
        for(int i=0;i<edges.size();i++)
        {
            edges2.push_back({edges[i][0],edges[i][1],edges[i][2],i});
        }

        sort(edges2.begin(),edges2.end(),[](const auto& a,const auto& b){
            return a[2] < b[2];
        });

        int minCost = 0;
        int edge = 0;
        for(const auto& i:edges2)
        {
            if(edge>=n-1)
                break;
            int w = i[2], n1 = i[0], n2 = i[1];
            if(uf->uniond(n1,n2))
            {
                minCost+=w;
                edge++;
            }
        }
        vector<vector<int>> res(2,vector<int>());
        for(int i=0;i<edges2.size();i++)
        {
            uf->reset();
            int cost = 0;
            int edge = 0;
            for(int j=0;j<edges2.size();j++)
            {
                if(i==j)
                    continue;

                int w = edges2[j][2], n1 = edges2[j][0], n2 = edges2[j][1];

                if(!(uf->uniond(n1,n2)))
                    continue;
                
                edge++;
                cost+=w;
            }
            if(cost>minCost || edge<n-1)
            {
                res[0].push_back(edges2[i][3]);
            }
            else
            {
                uf->reset();
                int cost = edges2[i][2];
                int edge = 1;
                uf->uniond(edges2[i][0],edges2[i][1]);
                for(int j=0;j<edges.size();j++)
                {
                    if(i==j)
                        continue;

                    int w = edges2[j][2], n1 = edges2[j][0], n2 = edges2[j][1];

                    if(!(uf->uniond(n1,n2)))
                        continue;
                    
                    edge++;
                    cost+=w;
                }
                if(cost==minCost && edge==n-1)
                {
                    res[1].push_back(edges2[i][3]);
                }
            }
        }
        return res;
    }
};