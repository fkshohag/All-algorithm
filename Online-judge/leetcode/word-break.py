from typing import List

'''
* @author Md.Shohag <shohag.fks@gmail.com>
* Problem : https://leetcode.com/problems/word-break/description/
* Time Complexity: O(N)
* Space Complexity: O(N)
'''

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break
        return dp[n]