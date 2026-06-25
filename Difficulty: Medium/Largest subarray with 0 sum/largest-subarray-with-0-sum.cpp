class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> mp; 

        int prefixSum = 0;
        int maxi = 0;

        for(int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if(prefixSum == 0) {
                maxi = i + 1;
            }

            if(mp.find(prefixSum) != mp.end()) {
                maxi = max(maxi, i - mp[prefixSum]);
            }
            else {
                mp[prefixSum] = i;
            }
        }

        return maxi;
    }
};