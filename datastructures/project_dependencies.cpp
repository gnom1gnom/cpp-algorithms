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
    visiting, // ten stan jest poto żeby w DFS zorientować się że zatoczyłem cykl z dziecka do rodzica
    visited
};

template <class T>
class Graph
{
public:
    map<T, state> visit_state;
    map<T, list<T>> adj;

    void addEdge(T v, T w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }

    template <typename... ints>
    void addEdge(T v, ints... ws)
    {
        T args[]{ws...};
        for (T arg : args)
            adj[v].push_back(arg);
    }

    void clearVisited()
    {
        for (auto &elem : visit_state)
            elem.second = unvisited;
    }

    void DFS(T v, list<T> &queue)
    {
        // Mark the current node as visit_state and
        // print it
        if (visit_state[v] == visiting)
        {
            throw std::invalid_argument("Discovered a cycle in grapth");
        }
        if (visit_state[v] == unvisited)
        {
            visit_state[v] = visiting;

            // Recur for all the vertices adjacent
            // to this vertex

            for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
                if (visit_state[*i] == unvisited)
                    DFS(*i, queue);

            queue.push_front(v);
            visit_state[v] = visited;
        }
    }
};

// Driver code
int main(int argc, char const *argv[])
{

    // set<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    // vector<vector<char>> dependencies = {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};

    // set<char> projects = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    // vector<vector<char>> dependencies = {{'d', 'g'}, {'f', 'a'}, {'f', 'c'}, {'f', 'b'}, {'a', 'e'}, {'b', 'e'}, {'c', 'a'}, {'b', 'a'}};

    set<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<vector<char>> dependencies = {{'a', 'b'}, {'a', 'd'}, {'a', 'e'}, {'b', 'd'}, {'d', 'e'}, {'f', 'e'}};

    Graph<char> graph;

    for (auto d : dependencies)
    {
        graph.addEdge(d[0], d[1]);
        projects.erase(d[1]);
    }

    list<char> queue;
    graph.clearVisited();

    for (char root : projects)
        graph.DFS(root, queue);

    for (char p : queue)
        cout << p << " " << flush;

    cout << endl;

    return 0;
}