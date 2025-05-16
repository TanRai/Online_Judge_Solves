class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;


        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2)
                    q.push(make_pair(i,j));
            }
        }


        int minutes = 0;
        int neighbors[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int qSize = q.size();
            for(int i=0;i<qSize;i++)
            {
                pair<int,int> curPair = q.front();
                q.pop();
                int r = curPair.first;
                int c= curPair.second;

                for(int j=0;j<4;j++)
                {
                    int newR = r + neighbors[j][0];
                    int newC = c + neighbors[j][1];
                    if(min(newR,newC)<0 || newR == rows || newC == cols || grid[newR][newC]!=1)
                        continue;
                    
                    q.push(make_pair(newR,newC));
                    grid[newR][newC] = 2;
                }
            }
            minutes++;
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        if(!minutes)
            return minutes;

        return minutes-1;
    }
};