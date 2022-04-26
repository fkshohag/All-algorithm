# include <iostream>
# include <cstdio>
# define inf -1000000

using namespace std;

int  max_sum(int arr [], int len) {

	if (len <= 0) return 0;
	int maxSum = inf, currentMax = 0;

	for(int i = 0 ; i < len; i++) {
		
		currentMax += arr[i];
		if (currentMax < 0)
			currentMax = 0;

		if(currentMax > maxSum)
			maxSum = currentMax;
	}
	return maxSum;
}
 
int main() {
	int data[] = {-1, -2, 1, 2, 3, -5, 4, 5};
	int len = sizeof(data) / sizeof(data[0]);
	int sum = max_sum(data, len);
	printf("%d\n", sum);
	return 0;
}
