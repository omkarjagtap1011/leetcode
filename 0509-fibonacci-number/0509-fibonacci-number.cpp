class Solution {
    int calculateFib(int n, vector<int>& dp){
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = calculateFib(n-1, dp) + calculateFib(n-2, dp);
    }
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return calculateFib(n, dp);
    }
};