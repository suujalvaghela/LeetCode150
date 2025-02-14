#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string longestcommonprefix(vector<string> str)
{
    if (str.size() == 0)
    {
        return "";
    }
    string s = str[0];

    for (int i = 1; i < str.size(); i++)
    {
        string s1 = s;
        string s2 = str[i];

        s = "";

        int minL = min(s1.size(), s2.size());

        for (int j = 0; j < minL; j++)
        {
            if (s1[j] == s2[j])
            {
                s += s1[j];
            }
            else
            {
                break;
            }
        }
    }

    return s;
}

int main()
{

    vector<string> str = {"vaghelaaaaaa", "sujal", "vaghela"};

    string s = longestcommonprefix(str);
    cout << s << endl;

    return 0;
}