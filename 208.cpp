class Trie {
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
    Trie() {
        root = newNode(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode_t *curr = root; 
        for(int i = 0; i < word.size(); i++){
            if(curr->children[(int)(word[i]-'a')] == NULL){
                return false; 
            }
            else curr = curr->children[(int)(word[i]-'a')]; 
        }
        return curr->isEndOfWord; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode_t *curr = root; 
        for(int i = 0; i < prefix.size(); i++){
            if(curr->children[(int)(prefix[i]-'a')] == NULL){
                return false; 
            }
            else curr = curr->children[(int)(prefix[i]-'a')]; 
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
