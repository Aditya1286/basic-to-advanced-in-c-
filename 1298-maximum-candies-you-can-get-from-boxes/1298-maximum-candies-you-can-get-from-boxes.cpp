#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status,
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> owned(n, false);
        vector<bool> haveKey(n, false);
        vector<bool> processed(n, false);
        queue<int> q;
        long long totalCandies = 0;

        for (int b : initialBoxes) {
            if (!owned[b]) {
                owned[b] = true;
                if (status[b] == 1) {
                    q.push(b);
                }
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            if (processed[box]) continue;
            processed[box] = true;
            totalCandies += candies[box];

            for (int k : keys[box]) {
                if (!haveKey[k]) {
                    haveKey[k] = true;
                    if (owned[k] && !processed[k]) {
                        q.push(k);
                    }
                }
            }

            for (int innerBox : containedBoxes[box]) {
                if (!owned[innerBox]) {
                    owned[innerBox] = true;
                    if ((status[innerBox] == 1 || haveKey[innerBox]) && !processed[innerBox]) {
                        q.push(innerBox);
                    }
                }
            }
        }

        return (int) totalCandies;
    }
};
