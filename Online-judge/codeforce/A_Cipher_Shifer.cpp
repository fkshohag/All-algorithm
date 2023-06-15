# include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        int index = 0;
        
        while (index < n) {
            int start = index;
            cout << s[index++];
            while (s[index++] != s[start]);
        }
        cout << endl;
    }
    return 0; 
}