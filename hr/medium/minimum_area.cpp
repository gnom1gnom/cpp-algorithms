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

    vector<pair<int, int>> vect;
    for (int i = 0; i < x.size(); i++)
    {
        vect.push_back(make_pair(x[i], y[i]));
    }

    sort(vect.begin(), vect.end());

    pair<int, int> lowerBig = vect.front();
    pair<int, int> upperBig = vect.back();

    long bokBig = ((upperBig.first - lowerBig.first) > (upperBig.second - lowerBig.second)) ? (upperBig.first - lowerBig.first) : (upperBig.second - lowerBig.second);

    cout << "large square: " << pow(bokBig + 2, 2) << endl;

    vector<pair<int, int>> vect_small;
    int nextIndex = vect.size() / 2;

    // odejmujemy punk lower albo upper 
    size_t lowerInd{0}, upperInd{vect.size() - 1};
    for (int i = vect.size(); i > k && upperInd > lowerInd; i--)
    {
        // kwadrat mniejszy o punkt z dołu
        pair<int, int> lower1 = vect[lowerInd];
        pair<int, int> upper1 = vect[upperInd - 1];
        long bok1 = ((upper1.first - lower1.first) > (upper1.second - lower1.second)) ? (upper1.first - lower1.first) : (upper1.second - lower1.second);

        // kwadrat mniejszy o punkt z góry
        pair<int, int> lower2 = vect[lowerInd + 1];
        pair<int, int> upper2 = vect[upperInd];
        long bok2 = ((upper2.first - lower2.first) > (upper2.second - lower2.second)) ? (upper2.first - lower2.first) : (upper2.second - lower2.second);

        // sprawdzamy który ma mniejszy bok
        // odrzucamy wierdzłołek który generuje większy bok
        (bok1 >= bok2) ? lowerInd++ : upperInd--;
    }

    pair<int, int> lower = vect[lowerInd];
    pair<int, int> upper = vect[upperInd];

    long bok = ((upper.first - lower.first) > (upper.second - lower.second)) ? (upper.first - lower.first) : (upper.second - lower.second);

    cout << "small square: " << pow(bok + 2, 2) << endl;

    return pow(bok + 2, 2);
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

    // out 81
    // vector<int> x = {0, 3};
    // vector<int> y = {0, 7};

    // out 36
    vector<int> x = {0, 0, 1, 1, 2, 2};
    vector<int> y = {0, 1, 0, 1, 0, 1};
    int k = 4;

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