"""
Md.Shohag <shohag.fks@gmail.com>
https://leetcode.com/problems/all-paths-from-source-to-target/description/
Time complexity O(N)
Space complexity O(N)
"""

class Solution(object):
    def wordPattern(self, pattern, s):
        words = s.split(" ")
        if len(pattern) != len(words):
            return False
        char_map = {}
        word_map = {}

        for c, w in zip(pattern, words):
            if c not in char_map:
                if w in word_map:
                    return False
                else:
                    word_map[w] = c
                    char_map[c] = w
            else:
                if char_map[c] != w:
                    return False
        return True