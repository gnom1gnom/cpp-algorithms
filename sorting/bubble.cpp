#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minComperator(int arg1, int arg2)
{
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int maxComperator(int arg1, int arg2)
{
    if (arg1 > arg2)
        return -1;
    if (arg1 < arg2)
        return 1;
    return 0;
}

void sort(vector<int> &L, int (*comperator)(int, int))
{
    size_t n = L.size();
    int temp;
    while (n)
    {
        for (int i = 1; i < n; i++)
        {
            // porównujemy sąsiadów
            if (comperator(L[i - 1], L[i]) == 1)
            {
                // większy jest po lewej - zamieniamy ich kolejnościa
                temp = L[i];
                L[i] = L[i - 1];
                L[i - 1] = temp;
            }
        }
        n--;
    }
}

int main()
{
    vector<int> L = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    int (*comperator)(int, int) = maxComperator;

    sort(L, comperator);
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " ";

    cout << endl;
    return 0;
}