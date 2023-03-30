# include <bits/stdc++.h> 
using namespace std;

int main() {
    set<int> s1 = {2, 3 ,4, 7, 5};
    set<int> s2 = {2, 4, 4, 5};
    set<int> s3;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
    auto it = s3.begin();
    while (it != s3.end()) {
        cout << *it << " ";
        *it++;
    }

    cout << endl;
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
    it = s3.begin();
    while (it != s3.end()) {
        cout << *it << " ";
        *it++;
    }
}