/*
Given a string, reduce it in such a way that all of its substrings are distinct. To do so, you may delete any characters at any index. What is the minimum number of deletions needed?Note: A substring is a contiguous group of 1 or more characters within a string.

Example

s = "abab"

Substrings in s are { 'a', 'b', 'a', 'b', 'ab', 'ba', 'ab', 'aba', 'bab', 'abab'}. By deleting one "a" and one "b", the string becomes "ab" or "ba" and all of its substrings are distinct. This required 2 deletions.

Function Description

Complete the function getMinDeletions in the editor below.

getMinDeletions has the following parameter(s):
   string s:  the given string

Returns:
   int: the minimum number of deletions required
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getMinDeletions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int getMinDeletions(string s)
{
    unordered_set<char> letterSet;
    int deletions = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // pozostawiamy w stringu unikalne litery
        auto search = letterSet.find(s[i]);
        if (search != letterSet.end())
            deletions++; // za kazdym razem kiedy znajdujemy powtorzenie, doliczamy deletion
        else
            letterSet.insert(s[i]);
    }
    return deletions;
}

int main()
{

    string s = "ffcccdndha";

    int result = getMinDeletions(s);

    cout << result << "\n";

    return 0;
}