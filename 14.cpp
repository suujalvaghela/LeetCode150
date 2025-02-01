// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         int sum = 0;
//         int firstIdx, prvIdx;
//         bool isFirst = true;

//         for (int i = 0; i < n; i++) {
//             if (isFirst && sum + (gas[i] - cost[i]) >= 0) {
//                 isFirst = false;
//                 firstIdx = i;
//                 if (i != 0) {
//                     prvIdx = i - 1;
//                 }
//                 sum += gas[i] - cost[i];
//                 if (i + 1 != n) {
//                     sum += gas[i + 1];
//                 } else {
//                     sum += gas[0];
//                 }
//             } else if (!isFirst && sum - cost[i] >= 0) {
//                 sum -= cost[i];
//                 if (i + 1 != n) {
//                     sum += gas[i + 1];
//                 } else {
//                     sum += gas[0];
//                 }
//             } else if (!isFirst) {
//                 isFirst = true;
//                 sum = 0;
//             }
//         }
//         if(isFirst){
//             return -1;
//         }

//         if (!isFirst && firstIdx > 0) {
//             for (int i = 0; i < firstIdx - 1; i++) {
//                 if (sum - cost[i] >= 0) {
//                     sum = sum - cost[i] + gas[i + 1];
//                 } else {
//                     return -1;
//                 }
//             }
//         }
//         if (firstIdx == 0 || sum >= cost[prvIdx]) { //3,1,1         1,2,2
//             return firstIdx;
//         }
//         return -1;
//     }
// };

#include <iostream>
#include <vector>
using namespace std;

int findidx(vector<int> arr, vector<int> gas)
{
    int comb = 0, plus1 = 0, plus2 = 0, stIdx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        plus1 += arr[i];
        plus2 += gas[i];
        comb += arr[i] - gas[i];

        if (comb < 0)
        {
            stIdx = i+1;
            comb = 0;
        }
    }
    if (plus1 < plus2)
    {
        return -1;
    }
    return stIdx;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5}, gas = {3, 4, 5, 1, 2};

    int idx = findidx(arr, gas);

    cout<<idx<<endl;
    return 0;
}