#include <iostream> 
#include <cstdio>
# include <vector>
using namespace std;

int main(){

    // Initialize 
    const int vertices = 5;
    int a[vertices][vertices];
    // initialize diagonal
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            a[i][j]=999999999;
        }
    }
    for(int i=0; i < vertices; i++)
        a[i][i]=0;

    // initialize distances
    a[0][1]=20;
    a[0][2]=10;
    a[0][4]=5;
    a[2][3]=10;
    a[3][1]=3;
    a[4][2]=2;
    a[4][3]=4;

    // Floyd-Warshall
    // Add nodes between (first 1 then 2, 3 till n) and look if
    // distance is shorter
    for(int k = 0; k < vertices; k++)
        for(int i = 0; i < vertices; i++)
            for(int j = 0; j < vertices; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];

    // Print out final distance matrix
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
