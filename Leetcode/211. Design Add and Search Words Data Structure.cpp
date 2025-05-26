struct TrieNode
{
    bool word = false;
    unordered_map<char,TrieNode*> children;
    TrieNode()
    {

    }
};

class WordDictionary {
    TrieNode* root = new TrieNode();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto c:word)
        {
            if(!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return search(word,0,root);
    }
    bool search(string word,int i,TrieNode* cur)
    {
        if(i>=word.size())
        {
            return cur->word;
        }
        if(cur->children.empty())
            return false;
        if(word[i]=='.')
        {
            for(auto children:cur->children)
            {
                if(search(word,i+1,children.second))
                    return true;
            }
            return false;
        }
        
        if(!cur->children.count(word[i]))
            return false;
        cur = cur->children[word[i]];
        return search(word,i+1,cur);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */