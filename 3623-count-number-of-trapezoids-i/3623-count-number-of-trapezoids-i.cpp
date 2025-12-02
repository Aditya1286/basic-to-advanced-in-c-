#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1'000'000'007LL;
        unordered_map<long long,long long> freq;

        for (auto &p : points) {
            long long y = p[1];
            freq[y]++;
        }

        long long prefix = 0;
        long long ans = 0;
        for (auto &kv : freq) {
            long long k = kv.second;
            if (k < 2) continue;
            long long c = (k * (k - 1)) / 2;
            long long cmod = c % MOD;
            ans = (ans + cmod * prefix) % MOD;
            prefix = (prefix + cmod) % MOD;
        }

        return (int)ans;
    }
};
