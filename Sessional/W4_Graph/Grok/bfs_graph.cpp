#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum Color { WHITE, GRAY, BLACK };

struct Vertex {
    Color color;
    int d; // Distance from source
    int pi; // Parent vertex index (-1 for NIL)
    Vertex() : color(WHITE), d(INT_MAX), pi(-1) {}
};

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency lists
    vector<Vertex> vertices;

public:
    Graph(int vertices) : V(vertices), adj(vertices), vertices(vertices) {}

    // Add undirected edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int s) {
        // Initialize vertices
        for (int u = 0; u < V; u++) {
            vertices[u].color = WHITE;
            vertices[u].d = INT_MAX;
            vertices[u].pi = -1;
        }

        // Initialize source
        vertices[s].color = GRAY;
        vertices[s].d = 0;
        vertices[s].pi = -1;

        queue<int> Q;
        Q.push(s);
        vector<int> dequeued; // Track dequeue order for Lemma 22.3

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            dequeued.push_back(u);

            // Process adjacent vertices
            for (int v : adj[u]) {
                if (vertices[v].color == WHITE) {
                    vertices[v].color = GRAY;
                    vertices[v].d = vertices[u].d + 1;
                    vertices[v].pi = u;
                    Q.push(v);
                }
            }
            vertices[u].color = BLACK;
        }

        // Print results
        cout << "BFS Results (Vertex: Distance, Parent):\n";
        for (int u = 0; u < V; u++) {
            cout << u << ": d=" << (vertices[u].d == INT_MAX ? "INF" : to_string(vertices[u].d))
                 << ", pi=" << (vertices[u].pi == -1 ? "NIL" : to_string(vertices[u].pi)) << endl;
        }

        // Verify Lemma 22.3
        cout << "\nVerifying Lemma 22.3:\n";
        cout << "Dequeued order: ";
        for (int u : dequeued) cout << u << " ";
        cout << "\nDistances: ";
        for (int u : dequeued) cout << vertices[u].d << " ";
        cout << "\n(1) v_r.d <= v_1.d + 1: " << vertices[dequeued.back()].d << " <= "
             << vertices[dequeued.front()].d + 1 << " ("
             << (vertices[dequeued.back()].d <= vertices[dequeued.front()].d + 1 ? "True" : "False") << ")\n";
        cout << "(2) Non-decreasing distances: ";
        bool non_decreasing = true;
        for (size_t i = 1; i < dequeued.size(); i++) {
            if (vertices[dequeued[i]].d < vertices[dequeued[i-1]].d) {
                non_decreasing = false;
                break;
            }
        }
        cout << (non_decreasing ? "True" : "False") << endl;
    }
};

int main() {
    // Create graph with 6 vertices (0 to 5)
    Graph g(6);
    // Add edges (undirected)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    // Graph structure:
    // 0 -- 1
    // |    |
    // 2 -- 3 -- 5
    // |    |
    // 4 ----

    cout << "Running BFS with source vertex 0:\n";
    g.BFS(0);

    return 0;
}