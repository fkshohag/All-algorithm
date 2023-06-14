# include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> numbers;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '+') continue;
        int k = str[i] - '0';
        numbers.push_back(k);
    }
    sort(numbers.begin(), numbers.end());

    string res;
    for (int i = 0; i < numbers.size(); i++) {
        res += to_string(numbers[i]);
        if (i != numbers.size() - 1) {
            res += "+";
        }
    }
    
    cout << res;
}