# include <iostream>
# include <cstdio>
using namespace std;

int binary_search(int data[], int len, int value) {
	int start = 0;
	int end = len - 1;

	while(start <= end) {
		int mid = (start + end);
		if(data[mid] == value) return mid+1;
		else if (value < data[mid]) 
			end = mid-1;
		else 
			start = mid+1;
	}
	return -1;
}


int main() {
	int data[] = {1, 3, 4, 54, 67, 100};
	int key = binary_search(data, sizeof(data)/sizeof(data[0]), 100);
	printf("%d\n", key);
    return 0;	
}

