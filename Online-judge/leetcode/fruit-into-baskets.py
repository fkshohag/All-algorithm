from collections import defaultdict


class Solution(object):
    def totalFruit(self, fruits):
        mp = defaultdict(int)
        i = j = ans = 0
        while j < len(fruits):
            mp[fruits[j]] += 1
            if len(mp) > 2:
                mp[fruits[i]] -= 1
                if mp[fruits[i]] == 0:
                    del mp[fruits[i]]
                i +=1
            ans = max(ans, j-i+1)
            j +=1
        return ans