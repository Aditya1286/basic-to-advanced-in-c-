#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void func(int index, int sum, vector<int> &arr, int N, vector<int> &sub) {
        if (index == N) {
            sub.push_back(sum);
            return;
        }
        func(index + 1, sum + arr[index], arr, N, sub);
        func(index + 1, sum, arr, N, sub);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sub;
        func(0, 0, arr, arr.size(), sub);
        sort(sub.begin(), sub.end());
        return sub;
    }
};
