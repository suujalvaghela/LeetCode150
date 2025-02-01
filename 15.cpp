// #include <iostream>
// #include <vector>
// using namespace std;

// int countcandy(vector<int> arr){
//     int count = 1;
//     for(int i = 1 ; i < arr.size() ; i++){
//         if(arr[i] == arr[i-1]){
//             count++;
//         }else{
//             count = count + 2;
//         }
//     }
//     return count;
// }

// int main(){

//     vector<int> arr = {1,2,2};

//     int Tcandy = countcandy(arr);

//     cout<<Tcandy<<endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countcandy(vector<int> arr, vector<int> candyarr)
{
    int Tcandy = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] < arr[i])
        {
            candyarr[i] = candyarr[i -1] + 1;
        }
    } // 1 2 3 4 1
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            candyarr[i] = max(candyarr[i] , candyarr[i + 1] + 1);
        }
    } // 1 2 3 2 1 

    for (int el : candyarr)
    {
        Tcandy += el;
    }
    return Tcandy;
}

int main()
{

    vector<int> arr = {1,3,4,5,2}; 
    vector<int> candyarr(arr.size(), 1);

    int Tcandy = countcandy(arr, candyarr);

    cout << Tcandy << endl;
    return 0;
}