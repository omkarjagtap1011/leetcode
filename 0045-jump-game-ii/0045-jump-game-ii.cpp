class Solution {

int recur(vector<int>& nums, int n, int idx, vector<int>& dp){
    if(idx>=n-1) return 0;
    if(dp[idx] != -1){
        return dp[idx];
    }
    int res = INT_MAX;
    for(int j=1; j<=nums[idx]; j++){
        if(idx+j < n){
            int temp = recur(nums, n, idx + j, dp);
            if(temp != INT_MAX)
                res = min(res, 1 + temp);
        }else{
            break;
        }
    }
    return dp[idx] = res;
}
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recur(nums, n, 0, dp);
    }
};