# include <iostream>
# include <cstdio>
# include <string>
# include <utility>
# include <vector>
# include <queue>

using namespace std;

vector <int> edge[100]; 
vector <int> cost[100];

struct Graph {
	int city;
	double weight;
	bool operator < (const Graph &others) const {
		return (weight > others.weight);
	}
};

int prim(int source) {
	priority_queue<Graph> q;
	Graph u, v;
	bool visited[100];
	int total_cost = 0;
	for(int i = 0; i < 100; i++) visited[i] = false;

	u.city = source;
	u.weight = 0;
	q.push(u);

	while(!q.empty()) {
		u = q.top(), q.pop();
		if(!visited[u.city]) total_cost += u.weight;
		if(!visited[u.city]) {
			for(int i = 0; i < edge[u.city].size(); i++) {
				v.city = edge[u.city][i];
				v.weight = cost[u.city][i];
				if(!visited[v.city]) {
					q.push(v);
				}
			}
		}
		visited[u.city] = true;
	}
	return total_cost;
}

int main() {
	edge[1].push_back(2);
	cost[1].push_back(1);
	edge[1].push_back(3);
	cost[1].push_back(3);
	edge[1].push_back(4);
	cost[1].push_back(4);
	edge[2].push_back(3);
	cost[2].push_back(2);
	edge[3].push_back(4);
	cost[3].push_back(5);

	int x = prim(1);
	printf("%d\n", x);
}
