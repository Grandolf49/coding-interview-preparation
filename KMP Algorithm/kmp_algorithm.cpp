#include <iostream>

using namespace std;

void createLps(string pattern, int lps[])
{

    // Initialize LPS Array
    for (int i = 0; i < pattern.size(); i++)
    {
        lps[i] = 0;
    }

    // Create LPS Array
    int start = 0, end = 1;
    while (end < pattern.size())
    {
        if (pattern[start] == pattern[end])
        {
            lps[end] = start + 1;
            start++;
            end++;
        }
        else
        {
            if (lps[start] == 0)
            {
                start = 0;
                end++;
            }
            else
            {
                start = lps[start] - 1;
            }
        }
    }
}

bool kmp(string str, string pattern)
{
    int str_size = str.size();
    int pattern_size = pattern.size();
    bool result = false;

    if (str_size < pattern_size)
    {
        cout << "Error: Input string size is less than pattern size\n";
        return result;
    }

    int lps[pattern_size];
    createLps(pattern, lps);

    cout << "Pattern:\t";
    for (int i = 0; i < pattern_size; i++)
    {
        cout << pattern[i] << " ";
    }
    cout << "\n";

    cout << "LPS Array:\t";
    for (int i = 0; i < pattern_size; i++)
    {
        cout << lps[i] << " ";
    }
    cout << "\n\n";

    // Match Pattern P with String S
    int str_start = 0, pattern_start = 0;
    while (str_start < str_size)
    {
        cout << "str_start: " << str_start << " " << str[str_start] << " "
             << " pattern_start: " << pattern_start << " " << pattern[pattern_start] << "\n";

        if (str[str_start] == pattern[pattern_start])
        {
            cout << "matched\n";
            if (pattern_start == pattern_size - 1)
            {
                cout << "pattern found!\n";
                result = true;
                break;
            }
            str_start++;
            pattern_start++;
        }
        else
        {
            cout << "not matched\n";
            if (pattern_start == 0)
            {
                cout << "move to next character in main string\n";
                str_start++;
            }
            else if (lps[pattern_start - 1] == 0)
            {
                cout << "match pattern from start\n";
                pattern_start = 0;
            }
            else
            {
                cout << "go back to previously matched prefix\n";
                pattern_start = lps[pattern_start - 1];
            }
        }
        cout << "\n";
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /**
     * Input Format for input.txt file
     * (1st line) pattern
     * (2nd line) string
     *
     * Eg:
     * ababc
     * abbabcababc
    */

    string str, pattern;
    cin >> pattern;
    cin >> str;

    cout << "Pattern Present: " << kmp(str, pattern);
    return 0;
}