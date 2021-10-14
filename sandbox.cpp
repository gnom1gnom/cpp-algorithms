#include <cstdio>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

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

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("The %d element is %d.\n", i, arr[i]);
    }

    // or
    int i = 0;
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

void petruchio(char *shrew)
{
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char *upper_ptr = upper; // Equivalent: &upper[0]

    lower[3] = 'd';     // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0

    char letter_d = lower[3];     // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D'

    printf("lower: %s\nupper: %s\n", lower, upper);
    shrew[0] = 'K';
    printf("Fear not, sweet wench, they shall not touch thee, %s.\n", shrew);

    // Compiler error! The shrew cannot be tamed.
}
struct ClockOfTheLongNow
{
    ClockOfTheLongNow(int year_in)
    {
        if (!set_year(year_in))
        {
            year = 2019;
        }
    }
    ClockOfTheLongNow()
    {
        year = 2019;
    }
    void add_year()
    {
        year++;
    }
    bool set_year(int new_year)
    {
        if (new_year < 2019)
            return false;
        year = new_year;
        return true;
    }
    int get_year() const
    {
        return year;
    }

private:
    int year;
};

struct Avout
{
    const char *name;
    ClockOfTheLongNow apert;

    Avout(const char *name, long year_of_apert) : name{name}, apert{year_of_apert}
    {
    }

    void announce() const
    {
        printf("My name is %s and my next apert is %d.\n", name, apert.get_year());
    }
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
    char shrew[]{"Dupa"};
    petruchio(shrew);
}