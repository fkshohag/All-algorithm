# include <stdio.h>
int dp[1000];
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0; dp[1] = 1;
	printf("%d %d ",dp[0], dp[1]);
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
		printf("%d ", dp[i]);
	}
	return 0;
}
