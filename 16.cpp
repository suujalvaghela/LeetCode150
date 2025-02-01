#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countH(vector<int> arr)
{
    vector<int> leftArr(arr.size() , 0), rightArr(arr.size() , 0);
    int maxi = 0;
    int newMaxi = 0;
    int totalWater = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
        leftArr[i] = maxi;
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        newMaxi = max(newMaxi , arr[i]);
        rightArr[i] = newMaxi;
    }

    for(int i = 0 ; i < arr.size() ; i++){
        int mini = min(leftArr[i] , rightArr[i]);
        totalWater += mini - arr[i];
    }
    return totalWater;
}

int main()
{

    vector<int> arr = {4,2,0,3,2,5};

    int h = countH(arr);
    cout << h << endl;
    return 0;
}