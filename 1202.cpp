class Solution {
    int find(vector<int>& parents, int i) {
        return parents[i] < 0 ? i : parents[i] = find(parents, parents[i]);
    }
public:    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parents(s.size(), -1);
        vector<vector<int>> m(s.size());
        for (auto& p : pairs) {
            auto i = find(parents, p[0]), j = find(parents, p[1]);
            if (i != j) parents[j] = i;
        }
        for (auto i = 0; i < s.size(); ++i) m[find(parents, i)].push_back(i);
        for (auto ids : m) {
            string ss = "";
            for (auto id : ids) ss += s[id];
            sort(begin(ss), end(ss));
            for (auto i = 0; i < ids.size(); ++i) s[ids[i]] = ss[i];
        }
        return s;
    }
};

/*
class Solution {
public:
    vector<int> v;
    set<int> st;
    void neighbours(vector<vector<int>> &graph, int index)
    {
        v.push_back(index);
        st.insert(index);
        for(int i=0; i<graph[index].size(); i++)
        {
            if(!st.count(graph[index][i]))
                neighbours(graph, graph[index][i]);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> graph(s.size());
        for(int i=0; i<pairs.size(); i++)
        {
            graph[pairs[i][0]].push_back(pairs[i][1]);
            graph[pairs[i][1]].push_back(pairs[i][0]);
        }
        for(int i=0; i<graph.size(); i++)
        {
            if(st.count(i)!=0)
                continue;
            neighbours(graph, i);
            if(v.size()>1)
            {
                string p = "";
                for(int j=0; j<v.size(); j++)
                    p += s[v[j]];
                sort(p.begin(), p.end()); 
                sort(v.begin(), v.end()); 
                for(int j=0; j<v.size(); j++)
                    s[v[j]] = p[j];
            }
            v.clear();
        }
       return s; 
    }
    
    
    
    
    
    
    typedef struct{
        //int group; 
        int state; // 0:unexplored, 1:curr, 2:done grouped
        vector<int> *edges; 
    } pairinfo_t; 
    
    void DFScheck(vector<pairinfo_t>& swapinfo, int i){
        if(swapinfo[i].state == 2){
            cout << "state is 2?? " << i << endl; 
            exit(1); 
        }
        swapinfo[i].state = 1; 
        for(auto it = swapinfo[i].edges->begin(); 
            it != swapinfo[i].edges->end(); ++it){
            if(swapinfo[*it].state == 0)
                DFScheck(swapinfo, *it); 
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // union find, these pairs will construct a swapping groups
        // all char position in this swapping group can freely swapped
        
        vector<pairinfo_t> swapinfo; 
        swapinfo.reserve(s.size()); 
        
        for(int i = 0; i < s.size(); i++){
            //swapinfo[i].group = i; 
            swapinfo[i].state = 0; 
            swapinfo[i].edges = new vector<int>(); 
        }
        
        // install edges
        for(int i = 0; i < pairs.size(); i++){
            int a = pairs[i][0]; 
            int b = pairs[i][1]; 
            swapinfo[a].edges->push_back(b); 
            swapinfo[b].edges->push_back(a); 
        }
        
        vector<unsigned> charlist; 
        vector<int> poslist; 
        for(int i = 0; i < s.size(); i++){
            if(swapinfo[i].state == 0)
                DFScheck(swapinfo, i); 
            else continue; 
            
            // label all state 1 with group i. 
            // i is the smallest one.. 
            //for(int j = 0; j < s.size(); j++){
            //    if(swapinfo[j].state == 1){
            //        swapinfo[j].state = 2; 
            //        swapinfo[j].group = i; 
            //    }
            //}
            
            // I can directly work on it.. 
            // now the current gourp is labed as state==1
            // I need their position, and ordered char list.. 
            charlist.clear(); 
            poslist.clear(); 
            for(int j = i; j < s.size(); j++){
                if(swapinfo[j].state == 1){
                    swapinfo[j].state = 2; 
                    poslist.push_back(j); // it's in-ordered
                    charlist.push_back((unsigned)s[j]); 
                }
            }
            sort(charlist.begin(), charlist.end()); 
            for(int j = 0; j < poslist.size(); j++){
                int pos = poslist[j];
                s[pos] = (char)charlist[j]; 
            }
            
        }
        
        return s; 
    }
};

*/
