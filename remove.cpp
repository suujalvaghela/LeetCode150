#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> arr1 = {3, 2, 2, 3};

    int val = 3;

    for(int el : arr1){
        if(el == val){
            arr1.pop_back(el);
        }
    }

    for(int element : arr1){
        cout<<element<<" ";
    }
    cout<<endl;

    return 0;
}