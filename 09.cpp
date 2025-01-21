class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        int finalval = false;
        int maximum = 0;
        if(n == 0 || n == 1){
            return finalval = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (i > maximum) {
                return finalval = false;
            }

            maximum = max(arr[i] + i, maximum);

            if (maximum >= n - 1) {
                return finalval = true;
            }
        }
        return finalval;
    }
};