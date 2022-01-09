# include <cstdio>
# include <iostream>
using namespace std;
# define ll long long
int main() {
	//freopen("in.text", "r", stdin);
	int T, m, n;
	ll number, sum, ans;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++) {
		scanf("%d %d", &m, &n);
		ans = 0;
		for(int i = 0; i < m; i++) {
			sum = 0;
			for(int j = 0; j < n; j++) {
				scanf("%lld", &number);
				sum += number;
			}
			ans ^= sum;
		}
		if(ans > 0) 
			printf("Case %d: Alice\n", k);
		else 
			printf("Case %d: Bob\n", k);

	}
	return 0;
}
