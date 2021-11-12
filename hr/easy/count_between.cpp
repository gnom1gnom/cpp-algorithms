#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &array, int var, bool isLow)
{
    if (isLow && var <= array[0])
        return 0;

    if (!isLow && var >= array[array.size() - 1])
        return array.size() - 1;

    //array should be sorted in ascending order in this case
    int start = 0;
    int end = array.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (array[mid] == var)
        {
            return mid;
        }
        else if (var < array[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    // nie znaleźliśmy szukanego elementu przedziału
    if (isLow)
    {
        if (array[mid] < var)
            return mid + 1;
    }
    else if (array[mid] > var)
        return mid - 1;

    return mid;
}

vector<int> countBetween(vector<int> arr, vector<int> low, vector<int> high)
{
    vector<int> out;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < low.size(); i++)
    {
        int lind = binarySearch(arr, low[i], true);
        int hind = binarySearch(arr, high[i], false);

        if (lind >= 0 && lind < arr.size() && hind >= 0 && hind < arr.size())
            out.push_back(hind - lind + 1);
        else
            out.push_back(0);
    }
    return out;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 1};
    int indL = binarySearch(arr, 1, true);
    int indH = binarySearch(arr, 1, false);
    cout << "arr[" << indL << "]=" << arr[indL] << endl;
    cout << "arr[" << indH << "]=" << arr[indH] << endl;

    return 0;
}
