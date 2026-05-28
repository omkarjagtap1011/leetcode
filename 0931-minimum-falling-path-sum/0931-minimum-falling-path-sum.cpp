class Solution {
    int recur(int row, int last, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp){
        if(dp[row][last] != -1) return dp[row][last];
        if(row==0){
            int mini = INT_MAX;
            for(int i=0; i<n; i++){
                if(abs(last-i) <= 1){
                    mini = min(mini, matrix[0][i]);
                }
            }

            return dp[row][last] = mini;
        }

        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            if(row==n-1 || abs(last-i) <= 1){
                int score = matrix[row][i] + recur(row-1, i, matrix, n, dp);
                mini = min(mini, score);
            }
        }

        return dp[row][last] = mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int row=1; row<n; row++){
            for(int curcol=0; curcol<n; curcol++){
                int mini = INT_MAX;
                for(int prevcol=0; prevcol<n; prevcol++){
                    if(abs(prevcol-curcol) <= 1){
                        int score = matrix[row][curcol] + dp[row-1][prevcol];
                        mini = min(mini, score);
                    }
                }
                dp[row][curcol] = mini;
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};