class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // first we resolve each number with a double.. 
        // then we evaluate queries.. 

        map<string, vector<int>> relationmap; // var is used in which equation
        map<string, pair<double, int>> valuemap; // var relative value, init with -1, graph id
        unordered_set<string> remainset; // helper set for the next remaining var

        for (int i = 0; i < equations.size(); i++){
            auto& equation = equations[i]; 
            string& a = equation[0]; 
            string& b = equation[1]; 
            
            if (remainset.count(a) == 0){
                remainset.insert(a); 
                valuemap[a] = make_pair(-1.0, -1); 
            }
            if (remainset.count(b) == 0){
                remainset.insert(b); 
                valuemap[b] = make_pair(-1.0, -1); 
            }

            if (relationmap.count(a) == 0){
                vector<int> tmp; 
                tmp.push_back(i); 
                relationmap[a] = tmp; 
            }
            else{
                relationmap[a].push_back(i); 
            }
            if (relationmap.count(b) == 0){
                vector<int> tmp; 
                tmp.push_back(i); 
                relationmap[b] = tmp; 
            }
            else{
                relationmap[b].push_back(i); 
            }
        }

        queue<string> procqueue; 
        int graphid = 0; 
        while (!remainset.empty()){ // each independent graph
            graphid++; 
            const string &head = *remainset.begin(); 
            valuemap[head] = make_pair(1.0, graphid); // init val

            procqueue.push(head); 
            while (!procqueue.empty()){
                // in queue, we always have value, but not sure visited ot not
                string curr = procqueue.front(); 
                procqueue.pop(); 

                // we have value and visited, pass
                if (remainset.count(curr) == 0)
                    continue; 
                // we have value, but not check my related vars
                remainset.erase(curr); 

                // compute all its relative's value
                for (int i : relationmap[curr]){
                    auto& equation = equations[i]; 
                    if (equation[0] == curr){
                        valuemap[equation[1]] = make_pair(valuemap[curr].first/values[i], graphid); 
                        procqueue.push(equation[1]); 
                    }
                    else{
                        valuemap[equation[0]] = make_pair(valuemap[curr].first*values[i], graphid); 
                        procqueue.push(equation[0]); 
                    }
                }
                
            }
        }

        vector<double> ret; 
        for (auto& query : queries){
            string& a = query[0]; 
            string& b = query[1]; 

            if ((valuemap.count(a) == 0) || (valuemap.count(b) == 0)){
                ret.push_back(-1.0); 
                continue; 
            }
            if (valuemap[a].second != valuemap[b].second){
                ret.push_back(-1.0); 
                continue; 
            }

            else{
                double vala = valuemap[a].first; 
                double valb = valuemap[b].first; 
                ret.push_back(vala/valb); 
            }
        }

        return ret; 
    }
};
