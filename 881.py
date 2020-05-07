class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        #// decreasing order. 
        #// work on one and remaining limit. 
        #// at most 2 people....... 
        
        # slightly different. since starting from two sides will shorter
        # the time usage.. they are equal but needs demonstration.. 
        # but bounded by sorting.. 
        people.sort()
        i, j = 0, len(people) - 1
        ans = 0
        while i <= j:
            ans += 1
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
        return ans
        
