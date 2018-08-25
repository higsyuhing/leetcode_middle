class Solution(object):
    def generateParenthesis(self, N):
        """
        :type n: int
        :rtype: List[str]
        """
        # the solution is quite good. star this question. 
        ans = []
        def backtrack(S = '', left = 0, right = 0):
            print S
            if len(S) == 2 * N:
                ans.append(S)
                return
            if left < N:
                backtrack(S+'(', left+1, right)
            if right < left:
                backtrack(S+')', left, right+1)

        backtrack()
        return ans
    
        '''
        arr = []
        for i in range(n): 
            arr.append("(")
            pass
        for i in range(n): 
            arr.append(")")
            pass
        '''
        
        
        
        
            
