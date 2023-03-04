class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) > len(haystack):
            return - 1
        elif len(needle) < 1:
            return 0
        elif haystack == needle:
            return 0
        for index in range(len(haystack) - len(needle) + 1):
            sub_string = haystack[index : index + len(needle)]
            if sub_string == needle:
                return index
        return -1