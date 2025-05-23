class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix = vector<vector<int>>(rows+1,vector<int>(cols+1,0));
        for(int r=0;r<rows;r++)
        {
            int total = 0;
            for(int c=0;c<cols;c++)
            {
                total += matrix[r][c];
                int above = prefix[r][c+1];
                prefix[r+1][c+1] = total+above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        int pre = prefix[row2][col2];
        int above = prefix[row1-1][col2];
        int left = prefix[row2][col1-1];
        int topleft = prefix[row1-1][col1-1];

        return pre - above - left + topleft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */