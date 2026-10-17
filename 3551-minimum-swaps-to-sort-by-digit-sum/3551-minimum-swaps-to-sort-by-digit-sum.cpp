
class Solution {
private:
    int sumofdigits(int n) {
        int x = 0;

        while (n != 0) {
            int rem = n % 10;
            x += rem;
            n /= 10;
        }

        return x;
    }

public:
    int minSwaps(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            v.push_back({
                sumofdigits(nums[i]),
                nums[i],
                i
            });
        }

        sort(v.begin(), v.end());

        vector<int> target(n);

        for (int i = 0; i < n; i++) {
            target[v[i][2]] = i;
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (target[i] == i || visited[i])
                continue;

            int j = i;
            int cycle = 0;

            while (!visited[j]) {
                cycle++;
                visited[j] = true;
                j = target[j];
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
