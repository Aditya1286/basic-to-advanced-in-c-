class Solution {
private:
    bool canr(vector<int>& arr, int start, vector<int>& vis) {

        if(arr[start] == 0)
            return true;

        vis[start] = 1;

        if(start - arr[start] >= 0 && !vis[start - arr[start]]) {
            if(canr(arr, start - arr[start], vis))
                return true;
        }

        if(start + arr[start] < arr.size() && !vis[start + arr[start]]) {
            if(canr(arr, start + arr[start], vis))
                return true;
        }

        return false;
    }

public:
    bool canReach(vector<int>& arr, int start) {

        vector<int> vis(arr.size(), 0);

        return canr(arr, start, vis);
    }
};