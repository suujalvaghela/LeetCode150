
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// vector<int> product(vector<int> arr)
// {
//     vector<int> newarr;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int val = 1;
//         for (int j = 0; j < arr.size(); j++)
//         {
//             if (arr[i] != arr[j])
//             {
//                 val *= arr[j];
//             }
//         }
//         newarr.push_back(val);
//     }
//     return newarr;
// }

// int main()
// {

//     // vector<int> arr = {1, 2, 3, 4};
//     vector<int> arr = {-1,1,0,-3,3};

//     vector<int> newarr = product(arr);

//     for (int el : newarr)
//     {
//         cout << el << "  ";
//     }
//     return 0;
// }


vector<int> ProExIts(vector<int> & arr){
    int n = arr.size();
    vector<int> prefixx(n) , sufixx(n) , newArr(n);

    prefixx[0] = 1;

    for(int i = 1 ; i < n ; i++){
        prefixx[i] = arr[i-1] * prefixx[i-1];
    }

    sufixx[n-1] = 1;

    for(int i = n-2 ; i >= 0 ; i--){
        sufixx[i] = arr[i+1] * sufixx[i+1];
    }

    for(int i = 0 ; i < n ; i++){
        newArr[i] = prefixx[i] * sufixx[i];
    }

    return newArr;

}

int main(){

    vector<int> arr = {1,2,3,4};

    vector<int> newArr = ProExIts(arr);

    for(int el : newArr){
        cout<<el<<" ";
    }

    cout<<endl;

    return 0;
}