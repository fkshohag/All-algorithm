# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# define ll long long
using namespace std;
vector<ll> point;

int main() {
	//freopen("input.text", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++) {
		ll N, q;
		point.clear();
		scanf("%lld %lld", &N, &q);
		for(ll i = 1; i <= N; i++) {
			ll x;
			scanf("%lld", &x);
			point.push_back(x);
		}
		printf("Case %d:\n", k);
		for(ll i = 1; i <= q; i++) {
			ll x, y;
			scanf("%lld %lld", &x, &y);
			x = lower_bound(point.begin(), point.end(), x) - point.begin();
			y = upper_bound(point.begin(), point.end(), y) - point.begin();
			printf("%lld\n", y - x);
		}
	}
	return 0;
}
