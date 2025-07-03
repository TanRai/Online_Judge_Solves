class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minHeap;

        set<int> visit;

        visit.insert(0);

        for(int i=1;i<points.size();i++)
        {
            int w = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            minHeap.push({w,0,i});
        }

        int cost = 0;

        while(visit.size()<points.size())
        {
            vector<int> v = minHeap.top();
            minHeap.pop();

            int w = v[0];
            int node = v[2];
            if(visit.count(node))
                continue;
            cost += w;
            visit.insert(node);
            for(int i=0;i<points.size();i++)
            {
                if(visit.count(i))
                    continue;

                int w = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                minHeap.push({w,0,i});
            }
        }

        return cost;
    }
};