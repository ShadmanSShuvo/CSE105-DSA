// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;


vector<int> bfs0fGraph(int V, vector<int > adj[]) {
	int vis[n] = {0};
	vis[0] = 1;
	queue<int> q;
	q.push(0) ;
	vector<int> bfs;
	while(!q.emptyO) {
		int node = q.front();
		q.pop() ;
		bfs.push(node);
		for(auto it : adj[node]) {
			if(!vis[it]) {
			vis[it] = 1;
			q. push(it); 
			}
		}
	}
	return bfs;
}




class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);

        // Traverse all its neighbours
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> ls;
        int start = 0; // Start DFS from node 0
        dfs(start, adj, vis, ls);
        return ls;
    }
};


int main(){
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		/// u---->v if directed
		/// u<--->v if undirected
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}