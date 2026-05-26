class Solution {
    int recur(int i, vector<int>& nums, vector<int>& dp){
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + recur(i-2, nums, dp);
        int notpick = 0 + recur(i-1, nums, dp);

        return dp[i] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recur(n-1, nums, dp);
    }
};