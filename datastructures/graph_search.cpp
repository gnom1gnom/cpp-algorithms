// C++ program to print DFS traversal from
// a given vertex in a given graph
#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// Graph class represents a directed graph
// using adjacency list representation

enum state
{
    unvisited,
    visited
};

class Graph
{
public:
    Graph(int root)
    {
        this->root = root;
    }
    int root;
    map<int, state> visit_state;
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
        for (auto &elem : visit_state)
            elem.second = unvisited;
    }

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);

    void BFS(int s);

    bool BFS(int s, int e);
};

void Graph::DFS(int v)
{
    // Mark the current node as visit_state and
    // print it
    visit_state[v] = visited;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (visit_state[*i] == unvisited)
            DFS(*i);
}

void Graph::BFS(int s)
{
    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visit_state and enqueue it
    visit_state[s] = visited;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visit_state,
        // then mark it visit_state and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (visit_state[*i] == unvisited)
            {
                visit_state[*i] = visited;
                queue.push_back(*i);
            }
        }
    }
}

bool Graph::BFS(int s, int e)
{
    if (s == e)
        return true;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visit_state and enqueue it
    // visit_state[s] = visiting;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " " << flush;
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visit_state,
        // then mark it visit_state and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (visit_state[*i] == unvisited)
            {
                if (*i == e)
                {
                    cout << e << " " << flush;
                    return true;
                }
                else
                {
                    // visit_state[*i] = visiting;
                    queue.push_back(*i);
                }
            }
            visit_state[s] = visited;
        }
    }
    return false;
}

// Driver code
int main()
{
    /**
     *  0 → 1 ← 2
     *  ↓ ↘ ↓ ↘ ↑
     *  5   4 ← 3
     **/

    Graph g(0);
    g.addEdge(0, 1, 4, 5);
    g.addEdge(1, 3, 4);
    g.addEdge(3, 2, 4);
    // cycle
    g.addEdge(2, 1);

    cout << "Depth First (starting from vertex 0) \n";
    g.clearVisited();
    g.DFS(g.root);
    cout << "\n";

    cout << "Breadth First (starting from vertex 0) \n";
    g.clearVisited();
    g.BFS(g.root);
    cout << "\n";

    cout << "Searching path between 2 and 4 \n";
    g.clearVisited();
    fmt::print("{}\n", g.BFS(2, 4));

    cout << "Searching path between 5 and 3 \n";
    g.clearVisited();
    fmt::print("{}\n", g.BFS(5, 3));

    return 0;
}