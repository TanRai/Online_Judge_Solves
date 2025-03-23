class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i:students)
        {
            q.push(i);
        }
        stack<int> st;
        for(auto it = sandwiches.rbegin();it!=sandwiches.rend();it++)
        {
            st.push(*it);
        }
        int count = 0;
        while(!q.empty())
        {
            if(q.front()==st.top())
            {
                q.pop();
                st.pop();
                count = 0;
            }
            else
            {
                int temp = q.front();
                q.pop();
                q.push(temp);
                count++;
                if(count==q.size())
                    break;
            }
        }
        return q.size();
    }
};