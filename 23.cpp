#include <bits/stdc++.h>
using namespace std;

int cont(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int j = 0;
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        if (s1[i] == s2[j])
        {
            j++;
            if (j == n2)
            {
                return i - n2 + 1;
            }
        }
        else
        {
            if (j > 0)
            {
                i -= j; // first match failed so firstmatch+1
            }
            j = 0;
        }
    }
    return -1;
}

int main()
{
    string s1 = "mississippi";
    string s2 = "issip";

    int idx = cont(s1, s2);
    cout << idx << endl;
    return 0;
}