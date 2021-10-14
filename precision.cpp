#include <cstdio>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

struct Incrementer
{
    int value;
    Incrementer(int value) : value{value + 10} {}

    void print()
    {
        cout << "incrementer = " << value << "\n";
    }

    Incrementer operator+(int other)
    {
        return Incrementer(other + value);
    }
};

void printWithPrecision(auto input)
{
    std::cout << "default precision (6): " << std::setprecision(6) << input << std::endl
              << "std::setprecision(10): " << std::setprecision(10) << input << std::endl
              << "max precision:         "
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << input << std::endl;
}

int main(int argc, char const *argv[])
{
    // int x = 10;
    // x += 5;
    // cout << "x= " << x << "\n";
    // x /= 3;
    // cout << "x= " << x << "\n";
    // x %= 2;
    // cout << "x= " << x << "\n";

    Incrementer incr{10};
    incr.print();
    Incrementer incr2 = incr + 10;
    incr2.print();

    const long double pi = std::acos(-1.L);
    printWithPrecision(pi);

    int y = pi;
    double z{pi};

    printWithPrecision(y);
    printWithPrecision(z);

    return 0;
}