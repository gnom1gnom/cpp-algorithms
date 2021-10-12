#include <cstdio>
#include <iostream>

using namespace std;

/**
 * @brief Iterates over array and print elements
 *
 */
void iteratArray()
{

    int array_1[]{1, 2, 3};  // Array of length 3; 1, 2, 3
    int array_2[5]{};        // Array of length 5; 0, 0, 0, 0, 0
    int array_3[5]{1, 2, 3}; // Array of length 5; 1, 2, 3, 0, 0
    int array_4[5];          // Array of length 5; uninitialized values

    int arr[] = {11, 22, 33, 44};

    for (long i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("The %d element is %d.\n", i, arr[i]);
    }

    // or
    long i = 0;
    for (int val : arr)
    {
        printf("The element %d is %d.\n", ++i, val);
    }
}

enum class Race
{
    Dinan,
    Teklan,
    Ivyn,
    Moiran,
    Camite,
    Julian,
    Aidan
};

string raceToString(Race race)
{
    string result;
    switch (race)
    {
    case Race::Dinan:
    {
        result = "You work hard.";
    }
    break;
    case Race::Teklan:
    {
        result = "You are very strong.";
    }
    break;
    case Race::Ivyn:
    {
        result = "You are a great leader.";
    }
    break;
    case Race::Moiran:
    {
        result = "My, how versatile you are!";
    }
    break;
    case Race::Camite:
    {
        result = "You're incredibly helpful.";
    }
    break;
    case Race::Julian:
    {
        result = "Anything you want!";
    }
    break;
    case Race::Aidan:
    {
        result = "What an enigma.";
    }
    break;
    default:
    {
        result = "Error: unknown race!";
    }
    }
    return result;
}

int main()
{
    iteratArray();
    string raceResult = raceToString(Race::Camite);
    printf("The result is %s\n", raceResult.c_str());
    cout << raceResult << "\n";
}