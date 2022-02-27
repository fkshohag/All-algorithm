# include <iostream>
# include <cstdio>
# include <algorithm>
# include <vector>

# define ll long long
# define pb push_back


using namespace std;

ll data[100000+1];


int main() {
	// freopen("./../in.txt", "r", stdin);

	ll t, n;
	vector<ll>v1,v2, odd, even;
	scanf("%lld", &t);

	for(ll test = 0; test < t; test++) {
		scanf("%lld", &n);

		for(ll index = 0; index < n; index++) {
			scanf("%lld", &data[index]);

			if (data[index] % 2 == 0) {
				even.pb(data[index]);
				v2.pb(data[index]);
			} else {
				odd.pb(data[index]);
				v1.pb(data[index]);
			}
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		if (v1 == odd && v2 == even) {
			printf("%s", "Yes\n");
		} else {
			printf("%s", "No\n");
		}

		v1.clear(); v2.clear(); odd.clear(); even.clear();
	}

	return 0;
}