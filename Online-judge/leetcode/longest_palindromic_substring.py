class Solution(object):
    def longestPalindrome(self, s):

        length = len(s)
        if length < 0:
            return s
        longestString=''
        longestStringLength = 0

        for index in range(0, length):

            left ,right = self.expandPalindrome(s, length, index, index)
            _left ,_right = self.expandPalindrome(s, length, index, index+1)
            mx = len(s[left:right])
            _mx = len(s[_left:_right])

            if mx > _mx:
                if mx > longestStringLength:
                    longestString = s[left:right]
                    longestStringLength = mx
            else:
                if _mx > longestStringLength:
                    longestString = s[_left:_right]
                    longestStringLength = _mx
        return longestString

    def expandPalindrome(self, word, length, left, right):
        _left, _right = left, right
        
        while _left >= 0 and _right < length and word[_left] == word[_right]:
            _left -= 1
            _right += 1
        return _left+1, _right
