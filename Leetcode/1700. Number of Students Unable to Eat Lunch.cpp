class Solution {
  public:
      int countStudents(vector<int>& students, vector<int>& sandwiches) {
          queue<int> std(students.begin(),students.end());
          stack<int> sand(sandwiches.rbegin(),sandwiches.rend());
  
          int count = 0;
  
          while(!std.empty() && count!=std.size())
          {
              if(std.front()==sand.top())
              {
                  std.pop();
                  sand.pop();
                  count = 0;
              }
              else
              {
                  count++;
                  std.push(std.front());
                  std.pop();
              }
          }
          return std.size();
      }
  };