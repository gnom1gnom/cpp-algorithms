#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

const int MOD = (int)(1e9 + 7);

unordered_map<char, vector<char>> charMap;

unordered_map<char, int> next(unordered_map<char, int> charsCount)
{
    unordered_map<char, int> outCount;
    outCount['a'] = 0;
    outCount['e'] = 0;
    outCount['i'] = 0;
    outCount['o'] = 0;
    outCount['u'] = 0;

    // dla każdej litery w aktualnej iteracji
    for (auto &charCount : charsCount)
    {
        // odszukaj mapowanie dla tej litery
        auto mapVal = charMap.find(charCount.first);

        vector<char> chars = mapVal->second;

        // dla akażdej liter z mapowania
        for (char c : chars)
        {
            // zwiększ ilość liter w aktualnej iteracji
            // multiplikując przez ilość liter z której mapowaliśmy
            // np: jedna litera 'e' daje jedno i oraz a, dwie 'e' dwa razy tyle
            outCount[c] = (outCount[c] + charCount.second) % MOD;
        }
    }

    return outCount;
}

int countPerms(int n)
{
    if (!n)
        return 0;

    charMap['a'] = vector<char>{'e'};
    charMap['e'] = vector<char>{'i', 'a'};
    charMap['i'] = vector<char>{'a', 'e', 'o', 'u'};
    charMap['o'] = vector<char>{'u', 'i'};
    charMap['u'] = vector<char>{'a'};

    unordered_map<char, int> charsCount;
    charsCount['a'] = 1;
    charsCount['e'] = 1;
    charsCount['i'] = 1;
    charsCount['o'] = 1;
    charsCount['u'] = 1;

    for (int i = 1; i < n; i++)
        charsCount = next(charsCount);

    int size = 0;
    for (auto &charCount : charsCount)
        size = (size + charCount.second) % MOD;

    return size;
}

int main()
{
    cout << countPerms(764) << endl;
}