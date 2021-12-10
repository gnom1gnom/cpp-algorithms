#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

void my_scal(vector<int> &L, int from, int mid, int to)
{
    // Ze względu na to, że będziemy zapisywać posortowane dane w głównej tablicy L
    // wykonujemy kopię elementów w tablicy L_pom
    vector<int> L_old = L;

    // left oraz right to indeks początkowego elementu listy 1 i listy 2
    int left = from, right = mid + 1;

    for (int m = from; m <= to; m++) // m to pozycja w nowej posortowanie jiście w którą będziemy wstawiać posortowany element
    {
        if (left <= mid) // czy są elementy na pierwszej liście
        {
            if (right <= to) // czy są elementy na drugiej liscie
            {
                // obie listy są niepuste to porównujemy i przepisujemy mniejszy element
                if (L_old[left] <= L_old[right])
                    L[m] = L_old[left++];
                else
                    L[m] = L_old[right++];
            }
            else // else dodaj elementy z pierwszej listy
            {
                while (m <= to)
                {
                    L[m++] = L_old[left++];
                }
            }
        }
        else // dodaj lelementy z drugiej listy
        {
            while (m <= to)
            {
                L[m++] = L_old[right++];
            }
        }
    }
}

void sortuj(vector<int> &L, int from, int to)
{
    if (from >= to)
        return;

    int mid = (to + from) / 2;

    sortuj(L, from, mid);
    sortuj(L, mid + 1, to);

    my_scal(L, from, mid, to);
}

int main()
{
    // vector<int> L = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vector<int> L = {3, 5, 2, 4, 1};
    for (int i = 0; i < L.size(); i++)
    {
        fmt::print("{} ", L[i]);
        cout << flush;
    }

    fmt::print("\n");

    // L_pom.assign(L.size(), 0);

    sortuj(L, 0, L.size() - 1);

    cout << "Po posortowaniu:\n";
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " ";

    cout << endl;
    return 0;
}