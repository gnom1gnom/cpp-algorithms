#include <cstdio>

/**
 * @brief Iterates over array and print elements
 * 
 */
void iteratArray()
{
    int arr[] = {11, 22, 33, 44};

    for (long i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("The %d element is %d.\n", i, arr[i]);
    }

    // or
    long i =0;
    for(int val : arr)
    {
       printf("The element %d is %d.\n", ++i, val); 
    }
    
}

int main()
{
    iteratArray();
}