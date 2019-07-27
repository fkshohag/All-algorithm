# include <stdio.h>
# include <string.h>
int dp[100][100];

int power(int x, int n) {
	int y;
	if(n == 0) return 1;
	if(n % 2 == 0){
		y = power(x, n/2);
		return y * y;
	}else {
		return x * power(x, n-1);
	}
}
int fact(int n){
	if (n == 0 || n == 1) return 1;
	return n*fact(n-1);
}

int nCr(int n, int r){
	if(n == r) return 1;
	if(r == 1) return n;
	if(dp[n][r] != -1) return dp[n][r];
	return dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1); 
}

int main() {
	memset(dp, -1, sizeof(dp));
	int x, n;
	scanf("%d %d", &x, &n);
	printf(" x^n = %d\n n! = %d\n nCr = %d\n nPr = %d\n", power(x, n), fact(n), nCr(x, n), fact(x)/fact(x-n));
	return 0;
}
