#include <iostream>
#include <stack>
#include <queue>

const int Max_Vertex = 50;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void addNode(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
     void deleteNode(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        }
    }
};

class Graph {
private:
    LinkedList* adjList;
    int Vertex;
    int Edge;

public:
    Graph() {
        Vertex = 0;
        Edge = 0;

        adjList = new LinkedList[Max_Vertex];
    }

    ~Graph() {
        delete[] adjList;
    }

    bool IsEmpty() {
        return Vertex == 0;
    }

    void Insert_Vertex(int u) {
        if (u >= 0 && u < Max_Vertex) {
            Vertex++;
        } else {
            throw std::invalid_argument("Invalid Index");
        }
    }

    void Insert_Edge(int u, int v) {
        if (u >= 0 && u < Max_Vertex && v >= 0 && v < Max_Vertex) {
            adjList[u].addNode(v);
            adjList[v].addNode(u); // For undirected graph
            Edge++;
        } else {
            throw std::invalid_argument("Invalid Index");
        }
    }

    void Delete_Vertex(int u) {
        if (u >= 0 && u < Max_Vertex) {
            for (int i = 0; i < Max_Vertex; i++) {
                adjList[i].deleteNode(u);
            }
            Vertex--;
        } else {
            throw std::invalid_argument("Invalid Index");
        }
    }

    void Delete_Edge(int u, int v) {
        if (u >= 0 && u < Max_Vertex && v >= 0 && v < Max_Vertex) {
            adjList[u].deleteNode(v);
            adjList[v].deleteNode(u);
            Edge--;
        } else {
            throw std::invalid_argument("Invalid Index");
        }
    }

    void PrintAdjList() {
        for (int i = 0; i < Vertex; ++i) {
            Node* current = adjList[i].head;
            std::cout << "Adjacency list of vertex " << i << ": ";
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    // Depth-First Search (DFS) without recursion
    void DFS(int startVertex) {
        bool* visited = new bool[Max_Vertex];
        for (int i = 0; i < Max_Vertex; ++i) {
            visited[i] = false;
        }

        std::stack<int> stack;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            if (!visited[currentVertex]) {
                std::cout << currentVertex << " ";
                visited[currentVertex] = true;

                Node* current = adjList[currentVertex].head;
                while (current != nullptr) {
                    if (!visited[current->data]) {
                        stack.push(current->data);
                    }
                    current = current->next;
                }
            }
        }

        delete[] visited;
    }

    // Breadth-First Search (BFS)
    void BFS(int startVertex) {
        bool* visited = new bool[Max_Vertex];
        for (int i = 0; i < Max_Vertex; ++i) {
            visited[i] = false;
        }

        std::queue<int> queue;
        queue.push(startVertex);
        visited[startVertex] = true;

        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.pop();

            std::cout << currentVertex << " ";

            Node* current = adjList[currentVertex].head;
            while (current != nullptr) {
                if (!visited[current->data]) {
                    queue.push(current->data);
                    visited[current->data] = true;
                }
                current = current->next;
            }
        }

        delete[] visited;
    }
};

int main() {
    Graph myGraph;

    myGraph.Insert_Vertex(0);
    myGraph.Insert_Vertex(1);
    myGraph.Insert_Vertex(2);
    myGraph.Insert_Vertex(3);
    myGraph.Insert_Vertex(4);

    myGraph.Insert_Edge(0, 1);
    myGraph.Insert_Edge(0, 2);
    myGraph.Insert_Edge(1, 2);
    myGraph.Insert_Edge(2, 0);
    myGraph.Insert_Edge(2, 3);
    myGraph.Insert_Edge(3, 3);
    myGraph.Insert_Edge(3, 4);

    std::cout << "Depth-First Search (DFS): ";
    myGraph.DFS(0);
    std::cout << std::endl;

    std::cout << "Breadth-First Search (BFS): ";
    myGraph.BFS(0);
    std::cout << std::endl;

    return 0;
}
