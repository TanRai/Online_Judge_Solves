class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxProfit;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minCapital;

        for(int i=0;i<profits.size();i++)
        {
            minCapital.emplace(capital[i],profits[i]);
        }

        while(k)
        {
            while(!minCapital.empty() && minCapital.top().first<=w)
            {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            if(maxProfit.empty())
                break;

            w += maxProfit.top();
            maxProfit.pop();
            k--;
        }
        return w;
    }
};