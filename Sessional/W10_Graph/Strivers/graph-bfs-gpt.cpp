#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS from node 0
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(V, 0); // Fix 1: 'n' is undefined; use 'V'

    queue<int> q;
    vis[0] = 1;
    q.push(0);

    while(!q.empty()) { // Fix 2: Typo in 'q.emptyO' → should be 'q.empty()'
        int node = q.front();
        q.pop();
        bfs.push_back(node); // Fix 3: 'bfs.push(node)' → should be 'push_back'

        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it); // Fix 4: 'q. push(it)' → remove space
            }
        }
    }
    return bfs;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n]; // Fix 5: If graph is 0-indexed, use size n; if 1-indexed, use n+1

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // For undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Call BFS and print the result
    vector<int> res = bfsOfGraph(n, adj);
    for(int i : res) cout << i << " ";
    cout << endl;
    return 0;
}