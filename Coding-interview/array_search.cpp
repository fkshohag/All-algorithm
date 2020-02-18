# include <cstdio>
# include <iostream>
# include <vector>

using namespace std;

int* insertionSort(int data[], int len) {
	for(int i = 0; i < len; i++) {
		int j = i;
		while(j > 0 && data[j-1] > data[j]) {
			int temp = data[j-1];
			data[j-1] = data[j];
			data[j] = temp;
			j--;
		}
	}
	return data;
}


int arraySearch(int data[], int len, int value) {
	int left = 0, right = len-1, mid;

	if(len == 0) return 0;

	while(left <= right) {

		if(value < data[left]) return left;
		if(value > data[right]) return right+1;
		int mid = left + (right - left) / 2;

		if(value == data[left]) {
			if(mid == left || data[left-1] != value) return mid;
			right = mid;
		}
		else if(value < data[mid]) {
			if(mid > left && value > data[mid-1]) return mid;
			right = mid-1;
		} else {
			if(mid < right && value < data[mid+1]) return mid+1;
			left = mid+1;
		}
	}
	return -1;
}

int main() {

	int data[] = {1, 2, 4, 4, 4, 5, 7, 7};
	int len = sizeof(data) / sizeof(data[0]);
	int *sortedArray = insertionSort(data, len);
	
	int index = arraySearch(sortedArray, len, 7);

	printf("%d\n", index);
}
