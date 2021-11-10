#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 6};

    int s = arr.size();
    vector<int> left(s);
    vector<int> right(s);
    left[0] = arr[0];
    right[s - 1] = arr[s - 1];

    for (int i = 1; i < s; i++)
    {
        left[i] = arr[i] + left[i - 1];
        right[s - i - 1] = arr[s - i - 1] + right[s - i];
    }

    for (int i = 0; i < s; i++)
    {
        if (left[i] == right[i])
            return i;
    }

    return 0;
}
