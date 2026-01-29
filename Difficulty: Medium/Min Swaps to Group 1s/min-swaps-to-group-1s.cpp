class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();

        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) ones++;
        }

        if (ones == 1) return 0;
        if(ones==0)return -1;

        int zeroes = 0;
        for (int i = 0; i < ones; i++) {
            if (arr[i] == 0) zeroes++;
        }

        int minswap = zeroes;

        for (int i = ones; i < n; i++) {
            if (arr[i] == 0) zeroes++;           
            if (arr[i - ones] == 0) zeroes--;   
            minswap = min(minswap, zeroes);
        }

        return minswap;
    }
};
