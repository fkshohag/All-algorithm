# include <iostream>
# include <cstdio>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp; 
}

int partition(int data[], int low, int high) {
	int counter = low-1;
	int pivot = data[high];
	for (int i = low; i < high; ++i) {
		if(data[i] <= pivot) {
			counter++;
			swap(&data[i], &data[counter]);
		}
	}
	swap(&data[counter+1], &data[high]);
	return counter+1;
}

void quickSort(int data[], int low, int high) {
	if (low < high) {
		int pi = partition(data, low, high);
		quickSort(data, low, pi-1);
		quickSort(data, pi+1, high);
	}
}

int main() {
	int data[] = {-4,0,7,4,9,-5,-1,0,-7,-1};
	int size = sizeof(data)/sizeof(data[0]);
	quickSort(data, 0, size-1);
	for(int i = 0; i < size; i++) {
		printf("%d\n", data[i]);
	}
}
