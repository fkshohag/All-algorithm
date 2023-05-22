#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class Graph {
 
public:
    // instance variables
    int time = 0;
    vector<int> traversal_array;
    int v;
    int e;
    vector<vector <int> > graph_list;
    vector<vector <int> > graph_matrix;
 
    Graph(int v, int e) {
        this->v = v;
        this->e = e;
        this->graph_list.resize(v);
        this->graph_matrix.resize(v, vector<int>(v, 0));
    }
 
    // function to create random graph
    void create_random_graph() {
        for (int i = 0; i < this->e; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            this->graph_list[u].push_back(v);
            this->graph_matrix[u][v] = 1;
        }
    }
 
    void print_graph_list() {
        cout << "Adjacency List Representation:" << endl;
        for (int i = 0; i < this->v; i++)
        {
            cout << i << "-->";
            for (int j = 0; j < this->graph_list[i].size(); j++)
            {
                cout << this->graph_list[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
 
    void print_graph_matrix() {
        cout << "Adjacency Matrix Representation:" << endl;
        for (int i = 0; i < this->graph_matrix.size(); i++)
        {
            for (int j = 0; j < this->graph_matrix[i].size(); j++)
            {
                cout << this->graph_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int number_of_edges()
    {
        return this->e;
    }
 
    void dfs()
    {
        this->visited.resize(this->v);
        this->start_time.resize(this->v);
        this->end_time.resize(this->v);
        fill(this->visited.begin(), this->visited.end(), false);
 
        for (int node = 0; node < this->v; node++)
        {
            if (!this->visited[node])
            {
                this->traverse_dfs(node);
            }
        }
        cout << endl;
        cout << "DFS Traversal: ";
        for (int i = 0; i < this->traversal_array.size(); i++)
        {
            cout << this->traversal_array[i] << " ";
        }
        cout << endl;
    }
 
    void traverse_dfs(int node)
    {
        this->visited[node] = true;
        this->traversal_array.push_back(node);
        this->start_time[node] = this->time;
        this->time++;

        // traverse through the neighbours
        for (int neighbour = 0; neighbour < this->graph_list[node].size(); neighbour++)
        {
            if (!this->visited[this->graph_list[node][neighbour]]) {
                cout << "Tree Edge:" << node << "-->" << this->graph_list[node][neighbour] << endl;
                this->traverse_dfs(this->graph_list[node][neighbour]);
            }
            else {
                // when the parent node is traversed after the neighbour node
                if (this->start_time[node] > this->start_time[this->graph_list[node][neighbour]] && this->end_time[node] < this->end_time[this->graph_list[node][neighbour]]) {
                    cout << "Back Edge:" << node << "-->" << this->graph_list[node][neighbour] << endl;
                }
                // when the neighbour node is a descendant but not a part of tree
                else if (this->start_time[node] < this->start_time[this->graph_list[node][neighbour]] && this->end_time[node] > this->end_time[this->graph_list[node][neighbour]]) {
                    cout << "Forward Edge:" << node << "-->" << this->graph_list[node][neighbour] << endl;
                }
                // when parent and neighbour node do not have any ancestor and a descendant relationship between them
                else if (this->start_time[node] > this->start_time[this->graph_list[node][neighbour]] && this->end_time[node] > this->end_time[this->graph_list[node][neighbour]]) {
                    cout << "Cross Edge:" << node << "-->" << this->graph_list[node][neighbour] << endl;
                }
            }
            this->end_time[node] = this->time;
            this->time++;
        }
    }
 
private:
    vector<bool> visited;
    vector<int> start_time;
    vector<int> end_time;
};
 
int main()
{
    freopen("input/a1.txt", "r", stdin);
    srand(time(NULL));

    int v, e;
    scanf("%d %d", &v, &e);
    Graph g(v, e);

    g.create_random_graph();
    g.print_graph_list();
    g.print_graph_matrix();
    g.dfs();

    return 0;
}
 