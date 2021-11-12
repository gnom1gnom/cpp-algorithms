#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> icnt;

bool compareInterval(int i1, int i2)
{
    return icnt[i1] < icnt[i2] || (icnt[i1] == icnt[i2] && i1 < i2);
}

int main(int argc, char const *argv[])
{

    vector<int> items = {3, 1, 2, 2, 4};

    for (int v : items)
        icnt[v] += 1;

    sort(items.begin(), items.end(), compareInterval);

    for (int i : items)
        cout << i << " ";

    return 0;
}
