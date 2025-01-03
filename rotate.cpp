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