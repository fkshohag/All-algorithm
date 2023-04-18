'''
Time complexity: O(n + m)
Space complexity: O(1) 
'''

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n, m = len(word1), len(word2)
        i, j = 0, 0
        s = ""
        while i < n and j < m:
            s += word1[i] + word2[j]
            i += 1
            j += 1
        if m > n:
            while j < m:
                s += word2[j]
                j += 1
        else:
            while i < n:
                s += word1[i]
                i += 1
        return s