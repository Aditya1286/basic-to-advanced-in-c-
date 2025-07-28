// class Solution {
// public:
//     int countSubsets(int index, int sum, int target, vector<int>& arr) {
//         if (index == arr.size()) {
//             if (sum == target)return 1;
//             return 0;
//         }

        
//         int l=countSubsets(index + 1, sum + arr[index], target, arr);

//         int r=countSubsets(index + 1, sum, target, arr);
//         return l+r;
//     }

//     int perfectSum(vector<int>& arr, int target) {
//         int count = 0;
//         return countSubsets(0, 0, target, arr);
        
//     }
// };
class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int index, int sum, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if(index == arr.size()) {
            return sum == target ? 1 : 0;
        }
        if(dp[index][sum] != -1) return dp[index][sum];

        int take = 0;
        if(sum + arr[index] <= target)
            take = solve(index + 1, sum + arr[index], arr, target, dp);

        int notTake = solve(index + 1, sum, arr, target, dp);

        return dp[index][sum] = (take + notTake) % mod;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(0, 0, arr, target, dp);
    }
};
