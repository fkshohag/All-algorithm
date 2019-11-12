# include <cstdio>
# include <iostream>
using namespace std;

int main() {

    int data[] = {2, 3, 1, 9};
    int len = sizeof(data) / sizeof(data[0]);

    for(int i = len-1; i >= 0; i--) {
        int mxIndex = 0;
        for(int j = 0; j <= i; j++) {
            if(data[j] > data[mxIndex]) {
                mxIndex = j;
            }
        }

        int temp = data[mxIndex];
        data[mxIndex] = data[i];
        data[i] = temp;
    }

    for(int i= 0; i < len; i++)
        printf("%d ", data[i]);

    return 0;
}
