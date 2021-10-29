#include <iostream>
using namespace std;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

string longestPalindrome(string mainString)
{
    int n = mainString.size();
    if (n == 0)
        return "";
    n = 2 * n + 1; // count the next position
    int LPS[n];    // array to store longest palindrome length
    LPS[0] = 0;    // Initialize starting even position as 0
    LPS[1] = 1;    // Initialize starting odd position as 1
    int centerIndex = 1;
    int rightIndex = 2;
    int right = 0, left;
    int maxPalLength = 0, maxCenterIndex = 0;
    int start = -1, end = -1, diff = -1;

    for (right = 2; right < n; right++)
    {
        left = 2 * centerIndex - right; // calculate left position using center and right
        LPS[right] = 0;
        diff = rightIndex - right;

        if (diff > 0)
            LPS[right] = min(LPS[left], diff);
        while (((right + LPS[right]) < n && (right - LPS[right]) > 0) && (((right + LPS[right] + 1) % 2 == 0) || (mainString[(right + LPS[right] + 1) / 2] == mainString[(right - LPS[right] - 1) / 2])))
        {
            LPS[right]++;
        }

        if (LPS[right] > maxPalLength)
        { // max palindrome length
            maxPalLength = LPS[right];
            maxCenterIndex = right;
        }

        if (right + LPS[right] > rightIndex)
        {
            centerIndex = right;
            rightIndex = right + LPS[right];
        }
    }

    start = (maxCenterIndex - maxPalLength) / 2;
    end = start + maxPalLength - 1;
    string palindrome;

    for (int i = start; i <= end; i++)
        palindrome += mainString[i];
    return palindrome;
}

int main(int argc, char *argv[])
{
    string mainString, palindrome;
    cout << "Enter String:";
    cin >> mainString;
    palindrome = longestPalindrome(mainString);
    cout << "Longest palindrome is: " << palindrome << endl;
}