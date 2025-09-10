class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long total_waiting_time = 0;
        long long current_time = 0;
        int n = bt.size();
        
        for (int i = 0; i < n; i++) {
            total_waiting_time += current_time;
            current_time += bt[i];
        }
        
        return total_waiting_time / n;
    }
};
