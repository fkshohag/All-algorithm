# include <cstdio>
# include <iostream>
using namespace std;

int main() {
	freopen("in.text", "r", stdin);
	int T, k, n;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		int res = 0, one = 0;
		scanf("%d", &k);
		for(int i = 0; i < k; i++) {
			scanf("%d", &n);
			if(n == 1) one++;
			res ^= n; 
		}
		if(one != k) {
			if(res == 0) 
				printf("Case %d: Bob\n", i);
			else 
				printf("Case %d: Alice\n", i);
		} else {
			if(k % 2 != 0) 
			    printf("Case %d: Bob\n", i);
			else 
				printf("Case %d: Alice\n", i);
		}
	}
	return 0;
}
