"""
@author Md.Shohag <shohag.fks@gmail.com>
Problem : https://leetcode.com/problems/longest-substring-without-repeating-characters/
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        slow = rent = 0
        seen = {}
        for fast in range(0, len(s), 1):
            if s[fast] in seen.keys():
                slow = max(slow, seen[s[fast]]+1)
            seen[s[fast]] = fast
            rent = max(rent, fast - slow + 1)
        return rent
        
s = Solution()
rent = s.lengthOfLongestSubstring('pwwkew')
print(rent)