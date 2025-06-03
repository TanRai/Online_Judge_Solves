class Solution {
    void dfs(int i,string& digits,vector<string>& res,unordered_map<char,vector<char>>& map,string& comb)
    {
        if(i==digits.size())
        {
            res.push_back(comb);
            return;
        }

        for(auto& c:map[digits[i]])
        {
            comb.push_back(c);
            dfs(i+1,digits,res,map,comb);
            comb.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        unordered_map<char,vector<char>> map;
        map['2'] = {'a','b','c'};
        map['3'] = {'d','e','f'};
        map['4'] = {'g','h','i'};
        map['5'] = {'j','k','l'};
        map['6'] = {'m','n','o'};
        map['7'] = {'p','q','r','s'};
        map['8'] = {'t','u','v'};
        map['9'] = {'w','x','y','z'};
        string comb;
        dfs(0,digits,res,map,comb);
        return res;
    }
};