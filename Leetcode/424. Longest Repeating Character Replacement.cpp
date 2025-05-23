class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0;
        int L = 0;
        unordered_map<char,int> window;
        int max = 0;
        char maxChar = ' ';
        for(int R=0;R<s.size();R++)
        {
            window[s[R]]+=1;
            if(s[R]==maxChar)
                max++;
            else if(window[s[R]]>max && s[R]!=maxChar)
            {
                max = window[s[R]];
                maxChar = s[R];
            }
            while(R-L+1-max > k)
            {
                window[s[L]]-=1;
                if(s[L]==maxChar)
                    max--;
                for(pair<char,int> i:window)
                {
                    if(window[i.first]>max)
                    {
                        maxChar = i.first;
                        max = window[i.first];
                    }
                }
                L++;
            }
            length = std::max(length,R-L+1);
        }
        return length;
    }
};

//Slight Optimization

class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0;
        int L = 0;
        unordered_map<char,int> window;
        int max = 0;
        for(int R=0;R<s.size();R++)
        {
            window[s[R]]+=1;
            max = std::max(max,window[s[R]]);
            while(R-L+1-max > k)
            {
                window[s[L]]-=1;
                max = 0;
                for(pair<char,int> i:window)
                {
                    max = std::max(max,window[i.first]);
                }
                L++;
            }
            length = std::max(length,R-L+1);
        }
        return length;
    }
};

//Optimized
class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0;
        int L = 0;
        unordered_map<char,int> window;
        int max = 0;
        for(int R=0;R<s.size();R++)
        {
            window[s[R]]+=1;
            max = std::max(max,window[s[R]]);
            while(R-L+1-max > k)
            {
                window[s[L]]-=1;
                L++;
            }
            length = std::max(length,R-L+1);
        }
        return length;
    }
};