#include <bits/stdc++.h>
using namespace std;

bool checkString(string s, string subS)
{
    int i = 0, j = 0;

    while (i < s.length() && j < subS.length())
    {
        if (s[i] != subS[j])
        {
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return j == subS.length();
}

int main()
{

    string s = "sujal";
    string subS = "sal";

    bool isIt = checkString(s, subS);

    if (isIt)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}