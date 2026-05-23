class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;

        for(int i=1; i<=n; i++){
            int c = costs[i-1];
            int res = dp[i-1] + c + 1;
            if(i>1) res = min(res, dp[i-2] + (costs[i-1] + 4));
            if(i>2) res = min(res, dp[i-3] + (costs[i-1] + 9));

            dp[i] = res;
        }
        return dp[n];
    }
};