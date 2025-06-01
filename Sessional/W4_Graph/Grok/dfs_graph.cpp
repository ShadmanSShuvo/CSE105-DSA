#include <iostream>
#include <vector>
using namespace std;

enum Color { WHITE, GRAY, BLACK };

struct Vertex {
    Color color;
    int d; // Discovery time
    int f; // Finishing time
    int pi; // Parent vertex index (-1 for NIL)
    Vertex() : color(WHITE), d(0), f(0), pi(-1) {}
};

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency lists
    vector<Vertex> vertices;
    int time;

    void DFSVisit(int u) {
        time++;
        vertices[u].d = time;
        vertices[u].color = GRAY;

        for (int v : adj[u]) {
            if (vertices[v].color == WHITE) {
                vertices[v].pi = u;
                DFSVisit(v);
            }
        }

        vertices[u].color = BLACK;
        time++;
        vertices[u].f = time;
    }

public:
    Graph(int vertices) : V(vertices), adj(vertices), vertices(vertices), time(0) {}

    // Add undirected edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS() {
        // Initialize vertices
        for (int u = 0; u < V; u++) {
            vertices[u].color = WHITE;
            vertices[u].pi = -1;
            vertices[u].d = 0;
            vertices[u].f = 0;
        }
        time = 0;

        // Run DFS
        for (int u = 0; u < V; u++) {
            if (vertices[u].color == WHITE) {
                DFSVisit(u);
            }
        }

        // Print DFS results
        cout << "DFS Results (Vertex: Discovery/Finish Time, Parent):\n";
        for (int u = 0; u < V; u++) {
            cout << u << ": d=" << vertices[u].d << ", f=" << vertices[u].f
                 << ", pi=" << (vertices[u].pi == -1 ? "NIL" : to_string(vertices[u].pi)) << endl;
        }

        // Construct and print predecessor subgraph (DFS forest)
        cout << "\nPredecessor Subgraph (DFS Forest) Edges:\n";
        vector<pair<int, int>> E_pi;
        for (int v = 0; v < V; v++) {
            if (vertices[v].pi != -1) {
                E_pi.push_back({vertices[v].pi, v});
            }
        }
        for (const auto& edge : E_pi) {
            cout << "(" << edge.first << ", " << edge.second << ")\n";
        }
    }
};

int main() {
    // Create graph with 8 vertices (0 to 7, labeled s=0, r=1, w=2, t=3, x=4, u=5, v=6, y=7)
    Graph g(8);
    // Add edges based on Page 42 example
    g.addEdge(0, 1); // s-r
    g.addEdge(0, 2); // s-w
    g.addEdge(1, 6); // r-v
    g.addEdge(2, 3); // w-t
    g.addEdge(2, 4); // w-x
    g.addEdge(3, 4); // t-x
    g.addEdge(3, 5); // t-u
    g.addEdge(4, 7); // x-y
    g.addEdge(5, 7); // u-y

    cout << "Running DFS:\n";
    g.DFS();

    return 0;
}