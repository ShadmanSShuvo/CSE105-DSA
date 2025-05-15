#include <iostream>
#include <vector>
/// use pair inside vector
/// TO-DO
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for (int i = 0; i < m; i++)
	{
		int u, v, wt;
		/// u---->v if directed
		/// u<--->v if undirected
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
