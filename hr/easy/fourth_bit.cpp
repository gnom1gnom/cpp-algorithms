#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'fourthBit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER number as parameter.
 */

int fourthBit(int number)
{
    std::bitset<32> binary = std::bitset<32>(number); //to binary

    cout << binary << endl;
    for (int i = 0; i < binary.size(); i++)
        cout << binary[i];

    cout << endl;
    // index zerowy to 2^0
    return binary[3];
}

// tak na przysłość ;)
std::string toBinary(int n)
{
    std::string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

int main()
{

    cout << toBinary(77) << endl;
    int result = fourthBit(77);
    cout << result << endl;

    return 0;
}
