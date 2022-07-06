"""
 @author Md.Shohag <shohag.fks@gmail.com>
 Problem : https://leetcode.com/problems/roman-to-integer/submissions/
 O(n)
"""

symbolToValues = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000
}
class Solution(object):
    def romanToInt(self, s):
        _len = len(s)
        index = 0
        number = 0;
        while index < _len:
            if index + 1 < _len and symbolToValues[s[index]] < symbolToValues[s[index + 1]]:
                number +=  (symbolToValues[s[index + 1]] - symbolToValues[s[index]])
                index += 2
            else:
                number += symbolToValues[s[index]]
                index +=  1
        return number

s = Solution()
res =  s.romanToInt("MCMXCIV")
print(res)