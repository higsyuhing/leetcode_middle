class Solution(object):
    def func(self, cutting, ele): 
        #print cutting, ele
        start = 0 # avail
        end = len(cutting) # not avail
        while start < end: 
            mid = (start + end)/2
            if cutting[mid][0] < ele[0]: 
                start = mid + 1
                pass
            elif cutting[mid][0] > ele[0]: 
                end = mid
                pass
            else: 
                start = mid
                end = mid
                pass
            pass
        #print start, end
        if start != end: 
            print "Error? "
            return cutting
        else: 
            if start == len(cutting): 
                cutting.append(ele)
                return cutting
            if start == 0: 
                cutting.insert(0, ele)
                return cutting
            cutting.insert(start, ele)
            return cutting
        pass
    
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        n = len(matrix)
        cutting = []
        cutting.append([matrix[0][0], 0, 0])
        dicrow = {}
        diccol = {}
        dicrow[0] = [0,0]
        diccol[0] = [0,0]
        count = 0
        while count < (k-1): 
            source = cutting[0]
            del cutting[0]
            del dicrow[source[1]]
            del diccol[source[2]]
            i = source[1] + 1
            j = source[2]
            if i < n and (not dicrow.has_key(i)): 
                ele = [matrix[i][j], i, j]
                self.func(cutting, ele)
                dicrow[i] = [i,j]
                diccol[j] = [i,j]
                pass
            i = source[1]
            j = source[2] + 1
            if j < n and (not diccol.has_key(j)): 
                ele = [matrix[i][j], i, j]
                self.func(cutting, ele)
                dicrow[i] = [i,j]
                diccol[j] = [i,j]
                pass
            count += 1
            pass
        return cutting[0][0]
        
        
        
        '''
        n = len(matrix)
        c = 0
        flag = -1
        flag1 = -1
        for i in range(n): 
            index = i + 1
            c += index
            if k <= c: 
                flag = i # i + j
                flag1 = c - index # the order after the last row|col
                break
                pass
            pass
        if flag == -1: 
            for i in range(n-1): 
                index = n-1 - i
                c += index
                if k <= c: 
                    flag = n + i
                    flag1 = c - index
                    break
                    pass
                pass
            pass
        print flag, flag1
        arr = []
        for i in range(n): 
            j = flag - i
            if j < 0 or j >= n: 
                continue
                pass
            arr.append(matrix[i][j])
            pass
        print arr
        arr.sort()
        #return 0
        return arr[k-flag1-1]
        '''
        
        '''
        # this solution, start with [min, max)
        # use binary search to count each side.. 
        l, r = matrix[0][0], matrix[-1][-1] + 1
        
        while l < r:
            m = (r - l) / 2 + l
            
            count = 0
            for i in range(len(matrix)):
                count += bisect.bisect_right(matrix[i], m)
            
            if count >= k:
                r = m
            else:
                l = m + 1
        
        return l
        '''
