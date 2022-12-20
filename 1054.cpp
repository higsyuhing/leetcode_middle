class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> hash; 
        for (int& code : barcodes){
            if (hash.count(code) == 0){
                hash[code] = 1; 
            }
            else{
                hash[code]++; 
            }
        }
        vector<pair<int, int>> histo(hash.size(), make_pair(0, 0)); 
        int i = 0; 
        for (auto it = hash.begin(); it != hash.end(); it++){
            histo[i].first = it->second; // freq
            histo[i].second = it->first; // code
            i++; 
        }
        sort(histo.begin(), histo.end()); 

        // for (int i = 0; i < histo.size(); i++){
        //     cout << histo[i].first << ", " << histo[i].second << endl; 
        // }

        vector<int> ret; 
        ret.reserve(barcodes.size()); 

        // init install
        auto rit = histo.rbegin(); 
        int freq = rit->first; 
        vector<int> tmp; 
        vector<vector<int>> array(freq, tmp); 
        int pos = 0; 
        for (; rit != histo.rend(); rit++){
            int currfreq = rit->first; 
            int code = rit->second; 
            for (int i = 0; i < currfreq; i++){
                array[pos].push_back(code); 
                pos = (pos + 1) % freq; 
            }
        }
        for (vector<int>& vec : array){
            ret.insert(ret.end(), vec.begin(), vec.end()); 
        }

        return ret; 
    }
};


