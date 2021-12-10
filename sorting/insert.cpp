#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
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

void insertionSort(vector<int> &arr)
{
    int i, key, j;
    for (i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // z j zatrzymaliśmy się na pierwszym elemencie mniejszym lub RÓWNYM key
        // w wyniku przesuwania element wiekszy od key jest "zdublowany" - na swoim poprzednim i przesunietym miejscu
        // zastępujemy jego poprzednie miejsce przez key
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> L = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    insertionSort(L);

    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " ";

    cout << endl;
    return 0;
}