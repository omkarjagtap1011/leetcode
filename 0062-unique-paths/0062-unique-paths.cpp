class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for(int row=1; row<m; row++){
            int ans = 1;
            for(int col=1; col<n; col++){
                ans = ans + dp[col];
                dp[col] = ans;
            }
        }
        return dp[n-1];
    }
};