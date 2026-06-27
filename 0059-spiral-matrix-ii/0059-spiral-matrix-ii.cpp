class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count=1;
         vector<vector<int>> ans(n,vector<int>(n));

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++)
                ans[top][j]=count++;
            top++;

            for (int i = top; i <= bottom; i++)
                ans[i][right]=count++;
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans[bottom][j]=count++;
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans[i][left]=count++;
                left++;
            }
        }

        return ans;
    }
};