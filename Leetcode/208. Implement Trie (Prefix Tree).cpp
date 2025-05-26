struct TrieNode
{
    bool word = false;
    unordered_map<char,TrieNode*> children;
    TrieNode()
    {

    }
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto c:word)
        {
            if(!cur->children.count(c))
            {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto c:word)
        {
            if(!cur->children.count(c))
                return false;
            cur = cur->children[c];
        }
        return cur->word;
    }
    
    bool startsWith(string prefix) {
                TrieNode* cur = root;
        for(auto c:prefix)
        {
            if(!cur->children.count(c))
                return false;
            cur = cur->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */