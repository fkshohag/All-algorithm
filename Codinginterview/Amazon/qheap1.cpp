/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://www.hackerrank.com/challenges/sparse-arrays/problem
 */

# include <cmath>
# include <cstdio>
# include <vector>
# include <iostream>
# include <algorithm>
using namespace std;

int data[1000000];
int N = -1;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHepify(int index) {
    int left = 2 * 1;
    int right = 2 * 1 + 1;
    int smallest;

    if (left <= N && data[left] < data[index]) {
        smallest = left;
    } else {
        smallest = index;
    }
    if (right <= N && data[right] < data[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&data[index], &data[smallest]);
        minHepify(smallest);
    }
}

void buildHeap(int value) {
    data[++N] = value;
    minHepify(N);
}

int findIndex(int value) {
    for (int index = 0; index <= N; index++) {
        if (value == data[index]) {
            return index;
        }
    }
    return -1;
} 

void deleteNode(int value) {
    int indexOfNode = findIndex(value);

    if (indexOfNode > -1) {
        swap(&data[indexOfNode], &data[N]);
        N--; 
        minHepify(indexOfNode);
    }
}

int main() {

    // freopen("in.txt", "r", stdin);
    
    int test, query, value;
    
    scanf("%d", &test);

    for (int index = 0; index < test; index++) {
        scanf("%d", &query);
        if (query == 1) {
            scanf("%d", &value);
            buildHeap(value);
        }
        else if (query == 2) {
            scanf("%d", &value);
            deleteNode(value);
        }
        else if (query == 3) {
            if (N > -1) {
                printf("%d\n", data[0]);
            }
        }
    }

    return 0;
}

/*
Input
9
1 4
1 9
3
2 4
2 9
1 1
2 1
3
2 4

Output:
4
*/
