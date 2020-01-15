#include <iostream>
#include <vector>
#include <queue>

/*
 * hints:
 * 127
 *
 * solution:
 * - representing graph in adjacency list
 * 1. use BFS
 * 2. use DFS
 */

/* BFS using queue */
bool isRouteBFS(std::vector<std::vector<int>> &adj, int u, int v)
{
	int V = adj.size();

	std::vector<bool> visited(V, false);
	std::queue<int> q;
	
	q.push(u);
	
	while (!q.empty()) {
		int n = q.front(); q.pop();
		visited[n] = true;

		if (n == v) return true;

		for (int i = 0; i < adj[n].size(); ++i) {
			if (!visited[adj[n][i]])
				q.push(adj[n][i]);
		}
	}

	return false;
}

/* helper function to do dfs */
bool dfs(std::vector<std::vector<int>> &adj, std::vector<bool> &visited, int u, int v)
{
	visited[u] = true;
	if (u == v)
		return true;

	for (int i = 0; i < adj[u].size(); ++i) {
		if (!visited[adj[u][i]])
			return dfs(adj, visited, adj[u][i], v);
	}
	return false;
}

/* DFS recursion */
bool isRouteDFS(std::vector<std::vector<int>> &adj, int u, int v)
{
	int V = adj.size();
	std::vector<bool> visited(V, false);

	return dfs(adj, visited, u, v);
}

/* helper function to add edge to adj list */
void addEdge(std::vector<std::vector<int>> &adj, int u, int v)
{
	adj[u].push_back(v);
//	adj[v].push_back(u);
}

/* helper function to print graph in adj list */
void printGraph(std::vector<std::vector<int>> &adj)
{
	for (int i = 0; i < adj.size(); ++i) {
		std::cout << i << ": ";
		for (int j = 0; j < adj[i].size(); ++j)
			std::cout << adj[i][j] << ", "; 
		std::cout << std::endl;
	}
}

int main()
{
	int V = 6;
	std::vector<std::vector<int>> adj(V, std::vector<int>());

	addEdge(adj, 5, 2);
	addEdge(adj, 5, 0);
	addEdge(adj, 4, 0);
	addEdge(adj, 4, 1);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	printGraph(adj);

/*	
	Test graph:
	0<---4--->1
	^	  ^
	|	  |
	|	  |
    	5--->2--->3 
*/

	std::cout << "5 and 4 is route(BFS): " << isRouteBFS(adj, 5, 4) << std::endl;
	std::cout << "5 and 1 is route(BFS): " << isRouteBFS(adj, 5, 1) << std::endl;

	std::cout << "5 and 4 is route(DFS): " << isRouteDFS(adj, 5, 4) << std::endl;
	std::cout << "5 and 1 is route(DFS): " << isRouteDFS(adj, 5, 1) << std::endl;

	return 0;
}
