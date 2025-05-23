class Solution {
    bool isAlphaNum(char c)
    {
        if(c>='a' && c<='z')
            return true;
        if(c>='A' && c<='Z')
            return true;
        if(c>='0' && c<='9')
            return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size()-1;
        for(auto& c : s)
        {
            c = tolower(c);
        }
        while(L<R)
        {
            if(!isAlphaNum(s[L]))
            {
                L++;
                continue;
            }
            if(!isAlphaNum(s[R]))
            {
                R--;
                continue;
            }
            if(s[L]!=s[R])
                return false;
            L++;
            R--;
        }
        return true;
    }
};