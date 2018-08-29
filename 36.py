class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        dic = {}
        # check rows
        for row in board: 
            for char in row: 
                if char != ".": 
                    if not dic.has_key(char): 
                        dic[char] = 1
                        pass
                    else: 
                        return False
                    pass
                pass
            dic.clear()
            pass
        # check cols
        for i in range(9): 
            for j in range(9): 
                char = board[j][i]
                if char != ".": 
                    if not dic.has_key(char): 
                        dic[char] = 1
                        pass
                    else: 
                        return False
                    pass
                pass
            dic.clear()
            pass
        # check central 9
        for i in range(3): 
            for j in range(3): 
                for ii in range(3): 
                    for jj in range(3): 
                        x = 3*i + ii
                        y = 3*j + jj
                        char = board[x][y]
                        if char != ".": 
                            if not dic.has_key(char): 
                                dic[char] = 1
                                pass
                            else: 
                                return False
                            pass
                        pass
                    pass
                dic.clear()
                pass
            pass
        return True
        
        
        
        
        
        
        
        
        
                    
