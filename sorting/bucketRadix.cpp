// implementation of radix sort using bin/bucket sort
#include <bits/stdc++.h>
using namespace std;

// utility function to get the number of digits in the
// max_element
int digits(int n)
{
    int i = 1;
    if (n < 10)
        return 1;

    while (n > (int)pow(10, i))
        i++;
    return i;
}

void radix_sort(vector<int> &arr)
{
    // size of the array to be sorted
    int sz = arr.size();

    // getting the maximum element in the array
    int max_val = *max_element(arr.begin(), arr.end());

    // getting digits in the maximum element
    int d = digits(max_val);

    // creating buckets to store the pointers

    // array of pointers to linked list of size 10 as
    // integers are decimal numbers so they can hold numbers
    // from 0-9 only, that's why size of 10

    vector<list<int>> bins(10);

    // first loop working for a constant time only and inner
    // loop is iterating through the array to store elements
    // of array in the linked list by their digits value
    for (int i = 0; i < d; i++)
    {
        // obliczanie cyfry przez modulo
        for (int j = 0; j < sz; j++) // bins updation
            bins[(arr[j] / (int)pow(10, i)) % 10].push_back(arr[j]);

        int x = 0, y = 0;
        // write back to the array after each pass

        while (x < 10)
        {
            while (!bins[x].empty())
            {
                arr[y++] = bins[x].front();
                bins[x].pop_front();
            }
            x++;
        }
    }
}

// a utility function to print the sorted array
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {573, 25, 415, 12, 161, 6};

    // function call
    radix_sort(arr);
    print(arr);

    return 0;
}
