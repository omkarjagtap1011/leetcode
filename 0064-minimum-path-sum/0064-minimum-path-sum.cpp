class Solution {
    int recur(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row==0 && col==0){
            return grid[row][col];
        }

        if(row < 0 || col < 0){
            return 200000;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int left = recur(row, col-1, grid, dp);
        int up = recur(row-1, col, grid, dp);

        return dp[row][col] = (grid[row][col] + min(left, up));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recur(m-1, n-1, grid, dp);
    }
};