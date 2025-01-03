#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> removedup(vector<int>& arr)
{
    // if(arr.size() == 0){
    //     return 0;
    // }

    vector<int> arr2;
    arr2.push_back(arr[0]);
    arr2.push_back(arr[1]);

    for (int i = 2; i < arr.size(); i++)
    {
        if (arr[i] != arr[i - 2])
        {
            arr2.push_back(arr[i]);
        }
    }
    return arr2;
}

int main()
{

    vector<int> arr = {1,1,1,2,2,3};

    vector<int> arr2 = removedup(arr);

    for (int el : arr2)
    {
        cout << el << " ";
    }

    cout<<endl;
    return 0;
}