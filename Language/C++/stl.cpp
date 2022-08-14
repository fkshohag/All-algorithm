// Online C++ compiler to run C++ program online
# include <iostream>
# include <set>
# include <cstdio>
# include <vector>
# include <queue>
# include <stack>
# include <utility>
# include <tuple>
# include <algorithm>
# include <numeric>
using namespace std;

int main() {
    int data[] = {1, 2, 3, 4, 5, 24, 2, 4, 67, 35};
    int size = sizeof(data) / sizeof(data[0]);

    vector<int>v(data, data+size);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());

    cout << *max_element(v.begin(), v.end()) << endl;
    cout << *min_element(v.begin(), v.end()) << endl;
    cout << accumulate(v.begin(), v.end(), 0);
    
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    
    cout << distance(v.begin(), max_element(v.begin(), v.end()));
    return 0;
}