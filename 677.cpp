class MapSum {
public:
    
    #define ALPHABET_SIZE   26
    // trie node 
    typedef struct TrieNode { 
        struct TrieNode *children[ALPHABET_SIZE]; 

        // value, default is 0. which doesn't affect the final result
        // addition is cheaper than branch
        int value; 
    } TrieNode_t; 
    TrieNode_t *root; 
    
    TrieNode_t *newNode(){
        TrieNode_t *res = new TrieNode_t(); 
        res->value = 0; 
        for(int i = 0; i < ALPHABET_SIZE; i++)
            res->children[i] = NULL; 
        return res; 
    }
    
    
    /** Initialize your data structure here. */
    MapSum() {
        root = newNode(); 
    }
    
    void insert(string key, int val) {
        TrieNode_t *curr = root; 
        for(int i = 0; i < key.size(); i++){
            if(curr->children[(int)(key[i]-'a')] == NULL){
                curr->children[(int)(key[i]-'a')] = newNode(); 
                curr = curr->children[(int)(key[i]-'a')]; 
            }
            else curr = curr->children[(int)(key[i]-'a')]; 
        }
        curr->value = val; 
    }
    
    int inner_sum(TrieNode_t *curr){
        if(curr == NULL) return 0; 
        
        int ret = curr->value; 
        for(int i = 0; i < ALPHABET_SIZE; i++)
            ret += inner_sum(curr->children[i]); 
        
        return ret; 
    }
    
    
    int sum(string prefix) {
        TrieNode_t *curr = root; 
        for(int i = 0; i < prefix.size(); i++){
            if(curr->children[(int)(prefix[i]-'a')] == NULL){
                return 0; 
            }
            else curr = curr->children[(int)(prefix[i]-'a')]; 
        }
        return inner_sum(curr); 
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
