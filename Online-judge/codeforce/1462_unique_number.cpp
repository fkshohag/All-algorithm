# include <bits/stdc++.h>
# define ll long long
# define ull unsigned long long
# define pb push_back

using namespace std;

class Solution {
public:
    void uniqueNumber() {
        int T, n;
        scanf("%d", &T);

        while(T--) {
            int x = 9, sum = 0;
            string s;
            set<int> S;
            scanf("%d", &n);

            while (x > 0) {
                if (n - sum >= x) {
                    sum += x;
                    s += (x + '0');
                    S.insert(x);
                }
                x--;
            } 
            if (s.size() != S.size() || sum != n) {
                cout<<-1<<endl;
            } else {
                sort(s.begin(), s.end());
                cout<<s<<endl;
            }
        }
    }
};

int main() {
    // freopen("./../in.txt", "r", stdin);
    Solution s;
    s.uniqueNumber();
}
