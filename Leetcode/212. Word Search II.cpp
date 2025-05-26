struct PreNode
{
    bool word = false;
    unordered_map<char,PreNode*> children;
    PreNode()
    {

    }
};
class Solution {
    PreNode* root = new PreNode();
    vector<string> res;
    void insert(string word)
    {
        PreNode* cur = root;
        for(auto c:word)
        {
            if(!cur->children.count(c))
                cur->children[c] = new PreNode();
            cur = cur->children[c];
        }
        cur->word = true;
    }
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>& visit,string& s,PreNode* cur)
    {   
        int rows = board.size();
        int cols = board[0].size();
        if(min(r,c)<0 || r==rows || c==cols || visit[r][c] || !cur->children.count(board[r][c]))
            return;

        cur = cur->children[board[r][c]];

        s+=board[r][c];
        visit[r][c] = 1;
        if(cur->word)
        {
            res.push_back(s);
            cur->word = false;
        }
        dfs(r+1,c,board,visit,s,cur);
        dfs(r-1,c,board,visit,s,cur);
        dfs(r,c+1,board,visit,s,cur);
        dfs(r,c-1,board,visit,s,cur);
        visit[r][c]=0;
        s.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto s:words)
        {
            insert(s);
        }
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visit(rows,vector<int>(cols));
        string s = "";
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                dfs(i,j,board,visit,s,root);
            }
        }
        
        return res;
    }
};