class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q : queries){
            int target = nums[q];
            auto &vec = mp[target];

            if(vec.size() == 1){
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(vec.begin(), vec.end(), q);
            int res = INT_MAX;

            int idx = it - vec.begin();

            int next = vec[(idx + 1) % vec.size()];
            int diff1 = abs(next - q);
            res = min(res, min(diff1, n - diff1));

            int prev = vec[(idx - 1 + vec.size()) % vec.size()];
            int diff2 = abs(prev - q);
            res = min(res, min(diff2, n - diff2));

            ans.push_back(res);
        }

        return ans;
    }
};