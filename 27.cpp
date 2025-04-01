#include <bits/stdc++.h>
using namespace std;

vector<int> findSum(vector<int> arr1, int sum)
{
    int left = 0, right = arr1.size() - 1, elSum = 0;

    while (left < right)
    {
        elSum = arr1[left] + arr1[right];
        if (elSum == sum)
        {
            return {left + 1, right + 1};
        }
        else if (elSum < sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 8};
    int sum = 12;

    vector<int> arr2 = findSum(arr1, sum);
    for (int el : arr2)
    {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}