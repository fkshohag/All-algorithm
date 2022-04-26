# include <iostream>
# include <cstdio>
using namespace std;

int maximum_distance(int arr[], int len) {
	int mx = -1;

	for(int i = 0; i < len-1; i++)
		for(int j = i+1; j < len; j++)
			if(arr[j] > arr[i]) 
				mx = max(mx, j - i);

	return mx;
}

int main() {
	int data[] = {3, 5, 4, 2};
	int len = sizeof(data) / sizeof(data[0]);

	int mx = maximum_distance(data, len);
	printf("%d\n", mx);

	return 0;
}
