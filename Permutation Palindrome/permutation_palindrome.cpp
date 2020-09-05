#include <iostream>

using namespace std;

int getBitVector(string str)
{
    int bitVector = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int idx = -1;
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            idx = (int)(str[i] - 'A');
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            idx = (int)(str[i] - 'a');
        }
        if (idx != -1)
        {
            cout << "idx: " << idx << "\n";
            bitVector = bitVector ^ (1 << idx);
        }
    }
    return bitVector;
}

bool isPalindromePermutation(string str)
{
    int bitVector = getBitVector(str);
    cout << "Bit Vector of \"" << str << "\" " << bitVector << "\n";

    if (bitVector == 0)
    {
        return true;
    }
    else if ((bitVector & (bitVector - 1)) == 0)
    {
        cout << "Set bits = 1\n";
        return true;
    }
    else
    {
        return false;
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
     * (1st line) string
     *
     * Eg:
     * tactcoa
    */

    string str;
    getline(cin, str);

    if (isPalindromePermutation(str))
    {
        cout << "\"" << str << "\" is a permutation of a palindrome\n";
    }
    else
    {
        cout << "\"" << str << "\" is NOT a permutation of a palindrome\n";
    }
    return 0;
}