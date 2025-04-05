#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ansTri(vector<int> arr)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end()); //-4 -1 -1 0 1 2
    for (int i = 0; i < arr.size() - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1, k = arr.size() - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0)
            {
                res.push_back({arr[i], arr[j], arr[k]});
                while (j < k && arr[j] == arr[j + 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k - 1])
                {
                    k--;
                }
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return res;
}

int main()
{

    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> answ = ansTri(arr);

    for (auto newArr : answ)
    {
        for (int el : newArr)
        {
            cout << el << " ";
        }
    }
    cout << endl;
    return 0;
}