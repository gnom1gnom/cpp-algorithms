#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    vector<int> stocksProfit = {6, 6, 3, 9, 3, 5, 1};
    //vector<int> stocksProfit = {6, 12, 3, 9, 3, 5, 1};
    int target = 12;

    int cnt = 0;
    int halfCnt = 0;

    set<int> sp;

    for (int p : stocksProfit)
    {
        // target / 2 = p szukamy 2 pary która znikłaby nam zredukowana przez unikalnośc setu
        if (target / 2 == p)
            halfCnt++;
        else
            sp.insert(p);
    }

    if (halfCnt > 1)
    {
        cout << "(" << target / 2 << ", " << target / 2 << ")" << endl;
        cnt = 1;
    }

    set<int>::reverse_iterator i = sp.rbegin();

    while (i != sp.rend())
    {
        set<int>::iterator pair;

        while ((pair = sp.find(target - *i)) != sp.end())
        {
            cnt++;
            cout << "(" << *i << ", " << target - *i << ")" << endl;
            i = decltype(i)(sp.erase(std::next(i).base()));
        }
        i++;
    }

    cout << cnt << endl;

    return 0;
}