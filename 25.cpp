#include <bits/stdc++.h>
using namespace std;

bool isValidPalindrome(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        if (!isalnum(s[left]))
        {
            left++;
        }
        else if (!isalnum(s[right]))
        {
            right--;
        }
        else if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

int main()
{

    string s = "sujal d vaghela , alehgav d l:ajus";
    bool result = isValidPalindrome(s);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}