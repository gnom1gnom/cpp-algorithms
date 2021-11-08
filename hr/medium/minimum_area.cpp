/*
 * Complete the 'minArea' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER_ARRAY y
 *  3. INTEGER k
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long minArea(vector<int> x, vector<int> y, int k)
{
    // szukamy lewej dolnej krawędzi
    // szukamy prawej górnej krawedzi
    int lowerX{INT_MAX}, lowerY{INT_MAX};
    int upperX{INT_MIN}, upperY{INT_MIN};

    vector<pair<int, int>> vect;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] < lowerX)
            lowerX = x[i] - 1;
        if (x[i] > upperX)
            upperX = x[i] + 1;

        if (y[i] < lowerY)
            lowerY = y[i] - 1;
        if (y[i] > upperY)
            upperY = y[i] + 1;

        vect.push_back(make_pair(x[i], y[i]));
    }

    sort(vect.begin(), vect.end());

    long bok = ((upperX - lowerX) > (upperY - lowerY)) ? (upperX - lowerX) : (upperY - lowerY);
    return bok * bok;

    // obszar zawężamy do k punktów
}

int main()
{ /*
    ofstream fout(getenv("OUTPUT_PATH"));

    string x_count_temp;
    getline(cin, x_count_temp);

    int x_count = stoi(ltrim(rtrim(x_count_temp)));

    vector<int> x(x_count);

    for (int i = 0; i < x_count; i++) {
        string x_item_temp;
        getline(cin, x_item_temp);

        int x_item = stoi(ltrim(rtrim(x_item_temp)));

        x[i] = x_item;
    }

    string y_count_temp;
    getline(cin, y_count_temp);

    int y_count = stoi(ltrim(rtrim(y_count_temp)));

    vector<int> y(y_count);

    for (int i = 0; i < y_count; i++) {
        string y_item_temp;
        getline(cin, y_item_temp);

        int y_item = stoi(ltrim(rtrim(y_item_temp)));

        y[i] = y_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));
    */

    vector<int> x = {-4, 3, 1};
    vector<int> y = {3, -1, -2};
    int k = 2;

    long result = minArea(x, y, k);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}