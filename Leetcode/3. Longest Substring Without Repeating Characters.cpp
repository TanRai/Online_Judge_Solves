class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0;
        int length = 0;
        unordered_map<char,int> window;
        for(int R=0;R<s.size();R++)
        {
            if(window.count(s[R]) && L<=window[s[R]])
            {
                L = window[s[R]]+1;
            }
            window[s[R]] = R;
            length = max(length,R-L+1);
        }

        return length;
    }
};