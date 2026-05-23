class Solution {
    int recur(vector<int>& costs, int i, vector<int>& dp){
        if(i==0) return 0;

        if(dp[i] != -1) return dp[i];

        int c = costs[i-1];
        int res = recur(costs, i-1, dp) + c + 1;
        if(i>1) res = min(res, recur(costs, i-2, dp) + (costs[i-1] + 4));
        if(i>2) res = min(res, recur(costs, i-3, dp) + (costs[i-1] + 9));

        return dp[i] = res;
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return recur(costs, n, dp);
    }
};