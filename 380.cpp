class RandomizedSet {
public:
    map<int, int> hashmap; 
    vector<int> array; 
    
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashmap.find(val) == hashmap.end()){
            array.push_back(val); 
            hashmap[val] = array.size()-1; 
            return true; 
        }
        return false; 
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashmap.find(val) == hashmap.end()){
            return false; 
        }
        int index = hashmap[val]; //pos in middle
        int swapval = array[array.size()-1]; //val to the last ele
        hashmap[swapval] = index; 
        array[index] = swapval; 
        array.pop_back(); 
        hashmap.erase(val); 
        return true; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // if larger than 32767, this code should be updated
        int pos = rand()%(array.size()); 
        return array[pos]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
