#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

/*
 * Hints:
 * 26, 47, 60, 85, 125, 133
 *
 * Solution:
 * Use topological sort
 *
 * Time Complexity:
 * O(P + D), where P is the number of projects and D is the number of edges
 * between projects
 *
 * Space Complexity
 * O(1)
 */

/* Definition of Project */
class Project
{
	public:
		Project(char n) { name = n; dependencies = 0; }
		~Project() { }
		
		void addNeighbor(Project *node) {
			if (map.find(node->name) == map.end()) {
				children.push_back(node);
				map[node->name] = node;
				node->incDeps();
			}
		}
		
		char getName() { return name; }
		std::vector<Project *>* getChildren() { return &children; }
		int getDeps() { return dependencies; }
		void incDeps() { ++dependencies; }
		void decDeps() { --dependencies; }

	private:
		std::vector<Project *> children;
		std::unordered_map<char, Project *> map;
		char name;
		int dependencies;
};

/* Definition of Graph */
class Graph
{
	public:
		Project* getOrCreateNode(char name) {
			if (map.find(name) == map.end()) {
				Project *node = new Project(name);
				nodes.push_back(node);
				map[name] = node;
			}
			return map[name];
		}

		void addEdge(char uName, char vName) {
			Project *u = getOrCreateNode(uName);
			Project *v = getOrCreateNode(vName);
			u->addNeighbor(v);
		}

		std::vector<Project *> getNodes() { return nodes; }
	
	private:
		std::vector<Project *> nodes;
		std::unordered_map<char, Project *> map;
};

/* build order from graph */
std::vector<Project *> buildOrder(std::vector<Project *> projects)
{
	int N = projects.size();
	std::vector<Project *> order (N);

	/* add projects with 0 dependencies */
	int i = -1;
	for (auto &project : projects) {
		if (project->getDeps() == 0)
			order[++i] = project;
	}

	int j = 0;
	while (j < order.size()) {
		Project *cur = order[j];

		/* checks for circular dependency */
		if (!cur) {
			std::cout << "FAIL\n"; 
			return order;
		}

		/* remove dependencies for cur's children */
		std::vector<Project *> *children = cur->getChildren();
		
		if (children) {
			for (auto &child : *children)
				child->decDeps();

			/* add children with 0 dependencies */
			for (auto &project : *children) {
				if (project->getDeps() == 0)
					order[++i] = project;
			}
		}
		++j;
	}

	return order;
}

/* helper function to biuld graph from projects and dependencies */
Graph* buildGraph(std::vector<char> projs,
				  std::vector<std::vector<char>> deps)
{
	Graph *g = new Graph();
	for (auto p : projs)
		g->getOrCreateNode(p);
	for (auto d: deps)
		g->addEdge(d[0], d[1]);
	return g;
}


int main()
{
	std::vector<char> projects = { 'a', 'b', 'c', 'd', 'e', 'f' };
	std::vector<std::vector<char>> dependencies = {
		{ 'a', 'd' }, 
		{ 'f', 'b' }, 
		{ 'b', 'd' }, 
		{ 'f', 'a' }, 
		{ 'd', 'c' }
	};

	Graph *graph = buildGraph(projects, dependencies);	

	std::vector<Project *> order = buildOrder(graph->getNodes());

	for (auto &project : order)
		std::cout << project->getName() << ", ";
	std::cout << std::endl;

	return 0;
}
