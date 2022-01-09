# include <cstdio>
# include <iostream>
using namespace std;
int main() {
	//freopen("in.text", "r", stdin);
	int T, n;
	scanf("%d ", &T);
	for(int i = 1; i <= T; i++) {
		scanf("%d", &n);
		if (n <= 10) 
			printf("%d %d\n",n, 0);
		else
			printf("%d %d\n",10, n-10);
	}
	return 0;
}
