#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void _scal(vector<int> &L, int from, int sr, int to)
{
    // Ze względu na to, że będziemy zapisywać posortowane dane w głównej tablicy L
    // wykonujemy kopię elementów w tablicy L_pom
    vector<int> L_pom = L;

    // i oraz j to indeks początkowego elementu listy 1 i listy 2.
    int i = from, j = sr + 1;

    for (int k = from; k <= to; k++)
    {
        if (i <= sr) // Sprawdzamy czy 1 podlista ma jakiekolwiek elementy
        {
            if (j <= to) // Sprawdzamy czy 2 podlista ma jakiekolwiek elementy
            {
                // obie listy są niepuste to porównujemy i przepisujemy mniejszy element
                L[k] = (L_pom[j] < L_pom[i]) ? L_pom[j++] : L_pom[i++];
            }
            else
            {
                // L[k] = L_pom[i++]; // Jeśli nie to przepisujemy element z listy 1.
                while (i <= sr)
                {
                    L[k++] = L_pom[i++];
                }
            }
        }
        else // Jeśli nie to przepisujemy element z listy 2.
        {
            // L[k] = L_pom[j++];
            while (j <= to)
            {
                L[k++] = L_pom[j++];
            }
        }
    }
}

void my_scal(vector<int> &L, int from, int mid, int to)
{
    vector<int> L_old = L;

    int left = from, right = mid + 1;

    for (int m = from; m <= to; m++)
    {
        if (left <= mid) // czy są elementy na pierwszej liście
        {
            if (right <= to) // czy są elementy na drugiej liscie
            {
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
    vector<int> L = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    // vector<int> L = {3, 5, 2, 4, 1};
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " ";

    cout << endl;

    // L_pom.assign(L.size(), 0);

    sortuj(L, 0, L.size() - 1);

    cout << "Po posortowaniu:\n";
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " ";

    cout << endl;
    return 0;
}