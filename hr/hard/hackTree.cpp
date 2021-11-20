#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> adj;
unordered_map<int, int> freq;

int dfs(int ver1, int ver2, vector<int> &cost, int summ, int k)
{
    summ += cost[ver1];
    summ %= k;

    int ans = freq[summ];

    freq[summ] += 1;
    for (int v : adj[ver1])
    {
        if (v != ver2)
            ans += dfs(v, ver1, cost, summ, k);
    }
    freq[summ] -= 1;

    return ans;
}

int countVerticalPaths(vector<int> cost, int edge_nodes, vector<int> edge_from, vector<int> edge_to, int k)
{
    freq[0] = 1;

    for (int i = 0; i < edge_from.size(); i++)
    {
        adj[edge_from[i] - 1].push_back(edge_to[i] - 1);
        adj[edge_to[i] - 1].push_back(edge_from[i] - 1);
    }

    return dfs(0, -1, cost, 0, k);
}

int main(int argc, char const *argv[])
{

    vector<int> cost = {1, 2, 2, 1, 2};
    int edge_nodes = 5;
    vector<int> edge_from = {2, 2, 1, 2};
    vector<int> edge_to = {3, 1, 4, 5};
    int k = 2;

    cout << countVerticalPaths(cost, edge_nodes, edge_from, edge_to, k) << endl;

    return 0;
}