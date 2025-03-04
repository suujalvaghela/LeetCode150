#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    vector<string> newStr(numRows);
    string zigzag = "";
    bool isTrue = false;
    int i = 0;

    for (auto charac : s)
    {
        newStr[i] += charac;
        if (i == 0 || i == numRows - 1)
        {
            isTrue = !isTrue;
        }
        if (isTrue)
        {
            i++;
        }
        else
        {
            i--;
        }
    }
    for (auto charac : newStr)
    {
        zigzag += charac;
    }
    return zigzag;
}

int main()
{

    string s = "saaluvejlhga";
    int numRows = 3;

    string zigzag = convert(s, numRows);

    cout << zigzag;
    cout << endl;
    return 0;
}