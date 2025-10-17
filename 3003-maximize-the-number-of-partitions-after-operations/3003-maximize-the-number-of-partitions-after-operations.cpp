#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long,int> mem;
        return dfs(s, 0, true, 0, k, mem) + 1;
    }
private:
    int dfs(const string& s, int i, bool canChange, int mask, int k, unordered_map<long long,int>& mem) {
        if (i == (int)s.length()) return 0;
        long long key = (static_cast<long long>(i) << 27) | (static_cast<long long>(canChange ? 1 : 0) << 26) | mask;
        auto it = mem.find(key);
        if (it != mem.end()) return it->second;
        int res = getRes(s, i, canChange, mask, 1 << (s[i] - 'a'), k, mem);
        if (canChange) {
            for (int j = 0; j < 26; ++j) {
                res = max(res, getRes(s, i, false, mask, 1 << j, k, mem));
            }
        }
        mem[key] = res;
        return res;
    }
    int getRes(const string& s, int i, bool nextCanChange, int mask, int newBit, int k, unordered_map<long long,int>& mem) {
        int newMask = mask | newBit;
        if (__builtin_popcount((unsigned)newMask) > k)
            return 1 + dfs(s, i + 1, nextCanChange, newBit, k, mem);
        return dfs(s, i + 1, nextCanChange, newMask, k, mem);
    }
};
