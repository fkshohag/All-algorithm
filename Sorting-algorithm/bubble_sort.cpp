# include <cstdio>
# include <iostream>
using namespace std;

int main() {
    int data[] = {2, 3, 1, 0};
    int len = sizeof(data) / sizeof(data[0]);

    for(int i = len-1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(data[j] > data[j+1]) {
                int temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }

    for(int i= 0; i < len; i++)
        printf("%d ", data[i]);

    return 0;
}
