# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

int coin[] = {0, 12, 3}, possible[1000];

void solution(int p[]) {
	int n = 16;
	for(int i = 0; i < n; i++)
		printf("%d ", p[i]);
}

int main() {
	int n = 15;
	int len = 2;
	possible[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= len; j++) {
			if(i >= coin[j])
				possible[i] += possible[i-coin[j]];
		}
		solution(possible);
		printf("\n");
	}
	printf("%d\n", possible[15]);
	return 0;
}
