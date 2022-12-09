class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // sort does not matter. -> no need for sort
        // then use hash table for (num, occurrence)
        // then Cxx combination
        map<int, int> hash; // we need the order
        for (int val : arr){
            if (hash.count(val) == 0){
                hash[val] = 1; 
            }
            else{
                hash[val]++; 
            }
        }

        long long ret = 0; 
        long long MOD = 1000000007; 
        for (auto itx = hash.begin(); itx != hash.end(); itx++){
            for (auto ity = itx; ity != hash.end(); ity++){
                //// should not have this for loop, just directly looking for itz key with target-itx-ity
                for (auto itz = ity; itz != hash.end(); itz++){
                    int val = itx->first + ity->first + itz->first; 
                    if (val == target){
                        if (itx != ity && ity != itz){
                            ret += (1LL*itx->second*ity->second*itz->second); 
                            ret = ret % MOD; 
                        }
                        else if (itx != ity && ity == itz){
                            if (itz->second >= 2){
                                ret += (1LL*itx->second*(ity->second-1)*ity->second/2); 
                                ret = ret % MOD; 
                            }
                        }
                        else if (itx == ity && ity != itz){
                            if (ity->second >= 2){
                                ret += (1LL*itz->second*(ity->second-1)*ity->second/2); 
                                ret = ret % MOD; 
                            }
                        }
                        else if (itx == itz){
                            if (ity->second >= 3){
                                ret += (1LL*(itz->second-2)*(ity->second-1)*ity->second/6); 
                                ret = ret % MOD; 
                            }
                        }

                        break; // further will never hit target
                    }
                }
            }
        }

        return ret; 
    }
};
