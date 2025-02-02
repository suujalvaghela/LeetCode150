#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

void lastWords(string s)
{
    int count = 0;
    int n = s.size();
    int i = n - 1;

    while (i >= 0 && isspace(s[i])){
        i--;
    }

    while (i >= 0 && isalpha(s[i]))
    {
        count++;
        i--;
    }
    
        cout << count << endl;
}

int main()
{

    // string s = "hello world";
    // string s = "   fly me   to   the moon  ";
    string s = "luffy is still joyboy";

    lastWords(s);

    return 0;
}