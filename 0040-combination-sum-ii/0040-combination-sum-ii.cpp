class Solution {
public:
    void sum(int index, int target, vector<int>& ds, vector<int>& arr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); ++i) {
            if (i > index && arr[i] == arr[i - 1]) continue;  
            if (arr[i] > target) break;  

            ds.push_back(arr[i]);
            sum(i + 1, target - arr[i], ds, arr, res);  
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> ds;
        sum(0, target, ds, arr, res);
        return res;
    }
};
