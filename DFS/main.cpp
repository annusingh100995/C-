#include <iostream>
#include <list>

using namespace std;



// graph defined by adjacewncy list, ther can be adjacenty matrices
class Graph{

    int V; //number of vertices

    list<int> *adj; //pointer to an array containing the adacency list

    void DFSUtil(int v, bool visited[]); // function to implement dfs

public:

    // function prototyping


    Graph(int V); // constructor

    void DFS(int v); // actual dfs function

    void addEdge(int v , int w); // function to add edge in the graph


};

Graph::Graph(int V){

    // creates a list of v vertices
    this->V = V;
    adj = new list<int>[V];

}

void Graph::addEdge(int v , int w ){

    adj[v].push_back(w);
    // so , for each node you give the other node that are connected to it. basilcally numbers are used

}

void Graph::DFSUtil(int v, bool visited[]){

    // mark the curent node tobe visited and print it out
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);

}

void Graph::DFS(int v){

    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 5);
    g.addEdge(5, 2);
    g.addEdge(5, 4);
    g.addEdge(5, 3);
    g.addEdge(5, 0);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(4);

    return 0;
}








