# include <cstdio>
# include <iostream>
using namespace std;
# define i64 long long
i64 M = 9;
i64 F(i64 N, i64 P) {
	if (P == 0) return 1;
	if(P % 2 == 0) {
		i64 ret = F(N, P/2);
		return  ((ret % M) * (ret % M)) % M;
	} else {
		return ((N%M) * (F(N, P-1) % M)) % M;
	}
}

int main() {
	printf("%d ", F(2,5));
}
