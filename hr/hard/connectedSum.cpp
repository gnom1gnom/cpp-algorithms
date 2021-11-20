#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> v;
map<int, bool> visited;

int getConnectedComponentSize(int x)
{
    stack<int> nodes;
    nodes.push(x);

    visited[x] = true;
    int cnt = 0;
    while (nodes.size() > 0)
    {
        int x = nodes.top();
        nodes.pop();
        cnt += 1;
        for (int y : v[x])
        {
            if (visited[y] == false)
            {
                visited[y] = true;
                nodes.push(y);
            }
        }
    }
    return cnt;
}

int connectedSum(int graph_nodes, vector<int> graph_from, vector<int> graph_to)
{
    for (int i = 0; i < graph_from.size(); i++)
    {
        int x = graph_from[i];
        int y = graph_to[i];
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int ans = 0;
    for (int i = 1; i < graph_nodes + 1; i++)
    {
        if (visited[i] == false)
        {
            int cnt = getConnectedComponentSize(i);
            ans += ceil(sqrt(cnt));
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{

    int graph_nodes = 10;

    vector<int> graph_from = {1, 1, 2, 3, 7};

    vector<int> graph_to = {2, 3, 4, 5, 8};

    cout << connectedSum(graph_nodes, graph_from, graph_to) << endl;

    return 0;
}