#include <bits/stdc++.h>
using namespace std;
// Data structure to store a graph edge
struct Edge
{
    int src, dest, weight;

    bool operator<(const Edge &other) const
    {
        if (weight == other.weight)
            return (src + dest < other.src + other.dest);
        if (weight < other.weight)
            return true;

        return false;
    }
};

// A class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;

    // stores the depth of trees
    unordered_map<int, int> rank;

public:
    // perform MakeSet operation
    DisjointSet(int n)
    {
        // create `n` disjoint sets (one for each vertex)
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the root of the set in which element `k` belongs
    int find(int k)
    {
        if (parent[k] != k)
        {
            // skracamy ścieżkę, żeby na przyszłość nie trawersować wszystkich parentów
            parent[k] = find(parent[k]);
        }

        return parent[k];
    }

    // Perform Union of two subsets
    void join(int a, int b)
    {
        // unie robimy na reprezentantach setu
        //  żeby nie tworzyc list powięzań

        // wyszukujemy reprezentantów
        int pA = find(a);
        int pB = find(b);

        // jeśli sety nie są już łaczne
        if (pA != pB)
        {
            // dążymy do tego żeby mniejszy set był podłącznony pod większy
            // w przeciwnym razie stworzylibyśmy listę zależności
            // kiedy łączymy 0->3 i 5 chcemy 0->3<-5, a nie 0->3->5
            if (rank[pA] < rank[pB])
                parent[pA] = pB;
            else if (rank[pB] < rank[pA])
                parent[pB] = pA;
            else // mają ten sam rank
            {
                parent[pB] = pA;
                rank[pB]++;
            }
        }
    }
};

// Function to construct MST using Kruskal’s algorithm
list<Edge> runKruskalAlgorithm(list<Edge> edges, int n) // no-ref, no-const
{
    list<Edge> mst;

    // sortujemy krawędzie wedlug wagi
    // zaczniemy od najmniejszych do największych
    edges.sort();

    DisjointSet ds(n);

    for (auto edge : edges)
    {
        int pSrc = ds.find(edge.src);
        int pDest = ds.find(edge.dest);

        // jeśli dodanie krawędzi sie stworzy cyklu
        if (pSrc != pDest)
        {
            mst.push_back(edge);
            ds.join(edge.src, edge.dest);
        }
    }

    return mst;
}

int main()
{
    // vector of graph edges as per the above diagram.
    list<Edge> edges =
        {
            // (u, v, w) triplet represent undirected edge from
            // vertex `u` to vertex `v` having weight `w`
            {0, 1, 7},
            {1, 2, 8},
            {0, 3, 5},
            {1, 3, 9},
            {1, 4, 7},
            {2, 4, 5},
            {3, 4, 15},
            {3, 5, 6},
            {4, 5, 8},
            {4, 6, 9},
            {5, 6, 11}};

    // total number of nodes in the graph (labelled from 0 to 6)
    int n = 7;

    // construct graph
    list<Edge> e = runKruskalAlgorithm(edges, n);

    for (Edge &edge : e)
    {
        cout << "(" << edge.src << ", " << edge.dest << ", "
             << edge.weight << ")" << endl;
    }

    return 0;
}
