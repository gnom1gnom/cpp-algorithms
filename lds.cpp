#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int size = 16;

int binarySearch(int *tailTable, int N, int searchedTerm)
{
    int p = -1;
    int ip = 0;
    int ik = N - 1;
    int isr;

    while (ip <= ik)
    {
        isr = (ip + ik) >> 1;
        if (tailTable[isr] == searchedTerm)
        {
            p = isr;
            break;
        }
        else if (searchedTerm < tailTable[isr])
            ik = isr - 1;
        else
            ip = isr + 1;
    }

    return p;
}

int binarySearch(int tailTable[], int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;

        if (tailTable[m] <= key)
        {
            r = m;
        }

        else
        {
            l = m;
        }
    }
    return r;
}

int LDS(vector<int> arr)
{

    // Add boundary case, when array size is one.
    int size = arr.size();

    int tailTable[size];
    std::fill(tailTable, tailTable + size, -1);

    // Always points empty slot.
    int len;
    tailTable[0] = arr[0];
    len = 1;

    for (int i = 1; i < size; i++)
    {

        if (arr[i] > tailTable[0])
        {

            // New greatest value.
            tailTable[0] = arr[i];
        }

        else if (arr[i] < tailTable[len - 1])
        {

            // arr[i] wants to extend largest subsequence.
            tailTable[len++] = arr[i];
        }

        else
        {

            /*
                arr[i] wants to be current end candidate of an existing subsequence.
                It will replace ceiling value in tailTable.
            */
            tailTable[binarySearch(tailTable, len, arr[i])] = arr[i];
            // tailTable[binarySearch(tailTable, -1, len - 1, arr[i])] = arr[i];
        }
    }
    return len;
}

int main()
{
    vector<int> nums = {14, 8, 4, 12, 2, 10, 6, 10, 1, 9, 5, 13, 3, 11, 7, 15};

    for (int num : nums)
        cout << num << " ";
    cout << endl;
    cout << "The length of the LDS is " << LDS(nums) << endl;

    return 0;
}