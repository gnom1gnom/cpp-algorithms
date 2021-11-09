#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ratings = {2, 5, 6, 10, 7, 6, 7, 9, 7, 7};

    if (ratings.size() == 0)
        return 0;
    else if (ratings.size() == 1)
        return ratings[0];
    else
    {
        sort(ratings.begin(), ratings.end());

        int minBias = 0;

        for (int i = 0; i < ratings.size() - 1; i += 2)
            minBias += ratings[i + 1] - ratings[i];

        return minBias;
    }
}
