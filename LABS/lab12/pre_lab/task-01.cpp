
#include <iostream>
using namespace std;
class GraphNode {
public:
    int vertex;
    int weight;
    GraphNode* next;

    GraphNode(){
        vertex=0;
        weight=0;
        next=nullptr;
    }
    GraphNode(int v, int w) { 
        vertex=v;
         weight=w;
        next=nullptr;
     }
};

class Graph {
private:
    int max;
    GraphNode** headnodes;
    int* visited;          

public:
    int n;
    Graph(int m) {
        max=m;
        n=0;
        headnodes = new GraphNode*[max];
        visited = new int[max];
        initialize_visited();
    }

    ~Graph() {
        for (int i = 0; i < n; ++i) {
            GraphNode* temp = headnodes[i];
            while (temp) {
                GraphNode* temp = temp;
                temp = temp->next;
                delete temp;
            }
        }
        delete[] headnodes;
        delete[] visited;
    }

    void create() {
    
    }

    void initialize_visited() {
        for (int i = 0; i < max; i++) {
            visited[i] = 0;
        }
    }

    void addVertex(int v) {
        if (n < max) {
            headnodes[n] = nullptr;
            n++;
        } else {
            cout << "Graph is full." << endl;
        }
    }

    void removeVertex(int v) {
        if (v >= 0 && v< n) {
            visited[v] = 0;
            GraphNode* current = headnodes[v];
            while (current) {
                int temp = current->vertex;
                removeEdge(v, temp);
                current = current->next;
            }
            n--;
        } else {
            throw invalid_argument("Invalid Vertex");
        }
    }

    void addEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
            GraphNode* newNode = new GraphNode(v2, 0);
            newNode->next = headnodes[v1];
            headnodes[v1] = newNode;
        } else {
            throw invalid_argument("Invalid vertices");
        }
    }

    void removeEdge(int v1, int v2) {
        if (v1>= 0 && v1 < n && v2 >= 0 && v2 < n) {
            GraphNode* current = headnodes[v1];
            GraphNode* prev = nullptr;
            while (current && current->vertex != v2) {
                prev = current;
                current = current->next;
            }
            if (current) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    headnodes[v1] = current->next;
                }
                delete current;
            }
        } else {
             throw invalid_argument("Invalid Vertices");
        }
    }

    bool vertexExists(int v) {
        return v >= 0 && v < n;
    }

    int examine_n() const {
        return n;
    }

    int getWeight(int v1, int v2) {
        if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
            GraphNode* current = headnodes[v1];
            while (current && current->vertex != v2) {
                current = current->next;
            }

            if (current) {
                return current->weight;
            }
        }
        return 0;
    }

    void printGraph() {
        for (int i = 0; i < n; ++i) {
            cout << "Vertex " << i << ": ";
            GraphNode* current = headnodes[i];
            while (current) {
                cout << "(" << current->vertex << ", " << current->weight << ") ";
                current = current->next;
            }
            cout <<endl;
        }
    }
};

int main() {
    Graph myGraph(5); 

    myGraph.addVertex(0);
    myGraph.addVertex(1);
    myGraph.addVertex(2);

    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 2);

    myGraph.printGraph();

    return 0;
}
