#include<iostream>
#include<list>
#include<stack>
using namespace std;

//Class to represent a graph
class Graph{
	int V; // no. of vertices..
	
	//Pointer to an array containing adjacency list
	list<int> *adj;
	
	//A function used to topologicalSort
	void topologicalSortUtil(int n, bool visited[], stack<int> &Stack);
public:
	Graph(int V); //constructor
	
	//function to add an edge to graph.
	void addEdge(int v, int w);
	
	// prints a Topological sort of the complete graph.
	void topologicalSort();
};

//Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &stack)
{
	//Mark the current node as visited.
	visited[v]=true;
	//recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			topologicalSortUtil(*i, visited, stack);

	// Push current vertex to stack which stores the result.
	stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;

	//Mark all the vertices as not visited.
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	for(int i = 0; i < V; i++)
	{
		if(visited[i] == false)
			topologicalSortUtil(i, visited, Stack);
	}

	//Print contents of the stack
	while(Stack.empty() == false){
		cout<< Stack.top() << " ";
		Stack.pop();
	}
}

//Driver program to test the above function!!
int main(){
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(4, 0);
	g.addEdge(5, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout<< "Following is a topological sort of the given graph \n";
	g.topologicalSort();
	
	return 0;
}
