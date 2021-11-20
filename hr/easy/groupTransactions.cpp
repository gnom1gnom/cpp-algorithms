#include <bits/stdc++.h>

using namespace std;

vector<string> groupTransactions(vector<string> transactions)
{
    unordered_map<string, long> m;

    for (string s : transactions)
        m[s]++;

    vector<pair<string, int>> elems(m.begin(), m.end());
    sort(elems.begin(), elems.end(), [](pair<string, int> a, pair<string, int> b)
         {
             if (a.second > b.second)
                 return true;
             if (b.second > a.second)
                 return false;

             // a=b for primary condition, go to secondary
             if (a.first < b.first)
                 return true;
             else
                 return false;
         });

    vector<string> out;
    for (auto p : elems)
        out.push_back(p.first + " " + to_string(p.second));

    return out;
}

int main(int argc, char const *argv[])
{

    vector<string> transactions = {"bin", "can", "bin", "bin"};
    vector<string> out = groupTransactions(transactions);
    for (string o : out)
    {
        cout << o << endl;
    }

    return 0;
}