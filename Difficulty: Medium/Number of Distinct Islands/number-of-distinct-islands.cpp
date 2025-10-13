#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<pair<int,int>>& shape, int row0, int col0) {
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) return;

        grid[row][col] = 0;
        shape.push_back({row - row0, col - col0});

        dfs(row + 1, col, grid, shape, row0, col0);
        dfs(row - 1, col, grid, shape, row0, col0);
        dfs(row, col + 1, grid, shape, row0, col0);
        dfs(row, col - 1, grid, shape, row0, col0);
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> uniqueIslands;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, grid, shape, i, j);
                    uniqueIslands.insert(shape);
                }
            }
        }
        return uniqueIslands.size();
    }
};
