# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

int dp[100][100];

int max(int a, int b) {
	return a > b ? a: b;
}

int knapSack(int maxWeight, int weight[], int profit[], int n) {
	if(maxWeight == 0 || n == 0) return 0;
	if(dp[maxWeight][n-1] != -1) return dp[maxWeight][n-1];
	else if(weight[n-1] > maxWeight) return dp[maxWeight][n-1] = knapSack(maxWeight, weight, profit, n-1);
	else {
		dp[maxWeight - weight[n-1]][n-1] = profit[n-1] + knapSack(maxWeight - weight[n-1], weight, profit, n-1);
		dp[maxWeight][n-1] = knapSack(maxWeight, weight, profit, n-1);
		return max(dp[maxWeight - weight[n-1]][n-1], dp[maxWeight][n-1]);
	}

}

int main() {
	memset(dp, -1, sizeof(dp));
	int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0;

}
