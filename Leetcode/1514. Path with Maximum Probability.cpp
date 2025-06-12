class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;

        for(int i=0;i<succProb.size();i++)
        {
            int s = edges[i][0], d = edges[i][1];
            double w = succProb[i];
            adj[s].push_back({d,w});
            adj[d].push_back({s,w});
        }

        priority_queue<pair<double,int>> maxHeap;
        maxHeap.push({1.0,start_node});
        set<int> visit;

        while(!maxHeap.empty())
        {
            pair<double,int> p = maxHeap.top();
            maxHeap.pop();

            double w1 = p.first;
            int n1 = p.second;

            if(visit.count(n1))
                continue;

            if(n1 == end_node)
                return w1;

            visit.insert(n1);
            for(auto edge:adj[n1])
            {
                int n2 = edge.first;
                double w2 = edge.second;
                if(!visit.count(n2))
                    maxHeap.push({w1*w2,n2});

            }
        }

        return 0;
    }
};