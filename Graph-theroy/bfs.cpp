# include <iostream>
# include <cstdio>
# include <vector>
# include <queue>
using namespace std;
# define INF 1000000

vector<int> edge[100];
vector<int> cost[100];
int E, Node;

void store() {
	int u, v;
	for(int i = 0; i < E; i++) {
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
}

void visitNode() {
	int d[100];
	bool visited[100];
	for(int i = 0; i < 100; i++) {
		d[i] = INF;
		visited[i] = false; 
	}

	int source_node = 1;
	d[source_node] = 1;
	visited[source_node] = true;
	queue<int> Q;
	Q.push(source_node);
	printf("%d\n", source_node);

	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int i = 1; i < edge[u].size(); i++) {
			int v = edge[u][i];
			if(!visited[v]) {
				printf("%d\n", v);
				visited[v] = true;
				Q.push(v);
			}
		}
	}
}

int main() {
	freopen("in.text", "r", stdin);
	scanf("%d %d", &E, &Node);
	store();
	visitNode();
	return 0;
}
