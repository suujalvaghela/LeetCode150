#include <bits/stdc++.h>
using namespace std;

int calcW(vector<int> heightt)
{
    int maxW = 0;
    int n = heightt.size();
    int left = 0, right = n - 1;

    while (left < right)
    {
        int minH = min(heightt[left], heightt[right]);
        int wid = right - left;

        int calcAns = minH * wid;

        maxW = max(maxW, calcAns);

        heightt[left] < heightt[right] ? left++ : right--;
    }

    return maxW;
}

int main()
{

    // vector<int> heightt = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> heightt = {1, 4 , 3};
    int answ = calcW(heightt);
    cout << answ << endl;
    return 0;
}