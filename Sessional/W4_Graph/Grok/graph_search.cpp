#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

// Graph representation using adjacency list
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    // Add edge to the graph (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Add directed edge
    void addDirectedEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    // Print adjacency list
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    
    // BREADTH-FIRST SEARCH (BFS)
    void BFS(int source) {
        cout << "\n=== BREADTH-FIRST SEARCH ===" << endl;
        
        // Color coding: 0=white, 1=gray, 2=black
        vector<int> color(V, 0);
        vector<int> distance(V, INT_MAX);
        vector<int> parent(V, -1);
        
        // Initialize source
        color[source] = 1; // Gray
        distance[source] = 0;
        parent[source] = -1;
        
        queue<int> q;
        q.push(source);
        
        cout << "BFS traversal starting from vertex " << source << ":" << endl;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            cout << "Processing vertex " << u << " (distance: " << distance[u] << ")" << endl;
            
            // Explore all adjacent vertices
            for (int v : adj[u]) {
                if (color[v] == 0) { // White vertex
                    color[v] = 1; // Gray
                    distance[v] = distance[u] + 1;
                    parent[v] = u;
                    q.push(v);
                    cout << "  Discovered vertex " << v 
                         << " (distance: " << distance[v] << ")" << endl;
                }
            }
            color[u] = 2; // Black (finished)
        }
        
        // Print shortest distances
        cout << "\nShortest distances from source " << source << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (distance[i] == INT_MAX) {
                cout << "Vertex " << i << ": UNREACHABLE" << endl;
            } else {
                cout << "Vertex " << i << ": " << distance[i] << endl;
            }
        }
        
        // Print shortest paths
        cout << "\nShortest paths from source " << source << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (i != source && distance[i] != INT_MAX) {
                printPath(parent, source, i);
            }
        }
    }
    
    // Helper function to print path from source to destination
    void printPath(vector<int>& parent, int source, int dest) {
        vector<int> path;
        int current = dest;
        
        while (current != source) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(source);
        
        reverse(path.begin(), path.end());
        
        cout << "Path to " << dest << ": ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << " (distance: " << path.size() - 1 << ")" << endl;
    }
    
    // DEPTH-FIRST SEARCH (DFS)
    void DFS() {
        cout << "\n=== DEPTH-FIRST SEARCH ===" << endl;
        
        // Color coding: 0=white, 1=gray, 2=black
        vector<int> color(V, 0);
        vector<int> parent(V, -1);
        vector<int> discovery(V, 0);
        vector<int> finish(V, 0);
        int time = 0;
        
        cout << "DFS traversal:" << endl;
        
        for (int u = 0; u < V; u++) {
            if (color[u] == 0) { // White vertex
                cout << "\nStarting DFS from vertex " << u << endl;
                DFS_Visit(u, color, parent, discovery, finish, time);
            }
        }
        
        // Print timestamps
        cout << "\nDFS Timestamps:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": discovery=" << discovery[i] 
                 << ", finish=" << finish[i] << endl;
        }
        
        // Print DFS forest (predecessor subgraph)
        cout << "\nDFS Tree edges:" << endl;
        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " -> " << i << endl;
            }
        }
    }
    
    // DFS Visit helper function (recursive)
    void DFS_Visit(int u, vector<int>& color, vector<int>& parent, 
                   vector<int>& discovery, vector<int>& finish, int& time) {
        time++;
        discovery[u] = time;
        color[u] = 1; // Gray
        
        cout << "  Visiting vertex " << u << " (discovery time: " << time << ")" << endl;
        
        // Explore all adjacent vertices
        for (int v : adj[u]) {
            if (color[v] == 0) { // White vertex
                parent[v] = u;
                cout << "    Tree edge: " << u << " -> " << v << endl;
                DFS_Visit(v, color, parent, discovery, finish, time);
            } else if (color[v] == 1) { // Gray vertex
                cout << "    Back edge: " << u << " -> " << v << endl;
            } else { // Black vertex
                if (discovery[u] < discovery[v]) {
                    cout << "    Forward edge: " << u << " -> " << v << endl;
                } else {
                    cout << "    Cross edge: " << u << " -> " << v << endl;
                }
            }
        }
        
        color[u] = 2; // Black
        time++;
        finish[u] = time;
        cout << "  Finished vertex " << u << " (finish time: " << time << ")" << endl;
    }
    
    // Check if graph is connected using BFS
    bool isConnected() {
        if (V == 0) return true;
        
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        int visitedCount = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    visitedCount++;
                    q.push(v);
                }
            }
        }
        
        return visitedCount == V;
    }
    
    // Find shortest path between two vertices using BFS
    int shortestPath(int source, int destination) {
        if (source == destination) return 0;
        
        vector<bool> visited(V, false);
        vector<int> distance(V, 0);
        queue<int> q;
        
        visited[source] = true;
        q.push(source);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    q.push(v);
                    
                    if (v == destination) {
                        return distance[v];
                    }
                }
            }
        }
        
        return -1; // No path exists
    }
};

// Demonstration function
int main() {
    cout << "Graph Searching Algorithms Demonstration" << endl;
    cout << "=========================================" << endl;
    
    // Create the graph from the example in the document
    // Vertices: r=0, s=1, t=2, u=3, v=4, w=5, x=6, y=7
    Graph g(8);
    
    // Add edges as shown in the BFS example
    g.addEdge(0, 1); // r-s
    g.addEdge(0, 4); // r-v
    g.addEdge(1, 5); // s-w
    g.addEdge(2, 5); // t-w
    g.addEdge(2, 6); // t-x
    g.addEdge(2, 3); // t-u
    g.addEdge(3, 7); // u-y
    g.addEdge(5, 6); // w-x
    g.addEdge(6, 7); // x-y
    
    cout << "Graph structure:" << endl;
    g.printGraph();
    
    // Perform BFS from vertex 1 (s in the example)
    g.BFS(1);
    
    // Perform DFS
    g.DFS();
    
    // Additional operations
    cout << "\n=== ADDITIONAL OPERATIONS ===" << endl;
    cout << "Is graph connected? " << (g.isConnected() ? "Yes" : "No") << endl;
    
    int dist = g.shortestPath(1, 7); // s to y
    if (dist != -1) {
        cout << "Shortest distance from s(1) to y(7): " << dist << endl;
    } else {
        cout << "No path exists from s(1) to y(7)" << endl;
    }
    
    // Demonstrate with a smaller example
    cout << "\n=== SMALLER EXAMPLE ===" << endl;
    Graph small(4);
    small.addEdge(0, 1);
    small.addEdge(1, 2);
    small.addEdge(2, 3);
    small.addEdge(3, 0);
    
    cout << "Small graph structure:" << endl;
    small.printGraph();
    small.BFS(0);
    small.DFS();
    
    return 0;
}