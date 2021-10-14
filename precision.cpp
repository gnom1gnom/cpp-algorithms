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
    std::cout << "default precision (6): " << pi << '\n'
              << "std::setprecision(10): " << std::setprecision(10) << pi << '\n'
              << "max precision:         "
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << pi << '\n';

    double x = 2.7182818284590452353602874713527L;
    std::cout << std::setprecision(50) << x << std::endl;
    float y = x;
    uint8_t z{x};

    return 0;
}