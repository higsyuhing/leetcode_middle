class MagicDictionary {
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
    MagicDictionary() {
        root = newNode(); 
    }
    
    void inner_insert(string word) {
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
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i = 0; i < dict.size(); i++) inner_insert(dict[i]);
    }
    
    
    bool inner_search(TrieNode_t *curr, string& word, int i, bool modified){
        // empty curr
        if(curr == NULL) return false; 
        
        // end case
        if(i == word.size()){
            if(modified) return curr->isEndOfWord; 
            return false; // exactly same without modified, not we want
        }
        
        // if modified, directly go down
        if(modified) 
            return inner_search(curr->children[(int)(word[i]-'a')], 
                                word, i+1, modified); 
        
        // not modified, you can try all cases, but flipping modified flag
        bool res; 
        for(int j = 0; j < ALPHABET_SIZE; j++){
            if(j == (int)(word[i]-'a')) // if same char, not flip
                res = inner_search(curr->children[j], word, i+1, modified); 
            else
                res = inner_search(curr->children[j], word, i+1, true); 
            if(res) return true; 
        }
        return false; 
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        // recursive, thus inner func
        return inner_search(root, word, 0, false); 
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
