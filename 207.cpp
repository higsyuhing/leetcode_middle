class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // it's almost exactly same as lc210..
        // No, this is a topological sort.. :(
        // https://www.youtube.com/watch?v=M6SBePBMznU
        
        // ref from lc210
        
        // I see.. this is a tree problem.. post order traversal
        // but implemented in a hashmap
        
        // hashmap: <id, hashmap<int, int> prerequests>
        // constructing: for numCourses init, prerequisites fill-in hash
        // algorithm: while hashmap not empty: 
        // use bfs, dfs is too costly
        //              empty vector
        //              while for iteration, pick empty hashmap prerequests into vec
        //              if vector is empty, return []; 
        //                  // hashmap not empty but no direct selected course
        //              add vec into res, eliminate remaining hashmap
        
        // improved data structure: 
        // hashmap1: <id, vector<int> postrequests>
        //          // this course is the prereq of postreq
        // hashmap2: <id, prerequestnum>
        //          // direct course has 0, otherwise num of req
        // algorithm: while hashmap2 not empty: 
        //              empty vector
        //              for iteration, pick 0 prereq into vec
        //              if vect empty ret []
        //              add vec into res, eliminate hashmap2 of vect
        //              for each in hashmap1, hashmap2[i in postreq] --; 
        
        map<int, vector<int>> hashmap1; 
        map<int, int> hashmap2; 
        int i; 
        vector<int> tempvec; 
        for(i = 0; i < numCourses; i++){
            hashmap2[i] = 0; 
            hashmap1[i] = tempvec; 
        }
        for(i = 0; i < prerequisites.size(); i++){
            hashmap2[prerequisites[i][0]]++; //higher course, add prereq num
            hashmap1[prerequisites[i][1]].push_back(prerequisites[i][0]); 
                //lower course, add associated higher course
        }
        
        int tempi, j, tempj; 
        while(hashmap2.size() != 0){
            tempvec.clear(); 
            for(map<int,int>::iterator it = hashmap2.begin(); 
               it != hashmap2.end(); ++it){
                if(it->second == 0) tempvec.push_back(it->first); 
            }
            if(tempvec.size() == 0) return false; 
            
            for(i = 0; i < tempvec.size(); i++){
                tempi = tempvec[i]; 
                hashmap2.erase(tempi); 
                for(j = 0; j < hashmap1[tempi].size(); j++){
                    hashmap2[hashmap1[tempi][j]]--; 
                }
            }
        }
        
        return true; 
    }
};
