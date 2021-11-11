#include <bits/stdc++.h>

using namespace std;

int getTime(pair<int, int> pm, pair<int, int> cm)
{
    if (pm.first == cm.first)
        return abs(pm.second - cm.second);

    if (abs(pm.first - cm.first) == 1)
    {
        if (pm.second == cm.second)
            return 1;
        else
            return abs(pm.second - cm.second);
    }

    return 2;
}

int main(int argc, char const *argv[])
{
    string keypad = "923857614";
    string s = "423692";

    pair<int, int> keyMap[10];

    int iter = 0;
    for (int r = 1; r <= 3; r++)
    {
        for (int c = 1; c <= 3; c++)
        {
            int digit = keypad[iter] - '0';
            keyMap[digit] = pair<int, int>(r, c);
            iter++;
        }
    }

    unsigned long long int time = 0;
    int prev = s[0] - '0';

    for (int i = 1; i < s.size(); i++)
    {
        int current = s[i] - '0';

        pair<int, int> pm = keyMap[prev];
        pair<int, int> cm = keyMap[current];

        time += getTime(pm, cm);
        prev = current;
    }

    cout << time << endl;

    return 0;
}
