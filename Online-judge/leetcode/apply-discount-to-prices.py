'''
Problem : https://leetcode.com/problems/apply-discount-to-prices/
T.C: O(N)
M.C: O(N)
'''

class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        prices = sentence.split()
        for index, word in enumerate(prices):
            if word[0] == '$' and str.isdigit(word[1:]):
                discount_price = (100 - discount) * int(word[1:]) / 100
                prices[index] = f'${discount_price:.2f}'
        return " ".join(prices)

        