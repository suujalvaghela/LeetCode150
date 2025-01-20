class Solution {
public:
    int hIndex(vector<int>& arr) { //[3,0,6,1,5] [1,3,1] [100]
        int n = arr.size();
        if (n == 0) {
            return 0;
        }
        int h = 0;
        for (int i = 0; i < n; i++) { // [ 0, 0, 2 ]
            int count = 0;
            if (arr[i] >= h && arr[i] > 0) {
                for (int j = 0; j < n; j++) {
                    if (arr[i] <= arr[j]) {
                        count++;
                        if (count > h) {
                             h = arr[i];
                        }
                    }
                }
            }
        }
        return h;
    }
};