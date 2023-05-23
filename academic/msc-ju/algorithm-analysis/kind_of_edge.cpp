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
 
    Graph(int v, int e) {
        this->v = v;
        this->e = e;
        this->graph_list.resize(v);
    }
 
    // function to create random graph
    void create_graph() {
        for (int i = 0; i < this->e; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            this->graph_list[u].push_back(v);
        }
    }
 
    void print_graph_list() {
        cout << "Adjacency List Representation:" << endl;
        for (int i = 0; i < this->v; i++)
        {
            char uNode = (char) i + 'a';
            cout << uNode << "-->";
            for (int j = 0; j < this->graph_list[i].size(); j++)
            {
                char vNode = this->graph_list[i][j] + 'a';
                cout << vNode << " ";
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
            char node = (char) this->traversal_array[i] + 'a';
            cout << node << " ";
        }
        cout << endl;

        cout << "Finishing time: " << endl;
        for (int i = 0; i < this->traversal_array.size(); i++)
        {
            char node = (char) this->traversal_array[i] + 'a';
            cout << node << " ->> " << this->start_time[this->traversal_array[i]] << " ->> " << this->end_time[this->traversal_array[i]] << endl;
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
            char uNode = char(node + 'a');
            char vNode = char(graph_list[node][neighbour] + 'a');
            if (!this->visited[this->graph_list[node][neighbour]]) {
                cout << "Tree Edge:" << uNode << "-->" << vNode << endl;
                this->traverse_dfs(this->graph_list[node][neighbour]);
            }
            else {
                // when the parent node is traversed after the neighbour node
                if (this->start_time[node] > this->start_time[this->graph_list[node][neighbour]] && this->end_time[node] < this->end_time[this->graph_list[node][neighbour]]) {
                    cout << "Back Edge:" << uNode << "-->" << vNode << endl;
                }
                // when the neighbour node is a descendant but not a part of tree
                else if (this->start_time[node] < this->start_time[this->graph_list[node][neighbour]] && this->end_time[node] > this->end_time[this->graph_list[node][neighbour]]) {
                    cout << "Forward Edge:" << uNode << "-->" << vNode << endl;
                }
                // when parent and neighbour node do not have any ancestor and a descendant relationship between them
                else if (this->start_time[node] > this->start_time[this->graph_list[node][neighbour]] && this->end_time[node] > this->end_time[this->graph_list[node][neighbour]]) {
                    cout << "Cross Edge:" << uNode << "-->" << vNode << endl;
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
    // freopen("input/11.txt", "r", stdin);
    // freopen("input/12.txt", "r", stdin);
    freopen("input/13.txt", "r", stdin);
    // freopen("input/testedges.txt", "r", stdin);
    srand(time(NULL));

    int v, e;
    scanf("%d %d", &v, &e);
    Graph g(v, e);

    g.create_graph();
    g.print_graph_list();
    g.dfs();

    return 0;
}
 