# include <bits/stdc++.h>
# define ll long long
# define ull unsigned long long
# define pb push_back

using namespace std;

string solve(vector<int>& elements) {
    int n = elements.size();
    int i = 0;
    int j = n - 1;

    while (i < n - 1 && elements[i] <= elements[i + 1]) {
        i++;
    }

    while (j > i && elements[j] >= elements[j - 1]) {
        j--;
    }

    if (i == j) {
        return "NO";
    }

    return "YES";
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> elements(n);

        for (int i = 0; i < n; i++) {
            cin >> elements[i];
        }

        string ans = solve(elements);
        elements.clear();
        cout << ans << endl;
    }
    return 0;
}