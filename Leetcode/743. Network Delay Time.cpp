class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=1;i<=n;i++)
        {
            adj[i] = vector<pair<int,int>>();
        }
        for(auto edge:times)
        {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back(make_pair(d,w));
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        unordered_map<int,int> shortest;
        minHeap.push(make_pair(0,k));
        while(!minHeap.empty())
        {
            pair<int,int> p = minHeap.top();
            minHeap.pop();
            int w1 = p.first , n1 = p.second;
            if(shortest.count(n1))
                continue;
            shortest[n1] = w1;
            for(auto edge:adj[n1])
            {
                int n2 = edge.first, w2 = edge.second;
                if(!shortest.count(n2))
                {
                    minHeap.push({w1+w2,n2});
                }
            }
        }   
        int res = 0;
        for(int i=1;i<=n;i++)
        {
            if(!shortest.count(i))
            {
                return -1;
            }
            res = max(res,shortest[i]);
        }
        return res;
    }
};