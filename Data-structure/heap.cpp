# include <iostream>
# include <cstdio>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int data[], int i, int N) {

	int left = i*2;
	int right = i*2+1;
	int largest = 0;
	
	if(left <= N && data[left] > data[i]) largest = left;
	else largest = i;

	if(right <= N && data[right] > data[largest]) largest = right;

	if(largest != i) {
		swap(&data[i], &data[largest]);
		maxHeapify(data, largest, N);
	}
}

void minHeapify(int data[], int i, int N) {
	
	int left = i*2;
	int right = i*2+1;
	int smallest;

	if(left <= N && data[left] < data[i]) smallest = left;
	else smallest = i;

	if(right <= N && data[right] < data[smallest]) smallest = right;

	if(smallest != i) {
		swap(&data[i], &data[smallest]);
		minHeapify(data, smallest, N);
	}
}

void buildMaxHeap(int data[], int N) {
	for(int i = N/2; i >= 1; i--) {
		maxHeapify(data, i, N);
	}
} 

void buildMinHeap(int data[], int N) {
	for(int i = N/2; i >= 1; i--) {
		minHeapify(data, i, N);
	}
}

void heap_sort(int data[], int N) {
	int heapSize = N;
	buildMaxHeap(data, N);

	for(int i = N; i >= 2; i--) {
		swap(&data[1], &data[i]);
		heapSize--;
		maxHeapify(data, 1, heapSize);
	}
}

int main() {
	int data[8] = {0, 8, 7, 6, 3, 2, 4, 5};
	int N = 7;
	buildMaxHeap(data, N);

	for(int i = 1; i <= N; i++) {
		printf("%d ", data[i]);
	}

    printf("\n");
    
	buildMinHeap(data, N);
	for(int i = 1; i <= N; i++) {
		printf("%d ", data[i]);
	}

	printf("\n");
	
	heap_sort(data, N);

	for(int i = 1; i <= N; i++) {
		printf("%d ", data[i]);
	}
}
