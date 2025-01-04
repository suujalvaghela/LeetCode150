class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minBuy = arr[0];
        int maxProfit = 0;
        for(int i = 1 ; i<arr.size() ; i++){
            if(arr[i] < minBuy){
                minBuy = arr[i];
            }else{
                maxProfit += (arr[i] - minBuy);
                minBuy = arr[i];
            }
        }
        return maxProfit;
    }
};