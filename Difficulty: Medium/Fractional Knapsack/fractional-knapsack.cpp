#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

class Solution {
public:
    static bool comp(Item val1, Item val2) {
        double r1 = (double)val1.value / val1.weight;
        double r2 = (double)val2.value / val2.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> arr(n);

         for (int i = 0; i < n; i++) {
            arr[i].value = val[i];
            arr[i].weight = wt[i];
        }

        sort(arr.begin(), arr.end(), comp);

        double totalValue = 0.0;
        int curWeight = 0;

        for (int i = 0; i < n; i++) {
            if (curWeight + arr[i].weight <= capacity) {
                curWeight += arr[i].weight;
                totalValue += arr[i].value;
            } else {
                int remain = capacity - curWeight;
                totalValue += arr[i].value * ((double)remain / arr[i].weight);
                break;
            }
        }

        return totalValue;
    }
};