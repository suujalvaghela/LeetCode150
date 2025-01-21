#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int maxP = 0;
    int minB = arr[0];

    // cout<<maxPrice<<endl;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < minB) // 7,1,5,3,6,4
        {
            minB = arr[i]; 
        }
        else
        {
            int el = arr[i] - minB; 
            if(maxP < el){
                maxP=el;
            } 
        }
    }

    return maxP;
}

int main()
    {

        vector<int> arr = {7,8};

        int profit = maxProfit(arr);
        cout << profit << endl;
        return 0;
    }