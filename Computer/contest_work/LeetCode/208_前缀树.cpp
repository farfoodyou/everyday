class Trie {
public:
    /** Initialize your data structure here. */
    bool isWord;
    Trie* next[26];
    Trie() {
        for(int i = 0; i< 26; i++) {
            next[i] = NULL;
        }
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        std::cout << word << "\n";
        Trie* p = this;

        for(int i = 0; i< word.size(); i++){
            char ch = word[i];
            
            //不断创建新的节点
            if(p->next[ch-'a'] == NULL) {
                p->next[ch-'a'] = new Trie();
            } 
            
            p = p->next[ch-'a'];
            
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p = this;
        for(int i = 0; i< word.size(); i++){
            char ch = word[i];
            if(p->next[ch-'a'] == NULL) {
                return false;
            } else {
                p = p->next[ch-'a'];
            }
            if(i==word.size()-1){
                return p->isWord;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* p = this;
        for(int i = 0; i< prefix.size(); i++){
            char ch = prefix[i];
            if(p->next[ch-'a'] == NULL) {
                return false;
            } else {
                p = p->next[ch-'a'];
            }
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