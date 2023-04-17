from typing import List

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        pairs: List[int] = []
        for spell in spells:
            count = 0
            for p in potions:
                product = spell * p
                if (product >= success):
                    count += 1
            pairs.append(count)
        return pairs

'''
Time complexity O((m+n)*logm)
Space complexity O(M) for sorting space  
'''
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        pairs: List[int] = []
        m = len(potions)
        potions.sort()
        for spell in spells:
            left, right = 0, m
            while left < right:
                mid =  left + (right - left) // 2
                product = spell * potions[mid]
                if product >= success:
                    right = mid
                else:
                    left = mid + 1
            pairs.append(m - left)
        return pairs