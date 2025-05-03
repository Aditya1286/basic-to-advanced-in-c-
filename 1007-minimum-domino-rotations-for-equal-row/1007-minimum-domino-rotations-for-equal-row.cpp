class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int topRot = 0, bottomRot = 0;

        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x)
                return -1; 
            else if (tops[i] != x)
                ++topRot;
            else if (bottoms[i] != x)
                ++bottomRot;
        }

        return min(topRot, bottomRot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1)
            return result;
        return check(bottoms[0], tops, bottoms);
    }
};
