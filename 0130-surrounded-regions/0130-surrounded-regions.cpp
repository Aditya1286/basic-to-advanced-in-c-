#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& board) {
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, visited, board);
            if (board[n - 1][j] == 'O' && !visited[n - 1][j])
                dfs(n - 1, j, visited, board);
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, visited, board);
            if (board[i][m - 1] == 'O' && !visited[i][m - 1])
                dfs(i, m - 1, visited, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
