# include <iostream>
# include <cstdio>
using namespace std;

int main() {
    int data[] = {1,2,3,4,5,6};
    int len = (int) sizeof(data) / (int) sizeof(data[0]);
    for(int i = 1; i < len; i++) {
        data[i] += data[i-1];
    }

    for(int i = 0; i < len; i++)
        printf("%d ", data[i]);
    return 0;
}
