class Solution {
public:
    int findParent(int a, vector<int>& parent){
        if(parent[a]!=a)
            parent[a]=findParent(parent[a],parent);
        return parent[a];
    }
    bool merge(int a,int b, vector<int>& ranks, vector<int>& parent){
        int parent_a = findParent(a,parent);
        int parent_b = findParent(b,parent);
        if(parent_a == parent_b)
            return true;
        if(ranks[parent_a]>ranks[parent_b])
            parent[parent_b] = parent_a;
        else if(ranks[parent_a]<ranks[parent_b])
            parent[parent_a] = parent_b;
        else{
            parent[parent_b] = parent_a;
            ranks[parent_a]++;
        }
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // is this question: find all redundant lines, and connect remaining?? 
        
        vector<int> ranks(n,0);
        vector<int> parent(n);
        
        int componentCount = n;
        int extraCableCount = 0;
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0;i<connections.size();i++){
            bool isCycle = merge(connections[i][0],connections[i][1],ranks,parent);
            if(isCycle)
                extraCableCount++;
            else
                componentCount--;
        }
        
        if(extraCableCount+1>=componentCount)
            return componentCount-1;
        return -1;
    }
};
