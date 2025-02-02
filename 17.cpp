class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};
        int totalVal = 0 , currVal = 0 , nextVal = 0;

        for (int i = 0; i < s.size(); i++) { // III LVIII MCMXCIV 1000+100+90+4
            currVal = map[s[i]];
            if (i != s.size()) {
                nextVal = map[s[i + 1]];
            }
            if (currVal > nextVal) {
                totalVal += currVal;
            } else if (currVal < nextVal) {
                totalVal += nextVal - currVal;
                i++;
            } else {
                totalVal += currVal;
            }
        }

        return totalVal;
    }
};