/**
  * @authr Fazlul Kabir Shohag <shohag.fks@gmail.com>
  */
# include <iostream>
# include <cstdio>

using namespace std;

int remove_duplicate(int arr[], int len) {
	int counter = 1; 

	for(int i = 1; i < len; i++) {
		if(arr[i] != arr[i-1]) 
			arr[counter++] = arr[i];
	}
	return counter;
}

int main () {

    int arr[] = {1, 1, 1, 2, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int size = remove_duplicate(arr, len);

    printf("%d\n", size);
    
    return 0;
}
