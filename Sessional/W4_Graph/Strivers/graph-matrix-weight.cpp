#include <iostream>
using namespace std;
 

 // Matrix 
int main(){
	int n, m;
	cin >> n >> m;
	int adj[n+1][m+1];
	for(int i = 0;i<m;i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	return 0;
}