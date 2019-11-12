# include <cstdio>
# include <iostream>
using namespace std;

int main() {

    int data[] = {2, 0, 1, -1};
    int len = sizeof(data) / sizeof(data[0]);

    for(int i = 0; i < len; i++) {
        int j = i;
        while(j > 0 && data[j-1] > data[j]) {
            int temp = data[j-1];
            data[j-1] = data[j];
            data[j] = temp;
            j--;
        }
    }

    for(int i= 0; i < len; i++)
        printf("%d ", data[i]);

    return 0;
}
