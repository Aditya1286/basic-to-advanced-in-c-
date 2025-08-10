#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombinations(int idx, int target, vector<int> &arr, vector<int> &current, vector<vector<int>> &result) {
        if (idx == arr.size()) {
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }
        
        if (arr[idx] <= target) {
            current.push_back(arr[idx]);
            findCombinations(idx, target - arr[idx], arr, current, result);
            current.pop_back();
        }
        
        findCombinations(idx + 1, target, arr, current, result);
    }

    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, target, arr, current, result);
        return result;
    }
};
