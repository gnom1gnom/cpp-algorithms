#include <bits/stdc++.h>

using namespace std;

int howMany(string str)
{
    string regexPattern = "(^|\\s|\\?|\\!|\\,|\\.)[a-zA-Z\\-]+(?=(^|\\s|\\?|\\!|\\,|\\.|$))";
    const regex pattern(regexPattern);

    // Variable to count total
    // occurrences of the given word
    int count = 0;

    auto it = sregex_iterator(str.begin(), str.end(), pattern);

    for (it; it != sregex_iterator(); it++)
        count++;

    return count;
}

int _howMany(string sentence)
{
    if (sentence.size() == 0)
        return 0;

    long cnt = 0;
    char p = sentence[0];
    for (int i = 1; i < sentence.size(); i++)
    {
        char c = sentence[i];
        // jeśli prev to litera
        // i jesli current to interpunkcja
        if (isalpha(p) && (c == 32 || c == '?' || c == '!' || c == '.' || c == ','))
            cnt++;
        p = c;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    string s = "he is a good programmer, he won 865 competitions, but sometimes he dont. What do you think? All test-cases should pass. Done-done?";
    long cnt = howMany(s);
    cout << cnt << endl;

    return 0;
}
