class Solution {
public:
    void sum(int index, int target, int count, int k, vector<int>& ds, vector<vector<int>>& res) {
        if (target == 0 && count == k) {
            res.push_back(ds);
            return;
        }
        if (target < 0 || count > k) return;

        for (int i = index; i <= 9; ++i) {
            ds.push_back(i);
            sum(i + 1, target - i, count + 1, k, ds, res);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        sum(1, n, 0, k, ds, res); 
        return res;
    }
};
