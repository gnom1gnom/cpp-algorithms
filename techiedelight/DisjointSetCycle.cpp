#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

// Data structure to store a graph edge
struct Edge
{
    int src, dest;
};

// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);

        // add edges to the undirected graph (add each edge once only to avoid
        // detecting cycles among the same edges, say x -> y and y -> x)
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// A class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;

public:
    // perform MakeSet operation
    void MakeSet(int n)
    {
        // create `n` disjoint sets (one for each vertex)
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find the root of the set in which element `k` belongs
    int Find(int k)
    {
        // if `k` is root
        if (parent[k] == k)
        {
            return k;
        }

        // recur for the parent until we find the root
        return Find(parent[k]);
    }

    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find the root of the sets in which elements `x` and `y` belongs
        int x = Find(a);
        int y = Find(b);

        parent[x] = y;
    }
};

// Returns true if the graph has a cycle
bool findCycle(Graph const &graph, int n)
{
    // initialize Main class
    DisjointSet ds;

    // create a singleton set for each element of the universe
    ds.MakeSet(n);

    // consider every edge (u, v)
    for (int u = 0; u < n; u++)
    {
        // Recur for all adjacent vertices
        for (int v : graph.adjList[u])
        {
            // find the root of the sets to which elements `u` and `v` belongs
            int x = ds.Find(u);
            int y = ds.Find(v);

            // if both `u` and `v` have the same parent, the cycle is found
            if (x == y)
            {
                return true;
            }
            else
            {
                ds.Union(x, y);
            }
        }
    }

    return false;
}

// Union–find algorithm for cycle detection in a graph
int main()
{
    // vector of graph edges
    vector<Edge> edges =
        {
            {0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3}, {2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}
            // edge (10, 11) introduces a cycle in the graph
        };

    // total number of nodes in the graph (labelled from 0 to 11)
    int n = 12;

    // build a graph from the given edges
    Graph graph(edges, n);

    if (findCycle(graph, n))
    {
        cout << "Cycle Found" << endl;
    }
    else
    {
        cout << "No Cycle Found" << endl;
    }

    return 0;
}