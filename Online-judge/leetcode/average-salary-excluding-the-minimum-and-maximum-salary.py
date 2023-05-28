class Solution:
    def average(self, salary: List[int]) -> float:
        mx = float('-inf')
        mn = float('inf')
        summation = 0
        for s in salary:
            summation += s
            if s > mx:
                mx = s
            if s < mn:
                mn = s
        return (summation - (mx + mn)) / (len(salary) - 2)