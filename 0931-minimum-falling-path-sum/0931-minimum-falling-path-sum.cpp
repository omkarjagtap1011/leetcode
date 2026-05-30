class Solution {
    int recur(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp){
        if(col<0 || col>=n) return 100000;
        if(row==n-1){
            return matrix[row][col];
        }
        if(dp[row][col] != 100000) return dp[row][col];

        int leftdown = matrix[row][col] + recur(row+1, col-1, matrix, n, dp);
        int down = matrix[row][col] + recur(row+1, col, matrix, n, dp);
        int rightdown = matrix[row][col] + recur(row+1, col+1, matrix, n, dp);

        return dp[row][col] = min({leftdown, down, rightdown});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            vector<vector<int>> dp(n, vector<int>(n, 100000));
            mini = min(mini, recur(0, i, matrix, n, dp));
        }

        return mini;
    }
};