class Solution {
  public:
    void backtrack(int index, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); ++i) {
            if (i > index && arr[i] == arr[i - 1]) continue; 
            if (arr[i] > target) break;

            ds.push_back(arr[i]);
            backtrack(i + 1, target - arr[i], arr, ds, res); 
            ds.pop_back();
        }
    }

    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> ds;
        backtrack(0, target, arr, ds, res);
        return res;
    }
};
