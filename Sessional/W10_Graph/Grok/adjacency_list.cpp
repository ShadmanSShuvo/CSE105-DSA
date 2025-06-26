#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adjList; // Array of linked lists

public:
    Graph(int vertices) : V(vertices) {
        adjList = new list<int>[V];
    }

    // Add an edge (undirected)
    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjList[u].push_back(v);
            adjList[v].push_back(u); // For undirected graph
        }
    }

    // Print the adjacency list
    void printList() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ":";
            for (int vertex : adjList[i])
                cout << " -> " << vertex;
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adjList;
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Adjacency List:" << endl;
    g.printList();
    return 0;
}