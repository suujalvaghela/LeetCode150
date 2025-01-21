class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        
        for(int i = 0 ; i<n/2 ; i++){
            int temp = arr[i];
            arr[i] = arr[n-k+i];
            arr[n-k+i] = temp;
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k > nums.size()){
            return;
        }

        vector<int>temp;
        for (int i = nums.size() - k; i < nums.size(); i++){
            temp.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size()-k; i++){
            temp.push_back(nums[i]);
        }

        nums = temp;
    }
};

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &arr, int k)
{
    int idx = 0;
    int n = arr.size();
    for (int i = 0; i < n - k; i++)
    {
        if (n % 2 == 0)
        {
            arr[idx] = arr[n - k + i];
            arr[idx + k] = arr[i];
            idx++;
        }
        else
        {
            if (i != (n+1)/2)
            {
                arr[idx + k] = arr[i];
                arr[idx] = arr[n - k + i];
                idx++;
            }
            else
            {
                arr[idx + k] = arr[i];
                idx++;
            }
        }
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    int k = 3;

    for (int el : arr)
    {
        cout << el << " ";
    }
    cout << endl;

    rotate(arr, k);

    for (int el : arr)
    {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}