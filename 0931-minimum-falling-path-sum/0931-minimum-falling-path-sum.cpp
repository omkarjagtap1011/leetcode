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
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int leftdown = 100000;
                int rightdown = 100000;

                if(j-1>=0)
                    leftdown = matrix[i][j] + dp[i+1][j-1];

                int down = matrix[i][j] + dp[i+1][j];

                if(j+1<n)
                    rightdown = matrix[i][j] + dp[i+1][j+1];

                dp[i][j] = min({leftdown, down, rightdown});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};