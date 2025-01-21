class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        int maximum = 0;
        int minimum = 0;
        int curr = 0;
        if (n == 0 || n == 1) {
            return minimum;
        }
        for (int i = 0; i < n - 1; i++) {
            if (maximum < i) {
                return minimum = -1;
            }
            maximum = max(maximum, arr[i] + i);
            if (curr == i) {
                curr = maximum;
                minimum++;
            }
            if (curr >= n - 1) {
                return minimum;
            }
        }
        return minimum;
    }
};