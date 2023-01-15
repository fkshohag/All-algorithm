class Solution:
    representative = {}
    def find(self, ch):
        if self.representative[ch] == ch:
            return self.representative[ch]
        self.representative[ch] = self.find(self.representative[ch])
        return self.representative[ch]
    
    def makeRepresentative(self, x, y):
        xx = self.find(x)
        yy = self.find(y)
        if xx == yy:
            return
        if xx < yy:
            self.representative[yy] = xx
        else:
            self.representative[xx] = yy
        
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        for i in range(ord('a'), ord('z')+1):
            self.representative[chr(i)] = chr(i)
        for index in range(len(s1)):
            self.makeRepresentative(s1[index], s2[index])
            
        ans = ''
        for index in range(len(baseStr)):
            ans += self.find(baseStr[index])
        return ans
