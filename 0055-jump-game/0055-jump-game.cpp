class Solution {
    bool recur(int idx, vector<int>& nums, int n, vector<int> &dp){
        if(idx==n-1) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int i=1; i<=nums[idx]; i++){
            if(idx+i < n){
                bool res = recur(idx+i, nums, n, dp);
                if(res){
                    return dp[idx] =  true;
                } 
            }else break;
        }

        return dp[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recur(0, nums, n, dp);
    }
};