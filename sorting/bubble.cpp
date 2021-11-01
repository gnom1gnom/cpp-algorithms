#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void sort(vector<int> &L)
{
    size_t n = L.size();

    double t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (L[j] > L[j + 1])
            {
                t = L[j];
                L[j] = L[j + 1];
                L[j + 1] = t;
            }
        }
    }
}

int main()
{
    vector<int> L = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    sort(L);
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " ";

    cout << endl;
    return 0;
}