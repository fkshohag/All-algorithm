# include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum0 = 0;
        bool flag  = false;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                sum0++;
            } else if (x >= 2) {
                flag = true;
            }
        }

        if (sum0 <= (n + 1) / 2) {
            printf("0\n");
        } else if (flag || sum0 == n) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
    return 0;
}