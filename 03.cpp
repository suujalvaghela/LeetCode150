#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

 vector<int> removedup(vector<int>& arr1)
{
    vector<int> arr2;

    for (int i = 0; i < arr1.size(); i++)
    {
        if (arr1[i] != arr1[i - 1])
        {
            arr2.push_back(arr1[i]);
        }
    }

    
    return arr2;
}

int main()
{

    vector<int> arr1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    vector<int> arr2 = removedup(arr1);

    for(int el : arr2){
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}