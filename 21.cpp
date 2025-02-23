#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string reverseString(string s)
{
    string s2 = "";

    int n = s.size();
    int i = n - 1;

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        string word = "";

        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            s2 += " " + word;
        }
    }
    return s2.substr(1);
}

int main()
{

    // string s = "the sky is blue";
    string s = "  hello world  ";

    string reverse = reverseString(s);

    for (auto ch : reverse)
    {
        cout << ch;
    }
    cout << endl;
    cout << reverse.size() << endl;

    return 0;
}