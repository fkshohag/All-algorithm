from typing import List

# TL NOT solved 

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) > 1:
            mid = len(nums) // 2
            leftList = self.sortArray(nums[:mid])
            rightList = self.sortArray(nums[mid:])
            return self.merge(leftList, rightList)
        else:
            return nums

    def merge(self, leftList: List[int], rightList: List[int]) -> List[int]:
        i, j = 0, 0
        newList: List[int] = []
        while i < len(leftList) and j < len(rightList):
            if leftList[i] < rightList[j]:
                newList.append(leftList[i])
                i += 1
            else:
                newList.append(rightList[j])
                j += 1
        while i < len(leftList):
            newList.append(leftList[i])
            i += 1
        while j < len(rightList):
            newList.append(rightList[j])
        return newList 