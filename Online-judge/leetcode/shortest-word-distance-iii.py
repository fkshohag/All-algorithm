from typing import List

class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        ans = float("inf")
        startIndex, endIndex = None, None
        for index, word in enumerate(wordsDict):
            if word == word1:
                if endIndex is not None:
                    ans = min(ans, index - endIndex)
                if word1 == word2:
                    endIndex = index
                    continue
                startIndex = index
            if word == word2:
                if startIndex is not None:
                    ans = min(ans, index - startIndex)
                endIndex = index
        return ans