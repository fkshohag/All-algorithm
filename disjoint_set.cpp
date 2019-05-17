# include <cstdio>
# include <iostream>
# include <cstring>
using namespace std;

int data[34];
int dp[100];

int findFriend(int n){
	if(data[n] == n) return n;
	else if(dp[n] != -1) return dp[n];
	else return dp[n] = findFriend(data[n]);
}

void makeFriend(int a, int b) {
	a = findFriend(a);
	b = findFriend(b);
	if(a == b)
		printf("They already in same Set\n");
	else
		data[a] = b;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n = 10;
	for(int i = 1; i<=n; i++) {
		data[i] = i;
	}
	makeFriend(1,2);
	makeFriend(2,3);
	makeFriend(1,3);
}
