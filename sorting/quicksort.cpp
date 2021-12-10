#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

void sortuj(vector<int> &A, int left, int right)
{
    if (left >= right)
        return;

    int mid = (right + left) / 2;
    int pivot = A[mid];

    int l = left, r = right;
    while (l <= r) //
    {
        while (A[l] < pivot) // szukamy po lewej stronie pivota elementu który jest od niego większy
            l++;
        while (A[r] > pivot) // szukamy po prawej stronie pivota elementu który jest od niego mniejszy
            r--;

        // jeśli lewy i prawy index się nie spotkały
        if (l <= r)
        {
            swap(A[l], A[r]);
            l++;
            r--;
        }
    }

    sortuj(A, left, r);
    sortuj(A, l, right);
}

int main()
{
    vector<int> A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    // vector<int> A = {3, 5, 2, 4, 1};
    for (int i = 0; i < A.size(); i++)
    {
        fmt::print("{} ", A[i]);
        cout << flush;
    }

    fmt::print("\n");

    // L_pom.assign(A.size(), 0);

    sortuj(A, 0, A.size() - 1);

    cout << "Po posortowaniu:\n";
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}