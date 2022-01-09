class Solution(object):
    def longestPalindrome(self, s):
        
        length = len(s)
        _solution = ''
        if length < 2:
            return s
        dp = [[False for i in range(length+1)] for j in range(length+1)]

        for i in range(length):
            for j in range(i,-1,-1):
                if s[j] == s[i]:
                    dp[i][j] = dp[i-1][j+1] if i-j > 2 else True
                if dp[i][j]:
                    if len(_solution) < (i-j+1):
                        _solution = s[j:i+1]
        return _solution
