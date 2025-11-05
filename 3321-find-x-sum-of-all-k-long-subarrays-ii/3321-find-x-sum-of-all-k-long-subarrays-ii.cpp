#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> freq;
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        multiset<pair<int,int>, decltype(cmp)> top(cmp), rest(cmp);
        long long sumTop = 0;
        auto moveToTop = [&](pair<int,int> p) {
            auto it = rest.find(p);
            if (it != rest.end()) rest.erase(it);
            top.insert(p);
            sumTop += 1LL * p.first * p.second;
        };
        auto moveToRest = [&](pair<int,int> p) {
            auto it = top.find(p);
            if (it != top.end()) {
                top.erase(it);
                sumTop -= 1LL * p.first * p.second;
                rest.insert(p);
            }
        };
        auto balance = [&]() {
            while ((int)top.size() > x) {
                auto it = prev(top.end());
                moveToRest(*it);
            }
            while ((int)top.size() < x && !rest.empty()) {
                auto it = rest.begin();
                moveToTop(*it);
            }
        };
        auto insert = [&](int val) {
            auto old = make_pair(freq[val], val);
            if (freq[val]) {
                auto it = top.find(old);
                if (it != top.end()) { sumTop -= 1LL * old.first * old.second; top.erase(it); }
                else {
                    auto it2 = rest.find(old);
                    if (it2 != rest.end()) rest.erase(it2);
                }
            }
            freq[val]++;
            auto now = make_pair(freq[val], val);
            if (top.size() < x) { top.insert(now); sumTop += 1LL * now.first * now.second; }
            else {
                auto it = prev(top.end());
                if (cmp(now, *it)) { sumTop += 1LL * now.first * now.second - 1LL * it->first * it->second; rest.insert(*it); top.erase(it); top.insert(now); }
                else rest.insert(now);
            }
        };
        auto erase = [&](int val) {
            auto old = make_pair(freq[val], val);
            auto it = top.find(old);
            if (it != top.end()) { sumTop -= 1LL * old.first * old.second; top.erase(it); }
            else {
                auto it2 = rest.find(old);
                if (it2 != rest.end()) rest.erase(it2);
            }
            freq[val]--;
            if (freq[val]) {
                auto now = make_pair(freq[val], val);
                rest.insert(now);
            }
            balance();
        };
        for (int i = 0; i < k; i++) insert(nums[i]);
        vector<long long> ans; ans.push_back(sumTop);
        for (int i = k; i < n; i++) {
            erase(nums[i - k]);
            insert(nums[i]);
            balance();
            ans.push_back(sumTop);
        }
        return ans;
    }
};
