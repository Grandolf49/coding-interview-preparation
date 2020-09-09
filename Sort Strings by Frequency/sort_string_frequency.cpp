#include <bits/stdc++.h>

using namespace std;

// Comparator function to sort by the second value
bool sortByVal(const pair<string, int> &a, const pair<string, int> &b)
{
    return (a.second < b.second);
}

void calculateFrequency(vector<string> strings)
{
    // Create a map of strings and store count
    unordered_map<string, int> strMap;
    for (string str : strings)
    {
        // If string does not exist
        if (strMap.find(str) == strMap.end())
        {
            strMap[str] = 1;
        }
        else
        {
            strMap[str]++;
        }
    }

    // Add all elements into vector
    vector<pair<string, int>> vecStrings;
    for (auto itr = strMap.begin(); itr != strMap.end(); itr++)
    {
        vecStrings.push_back(make_pair(itr->first, itr->second));
    }

    // Sort the vector according to 2nd element
    sort(vecStrings.begin(), vecStrings.end(), sortByVal);

    // Print vectors in descending order
    for (int i = vecStrings.size() - 1; i >= 0; i--)
    {
        auto element = vecStrings[i];
        cout << element.first << " " << element.second << "\n";
    }
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    /**
     * Input Format for input.txt file
     * (1st line) size of array
     * (next n lines) n stringsstring
     *
     * Eg:
     * 6
     * covd
     * covd
     * snap
     * snap
     * title
     * title
     * title
    */
    vector<string> strings;
    int size;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        string temp;
        cin >> temp;
        strings.push_back(temp);
    }

    // Calculate frequency of each string
    calculateFrequency(strings);

    return 0;
}