class Solution {
    int bruteForce(int r,int c,int rows,int cols)
    {
        if(r==rows || c==cols)
            return 0;
        if(r==rows-1 && c==cols-1)
            return 1;

        return bruteForce(r+1,c,rows,cols)+bruteForce(r,c+1,rows,cols);
    }

    int memoization(int r,int c,int rows,int cols,vector<vector<int>>& cache)
    {
        if(r==rows || c==cols)
            return 0;
        if(r==rows-1 && c==cols-1)
            return 1;
        if(cache[r][c]>0)
            return cache[r][c];

        cache[r][c] =  memoization(r+1,c,rows,cols,cache)+memoization(r,c+1,rows,cols,cache);

        return cache[r][c];
    }

    int dp(int rows,int cols)
    {
        vector<int> prevrow(cols);

        for(int i=rows-1;i>=0;i--)
        {
            vector<int> currow(cols);
            currow[cols-1] = 1;
            for(int j=cols-2;j>=0;j--)
            {
                currow[j] = currow[j+1] + prevrow[j];
            }
            prevrow = currow;
        }

        return prevrow[0];
    }

public:
    int uniquePaths(int m, int n) {
        //vector<vector<int>> cache(m,vector<int>(n));
        //return memoization(0,0,m,n,cache);
        return dp(m,n);
    }
};