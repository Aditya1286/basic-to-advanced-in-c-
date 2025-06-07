class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ass;
        vector<bool> asd(arr[n - 1] + k + 1, false);

        for (int i = 0; i < n; i++) {
            if (arr[i] < asd.size())
                asd[arr[i]] = true;
        }

        for (int i = 1; i < asd.size(); i++) {
            if (asd[i] == false) {
                ass.push_back(i);
            }
        }

        return ass[k - 1];
    }
};
