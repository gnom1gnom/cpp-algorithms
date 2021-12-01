// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    Graph(int root)
    {
        this->root = root;
    }
    int root;
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }

    template <typename... ints>
    void addEdge(int v, ints... ws)
    {
        int args[]{ws...};
        for (int arg : args)
            adj[v].push_back(arg);
    }

    void clearVisited()
    {
        for (auto &elem : visited)
            elem.second = false;
    }

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);

    void BFS(int s);
};

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

void Graph::BFS(int s)
{
    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    /*
    Graph g(2);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0, 3);
    g.addEdge(3, 3);
    */

    Graph g(0);
    g.addEdge(0, 1, 4, 5);
    g.addEdge(1, 3, 4);
    g.addEdge(3, 2, 4);
    // cycle
    g.addEdge(2, 3);

    cout << "Depth First (starting from vertex 2) \n";
    g.clearVisited();
    g.DFS(g.root);
    cout << "\n";

    cout << "Breadth First (starting from vertex 2) \n";
    g.clearVisited();
    g.BFS(g.root);
    cout << "\n";

    return 0;
}

// improved by Vishnudev C
