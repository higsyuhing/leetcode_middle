class WordDictionary {
public:
    
    #define ALPHABET_SIZE   26
    // trie node 
    typedef struct TrieNode { 
        struct TrieNode *children[ALPHABET_SIZE]; 

        // isEndOfWord is true if the node represents 
        // end of a word 
        bool isEndOfWord; 
    } TrieNode_t; 
    TrieNode_t *root; 
    
    TrieNode_t *newNode(){
        TrieNode_t *res = new TrieNode_t(); 
        res->isEndOfWord = false; 
        for(int i = 0; i < ALPHABET_SIZE; i++)
            res->children[i] = NULL; 
        return res; 
    }
    
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = newNode(); 
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode_t *curr = root; 
        for(int i = 0; i < word.size(); i++){
            if(curr->children[(int)(word[i]-'a')] == NULL){
                curr->children[(int)(word[i]-'a')] = newNode(); 
                curr = curr->children[(int)(word[i]-'a')]; 
            }
            else curr = curr->children[(int)(word[i]-'a')]; 
        }
        curr->isEndOfWord = true; 
    }
    
    bool inner_search(TrieNode_t *curr, string& word, int i){
        // empty curr
        if(curr == NULL) return false; 
        
        // end case
        if(i == word.size()) return curr->isEndOfWord; 
        
        // '.' word[i]
        if(word[i] == '.'){
            bool res; 
            for(int j = 0; j < ALPHABET_SIZE; j++){
                res = inner_search(curr->children[j], word, i+1); 
                if(res) return true; 
            }
            return false; 
        }
        
        // non-'.' word[i]
        return inner_search(curr->children[(int)(word[i]-'a')], word, i+1); 
    }
    
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        // should support recursive
        return inner_search(root, word, 0); 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
