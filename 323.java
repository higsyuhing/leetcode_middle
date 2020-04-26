public class Solution {
// I'd say this is a coloring problem, instead of DFS. 

    public int countComponents(int n, int[][] edges) {
        int[] roots = new int[n];
        
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }
        
        for (int i = 0; i < edges.length; i++) {
            int r1 = find(roots, edges[i][0]);
            int r2 = find(roots, edges[i][1]);
            
            if (r1 != r2) {
                roots[r1] = r2;
                n--;
            }
        }
        
        return n;
    }
    
    private int find(int[] roots, int key) {
        while (roots[key] != key) {
            key = roots[key];
        }
        
        return key;
    }
}

/*
// the first slowdown is replacing the find function with recursive call.. this is bad of course
    public int findSet(int[] roots,int i){
        if(roots[i]==i)return i;//is top parent
        roots[i] = findSet(roots,roots[i]);//path compression(optional)
        return roots[i];
    }

// the second slowdown is using dfs/bfs to find all connected node. 
// https://www.youtube.com/watch?v=n0opsOWM_Kc

*/


