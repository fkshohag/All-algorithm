# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 * Time complexity : O(N) where N is the size of stack.
 * Space complexity : O(N) since we are not consuming additional space 
*/


class Solution {
private:
    typedef long long ll;
    bool isSymbol(string ch) {
        if ((ch.size() <= 1) && (ch == "+" || ch == "-" || ch == "*" || ch == "/")) {
            return true;
        }
        return false;
    }

    ll calculate(char op, ll a, ll b) {
        ll res = 0;
        switch (op) {
            case '+':
              res = a + b;
              break;
            case '-':
              res = a - b;
              break;
            case '/':
              res = (b == 0 ? INT_MAX : a / b);
              break;
            case '*':
              res = a * b;
              break;
            default:
              break;
        }
        return res;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> s;
        ll ans = 0;
        for (string token : tokens) {
            if (isSymbol(token)) {
                ll b = s.top(); s.pop();
                ll a = s.top(); s.pop();
                ans = calculate(token[0], a, b);
                s.push(ans);
            } else {
                ans = stoi(token);
                s.push(ans);
            }
        }
        return ans;
    }
};