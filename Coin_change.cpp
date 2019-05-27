# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

int coin[] = {0, 12, 5}, possible[1000];

int main() {
	int n = 15;
	int len = 2;
	possible[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= len; j++)
			if(i >= coin[j])
				possible[i] += possible[i-coin[j]];
	printf("%d\n", possible[15]);
}
