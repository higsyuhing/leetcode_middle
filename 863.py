# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distanceK(self, root, target, K):
        def dfs(node, par = None):
            if node:
                node.par = par
                dfs(node.left, node)
                dfs(node.right, node)

        dfs(root)

        queue = collections.deque([(target, 0)])
        seen = {target}
        while queue:
            if queue[0][1] == K:
                return [node.val for node, d in queue]
            node, d = queue.popleft()
            for nei in (node.left, node.right, node.par):
                if nei and nei not in seen:
                    seen.add(nei)
                    queue.append((nei, d+1))

        return []
    
'''
class Solution {
public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        // record parent in a hashmap, then perform bfs.. 
        
        
        /*
        // two traverse, starting from target or starting from
        // no.. if 5 is in right subtree, left will not get searched.. 
        
        // traverse to find target, using a stack keeping the trace
        // also a hashtable to maintain the trace node
        
        stack<TreeNode*> trace; 
        map<TreeNode*, int> checkmap; 
        
        // find target
        
        // traverse from the beginning
        
        */
        
        
    }
};
'''
