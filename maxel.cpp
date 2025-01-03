#include <iostream>
#include <vector>
using namespace std;

int maxel(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return arr[i];
        }
    }
    return 1;
}

int main()
{

    vector<int> arr = {2,2,1,1,1,2,2};
    int el = maxel(arr);

    cout<<el<<endl;
    return 0;
}