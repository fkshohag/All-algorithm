class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # [2:0] binary prefix 0b that is the reason for starting 2 number index
        return str(bin(int(a, 2) + int(b, 2)))[2:]