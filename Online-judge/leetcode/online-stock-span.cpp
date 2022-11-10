# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/online-stock-span/description/
 * Running complexity O(n)
 * Memory complexity O(n)
*/

class StockSpanner {
private:
    stack<pair<int, int>>stock;
public:
    StockSpanner() {
        stock = stack<pair<int, int>>();
    }
    
    int next(int price) {
        int count = 1;
        while (!stock.empty() && stock.top().first <= price) {
            count += stock.top().second;
            stock.pop();
        }
        stock.push({price, count});
        return count;
    }
};