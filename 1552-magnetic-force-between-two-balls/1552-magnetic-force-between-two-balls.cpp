class Solution {
public:
    bool isPossible(vector<int>& pos, int m, int dist) {
        int count = 1, lastPos = pos[0];
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - lastPos >= dist) {
                count++;
                lastPos = pos[i];
            }
            if (count >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position[0];
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
