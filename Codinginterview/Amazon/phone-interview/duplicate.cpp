#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 3, 2, 1, 1, 1, 1};
    sort(v.begin(), v.end());
    
    map<int, int> freq;
    for (int value : v) {
        freq[value]++;
    }
    for (auto it : freq) {
        if (it.second > 1) {
            cout << " " << it.first;
        }
    }

    return 0;
}