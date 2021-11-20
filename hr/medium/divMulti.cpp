#include <bits/stdc++.h>

using namespace std;

vector<int> getCount(vector<int> arr)
{
    int mx = *max_element(arr.begin(), arr.end()) + 1;
    unordered_map<int, int> cnt;
    unordered_map<int, int> ans;
    for (int item : arr)
        cnt[item] += 1;

    // Sito Eratostenesa
    for (int i = 1; i < mx; i++)
    {
        for (int j = i + i; j < mx; j += i)
        {
            ans[i] += cnt[j];
            ans[j] += cnt[i];
        }
    }

    vector<int> out;
    for (int item : arr)
        out.push_back(cnt[item] - 1 + ans[item]);

    return out;
}

vector<int> _getCount(vector<int> arr)
{
    vector<int> m(arr.size());
    vector<int> d(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {

            if (arr[i] != arr[j] && arr[i] % arr[j] == 0)
            {
                m[i]++;
                d[j]++;
            }
            if (arr[j] % arr[i] == 0)
            {
                m[j]++;
                d[i]++;
            }
        }
    }

    vector<int> out(arr.size());
    for (int i = 0; i < arr.size(); i++)
        out[i] = m[i] + d[i];

    return out;
}

int main(int argc, char const *argv[])
{

    //vector<int> arr = {10, 10, 10, 10, 10};
    vector<int> arr = {1, 3, 4, 2, 6};
    vector<int> out = getCount(arr);
    for (int o : out)
    {
        cout << o << endl;
    }

    return 0;
}