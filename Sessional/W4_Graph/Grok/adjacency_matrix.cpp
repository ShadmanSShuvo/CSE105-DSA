#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    Graph(int vertices) : V(vertices) {
        // Initialize matrix with zeros
        adjMatrix = vector<vector<int>>(V, vector<int>(V, 0));
    }

    // Add an edge (undirected, unweighted)
    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // For undirected graph
        }
    }

    // Print the adjacency matrix
    void printMatrix() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Adjacency Matrix:" << endl;
    g.printMatrix();
    return 0;
}