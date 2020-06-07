class Solution {
public:
    double BFS(string src, string dest, unordered_map < string, vector < pair < string, double >>> graph) {
   queue < pair < string, double >> q;
   unordered_set < string > visited;
   if (graph.count(src) > 0)
     q.push({
       src,
       1.0
     });
   visited.insert(src);
   while (!q.empty()) {
     int size = q.size();
     for (int i = 0; i < size; i++) {
       pair < string, double > temp = q.front();
       // cout<<temp.first<<endl;
       if (temp.first == dest)
         return temp.second;
       q.pop();
       for (int i = 0; i < graph[temp.first].size(); i++) {
         if (visited.find(graph[temp.first][i].first) == visited.end()) {
           visited.insert(graph[temp.first][i].first);
           q.push({
             graph[temp.first][i].first,
             temp.second * graph[temp.first][i].second
           });
         }
       }
     }
   }
   return -1.0;

 }

 vector < double > calcEquation(vector < vector < string >> & equations, vector < double > & values, vector < vector < string >> & queries) {
   unordered_map < string, vector < pair < string, double >>> graph;

   for (int i = 0; i < equations.size(); i++) {
     graph[equations[i][0]].push_back({
       equations[i][1],
       values[i]
     });
     graph[equations[i][1]].push_back({
       equations[i][0],
       (1 / values[i])
     });
   }
   vector < double > ans;

   for (int i = 0; i < queries.size(); i++) {
     double answer = BFS(queries[i][0], queries[i][1], graph);
     ans.push_back(answer);
   }
   return ans;
 }
};

/* 
This answer is really cool!! 

*/
