class Solution {
  void dfs(vector<vector<char>>& grid,vector<vector<char>>& visit,int r,int c)
  {
      int ROWS = grid.size();
      int COLS = grid[0].size();
      if(min(r,c)<0 || r==ROWS || c==COLS || visit[r][c]=='1' || grid[r][c]=='0')
          return;
      
      visit[r][c]='1';
      dfs(grid,visit,r+1,c);
      dfs(grid,visit,r-1,c);
      dfs(grid,visit,r,c+1);
      dfs(grid,visit,r,c-1);
  }


public:
  int numIslands(vector<vector<char>>& grid) {

      vector<vector<char>> visit(grid.size(),vector<char>(grid[0].size(),'0'));

      int count = 0;
      for(int i=0;i<grid.size();i++)
      {
          for(int j=0;j<grid[0].size();j++)
          {
              if(grid[i][j]=='1' && visit[i][j]=='0')
              {
                  count+= 1;
                  dfs(grid,visit,i,j);
              }
          }
      }
      return count;
  }
};

