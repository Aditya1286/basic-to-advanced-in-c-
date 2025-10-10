class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>>& image, int newColor, int oldColor) {
        int n = image.size();
        int m = image[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m) return;
        if (image[r][c] != oldColor) return;
        image[r][c] = newColor;
        dfs(r + 1, c, image, newColor, oldColor);
        dfs(r - 1, c, image, newColor, oldColor);
        dfs(r, c + 1, image, newColor, oldColor);
        dfs(r, c - 1, image, newColor, oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        dfs(sr, sc, image, newColor, oldColor);
        return image;
    }
};
