class Solution(object):
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        dp = [0.0] * (N + W + 1)
        # dp[x] = the answer when Alice has x points
        for k in xrange(K, N + 1):
            dp[k] = 1.0

        S = min(N - K + 1, W)
        # S = dp[k+1] + dp[k+2] + ... + dp[k+W]
        for k in xrange(K - 1, -1, -1):
            dp[k] = S / float(W)
            S += dp[k] - dp[k + W]

        return dp[0]
    
    '''
        // 1st: [1, W], then P times [P, PW]
        // dp with [1, K+W-1]
        // dp [1, W] with init 1/W
        // e.g. P = 2, then: 
        //      window[1, W] apply to all dp [1,W]? 
    
    '''
