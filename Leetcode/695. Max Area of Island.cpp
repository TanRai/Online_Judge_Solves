class Solution {
  int dfs(vector<vector<int>>& grid,int r,int c)
  {
      int ROWS = grid.size();
      int COLS = grid[0].size();
      if(min(r,c)<0 || r==ROWS || c==COLS || grid[r][c]!=1)
          return 0;
      
      grid[r][c]=2;
      int count = 1;
      count+=dfs(grid,r-1,c);
      count+=dfs(grid,r+1,c);
      count+=dfs(grid,r,c+1);
      count+=dfs(grid,r,c-1);

      return count;
  }


public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {

      int maximum = 0;
      for(int i=0;i<grid.size();i++)
      {
          for(int j=0;j<grid[0].size();j++)
          {
              if(grid[i][j]==1)
              {
                  maximum = max(maximum,dfs(grid,i,j));
              }
          }
      }
      return maximum;
  }
};