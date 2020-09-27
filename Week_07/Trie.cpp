class Trie {
    struct TrieNode{
        map<char,TrieNode*> children;
        bool endFlag;
        TrieNode():endFlag(false){}
    };
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curNode = root;
        for(int i = 0; i < word.size();i++){
            if(curNode->children.count(word[i]) == 0){
                curNode->children[word[i]] = new TrieNode;
            }
            curNode = curNode->children[word[i]];
        }
        curNode->endFlag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word,true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix,false);
    }
private:
    TrieNode* root;
    bool find(string f, bool matchAll){
        TrieNode* curNode = root;
        for(int i = 0;i < f.size();i++){
            if(0 == curNode->children.count(f[i])){
                return false;
            }
            else{
                curNode = curNode->children[f[i]];
            }
        }
        if(matchAll){
            return curNode->endFlag ? true : false;
        }
        else{
            return true;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */