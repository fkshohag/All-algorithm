# include <iostream>
# include <cstdio>
using namespace std;

int recurrence(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 1;
	int x = recurrence(n - 1) + recurrence(n - 3);
	printf("%d %d\n", n, x);
	return x;
}

int main() {
	printf("%d", recurrence(11));
}