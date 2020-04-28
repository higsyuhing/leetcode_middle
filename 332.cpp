class Solution {
public:
    vector<string> r;
    
    bool dfs(unordered_map<string, vector<string>> &m, string s, int size)
    {
        if(r.size() == size)
            return true;
        for(auto i = m[s].begin(); i != m[s].end(); ++i)
        {
            string sub_str = *i;
            r.push_back(sub_str);
            m[s].erase(i);
            if(dfs(m, sub_str, size))
                return true;
            m[s].insert(i, sub_str);
            r.pop_back();
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        // this question is so boring.. 
        
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < tickets.size(); ++i)
            m[tickets[i][0]].push_back(tickets[i][1]);
        for(auto i = m.begin(); i != m.end(); i++)
            sort(i->second.begin(), i->second.end());
        r.push_back("JFK");
        bool result = dfs(m, "JFK", tickets.size() + 1);
        return r;
    }
};
