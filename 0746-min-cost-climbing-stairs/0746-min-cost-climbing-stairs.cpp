class Solution {
    int findCost(vector<int>& cost, int index, vector<int>& dp){
        if(index==0) return cost[0];
        if(index==1) return cost[1];

        if(dp[index] != -1) return dp[index];
        int fs = cost[index] + findCost(cost, index-1, dp);
        int ss = INT_MAX;
        if(index>1)
            ss = cost[index] + findCost(cost, index-2, dp);

        return dp[index] = min(fs, ss);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        vector<int> dp(n, -1);
        return findCost(cost, n-1, dp);
    }
};