#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    vector<int> numbers = {1, 2, 3, 4, 5, 6};
    int k = 2;

    unordered_set<int> un(numbers.begin(), numbers.end());

    unordered_set<int>::iterator unItr = un.begin();

    int cnt = 0;

    while (unItr != un.end())
    {
        //nie sprawdzamy elementów kolejnych jedne po drugim, bo i tak wiem że jedyny element b musi być równy a+k
        // wystarczy sprawdzić czy jest taki w secie
        if (un.find(*unItr + k) != un.end())
        {
            cnt++;
            cout << "(" << *unItr << ", " << *unItr + k << ")" << endl;
        }
        unItr++;
    }

    return 0;
}