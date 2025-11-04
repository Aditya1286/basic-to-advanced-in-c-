#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            vector<pair<int, int>> arr;
            for (auto& it : freq) {
                arr.push_back({it.first, it.second});
            }
            sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            int count = 0;
            int sum = 0;
            for (auto &p : arr) {
                if (count == x) break;
                sum += p.first * p.second;
                count++;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
