class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> hash; 
        for (int val : nums){
            if (hash.count(val) == 0){
                hash[val] = 1; 
            }
            else{
                hash[val]++; 
            }
        }

        vector<vector<int>> ret; 
        for (auto itx = hash.begin(); itx != hash.end(); itx++){
            for (auto ity = itx; ity != hash.end(); ity++){
                int keyx = itx->first; 
                int keyy = ity->first; 
                int keyz = -keyx-keyy; 
                if (hash.count(keyz) != 0 && keyz >= keyy){
                    if (keyx != keyy && keyy != keyz && keyz != keyx){
                        vector<int> tmp(3, 0); 
                        tmp[0] = keyx; tmp[1] = keyy; tmp[2] = keyz; 
                        ret.push_back(tmp); 
                    }
                    else if (keyx == keyy && keyy != keyz && hash[keyx] >= 2){
                        vector<int> tmp(3, 0); 
                        tmp[0] = keyx; tmp[1] = keyy; tmp[2] = keyz; 
                        ret.push_back(tmp); 
                    }
                    else if (keyx != keyy && (keyy == keyz || keyx == keyz) && hash[keyz] >= 2){
                        vector<int> tmp(3, 0); 
                        tmp[0] = keyx; tmp[1] = keyy; tmp[2] = keyz; 
                        ret.push_back(tmp); 
                    }
                    else if (keyx == keyy && keyy == keyz && hash[keyz] >= 3){
                        vector<int> tmp(3, 0); 
                        tmp[0] = keyx; tmp[1] = keyy; tmp[2] = keyz; 
                        ret.push_back(tmp); 
                    }
                }
            }
        }
        return ret; 
    }
};
