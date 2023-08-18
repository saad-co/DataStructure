#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    void makeEdge(T u, T v, bool dir)
    {
        adj[u].push_back(v);
        if (dir == false)
        {
            adj[v].push_back(u);
        }
    }

    void printG()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m;
    int n;
    cout << "Enter the number of nodes in graph: " << endl;
    cin >> m;

    cout << "Enter the number of edges in the graph: " << endl;
    cin >> n;

    graph<int> g;
    for (int l = 0; l < m; l++)
    {
        int u, v;
        cin >> u >> v;
        g.makeEdge(u, v, false);
    }

    g.printG();

    return 0;
}
