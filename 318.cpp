class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        int n=words.size(),i,j,k;
        vector<int>arr(n,0);
        for(i=0;i<n;i++)
        {
            string  str=words[i];
            int bitwise=0;
            for(j=0;j<str.size();j++)
            {
                int bit_idx=str[j]-'a';
                bitwise=bitwise|(1<<bit_idx);
            }
            arr[i]=bitwise;
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(!(arr[i]&arr[j]))
                {
                    int l1=words[i].size();
                    int l2=words[j].size();
                    ans=max(ans,l1*l2);
                }
            }
        }
        return ans;
    }
};


/*
// exactly same idea, and he shows the O(n^2) comparison to find the maximum
// is there any better solution? 

class Solution {
public:
    int inner_computehash(string& word){
        // returns hash key, hash value can easily get computed by word.size()
        int key = 0; 
        for(char c:word){
            key |= (1 << (int)(c - 'a')); 
        }
        return key; 
    }
    
    int maxProduct(vector<string>& words) {
        // since only 26 chars, we can create a hash: 
        //  a->1, b->2, c->4, .., z->1<<25, value with the length of words
        // the hash only keeps the maximum length. 
        //  i.e. with 'aa', 'a' will not counted
        
        map<int, int> hash; 
        for(string word : words){
            int key = 0; 
            for(char c : word){
                key |= (1 << (int)(c - 'a')); 
            }
            if(hash.find(key) == hash.end()){
                hash[key] = word.size(); 
            }
            else{
                if(hash[key] < word.size())
                    hash[key] = word.size(); 
            }
        }
        
        // if 2 keys are AND to 0, that means no common letters
        int ret = 0; 
        
        
        
        
        
        
    }
};
*/


