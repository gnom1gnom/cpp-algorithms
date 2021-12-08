#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

template <class T>
class Graph
{
public:
    map<T, list<T>> adj;

    void addEdge(T v, T w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }
};

int main()
{
    // bool *visited, *color;

    // cout << "Czytamy liczbę wierzchołków i krawędzi\n";
    // cin >> n >> m; // Czytamy liczbę wierzchołków i krawędzi

    // Tworzymy zmienne dynamiczne

    map<int, list<int>> adj;
    map<int, bool> color;   // Kawalerowie ( true ), panny ( false )
    map<int, int> matching; // Skojarzenia
    map<int, int> augment;  // Ścieżka rozszerzająca
    map<int, bool> visited; // Odwiedziny

    int n = 10;
    vector<vector<int>> edges = {{0, 7}, {0, 8}, {1, 8}, {1, 6}, {1, 5}, {2, 5}, {3, 9}, {3, 8}, {3, 6}, {4, 8}, {4, 7}};
    for (auto edge : edges)
    {

        int x = edge[0];
        int y = edge[1];

        adj[x].push_back(y);
        adj[y].push_back(x);

        color[x] = false; // Panna
        color[y] = true;  // Kawaler
    }

    cout << endl;

    // Algorytm znajdowania maksymalnego skojarzenia

    for (int i = 0; i < n; i++) // Elementy tablicy matching ustawiamy na -1
        matching[i] = -1;       // Co oznacza brak skojarzenia

    list<int> Q;
    for (int v = 0; v < n; v++) // Przechodzimy przez kolejne wierzchołki
        if ((matching[v] == -1) && !color[v]) // jeśli panna bez kawalera
        {
            for (int i = 0; i < n; i++)
                visited[i] = false; // Zerujemy tablicę odwiedzin

            Q.clear();

            visited[v] = true; // Oznaczamy v jako wierzchołek odwiedzony
            augment[v] = -1;   // Poprzednikiem v jest korzeń drzewa rozpinającego
            Q.push_back(v);    // Umieszczamy v w kolejce

            while (!Q.empty()) // Uruchamiamy BFS
            {
                int x = Q.front(); // Pobieramy x z kolejki
                Q.pop_front();     // Pobrany wierzchołek usuwamy z kolejki

                if (color[x])
                { // Kawalerowie
                    if (matching[x] == -1)
                    { // Kawaler wolny
                        while (augment[x] > -1)
                        {
                            if (color[x])
                            { // Zamieniamy krawędzie skojarzone z nieskojarzonymi
                                matching[x] = augment[x];
                                matching[augment[x]] = x;
                            }
                            x = augment[x]; // Cofamy się po ścieżce rozszerzającej
                        }
                        break; // Wracamy do pętli głównej
                    }
                    else
                    { // Kawaler skojarzony
                        augment[matching[x]] = x;
                        visited[matching[x]] = true;
                        Q.push_back(matching[x]); // W kolejce umieszczamy skojarzoną pannę
                    }
                }
                else
                {
                    // Panny
                    //// Przeglądamy kawalerów
                    for (auto y : adj[x])
                    {
                        // y = p->v;        // Numer kawalera
                        if (!visited[y]) // Tylko kawalerowie nieskojarzeni
                        {                // są umieszczani w kolejce
                            visited[y] = true;
                            augment[y] = x; // Tworzymy ścieżkę rozszerzającą // to jest zachowujemy informacje o preferencjach kawalera
                            Q.push_back(y);
                        }
                    }
                }
            }
        }

    // Wyświetlamy skojarzenia panna --- kawaler

    for (int i = 0; i < n; i++)
        if (!color[i])
            cout << i << " --- " << matching[i] << endl;

    return 0;
}