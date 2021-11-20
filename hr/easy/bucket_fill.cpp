#include <bits/stdc++.h>

using namespace std;

int strokesRequired(vector<string> picture)
{
    //map<pair<int, int>, set<pair<int, int>>> G;
    map<string, set<string>> G;
    int rows{picture.size()}, columns{picture[0].size()};

    //initialize a dictionary to hold arrays of tuples(row, column);
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            G[to_string(r) + "|" + to_string(c)] = {};
        }
    }

    // initialize a bidirectional graph of connected nodes
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (c + 1 < columns)
            {
                //check east
                if (picture[r][c + 1] == picture[r][c])
                {
                    G[to_string(r) + "|" + to_string(c)].insert(to_string(r) + "|" + to_string(c + 1));
                    G[to_string(r) + "|" + to_string(c + 1)].insert(to_string(r) + "|" + to_string(c));
                }
            }
            if (r + 1 < rows)
            {
                //check south
                if (picture[r + 1][c] == picture[r][c])
                {
                    G[to_string(r) + "|" + to_string(c)].insert(to_string(r + 1) + "|" + to_string(c));
                    G[to_string(r + 1) + "|" + to_string(c)].insert(to_string(r) + "|" + to_string(c));
                }
            }
        }
    }

    //now that the graph is assembled, DFS to determine number;
    //of groups, this one is iterative;
    set<string> visited;
    int groups = 0;

    for (auto k : G)
    {
        if (visited.find(k.first) != visited.end())
            continue;

        while (!k.second.empty())
        {
            string node = *(k.second.rbegin());
            k.second.erase(*k.second.rbegin());

            if (visited.find(node) != visited.end())
                continue;

            visited.insert(node);

            k.second.insert(G[node].begin(), G[node].end());
        }
        groups += 1;
    }

    return groups;
}

int main(int argc, char const *argv[])
{

    vector<string> picture = {"bbba", "abba", "acaa", "aaac"};
    cout << strokesRequired(picture) << endl;
    return 0;
}