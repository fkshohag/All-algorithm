# include <cstdio>
# include <iostream>
# include <algorithm>
# define ll long long
# define SIZE 100000
# define INF 1000000000
using namespace std;
ll arr[SIZE+1];
ll Tree[SIZE*2];

void init(ll node, ll left, ll right) {
	if(left == right){
		Tree[node] = arr[left];
		return;
	}
	ll _left = 2 * node;
	ll _right = (2 * node) + 1;
	ll _mid = (left + right) / 2;
	init(_left, left, _mid);
	init(_right, _mid+1, right);
	Tree[node] = min(Tree[_left], Tree[_right]);

}

ll query(ll node, ll left, ll right, ll i, ll j) {
	if(i > right || j < left) return INF; // outside the range
	else if(i <= left && j>= right) return Tree[node]; // inside the range
	ll _left = 2 * node;
	ll _right = (2 * node) + 1;
	ll _mid = (left + right) / 2;
	ll p1 =  query(_left, left, _mid, i, j);
	ll p2 = query(_right, _mid + 1, right, i, j);
	return min(p1, p2);
}

int main() {
	//freopen("input.text", "r", stdin);
	ll T;
	scanf("%lld", &T);
	for(ll t = 1; t <= T; t++) {
		ll N, q;
		scanf ("%lld %lld", &N, &q);
		for(ll i = 1; i <= N; i++){
			scanf("%lld", &arr[i]);
		}
		init(1, 1, N);
		printf("Case %lld:\n",t);
		for(ll k = 1; k <= q; k++) {
			ll i, j;
			scanf("%lld %lld", &i, &j);
			ll res = query(1, 1, N, i, j);
			printf("%lld\n", res);
		}
	}
	return 0;
}
