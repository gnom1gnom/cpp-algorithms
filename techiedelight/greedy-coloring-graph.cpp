#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

// https://www.techiedelight.com/greedy-coloring-graph/

// Data structure to store a graph edge
struct Edge
{
    int src, dest;
};

class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);

        // add edges to the undirected graph
        for (Edge edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

// Add more colors for graphs with many more vertices
string color[] =
    {
        "", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
        "BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"};

// Function to assign colors to vertices of a graph
void colorGraph(Graph const &graph, int n)
{
    // keep track of the color assigned to each vertex
    unordered_map<int, int> result;

    // assign a color to vertex one by one
    for (int u = 0; u < n; u++)
    {
        // set to store the color of adjacent vertices of `u`
        set<int> assigned;

        // check colors of adjacent vertices of `u` and store them in a set
        for (int i : graph.adjList[u])
        {
            if (result[i])
            {
                assigned.insert(result[i]);
            }
        }

        // check for the first free color
        int color = 1;
        for (auto &c : assigned)
        {
            if (color != c)
            {
                break;
            }
            color++;
        }

        // assign vertex `u` the first available color
        result[u] = color;
    }

    for (int v = 0; v < n; v++)
    {
        cout << "The color assigned to vertex " << v << " is "
             << color[result[v]] << endl;
    }
}

// Add more colors for graphs with many more vertices
unordered_set<string> colors =
    {
        "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
        "WHITE", "PURPLE", "VOILET"};

// Function to assign colors to vertices of a graph
void my_colorGraph(Graph const &g, int n)
{
    unordered_map<int, string> vertexColors;

    for (int v = 0; v < n; v++)
    {
        unordered_set<string> free_colors(colors);
        for (auto c : g.adjList[v])
        {
            if (vertexColors.find(c) != vertexColors.end())
                free_colors.erase(vertexColors[c]);
        }

        vertexColors[v] = *free_colors.begin();
    }

    for (int v = 0; v < n; v++)
    {
        fmt::print("{}:{} ", v, vertexColors[v]);
    }
}

// Function to check if it is safe to assign color `c` to vertex `v`
bool isSafe(Graph const &graph, vector<int> clr, int v, int c)
{
    // check the color of every adjacent vertex of `v`
    for (int u : graph.adjList[v])
    {
        if (clr[u] == c)
        {
            return false;
        }
    }

    return true;
}

void kColorable(Graph const &graph, vector<int> &clr, int k, int v, int n)
{
    // if all colors are assigned, print the solution
    if (v == n)
    {
        for (int v = 0; v < n; v++)
        {
            cout << setw(8) << left << color[clr[v]];
        }
        cout << endl;

        return;
    }

    // try all possible combinations of available colors
    for (int c = 1; c <= k; c++)
    {
        // if it is safe to assign color `c` to vertex `v`
        if (isSafe(graph, clr, v, c))
        {
            // assign color `c` to vertex `v`
            clr[v] = c;

            // recur for the next vertex
            kColorable(graph, clr, k, v + 1, n);

            // backtrack
            // bez tego kolejne iteracje nie zaczynałyby z czystym arrayem
            clr[v] = 0;
        }
    }
}

// Greedy coloring of a graph
int main()
{
    // vector of graph edges as per the above diagram
    // vector<Edge> edges = {{0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}};
    vector<Edge> edges = {{0, 1}, {0, 2}, {1, 2}};

    // total number of nodes in the graph (labelled from 0 to 5)
    int n = 3;

    // build a graph from the given edges
    Graph graph(edges, n);

    // color graph using the greedy algorithm
    colorGraph(graph, n);
    cout << endl;

    int k = 3;

    vector<int> color(n, 0);

    // print all k–colorable configurations of the graph
    kColorable(graph, color, k, 0, n);

    return 0;
}