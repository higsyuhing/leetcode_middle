class Solution {
public:
    //O(n)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string,string> Email_Names;
        unordered_map<string,string> List;
        for(auto it : accounts){
            for(int i = 1; i < it.size(); i++){
                Email_Names[it[i]] = it[0];
                List[it[i]] = it[i];
            }
        }
        //vector<vector<string>> edges;
        for(auto it : accounts){
            for(int i = 1; i < it.size(); i++){
                for(int j = i; j < it.size(); j++){
                    Union(List,it[i],it[j]);
                }
            }
        }
        ////
        unordered_map<string, vector<string>> filter;
        for(auto it : List){
            filter[Find_Root(List, it.second)].push_back(it.first);
        }
        ////
        for(auto it : filter){
            vector<string> tmp;
            tmp.push_back(Email_Names[it.first]);
            sort(it.second.begin(), it.second.end(), [](const string& a, const string& b)->bool{
                return a < b;
            });
            for(auto v : it.second){
                tmp.push_back(v);
            }
            res.push_back(tmp);
        }
        return res;
    }
    //O(n)
    string Find_Root(unordered_map<string,string>& List, string a){
        string r = a;
        while(r != List.at(r)){
            r = List.at(r);
        }
        //compression
        string b = a;
        while(List.at(b) != r){
            string tmp = b;
            b = List[b];
            List[tmp] = r;
        }
        return r;
    }
    //O(1)
    void Union(unordered_map<string, string>& List, string a, string b){
        string Root_A = Find_Root(List, a);
        string Root_B = Find_Root(List, b);
        List[Root_A] = Root_B;    
    }
    //O(1)
    bool Connected(unordered_map<string,string>& List, string a, string b){
        string Root_A = Find_Root(List, a);
        string Root_B = Find_Root(List, b);     
        return Root_A == Root_B;
    }
    
};

/*
// the fastest solution. 

static int _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
private:
    int find(vector<int> &parent, int k) {
        if(parent[k]==k) return k;
        return find(parent,parent[k]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        vector<int> parent(accounts.size());
        for(int i=0;i<accounts.size();i++) parent[i] = i;
        unordered_map<string,int> m_res;
        for(int i=0;i<accounts.size();i++) {
            vector<string> a = accounts[i];
            for(int j=1;j<a.size();j++) {
                if(m_res.find(a[j])!=m_res.end()){//found in map
                    int p1 = find(parent, i);
                    int p2 = find(parent, m_res[a[j]]);
                    parent[p1]=p2;
                } else {
                    m_res[a[j]] = i;
                }
            }
        }
        unordered_map<int,vector<string>> res;
        for(auto e : m_res) {
            res[find(parent,e.second)].push_back(e.first);
        }
        
        for(auto e : res) {
            vector<string> emails = e.second;
            sort(emails.begin(),emails.end());
            emails.insert(emails.begin(),accounts[e.first][0]);
            ans.push_back(emails);
        }
        
        return ans;
    }
};

*/
