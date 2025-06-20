#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }

        int val = -1;
        int maxCount = 0;

        for (auto& num : mpp) {
            if (num.second > n / 2) {
                if (num.second > maxCount) {
                    val = num.first;
                    maxCount = num.second;
                }
            }
        }

        return val;
    }
};
