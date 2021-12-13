#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

template <typename T>
class BucketSorter
{
private:
    virtual int getBucket(T value, T max, int k) = 0;

public:
    vector<T> list; // list ot be sorted
    int k;          // bucket count

    BucketSorter(vector<T> list, int k)
    {
        this->list = list;
        this->k = k;
    }

    void print()
    {
        for (int i = 0; i < list.size(); i++)
            fmt::print("{} ", list[i]);

        fmt::print("\n");
    }

    void print(string message)
    {
        fmt::print("{}\n", message);
        print();
    }

    /**
     * Sortuje liczby dodatnie i ujemne
     **/
    void bucketSort()
    {
        vector<vector<T>> bucket;
        for (int i = 0; i < k; i++)
            bucket.push_back(vector<T>());

        T min = list[0], max = list[0];
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i] > max)
                max = list[i];
            else if (list[i] < min)
                min = list[i];
        }

        max = (max + min > 0) ? max : -min;
        max++;

        for (int i = 0; i < list.size(); i++)
            bucket[getBucket(list[i], max, k)].push_back(list[i]);

        for (int i = 0; i < k; i++)
            std::sort(bucket[i].begin(), bucket[i].end());

        list.clear();
        for (int i = 0; i < k; i++)
            for (int j = 0; j < bucket[i].size(); j++)
                list.push_back(bucket[i][j]);
    }
};

template <typename T>
class FractionBucketSorter : public BucketSorter<T>
{
    using BucketSorter<T>::BucketSorter;
    int getBucket(T value, T max, int k)
    {
        return value * k;
    }
};

template <typename T>
class PositiveBucketSorter : public BucketSorter<T>
{
    using BucketSorter<T>::BucketSorter;
    int getBucket(T value, T max, int k)
    {
        return (double(value) / double(max) * k);
    }
};

template <typename T>
class NegativeBucketSorter : public BucketSorter<T>
{
    using BucketSorter<T>::BucketSorter;
    int getBucket(T value, T max, int k)
    {
        return ((double(value) / double(max) + 1) / 2) * k;
    }
};

int main()
{
    int k = 5;

    vector<float> A = {0.8, 0.6, 0.1, 0.9, 0.07, 0.04, 0.0, 0.09, 0.8, 0.68};

    FractionBucketSorter<float> fbs(A, k);
    fbs.print();
    fbs.bucketSort();
    fbs.print("Po posortowaniu:");

    fmt::print("\n-----------------------------------------\n");
    vector<int> B = {0, 8, 4, 12, -2, 10, 6, 14, -1, -9, 5, -13, 3, 11, 7, 15};
    NegativeBucketSorter<int> nbs(B, k);
    nbs.print();
    nbs.bucketSort();
    nbs.print("Po posortowaniu:");

    fmt::print("\n-----------------------------------------\n");
    vector<float> C = {9.8, 0.6, 10.1, 1.9, 3.07, 3.04, 5.0, 8.0, 4.8, 7.68};
    PositiveBucketSorter<float> pbs(C, k);
    pbs.print();
    pbs.bucketSort();
    pbs.print("Po posortowaniu:");

    return 0;
}