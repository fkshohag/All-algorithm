# include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 2) {
        printf("NO");
    } else if (n % 2 == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
