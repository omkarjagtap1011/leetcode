class Solution {
    int calc(int n, vector<int>& dp){
        if(n<0) return 0;
        if(n==0) return 1;

        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = calc(n-1, dp) + calc(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return calc(n, dp);
    }
};