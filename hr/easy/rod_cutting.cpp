#include <bits/stdc++.h>

using namespace std;

vector<int> rodOffcut(vector<int> lengths)
{
    vector<int> sizes;
    sort(lengths.begin(), lengths.end());

    int small = 0;
    while (lengths.size() > 0)
    {
        sizes.push_back(lengths.size());
        small = lengths[0];
        // The reason is that indices are affected by erase so if you remove the 4-th element,
        // then the former 5-th element is now the new 4-th element, and it won't be processed by your loop if you're doing i++.
        for (int i = lengths.size() - 1; i >= 0; i--)
        {
            lengths[i] -= small;
            if (lengths[i] <= 0)
                lengths.erase(lengths.begin() + i);
        }
    }

    return sizes;
}

int main(int argc, char const *argv[])
{
    vector<int> rods = {5, 4, 4, 2, 2, 8};
    vector<int> sizes = rodOffcut(rods);

    return 0;
}
