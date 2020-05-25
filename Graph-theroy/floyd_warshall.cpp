# include <iostream>
# include <cstdio>
# include <cstring>
# define INF 99999
# define v 4
using namespace std;

int path[v][v];

int min(int a, int b) {
	return a < b ? a : b;
}

void printSolution(int dist[][v])  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < v; i++)  
    {  
        for (int j = 0; j < v; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
} 

void floydWarshall(int graph[][v]) {
	int d[v][v];

	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			d[i][j] = graph[i][j];

	for(int i = 0; i < v; i++)
		for(int k = 0; k < v; k++)
			for(int j = 0; j < v; j++) 
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
	printSolution(d);
}

int main() {
	int graph[v][v] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
 
    floydWarshall(graph);  
    return 0;  
}
